**Zonenmessung im EMV-Kontext** bedeutet in der Praxis meist **Fernfeldmessung mit Sweep**, also:

- Frequenzdurchlauf (Sweep) mit Spektrumanalysator oder EMV-Messempfänger  
- Messung der abgestrahlten Störleistung in definierten Zonen (z. B. 3 m, 10 m Abstand)  
- Variation von **Polarisation** (horizontal/vertikal)  
- Einsatz verschiedener **Antennentypen** je nach Frequenzbereich

---

### 🔍 Was gehört _zusätzlich_ zur Zonenmessung?

1. **Drehtischrotation**
   - Der Prüfling wird um 360° gedreht, um die maximale Abstrahlung in alle Richtungen zu erfassen.

2. **Antennen-Höhenscan**
   - Die Empfangsantenne wird vertikal bewegt (typisch 1–4 m), um Resonanzen und Maxima zu erfassen.

3. **Messmodi**
   - Es wird nicht nur „Sweep“ gemacht, sondern auch **Quasipeak**, **Peak** und **Average** bewertet – je nach Norm (z. B. CISPR 11, 22).

4. **Automatisierte Steuerung**
   - Die Messsoftware synchronisiert Sweep, Drehtisch und Antennenmast, um die **maximalen Werte** zu erfassen.

---

### 🧪 Also: Zonenmessung = mehr als nur Sweep

| Bestandteil            | Funktion                                           |
|------------------------|----------------------------------------------------|
| Sweep                  | Frequenzanalyse der Emissionen                     |
| Drehtisch              | Richtungsabhängige Erfassung                       |
| Höhenverstellung       | Erfassung vertikaler Maxima                        |
| Polarisation           | Erkennung feldrichtungsabhängiger Emissionen      |
| Antennenwahl           | Anpassung an Frequenzbereich und Norm             |
| Bewertungsmodi         | Quasipeak, Peak, Average – je nach Normvorgabe    |

---

Sehr gute Beobachtung – du bringst hier mehrere wichtige Aspekte zusammen, die in der Praxis oft miteinander verwechselt werden. Lass uns das sauber auseinanderziehen:

---

### 🧭 **Zonenmessung: Nahfeld vs. Fernfeld**

Bei einer klassischen **Zonenmessung im EMV-Kontext** geht es in der Regel um die **abgestrahlte elektromagnetische Emission** eines Geräts. Dabei unterscheidet man:

#### 🔹 **Nahfeldmessung**
- Direkt am Gerät oder der Leiterplatte
- Mit **Nahfeldsonden** (E- und H-Feld)
- Dient zur **lokalen Störquellenanalyse** (z. B. Taktleitungen, DC/DC-Wandler)
- Wird oft in der Entwicklungsphase eingesetzt

#### 🔹 **Fernfeldmessung**
- In definiertem Abstand (z. B. 3 m oder 10 m)
- Mit **Messantenne** und **Spektrumanalysator**
- Dient zur **normgerechten Bewertung** der Gesamtabstrahlung
- Typisch für CE-Zertifizierung und CISPR-konforme Tests

➡️ **Zonenmessung kann beides beinhalten**, je nachdem, ob du die Störquelle lokalisieren willst (Nahfeld) oder die Einhaltung von Grenzwerten prüfen musst (Fernfeld).

---

### ⚡ **Und was ist mit Burst-Messungen?**

**Burst-Tests** gehören zur **Störfestigkeitsprüfung**, nicht zur Emissionsmessung. Sie sind Teil der sogenannten **Immunitätsprüfungen** nach Normen wie **EN 61000-4-4**.

#### 🔸 Burst-Messung (Electrical Fast Transients, EFT)
- Simuliert schnelle, impulsartige Störungen auf Leitungen
- Wird mit einem **Burst-Generator** durchgeführt
- Ziel: Prüfen, ob das Gerät **funktional stabil bleibt**, wenn es gestört wird
- Betrifft **Netzleitungen, Datenleitungen, Steuerleitungen**

➡️ Burst-Messungen sind **nicht Teil der Zonenmessung**, sondern ein **separater Test**, der oft **parallel** zur EMV-Prüfung durchgeführt wird – aber mit ganz anderem Fokus: **Störresistenz statt Störaussendung**.

---

### 🧪 Fazit

- **Zonenmessung** = räumlich aufgelöste Emissionsmessung → Nahfeld & Fernfeld möglich  
- **Burst-Messung** = separate Immunitätsprüfung → keine Feldmessung, sondern Störsimulation  
- Beide Tests sind **Teil eines vollständigen EMV-Prüfprogramms**, aber mit **unterschiedlichen Zielen und Methoden**

---

Der klassische **Frequenz-Sweep mit Spektrumanalysator** ist zwar die bekannteste Methode bei EMV-Zonenmessungen, aber **nicht die einzige**. Es gibt mehrere alternative Messverfahren, je nach Ziel, Norm und Prüfaufbau. Hier sind die wichtigsten:

---

### ⚙️ 1. **Zeitbereichsmessung (Time Domain Scan)**  
Statt die Frequenz einzeln durchzuscannen, wird das Signal **direkt im Zeitbereich erfasst** und anschließend per **FFT (Fast Fourier Transform)** in den Frequenzbereich umgerechnet.

- **Vorteile:** Sehr schnell, ideal für transiente Störungen (z. B. Burst, ESD)
- **Typische Geräte:** Echtzeit-Spektrumanalysatoren, Oszilloskope mit FFT-Funktion
- **Anwendung:** Pre-Compliance, schnelle Übersicht, Störquellenanalyse

---

### 📡 2. **Nahfeldmessung mit Nahfeldsonden**  
Hier wird die EM-Abstrahlung **direkt auf der Platine oder am Gehäuse** gemessen – also nicht im Fernfeld, sondern **lokal und punktgenau**.

- **Vorteile:** Identifikation konkreter Störquellen (z. B. Taktleitungen, DC/DC-Wandler)
- **Typische Geräte:** Nahfeldsonden + Spektrumanalysator oder EMV-Scanner
- **Anwendung:** Entwicklung, Fehlersuche, Designoptimierung

---

### 🧪 3. **Modenverwirbelungskammer (Reverberation Chamber)**  
Statt Freifeld wird eine spezielle Kammer genutzt, in der die elektromagnetischen Wellen **reflektiert und verwirbelt** werden. Das ergibt eine **statistische Bewertung** der Emission.

- **Vorteile:** Sehr reproduzierbar, platzsparend, ideal für automatisierte Tests
- **Typische Geräte:** Modenverwirbelungskammer + Power Meter + Steuerungseinheit
- **Anwendung:** Automotive, Luftfahrt, sicherheitskritische Systeme

---

### 🧭 4. **Pre-Compliance-Messung mit Tracking-Generator**  
Hier wird ein **Tracking-Generator** verwendet, um gezielt Frequenzen zu stimulieren und die Reaktion des Systems zu beobachten – oft kombiniert mit Nahfeldsonden.

- **Vorteile:** Kostengünstig, frühzeitig im Entwicklungsprozess einsetzbar
- **Typische Geräte:** Spektrumanalysator mit Tracking-Generator, EMV-Precompliance-Tools
- **Anwendung:** Designphase, Prototypenprüfung

---

### 🧰 Fazit

Die Sweep-Methode ist ideal für **normgerechte Freifeldmessungen**, aber in der Praxis nutzt man oft **eine Kombination aus Zeitbereichs-, Nahfeld- und Precompliance-Messungen**, um Störungen frühzeitig zu erkennen und gezielt zu beheben.

---

Die Begriffe **Peak**, **Quasipeak** und **Average** sind zentrale Bewertungsmethoden in der EMV-Messtechnik, insbesondere bei **abgestrahlten und leitungsgeführten Störungen**. Sie sind **nicht einfach nur rechnerisch aus dem Sweep abgeleitet**, sondern basieren auf **unterschiedlichen Detektoren** mit jeweils eigener Bewertungslogik. Hier kommt eine klare Übersicht:

---

### 📊 Die drei Bewertungsmethoden im Überblick

| Methode       | Was sie misst                         | Aussagekraft / Anwendung                          |
|---------------|----------------------------------------|---------------------------------------------------|
| **Peak**      | Den **höchsten gemessenen Pegel**      | Schnell, zeigt Maximalwerte – aber oft zu streng  |
| **Quasipeak** | Bewertet **Störsignale nach Häufigkeit und Dauer** | Realitätsnah, normrelevant (z. B. CISPR)          |
| **Average**   | Den **Mittelwert über eine Zeitspanne**| Glättet impulsartige Störungen, zeigt Dauerbelastung |

---

### 🔹 1. **Peak Detektor**
- Misst den **höchsten Momentanwert** eines Signals im Frequenzbereich.
- Sehr empfindlich – zeigt auch kurze Impulse mit voller Amplitude.
- Wird oft **zur Vorprüfung** verwendet, um kritische Frequenzbereiche zu identifizieren.
- **Nicht normrelevant** für die finale Bewertung, da zu konservativ.

🧠 Beispiel:  
Ein kurzer Impuls mit hoher Amplitude wird voll erfasst – auch wenn er nur einmal auftritt.

---

### 🔸 2. **Quasipeak Detektor (QP)**
- Bewertet nicht nur die Höhe, sondern auch die **Wiederholrate und Dauer** von Störungen.
- Hat definierte **Lade- und Entladezeiten** (nach CISPR 16-1-1), die das Anzeigeverhalten beeinflussen.
- **Normrelevant** – z. B. für CE-Zertifizierung nach CISPR 11, 22, EN 55032.
- Simuliert, wie störend ein Signal **für ein Radio oder TV-Gerät** wäre.

🧠 Beispiel:  
Ein Signal, das häufig und regelmäßig auftritt, wird stärker gewichtet als ein einmaliger Impuls.

---

### 🔸 3. **Average Detektor**
- Berechnet den **arithmetischen Mittelwert** der Signalstärke über eine bestimmte Zeit.
- Glättet impulsartige Störungen – zeigt, wie stark ein Gerät **dauerhaft** abstrahlt.
- Wird oft **zusätzlich zur Quasipeak-Messung** durchgeführt, z. B. bei Breitbandstörungen.

🧠 Beispiel:  
Ein Gerät mit vielen kleinen Impulsen über längere Zeit zeigt einen mittleren Pegel – auch wenn kein einzelner Impuls besonders stark ist.

---

### 🧪 Fazit: Warum alle drei?

- **Peak** zeigt, wo Probleme sein _könnten_  
- **Quasipeak** zeigt, ob sie _normrelevant_ sind  
- **Average** zeigt, ob sie _dauerhaft_ auftreten

➡️ In der Praxis wird oft **zuerst mit Peak gescannt**, dann in kritischen Bereichen **Quasipeak und Average nachgemessen**.

---

Sehr gute Frage – du willst wissen, **woher die Störungen kommen**, die bei EMV-Messungen als **Peak**, **Quasipeak (QP)** und **Average (AvrP)** auftauchen, und welche davon **unvermeidbar** sind. Lass uns das praxisnah und elektrotechnisch aufdröseln:

---

## ⚡ Ursachen für Peak-, Quasipeak- und Average-Störungen

### 🔹 **Peak-Störungen**
Diese entstehen durch **kurze, impulsartige Ereignisse** mit hoher Amplitude. Typische Ursachen:

- **Schaltvorgänge** in digitalen ICs (z. B. Taktflanken, Flip-Flops)
- **DC/DC-Wandler** mit schnellen Transienten
- **Relais, Motoren, Ventile** beim Ein-/Ausschalten
- **ESD-Ereignisse** oder elektromechanische Impulse

➡️ **Peak-Störungen sind oft unvermeidbar**, da sie direkt aus der Funktion digitaler Systeme resultieren. Man kann sie aber **dämpfen oder abschirmen**.

---

### 🔸 **Quasipeak-Störungen (QP)**
Diese entstehen durch **wiederholte Impulse**, die **nicht extrem stark**, aber **häufig** auftreten. Ursachen:

- **Periodische Taktgeber** (z. B. 100 MHz Clock)
- **PWM-Signale** in Motorsteuerungen oder LED-Treibern
- **Regelkreise** in Schaltnetzteilen
- **Störsignale durch Buskommunikation** (SPI, I²C, CAN)

➡️ QP-Störungen sind **realitätsnah**, weil sie zeigen, wie störend ein Signal für andere Geräte ist. Sie lassen sich **durch gutes Layout, Filterung und EMV-Design** deutlich reduzieren.

---

### 🔸 **Average-Störungen (AvrP)**
Diese entstehen durch **dauerhafte oder breitbandige Emissionen**. Ursachen:

- **Rauschen** von Analogschaltungen oder ADCs
- **HF-Kommunikation** (z. B. Bluetooth, WLAN)
- **Stromversorgungsrauschen** (Ripple, Brumm)
- **Thermisches Rauschen** oder **Schaltflankenhäufung**

➡️ Average-Störungen sind oft **systembedingt** und schwer ganz zu vermeiden. Sie lassen sich aber **gezielt glätten**, z. B. durch bessere Masseführung, Filterkondensatoren oder Abschirmung.

---

## 🧠 Welche Störungen sind **unvermeidbar**?

| Typ         | Unvermeidbar? | Warum?                                               | Was hilft?                          |
|-------------|---------------|-------------------------------------------------------|-------------------------------------|
| **Peak**    | Teilweise      | Digitale Schaltvorgänge sind inhärent (untrennbar dazugehört) | EMV-Filter, Snubber, Abschirmung    |
| **Quasipeak** | Reduzierbar   | Wiederholrate und Impulsform sind designabhängig     | Taktoptimierung, Layout, Filter     |
| **Average** | Teilweise      | Rauschen und Daueremissionen sind physikalisch bedingt | Masseführung, Kondensatoren, Shielding |

---

