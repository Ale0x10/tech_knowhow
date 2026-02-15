**Thermal Vias** sind spezielle Durchkontaktierungen (Vias) auf einer Leiterplatte, die dazu dienen, **Wärme effizient von einem heißen Bauteil wegzuleiten** – meist von der Oberseite der Platine zur unteren Massefläche oder zu einem Kühlkörper.

---

## 🔥 Was passiert bei einem Thermal Via?

> Ein Bauteil (z. B. Spannungsregler, MOSFET, FPGA) erzeugt Wärme.  
> Die Wärme wird über das **Kupferpad unter dem Bauteil** aufgenommen und durch **mehrere Vias** zur **unteren Kupferlage (z. B. Massefläche)** geleitet, wo sie sich verteilen oder abgeführt werden kann.

---

## 📐 Eigenschaften von Thermal Vias

| Merkmal              | Typischer Wert / Empfehlung                         |
|----------------------|-----------------------------------------------------|
| Durchmesser          | 0.3 mm bis 0.5 mm                                    |
| Abstand zueinander   | 0.5 mm bis 1.0 mm                                    |
| Anzahl               | 4–20 Stück, je nach Leistung und Fläche             |
| Position             | Direkt unter dem Bauteil, in der **Thermal Pad-Zone** |
| Verbindung           | Zur **Massefläche** oder **Kühlfläche**             |
| Füllung              | Optional: **gefüllt oder mit Lot verschlossen**     |

---

## 🛠️ Wo werden Thermal Vias eingesetzt?

- Unter **spannungsführenden Bauteilen** mit hoher Verlustleistung:
  - Spannungsregler (LDO, Buck)
  - MOSFETs
  - FPGAs, CPUs
  - LED-Treiber
- In Kombination mit:
  - **Kühlflächen** (freigelegtes Kupfer)
  - **Kühlkörpern**
  - **Gehäusemasse**

---

## ✅ Vorteile

- **Effiziente Wärmeableitung**
- **Vermeidung von Hotspots**
- **Erhöhung der Lebensdauer** von Bauteilen
- **EMV-Vorteile**, wenn mit Masse verbunden

---














































































## 🧩 Fazit

> **Thermal Vias sind winzige Wärmetunnel**, die helfen, **Hitze von kritischen Bauteilen wegzuleiten** – durch die Platine hindurch zur Massefläche oder Kühlkörper.  
> Sie sind ein **essentielles Element im thermischen Design moderner PCBs**, besonders bei Leistungselektronik und FPGAs.
> Bei kritischen Bauteilen: Thermal Vias nur thermisch, elektrisch entkoppelt (z. B. über isolierte Pads oder RC-Glied)
> Thermal Vias sind thermisch sinnvoll und elektrisch sicher, wenn sie korrekt platziert sind – in der Massefläche, nahe am Bauteil, und nicht zwischen getrennten Massezonen.


