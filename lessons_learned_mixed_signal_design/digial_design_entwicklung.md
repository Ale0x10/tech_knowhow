## 📚 ** Ressourcen**

| Quelle | Inhalt | Link |
|-------|--------|------|
| PCBMay | Detaillierte EMV-Designregeln & Praxisbeispiele | [EMI & EMV in PCBs](https://www.pcbmay.com/de/EMI-und-EMV-in-Leiterplatten/) |
| Altium | EMV-Grundlagen & Layout-Tipps mit anschaulichen Beispielen | [Altium EMV-Design](https://resources.altium.com/de/p/design-electromagnetic-compatibility-pcb-let-your-revels-never-end) |
| Würth Elektronik | PDF mit EMV-Design-Tipps, Power Integrity & Filterstrategien | [EMV-Designtipps 2024 (PDF)](https://www.we-online.com/files/pdf1/emv-designtipps-2024_wesel2024.pdf) |

---

## 🧠 ** Kurze zusammenfassende Anleitung für PCB-Design mit EMV-Fokus**

### 🔧 **Design-Tipps für mehrlagige PCBs**
- **Lagenaufbau**: Nutze mindestens 4 Lagen – z. B. Signal / GND / Power / Signal – für bessere EMV und Signalintegrität.
- **GND-Flächen durchgängig halten**: Keine Unterbrechungen in Masseflächen, um Stromschleifen zu vermeiden.
- **Differenzielle Signale eng führen**: Vermeidet Übersprechen und verbessert EMV.
- **Impedanzkontrolliertes Layout**: Besonders wichtig bei Hochfrequenz-Designs (z. B. USB, HDMI, Ethernet).
- **Via-Management**: Vermeide unnötige Vias in kritischen Signalpfaden – sie verursachen Reflexionen und Verluste.

### ⚡ **EMV-Optimierung**
- **Stromversorgung entkoppeln**: Nutze mehrere Keramikkondensatoren unterschiedlicher Werte nahe an ICs.
- **Ferrite & Filter**: Setze gezielt Ferrite und LC-Filter zur Rauschunterdrückung ein.
- **Signalführung über Masseflächen**: Vermeide Signalführung über Lücken in GND – sonst entstehen Antennen.
- **Minimierung von Schleifenflächen**: Besonders bei schnellen Schaltvorgängen wichtig.

### ❌ **Häufige Fehler**
- Masseflächen unterbrechen durch Vias oder Aussparungen.
- Keine Impedanzkontrolle bei Hochgeschwindigkeitssignalen.
- Entkopplungskondensatoren zu weit von ICs entfernt.
- Unzureichende EMV-Simulation oder Messung.
- Zu enge Leiterbahnen bei hohen Strömen → thermische Probleme.

---


