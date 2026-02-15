Eine **kompakte Labor-Checkliste für SI-Messungen**
(geeignet für **DDR, PCIe, schnelle ADC/LVDS**).


---

# SI-Labor-Checkliste (Platinen-/Baugruppenebene)

## 1. Vorbereitung

### Dokumente

* Interface-Spec / Datenblatt bereit
* Grenzwerte bekannt:

  * Eye-Height / Eye-Width
  * Jitter-Limit
  * Pegel & Terminierung
  * Impedanz-Sollwert

### Messmittel

* Oszi-Bandbreite ≥ **5× Flankenfrequenz**
* Richtiger Tastkopf:

  * aktiv / differentiell **oder**
  * 50-Ω-Koax-Messpunkt
* **Deskew & Kalibrierung durchgeführt**
* Messung **am Empfänger-Pin**

---

## 2. Versorgung zuerst prüfen (immer!)

* Ripple auf relevanten Rails messen
* Keine starken Resonanzen im **10–500 MHz-Bereich**
* Saubere Referenz für:

  * DDR-VDDQ
  * PCIe-PLL
  * ADC-Clock

➡ Schlechte Versorgung ⇒ Eye-Closing & Jitter.

---

## 3. Impedanz & Kanal

### TDR / Struktur

* Single-ended ≈ Sollwert ±10 %
* Differenziell ≈ Sollwert ±10 %
* **Keine großen Diskontinuitäten**:

  * Via-Stubs
  * Stecker
  * Layerwechsel ohne GND-Via

### Terminierung

* DDR-ODT korrekt
* LVDS/ADC **100 Ω am Empfänger**
* 50-Ω-Messpfad korrekt abgeschlossen

---

## 4. Zeitbereich-Signalform

Am **Empfänger** messen:

* Rise/Fall-Time plausibel
* Overshoot/Undershoot innerhalb Spec
* **Ringing < ½ UI**
* Logische Pegel sicher erreicht

Wenn nicht:
→ meist Terminierung / Rückstrompfad / Leitungslänge.

---

## 5. Jitter-Messung

* ≥ **10⁵ Ereignisse** aufnehmen
* Random vs. Deterministic Jitter trennen
* Referenz-Trigger stabil

Grenzwert:

* Total-Jitter < erlaubtes Timing-Budget.

---

## 6. Eye-Diagramm (entscheidend)

Population:

* sinnvoll ab **10⁵ Bits**
* robust ab **10⁶ Bits**

Prüfen:

* Eye-Height ≥ Spec
* Eye-Width ≥ Spec
* **Mask-Test ohne Treffer**
* Symmetrie / Crossing-Point korrekt
* Kein sporadisches Eye-Closing

---

## 7. Interface-spezifische Kurzchecks

### DDR

* DQS-zu-DQ-Alignment
* Byte-Lane-Skew
* ODT-Konfiguration

### PCIe

* Differenz-Impedanz & Kanalverlust
* Tx-Equalization plausibel
* Lane-Skew / SSC-Einfluss

### Schneller ADC / LVDS

* Differenz-Amplitude korrekt
* 100-Ω-Terminierung vorhanden
* Clock-Jitter klein genug

---

## 8. Typische Fehler → Schnell-Diagnose

| Symptom                   | Häufige Ursache                        |
| ------------------------- | -------------------------------------- |
| Starkes Ringing           | fehlende Terminierung / Impedanzsprung |
| Zu kleines Eye            | Jitter, Kanalverlust, Versorgung       |
| Asymmetrisches Eye        | Skew im Differenzpaar                  |
| Wandernder Crossing-Point | Clock-Jitter / CM-Noise                |
| Sporadische Bitfehler     | seltene Störer, zu kleine Statistik    |

---

## 9. Abschluss-Kriterium „SI bestanden“

✔ Impedanz im Toleranzband
✔ Signalform innerhalb Spec
✔ Jitter-Budget eingehalten
✔ Eye-Mask bestanden
✔ Stabil über Temperatur & Spannung

➡ Erst dann gilt das Interface **signalintegriäts-seitig als robust**.

---

Wenn du möchtest, kann ich dir als Nächstes noch erstellen:

* **Fehler-Diagnose-Flowchart (grafisch)**
* **konkretes Beispiel: DDR4-Eye-Messung Schritt für Schritt am Oszi**
* **Layout-Review-Checkliste vor dem ersten Prototyp**

Das sind in der Praxis die drei Dinge, die am meisten Zeit sparen.
