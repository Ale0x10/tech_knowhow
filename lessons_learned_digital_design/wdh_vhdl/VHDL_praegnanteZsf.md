VHDL Wiederholung -prägnante Zusammenfassung:

In VHDL bedeutet es, dass **eine Variable, die innerhalb eines Prozesses deklariert ist**, nur **lokal** für diesen Prozess existiert – genauer gesagt: **nur während der Ausführung des Prozesses**.

### 🔍 Was heißt das konkret?

- Die Variable wird **bei jedem Aufruf des Prozesses neu erzeugt**.
- Sie **behält ihren Wert nicht** zwischen zwei Prozessaktivierungen.
- Sobald der Prozess **verlassen wird**, wird die Variable **verworfen** – sie existiert nicht mehr und ihr Wert geht verloren.

### 🧠 Beispiel zur Veranschaulichung

```vhdl
process(clk)
  variable counter : integer := 0;
begin
  if rising_edge(clk) then
    counter := counter + 1;
    report "Counter: " & integer'image(counter);
  end if;
end process;
```

Hier sieht es so aus, als würde `counter` bei jedem Takt steigen – **tut es aber nicht**. Warum?

- Weil `counter` eine **Variable** ist, nicht ein **Signal**.
- Sie wird **bei jedem Durchlauf neu mit 0 initialisiert**.
- Das heißt: `counter` ist **immer 1**, wenn `rising_edge(clk)` wahr ist.

### ✅ Wann sollte man stattdessen ein Signal verwenden?

Wenn du möchtest, dass ein Wert **zwischen Prozessdurchläufen erhalten bleibt**, musst du ein **Signal** verwenden:

```vhdl
signal counter : integer := 0;

process(clk)
begin
  if rising_edge(clk) then
    counter <= counter + 1;
  end if;
end process;
```

Jetzt bleibt `counter` erhalten – weil Signale **global im Design** sind und **nicht bei jedem Prozessdurchlauf neu erzeugt werden**.

---

💡 **Zusammenfassung:**

- **Variable in Prozess**: temporär, nur während Prozesslauf gültig.
- **Signal**: dauerhaft, speichert Wert über mehrere Prozessläufe.
- VHDL ist **nicht objektorientiert**, aber Prozesse sind wie kleine Funktionen mit lokalem Speicher (Variablen) und globalem Speicher (Signale).

---

In VHDL sind **Variablen innerhalb eines Prozesses sofort wirksam**, **ohne Delta-Zyklen**. Das ist ein ganz zentraler Unterschied zu Signalen.

---

## ⚡ Verhalten von Variablen vs. Signalen in VHDL

### 🧠 Faustregel

> **Variablen sind für Berechnungen, Signale sind für Kommunikation.**

Du kannst sie kombinieren – aber du musst wissen, **wann** der Wert gültig ist.

---

| Merkmal                  | **Variable**                         | **Signal**                             |
|--------------------------|--------------------------------------|----------------------------------------|
| Sichtbarkeit             | Nur im Prozess                       | Global                                 |
| Wirksamkeit              | **Sofort**                           | **Erst im nächsten Delta-Zyklus**      |
| Zuweisung                | `:=`                                 | `<=`                                   |
| Speichern über Zeit      | Nur temporär                         | Bleibt erhalten                        |
| Simulationseffekt        | Keine Delta-Verzögerung              | Delta-Zyklus-Verzögerung               |

---

### 🧠 Beispiel zur Verdeutlichung

```vhdl
process
  variable a : integer := 0;
  variable b : integer := 0;
begin
  a := 5;
  b := a + 1;  -- b wird sofort zu 6
end process;
```

→ `b` sieht **sofort** den neuen Wert von `a`.

Aber mit Signalen:

```vhdl
signal a, b : integer := 0;

process
begin
  a <= 5;
  b <= a + 1;  -- b wird zu 1, weil a noch 0 ist!
end process;
```

→ `b` sieht **noch den alten Wert** von `a`, weil die Zuweisung erst im nächsten Delta-Zyklus wirksam wird.

---

### 🧪 Warum ist das wichtig?

- Für **Berechnungen innerhalb eines Prozessdurchlaufs** sind Variablen ideal.
- Für **Speicherung über Zeit** oder **Kommunikation zwischen Prozessen** brauchst du Signale.
- Wenn du versehentlich ein Signal verwendest, wo du eine Variable brauchst, bekommst du **unerwartete Simulationsergebnisse**.
---
In VHDL kann man **Signale in Variablen speichern** und auch **Variablenwerte in Signale übertragen** – aber **nur innerhalb eines Prozesses**, und du musst die Unterschiede im Timing beachten.

---

## 🔁 Signal → Variable

Du kannst den aktuellen Wert eines Signals **sofort** in eine Variable kopieren:

```vhdl
process(clk)
  variable temp : integer;
begin
  if rising_edge(clk) then
    temp := signal_a;  -- signal_a wird gelesen und temp bekommt den Wert
  end if;
end process;
```

✅ Das funktioniert problemlos. Die Variable `temp` bekommt den **aktuellen Wert** von `signal_a`.
---

## 🔁 Variable → Signal

Du kannst auch den Wert einer Variable **in ein Signal schreiben**:

```vhdl
process(clk)
  variable temp : integer;
begin
  if rising_edge(clk) then
    temp := 42;
    signal_b <= temp;  -- signal_b bekommt den Wert von temp
  end if;
end process;
```

✅ Auch das ist erlaubt. Aber beachte: `signal_b` wird **erst im nächsten Delta-Zyklus** aktualisiert – also **nicht sofort sichtbar**.
---

## ⚠️ Wichtig: Timing beachten

| Aktion                  | Zeitpunkt der Wirkung         |
|-------------------------|-------------------------------|
| Variable-Zuweisung      | **Sofort**                    |
| Signal-Zuweisung        | **Erst im nächsten Delta-Zyklus** |

Das bedeutet: Wenn du zuerst ein Signal liest, in eine Variable schreibst, und dann mit der Variable weiterrechnest, ist alles **synchron und korrekt**. Aber wenn du versuchst, **mehrere Signal-Zuweisungen über Variablen zu steuern**, musst du aufpassen, dass du keine **Race Conditions** oder **falsche Simulationsergebnisse** bekommst.

---

VHDL hat ein paar Konzepte, die selbst erfahrene Entwickler manchmal ins Schwitzen bringen 😅. Einige der **schwierigeren oder besonders fehleranfälligen Konzepte**, die du kennen solltest:

## 🔥 1. **Shared Variables**
- Werden zwischen mehreren Prozessen geteilt.
- Können Race Conditions verursachen, wenn nicht korrekt synchronisiert.
- Nur sinnvoll in sehr speziellen Fällen (z. B. bei Testbenches).
- **Nicht für Synthese empfohlen!**

---

## 🧩 2. **Delta-Zyklen und Simulationstiming**
- VHDL-Simulation arbeitet mit **Simulationszeit** und **Delta-Zyklen**.
- Ein Signal kann sich **mehrfach innerhalb derselben Simulationszeit** ändern – aber in verschiedenen Delta-Zyklen.
- Das beeinflusst, **wann** eine Zuweisung wirksam wird.
- Beispiel: `a <= b;` wird erst im nächsten Delta-Zyklus sichtbar.

---

## 🧠 3. **Resolved vs. Unresolved Types**
- `std_logic` ist ein **resolved type** – kann mehrere Treiber haben.
- `bit` ist **unresolved** – nur ein Treiber erlaubt.
- Wenn du versehentlich mehrere Prozesse auf ein `bit` schreiben lässt → **Fehler**.
- Typwahl beeinflusst, ob dein Design überhaupt synthetisierbar ist.

---

## 🧪 4. **Initialisierung und Reset-Verhalten**
- VHDL erlaubt **Initialwerte** bei der Deklaration.
- Aber: viele Synthesetools ignorieren diese Initialisierung!
- Du musst **explizit resetten**, sonst startet dein Design mit undefiniertem Zustand.

---

## 🧠 5. **Generics und Configurations**
- Generics sind wie Parameter – super mächtig, aber komplex in großen Designs.
- Configurations erlauben es, verschiedene Architekturen zu wählen – selten genutzt, aber sehr mächtig.
- In der Praxis oft schwer zu debuggen und zu verwalten.

---

## 🧠 6. **Record- und Array-Typen**
- Sehr nützlich für strukturierte Daten.
- Aber: komplexe Typen können zu **komplizierten Zuweisungen** und **Timingproblemen** führen.
- Besonders bei Arrays von Records mit mehreren Feldern.

---

## 🧠 7. **Testbenches mit `textio` und File I/O**
- VHDL kann Dateien lesen/schreiben – z. B. für Simulationen.
- Aber das ist **nicht trivial**: du brauchst `textio`, `file`, `line`, `read`, `write`, etc.
- Fehleranfällig und schwer zu debuggen.

---

## 🧠 8. **Clock Domain Crossing (CDC)**
- Wenn du mehrere Taktbereiche hast, musst du Daten **sicher übertragen**.
- VHDL bietet keine automatische Lösung – du musst mit Synchronisierern, FIFOs oder Handshake-Logik arbeiten.
- Fehler hier führen zu **Metastabilität** und **Datenverlust**.

---