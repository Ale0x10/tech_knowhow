Die Umsetzung von Radiation Hardening auf RTL-/HDL-Ebene ist technisch anspruchsvoll, aber absolut machbar. Hier sind die wichtigsten Ansätze und wie man sie konkret implementiert:
---
Quellen:
https://nepp.nasa.gov/mapld_2009/talks/090309_Thursday/Session%20D/07_Huynh_Buu_mapld09_pres_1.ppt
https://www.asicnorth.com/blog/rad-hard-asic-design-approach/
https://www.mdpi.com/2079-9292/8/1/24  (Hardening Through VHDL Datatype)
https://www.mdpi.com/2079-9292/7/9/163 (Total Ionizing Dose Effects - PUFs)
---

### 🛡️ 1. Triple Modular Redundancy (TMR)

**Ziel:** Schutz vor Single Event Upsets (SEUs) durch Redundanz.

**Umsetzung:**
- Ersetze jede Flip-Flop-Instanz durch drei identische Flip-Flops.
- Füge eine **Majority-Voting-Logik** hinzu, die den korrekten Wert aus den drei Ausgaben bestimmt.
- Beispiel in Verilog:
  ```verilog
  assign voted_output = (ff1 & ff2) | (ff2 & ff3) | (ff1 & ff3);
  ```
- **Platzierung:** Die drei Flip-Flops sollten physisch voneinander getrennt sein, um Mehrfachausfälle (MBUs) zu vermeiden.

---

### 🔄 2. Safe State Machines

**Ziel:** Verhindern, dass FSMs durch Strahlung in ungültige Zustände geraten.

**Umsetzung:**
- Definiere **alle möglichen Zustände** explizit, inklusive eines sicheren Default-Zustands.
- Implementiere eine **Fehlererkennung** für ungültige Zustände und leite eine Rückkehr zum sicheren Zustand ein.
- Beispiel in VHDL:
  ```vhdl
  case current_state is
    when S0 => next_state <= S1;
    when S1 => next_state <= S2;
    ...
    when others => next_state <= S0; -- Safe fallback
  end case;
  ```
- **Vermeide** das Entfernen von "unreachable states" beim Syntheseprozess.

---

### 🧠 3. Fehlererkennung und -korrektur (EDAC)

**Ziel:** Schutz von Datenpfaden und Speicherbereichen.

**Umsetzung:**
- Verwende **Hamming-Codes** oder andere ECC-Methoden für Speicherblöcke.
- Implementiere **Parity Checks** für Register und Datenbusse.
- Beispiel:
  - Schreibe bei jedem Registerzugriff ein Paritätsbit mit.
  - Prüfe beim Lesen, ob die Parität korrekt ist.
  - Bei Fehler: Trigger für Fehlerbehandlung oder Wiederherstellung.

---

### 🧪 4. Verifikation

**Ziel:** Nachweis, dass die Maßnahmen funktionieren.

**Methoden:**
- **Fault Injection Tests** auf RTL-Ebene.
- **Simulation von SEUs** durch gezielte Bitflips.
- **Formale Verifikation** von FSMs und TMR-Logik.
- **Timing-Analyse** zur Sicherstellung, dass zusätzliche Logik keine kritischen Pfade stört.

---
---


Triple Modular Redundancy (TMR) in VHDL bedeutet, dass du eine Funktion oder ein Register dreifach implementierst und die Ausgaben über eine Mehrheitslogik zusammenführst. Hier zeige ich dir ein konkretes Beispiel für die Umsetzung auf RTL-Ebene:

---

### 🧠 Beispiel: TMR für ein einfaches Register

#### 🔧 Ziel:
Ein 1-Bit-Register mit TMR, das gegen SEUs geschützt ist.

#### 📦 Komponenten:
- Drei identische Register
- Majority-Voter-Logik

#### 📄 VHDL-Code:
```vhdl
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity TMR_Register is
    Port (
        clk     : in  STD_LOGIC;
        rst     : in  STD_LOGIC;
        d_in    : in  STD_LOGIC;
        q_out   : out STD_LOGIC
    );
end TMR_Register;

architecture Behavioral of TMR_Register is
    signal q1, q2, q3 : STD_LOGIC;
begin

    -- Drei identische Register
    process(clk, rst)
    begin
        if rst = '1' then
            q1 <= '0';
            q2 <= '0';
            q3 <= '0';
        elsif rising_edge(clk) then
            q1 <= d_in;
            q2 <= d_in;
            q3 <= d_in;
        end if;
    end process;

    -- Majority-Voter-Logik
    q_out <= (q1 and q2) or (q2 and q3) or (q1 and q3);

end Behavioral;
```

---

### 🧪 Tipps zur Verifikation

- **Fault Injection:** Simuliere Bitflips in einem der Register und prüfe, ob die Mehrheit korrekt bleibt.
- **Timing-Analyse:** Stelle sicher, dass die zusätzliche Logik keine kritischen Pfade beeinflusst.
- **Platzierung:** In der Synthese solltest du die Register räumlich trennen (z. B. mit `LOC`-Constraints), um Mehrfachausfälle zu vermeiden.

---
---




Es gibt durchaus Alternativen zu Triple Modular Redundancy (TMR) in VHDL, die ebenfalls zur **Strahlungshärtung** beitragen können – je nach Anforderungen an Robustheit, Ressourcenverbrauch und Designkomplexität. Hier sind einige Ansätze:

---

### 🧩 1. **Selective Hardening via VHDL-Datentypen**

Statt das gesamte Design zu tripplizieren, kannst du **nur kritische Komponenten** absichern – z. B. Register, die direkt mit externen Schnittstellen oder sicherheitsrelevanten Zuständen verbunden sind.

🔧 **Wie?**  
Ein Ansatz aus der Forschung schlägt vor, durch **Datentyp-Substitution** in VHDL automatisch Redundanz einzuführen. Du ersetzt z. B. `std_logic` durch einen benutzerdefinierten „hardened“ Typ, der intern Redundanz und Voting enthält.

📦 Vorteil: Minimalinvasive Änderung am Code, gezielte Absicherung.

---

### 🧠 2. **Error Detection and Correction (EDAC)**

Statt Fehler zu vermeiden, kannst du sie **erkennen und korrigieren**.

🔧 Beispiele:
- **Parity Bits** für einfache Fehlererkennung
- **Hamming Codes** für Speicherbereiche
- **CRC-Checks** für Datenpfade

📦 Vorteil: Spart Ressourcen im Vergleich zu TMR, aber benötigt Fehlerbehandlungslogik.

---

### 🔄 3. **Dual Modular Redundancy (DMR) + Error Flagging**

DMR nutzt zwei Instanzen und vergleicht deren Ausgaben. Bei Abweichung wird ein Fehler gemeldet, aber keine automatische Korrektur durchgeführt.

📦 Vorteil: Weniger Ressourcen als TMR, aber keine Selbstheilung.

---

### 🧮 4. **Safe State Machines mit Watchdog**

FSMs können durch Strahlung in ungültige Zustände geraten. Du kannst:
- Alle Zustände explizit definieren
- Ungültige Zustände erkennen und in einen sicheren Zustand zurückspringen
- Optional einen **Watchdog-Timer** integrieren, der bei Timeout einen Reset auslöst

---

### 🧪 5. **Temporal Redundancy**

Statt räumlicher Redundanz (mehrere Instanzen), nutzt du **zeitliche Wiederholung**:
- Berechne denselben Wert mehrfach über die Zeit
- Vergleiche Ergebnisse zur Fehlererkennung

📦 Vorteil: Spart Fläche, aber erhöht Latenz

---
---

LOC-Constraints (Location Constraints) sind eine Möglichkeit, in VHDL oder über eine Constraints-Datei (z. B. XDC bei AMD/Xilinx) festzulegen, **wo genau auf dem FPGA ein bestimmtes Element platziert werden soll**. Das ist besonders wichtig bei strahlungsharten Designs, etwa bei TMR, wo du sicherstellen willst, dass die drei redundanten Instanzen **nicht direkt nebeneinander liegen** – sonst könnten sie durch einen einzelnen Strahlungstreffer gleichzeitig ausfallen.

---

### 📍 Was bewirken LOC-Constraints?

- Sie **binden logische Elemente** (z. B. Flip-Flops, LUTs, I/O-Pins) an **physische Ressourcen** auf dem FPGA.
- Du kannst damit gezielt **räumliche Trennung** oder **Timing-Optimierung** erreichen.
- LOC wird oft zusammen mit anderen Constraints wie `BEL` (Basic Element Location) oder `PACKAGE_PIN` verwendet.

---

### 🧾 Beispiel in VHDL

```vhdl
attribute LOC : string;
attribute LOC of my_ff : label is "SLICE_X10Y20";
```

🔍 Das weist dem Flip-Flop `my_ff` die physische Position `SLICE_X10Y20` zu – eine Koordinate auf dem FPGA.

---

### 🧾 Beispiel in XDC (Constraints-Datei)

```xdc
set_property LOC SLICE_X10Y20 [get_cells my_ff]
```

📦 Das ist die bevorzugte Methode bei modernen Tools wie Vivado. Du kannst damit auch ganze Module oder Netze platzieren.

---

### 🛡️ Anwendung bei TMR

Wenn du drei Register für TMR hast (`ff1`, `ff2`, `ff3`), kannst du sie mit LOC-Constraints **weit voneinander entfernt platzieren**, z. B.:

```xdc
set_property LOC SLICE_X10Y20 [get_cells ff1]
set_property LOC SLICE_X30Y40 [get_cells ff2]
set_property LOC SLICE_X50Y60 [get_cells ff3]
```

So reduzierst du das Risiko, dass ein einzelner SEU alle drei gleichzeitig trifft.

---
---



Die Idee eines „hardened“ VHDL-Datentyps ist genial: Statt dein gesamtes Design manuell mit TMR oder EDAC auszustatten, kannst du gezielt kritische Signale durch einen speziellen Datentyp absichern – und die Redundanz wird automatisch eingefügt. Das spart Zeit, reduziert Fehler und macht dein Design modular robuster.
---

### 🧠 Konzept: Hardened Datentypen in VHDL

Ein „hardened“ Datentyp ist ein benutzerdefinierter VHDL-Typ, der intern:
- **Mehrfachspeicherung** (z. B. TMR) nutzt
- **Voting-Logik** enthält
- Optional **Fehlererkennung** und -korrektur bietet

Statt `std_logic` verwendest du z. B. `hardened_logic`, und dein Design wird automatisch strahlungsresistent – zumindest für diesen Signalpfad.

---

### 📦 Beispiel: Einfacher TMR-Datentyp in VHDL

```vhdl
-- Hardened_Types.vhd
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

package Hardened_Types is
    type hardened_logic is record
        r1 : std_logic;
        r2 : std_logic;
        r3 : std_logic;
    end record;

    function majority_vote(h : hardened_logic) return std_logic;
    function to_hardened(d : std_logic) return hardened_logic;
end package;

package body Hardened_Types is
    function majority_vote(h : hardened_logic) return std_logic is
    begin
        return (h.r1 and h.r2) or (h.r2 and h.r3) or (h.r1 and h.r3);
    end;

    function to_hardened(d : std_logic) return hardened_logic is
        variable h : hardened_logic;
    begin
        h.r1 := d;
        h.r2 := d;
        h.r3 := d;
        return h;
    end;
end package body;
```

---

### 🛠 Verwendung im Design

```vhdl
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.Hardened_Types.ALL;

entity HardenedExample is
    Port (
        clk   : in  std_logic;
        rst   : in  std_logic;
        d_in  : in  std_logic;
        q_out : out std_logic
    );
end HardenedExample;

architecture Behavioral of HardenedExample is
    signal h_reg : hardened_logic;
begin
    process(clk, rst)
    begin
        if rst = '1' then
            h_reg := to_hardened('0');
        elsif rising_edge(clk) then
            h_reg := to_hardened(d_in);
        end if;
    end process;

    q_out <= majority_vote(h_reg);
end Behavioral;
```

---

### 🔍 Vorteile

- **Modularität**: Du kannst gezielt einzelne Signale härten.
- **Wiederverwendbarkeit**: Einmal definierte Typen kannst du überall einsetzen.
- **Feingranularität**: Nur kritische Pfade werden geschützt – spart Ressourcen.

---

📚 Eine wissenschaftliche Quelle, die dieses Konzept vertieft, ist [dieser Artikel von MDPI](https://www.mdpi.com/2079-9292/8/1/24). Er beschreibt, wie man durch einfache Typänderung in VHDL automatisch Redundanz einfügt – inklusive Simulation und Fault Injection.


