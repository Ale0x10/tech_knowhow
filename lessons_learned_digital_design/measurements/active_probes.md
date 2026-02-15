Gute Frage – das ist genau der Punkt, an dem viele SI-Messungen falsch interpretiert werden.

**praxisnahe Faustregel + konkrete Oszi-Einstellungen**.

---

# 1. Ab welcher Frequenz braucht man aktive Tastköpfe?

Entscheidend ist **nicht die Taktfrequenz**, sondern die **Flankensteilheit** des Signals.

### Grundregel

Man betrachtet die **höchste relevante Frequenzkomponente** eines Rechtecksignals:

[
f_{max} \approx \frac{0{,}35}{t_r}
]

* (t_r) = Rise Time des Signals
* Alles oberhalb davon beeinflusst die Signalform

---

## Typische Bereiche

### < 100 MHz Signalbandbreite

* **Passive 10:1 Tastköpfe** meist ausreichend
* Voraussetzung:

  * kurze Massefeder
  * geringe Leitungsinduktivität

👉 Gilt z. B. für:

* Mikrocontroller-GPIO
* langsame SPI/I²C
* einfache Analogsignale

---

### 100 MHz – 1 GHz

* Passive Tastköpfe **werden kritisch**
* **Aktive Single-Ended-Tastköpfe** sinnvoll

Warum?

* geringere Eingangskapazität (≈ 0,5–1 pF statt 8–12 pF)
* weniger Signalverfälschung
* bessere Rise-Time-Darstellung

Typisch:

* schnelle CMOS-Signale
* SDRAM
* LVDS-Clocks

---

### > 1 GHz bzw. Rise-Time < 350 ps

➡️ **Aktive Tastköpfe zwingend**

Zusätzlich oft nötig:

* **Differenzielle Tastköpfe**
* **SMA-Direktanschluss** oder **Browser-Probe**
* sehr kurze Stub-Längen (< 1 mm)

Typisch:

* DDR3/4/5
* PCIe
* SerDes / Multi-Gbps-Links

---

# 2. Wichtige Oszilloskop-Einstellungen bei aktiven Tastköpfen

## a) Bandbreite richtig wählen

Faustregel:

[
BW_{Oszi} \ge 3…5 \times f_{Signal}
]

oder

[
BW_{Oszi} \ge \frac{0{,}35}{t_r} \times 3…5
]

Zu wenig Bandbreite ⇒

* Flanken sehen zu langsam aus
* Overshoot/Ringing verschwinden scheinbar

---

## b) Bandbreitenlimit **ausschalten**

Viele Oszis haben:

* 20 MHz-Limit
* 250 MHz-Limit

👉 Für SI-Messungen **immer deaktivieren**, sonst falsche Ergebnisse.

---

## c) Abtastrate

Mindestens:

[
5…10 \text{ Samples pro Rise-Time}
]

Praktisch:

* **≥ 10 GSa/s** für Sub-ns-Flanken
* sonst Jitter- und Eye-Fehler

---

## d) Tastkopf-Kalibrierung / Deskew

Sehr wichtig bei:

* Differenzsignalen
* Jitter-Messung
* Eye-Diagramm

Immer:

* Auto-Deskew durchführen
* Kabellängen matchen
* Temperatur beachten

---

## e) Richtige Terminierung

Häufiger Fehler:

* Hochohmig messen obwohl Leitung 50 Ω ist

Folgen:

* Reflexionen
* falsches Overshoot
* Ringing

Darum:

* 50 Ω-Abschluss aktivieren
  **oder**
* aktiven Tastkopf mit hoher Impedanz verwenden

---

# 3. Häufige Praxisfehler

* Passive Tastspitze mit langem Massekabel → misst Antenne statt Signal
* Oszi-Bandbreite zu klein → „Signal sieht gut aus“, ist es aber nicht
* Kein Deskew → falscher Jitter
* Falsche Terminierung → künstliches Ringing

---

# Kurz-Faustregel zum Mitnehmen

* **Rise-Time > 2 ns → passiv ok**
* **0,5 ns – 2 ns → aktiv empfohlen**
* **< 0,5 ns → aktiv zwingend + differenziell + 50 Ω-Messung**

---

Super – hier ist eine **praxisorientierte Signalintegritäts-Checkliste** speziell für **DDR- und LVDS-Messungen auf Baugruppenebene**.
Ich habe sie so aufgebaut, wie man sie im Labor wirklich abarbeitet.

---

# 1. Vorbereitung vor dem Messen

## Layout & Testzugang prüfen

* Messpunkte möglichst **direkt am Empfänger-Pin**
* **Keine langen Stubs** zu Testpads (> 2–3 mm vermeiden)
* Referenz-GND neben dem Messpunkt vorhanden
* Differenzpaare:

  * gleiche Länge
  * konstanter Abstand
  * keine Ebenenwechsel ohne GND-Via daneben

## Dokumente bereitlegen

* Timing-Budget der Schnittstelle
* zulässiger **Jitter, Overshoot, Eye-Mask**
* Soll-Impedanzen (z. B. 50 Ω / 100 Ω diff.)

Ohne diese Werte ist eine SI-Messung kaum bewertbar.

---

# 2. Richtiger Messaufbau

## Tastkopf wählen

### DDR

* Rise-Time typ. < 500 ps →
  **aktiver Single-Ended- oder differenzieller Tastkopf**
* Eingangskapazität ≤ 1 pF
* Sehr kurze Masse (< 1 mm)

### LVDS

* Immer **differenzieller aktiver Tastkopf**
  oder **direkter 50-Ω-Koaxanschluss**
* Keine passive 10:1-Messung → verfälscht Amplitude & Jitter

---

## Oszilloskop einstellen

### Bandbreite

* Mindestens **4–5× höher** als aus Rise-Time berechnet
* Typisch:

  * LVDS: ≥ 1 GHz
  * DDR3/4: 4–8 GHz

### Abtastrate

* ≥ 10 Samples pro Flanke
* Praxis:

  * 20 GSa/s ist ein guter Startwert für DDR

### Bandbreitenlimit

* **Alle Limits deaktivieren** (20 MHz / 250 MHz etc.)

### Terminierung

* Bei Koax-Messung: **50 Ω aktivieren**
* Bei aktivem Tastkopf: interne hohe Impedanz verwenden

### Deskew & Kalibrierung

* Differenz-Deskew vor jeder Messreihe
* Temperaturstabilisierung abwarten (~10 min)

---

# 3. Messreihen – Schritt für Schritt

## Schritt 1 – Versorgung prüfen

* Ripple auf VDD/VDDQ messen
* Ziel: **keine Resonanzen im 10–500 MHz-Bereich**
* Schlechte PDN → direkt mehr Jitter

---

## Schritt 2 – TDR / Impedanz

* Leiterbahnimpedanz kontrollieren
* Via-Diskontinuitäten erkennen
* Terminierung überprüfen

Abweichung > ±10 % → hohes Reflexionsrisiko.

---

## Schritt 3 – Zeitbereichssignal

### Messen von:

* Rise/Fall-Time
* Overshoot / Undershoot
* Ringing
* Amplitude (besonders kritisch bei LVDS)

Vergleich mit Datenblatt-Grenzen.

---

## Schritt 4 – Jitteranalyse

* Random vs. Deterministic Jitter trennen
* Messung über **viele Tausend Flanken**
* Trigger sauber auf Referenz-Clock

---

## Schritt 5 – Eye-Diagramm (entscheidend)

### DDR

* Eye-Höhe & Eye-Breite gegen Timing-Budget prüfen
* DQS-zu-DQ-Alignment kontrollieren

### LVDS

* Differenzielles Eye:

  * Mindest-Eye-Öffnung
  * Symmetrie
  * Common-Mode-Störungen

Wenn Eye-Maske verletzt → Layout- oder Terminierungsproblem.

---

## Schritt 6 – Crosstalk-Worst-Case

* Nachbarleitungen mit **aggressivem Pattern** toggeln
* Eye erneut messen
* Besonders wichtig bei:

  * Byte-Lanes (DDR)
  * eng gerouteten LVDS-Bussen

---

# 4. Typische Fehlerbilder

## DDR

* Zu kleine Eye-Breite → Timing-Problem / Jitter
* Starkes Ringing → falsche ODT / Impedanzsprung
* Byte-Lane-Unterschiede → Längen-Mismatch

## LVDS

* Zu geringe Amplitude → falsche Terminierung
* Eye asymmetrisch → Skew im Differenzpaar
* Common-Mode-Rauschen → PDN- oder GND-Problem

---

# 5. Abschluss & Bewertung

Am Ende immer:

* Messergebnisse **gegen Standard-Grenzen** prüfen
* **Margin berechnen** (nicht nur „funktioniert“)
* Messaufbau dokumentieren:

  * Tastkopf
  * Bandbreite
  * Terminierung
  * Position auf der Leiterplatte

Nur so sind Ergebnisse reproduzierbar.

---

Wenn du möchtest, kann ich dir als Nächstes eine **kompakte 1-seitige Labor-Checkliste zum Ausdrucken** oder eine **Fehlersuch-Matrix (Symptom → Ursache → Fix)** erstellen.
