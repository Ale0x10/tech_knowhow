### **Warum wird Gold verwendet?**

Gold wird in der Leiterplattenherstellung und bei elektronischen Bauteilen verwendet, insbesondere bei den **Pads** (Kontaktflächen), die für die Verbindung zwischen Bauteilen und der Leiterplatte sorgen. Es wird nicht für die gesamte Leiterplatte verwendet, sondern als **Oberflächenbeschichtung** auf den Kupferpads. Hier sind die Gründe:

---

### **1. Vorteile von Gold als Oberflächenbeschichtung**
1. **Korrosionsschutz**:
   - Gold ist extrem korrosionsbeständig und schützt die darunterliegende Kupferschicht vor Oxidation.
   - Kupfer oxidiert schnell, was die elektrische Leitfähigkeit und die Lötbarkeit beeinträchtigen würde.

2. **Verbesserte Lötbarkeit**:
   - Gold sorgt für eine glatte und gleichmäßige Oberfläche, die das Löten erleichtert.
   - Es verhindert die Bildung von Oxidschichten, die die Lötverbindung stören könnten.

3. **Zuverlässigkeit bei Kontaktflächen**:
   - Gold wird häufig bei **Steckverbindern**, **Kontaktflächen** und **Pads** verwendet, da es eine hohe elektrische Leitfähigkeit und geringe Kontaktwiderstände bietet.

4. **Selbstzentrierung bei WLCSP**:
   - Bei **WLCSP (Wafer Level Chip Scale Package)**-Bauteilen unterstützt die Goldbeschichtung den **Selbstzentrierungseffekt** während des Lötprozesses.

---

### **2. Warum nicht nur Kupfer?**
- **Kupfer** ist das Hauptmaterial für Leiterbahnen und Pads auf Leiterplatten, da es eine hervorragende elektrische Leitfähigkeit bietet.
- Allerdings oxidiert Kupfer schnell, wenn es der Luft ausgesetzt ist, und bildet eine isolierende Schicht (Kupferoxid), die die elektrische Verbindung beeinträchtigt.
- Daher wird Kupfer oft mit einer dünnen Schicht aus **Nickel** und **Gold** beschichtet:
  - **Nickel** dient als Barriere zwischen Kupfer und Gold.
  - **Gold** schützt die Oberfläche und verbessert die Lötbarkeit.
Gold wird als Oberflächenbeschichtung für Pads verwendet, um Korrosion zu verhindern, die Lötbarkeit zu verbessern und die Zuverlässigkeit der elektrischen Verbindung zu erhöhen. Kupfer bleibt das Hauptmaterial für Leiterbahnen, wird jedoch durch Nickel und Gold geschützt.
---

### **3. Warum ist eine zu dicke Goldschicht problematisch?**
- Eine **zu dicke Goldschicht** kann zu **spröden Lötstellen** führen, da Gold mit dem Lot interagiert und **intermetallische Verbindungen** bildet.
- Diese Verbindungen sind mechanisch weniger stabil und können bei Belastung brechen.
- Daher wird empfohlen, die Goldschicht dünn zu halten (typisch **0,05–0,1 μm**).

---

### **4. PCB-Design-Empfehlungen aus dem stm32-Design-Dokument**
Die Empfehlungen für **0,5 mm** und **0,4 mm Ball-Pitch-Pakete** beziehen sich auf die optimale Gestaltung der Pads und der Lötmasken, um die Zuverlässigkeit und elektrische Leistung zu maximieren.

#### **Empfehlungen für 0,5 mm Ball-Pitch-Pakete**:
- **PCB-Pad-Design**:
  - **Non-solder mask defined**: Die Pads sollten nicht durch die Lötmaske definiert werden, sondern durch die Kupferfläche.
  - **Microvias unter den Pads erlaubt**: Microvias können verwendet werden, um die Pads mit unteren Schichten zu verbinden.
- **Pad-Größe**:
  - Maximaler Durchmesser: **300 μm**.
  - Empfohlener Durchmesser: **250 μm**.
- **Lötmaskenöffnung**:
  - Mindestdurchmesser: **340 μm**.

#### **Empfehlungen für 0,4 mm Ball-Pitch-Pakete**:
- **PCB-Pad-Design**:
  - **Non-solder mask defined**: Wie bei 0,5 mm.
  - **Microvias unter den Pads erlaubt**.
- **Pad-Größe**:
  - Maximaler Durchmesser: **260 μm**.
  - Empfohlener Durchmesser: **220 μm**.
- **Lötmaskenöffnung**:
  - Mindestdurchmesser: **300 μm**.

 
Die PCB-Design-Empfehlungen im stm32-Dokument sind darauf ausgelegt, die Zuverlässigkeit und Leistung von WLCSP-Bauteilen zu maximieren, insbesondere durch präzise Pad-Größen und die Verwendung von Microvias.
---

Der **Selbstzentrierungseffekt** ist ein physikalisches Phänomen, das während des **Reflow-Lötprozesses** bei der Montage von elektronischen Bauteilen auf Leiterplatten (PCBs) auftritt. Es sorgt dafür, dass sich Bauteile wie Chips oder Widerstände automatisch korrekt auf den Pads der Leiterplatte ausrichten, selbst wenn sie vor dem Löten leicht verschoben sind. Hier ist eine detaillierte Erklärung:

---

### **Wie funktioniert der Selbstzentrierungseffekt?**
1. **Oberflächenspannung des Lots**:
   - Während des Reflow-Lötens wird das Lot (z. B. Zinn) erhitzt und schmilzt.
   - Das geschmolzene Lot hat eine hohe **Oberflächenspannung**, die dazu führt, dass es sich gleichmäßig auf den Pads verteilt.
   - Diese Oberflächenspannung zieht das Bauteil in die richtige Position, sodass es sich auf den Pads zentriert.

2. **Kapillareffekte**:
   - Das Lot fließt durch Kapillarkräfte zu den Pads und unter die Anschlüsse des Bauteils.
   - Diese Kräfte helfen ebenfalls, das Bauteil korrekt auszurichten.

3. **Mechanische Ausrichtung**:
   - Wenn das Bauteil leicht verschoben ist, zieht das Lot es durch die Kombination aus Oberflächenspannung und Kapillarkräften in die richtige Position.

---

### **Voraussetzungen für den Selbstzentrierungseffekt**
Damit der Selbstzentrierungseffekt funktioniert, müssen bestimmte Bedingungen erfüllt sein:
1. **Richtiges Pad-Design**:
   - Die Pads auf der Leiterplatte müssen korrekt dimensioniert und positioniert sein, um den Effekt zu unterstützen.
   - Beispiel aus deinem Dokument:
     - Für **0,5 mm Ball-Pitch-Pakete**: Pad-Größe Ø = 250–300 μm.
     - Für **0,4 mm Ball-Pitch-Pakete**: Pad-Größe Ø = 220–260 μm.

2. **Lotqualität**:
   - Das Lot muss eine gute Fließfähigkeit und Oberflächenspannung haben.

3. **Bauteilplatzierung**:
   - Das Bauteil darf nicht zu stark verschoben sein, da der Effekt nur kleine Abweichungen korrigieren kann.

4. **Reflow-Prozess**:
   - Der Reflow-Lötprozess muss korrekt durchgeführt werden, mit der richtigen Temperaturkurve und Zeit.

---

### **Vorteile des Selbstzentrierungseffekts**
1. **Fehlerkorrektur**:
   - Kleine Platzierungsfehler bei der Bestückung der Leiterplatte werden automatisch korrigiert.
   - Dies reduziert die Wahrscheinlichkeit von Kurzschlüssen oder offenen Verbindungen.

2. **Höhere Zuverlässigkeit**:
   - Der Effekt sorgt für eine gleichmäßige und zuverlässige Verbindung zwischen Bauteil und Leiterplatte.

3. **Effizienz**:
   - Der Effekt erleichtert die automatisierte Bestückung und Lötung, da keine perfekte Platzierung erforderlich ist.

---

### **Beispiel: WLCSP-Bauteile**
In deinem Dokument wird der Selbstzentrierungseffekt speziell für **WLCSP (Wafer Level Chip Scale Package)**-Bauteile erwähnt. Diese Bauteile haben kleine Kugeln (Balls) aus Lot, die auf den Pads der Leiterplatte sitzen. Der Effekt sorgt dafür, dass sich die Kugeln während des Reflow-Lötens korrekt auf den Pads ausrichten.

---

### **Fazit**
Der **Selbstzentrierungseffekt** ist ein wichtiger Vorteil des Reflow-Lötprozesses, der die korrekte Ausrichtung von Bauteilen auf Leiterplatten unterstützt. Er basiert auf physikalischen Kräften wie Oberflächenspannung und Kapillareffekten und trägt zur Zuverlässigkeit und Effizienz der elektronischen Montage bei.


Hier sind einige **Quellen**, die die Verwendung von Gold als Oberflächenbeschichtung in der Leiterplattenherstellung und bei elektronischen Bauteilen erklären:

---

### **Offizielle Dokumentationen**
- **IPC Standards**:
  - [IPC-4552: Specification for Electroless Nickel/Immersion Gold (ENIG) Plating](https://www.ipc.org/)
    - Dieser Standard beschreibt die Anforderungen und Vorteile von ENIG (Electroless Nickel/Immersion Gold), einer weit verbreiteten Oberflächenbeschichtung für Leiterplatten.

- **STMicroelectronics Application Notes**:
  - [AN2867: PCB Design Guidelines for STM32 Microcontrollers](https://www.st.com/resource/en/application_note/an2867-pcb-design-guidelines-for-stm32-microcontrollers-stmicroelectronics.pdf)
    - Diese Application Note enthält Empfehlungen für PCB-Designs, einschließlich der Verwendung von Goldbeschichtungen für Pads.

---

### **Technische Artikel**
- **Gold in der Leiterplattenherstellung**:
  - [Why Gold is Used in PCB Manufacturing](https://www.pcbonline.com/blog/why-gold-is-used-in-pcb-manufacturing)
    - Ein Artikel, der die Vorteile von Gold als Korrosionsschutz und für die Lötbarkeit erklärt.

- **ENIG vs. andere Oberflächenbeschichtungen**:
  - [ENIG Surface Finish for PCBs](https://www.protoexpress.com/blog/enig-surface-finish-for-pcbs/)
    - Vergleich von ENIG mit anderen Oberflächenbeschichtungen wie HASL (Hot Air Solder Leveling).

---

### **Bücher**
- **Leiterplatten-Design**:
  - "Printed Circuits Handbook" von Clyde F. Coombs Jr.
    - Dieses Buch behandelt die verschiedenen Oberflächenbeschichtungen für Leiterplatten, einschließlich der Verwendung von Gold.

- **Materialwissenschaften**:
  - "Materials for Advanced Packaging" von Daniel Lu und C.P. Wong.
    - Enthält detaillierte Informationen über die Materialeigenschaften von Gold und Nickel in der Elektronik.

---

### **Herstellerinformationen**
- **PCB-Hersteller**:
  - [Eurocircuits: Surface Finishes for PCBs](https://www.eurocircuits.com/)
    - Informationen über die Vorteile von Goldbeschichtungen bei Leiterplatten.
  - [Advanced Circuits: Gold Plating in PCB Manufacturing](https://www.4pcb.com/)
    - Erklärt die Rolle von Gold in der Leiterplattenherstellung.

---

### **Fazit**
Die Verwendung von Gold als Oberflächenbeschichtung für Pads auf Leiterplatten ist gut dokumentiert und wird durch Standards wie **IPC-4552** und technische Artikel unterstützt. Es wird hauptsächlich wegen seiner Korrosionsbeständigkeit, verbesserten Lötbarkeit und Zuverlässigkeit bei Kontaktflächen eingesetzt. Die oben genannten Quellen bieten detaillierte Informationen und technische Hintergründe.