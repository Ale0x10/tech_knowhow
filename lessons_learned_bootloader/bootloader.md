##  Bootloader bsp. und vgl. anhand des Mikrocontrollers **stm32f446** (hat unter anderem CAN Controller)

https://www.st.com/en/microcontrollers-microprocessors/stm32f446/documentation.html


## 🔧 Was ist ein **Bootloader**?

Ein **Bootloader** ist ein kleines Stück Software, das beim Einschalten (Power-on) oder Reset eines Mikrocontrollers oder Prozessors **als erstes ausgeführt wird**. Seine Aufgabe ist es, das eigentliche Benutzerprogramm (z. B. ein Betriebssystem oder eine Anwendung) zu laden und zu starten.

### Funktionen eines Bootloaders:

* Initialisierung von Hardwarekomponenten
* Prüfen, von wo gebootet werden soll (Flash, SD-Karte, USB, etc.)
* Laden des Programms ins RAM oder Starten direkt aus dem Speicher
* Sicherheitsfunktionen wie Firmware-Authentifizierung
* Bei Mikrocontrollern oft auch Update-Funktionen (z. B. per UART, USB)

---

## 📥 Bootvorgang bei **FPGAs oder SoCs von SD-Karte**

### FPGA:

Ein **FPGA** muss **bei jedem Start konfiguriert** werden. Das geschieht typischerweise über:

* **Bitstream-Datei** (z. B. `.bit` oder `.bin`)
* Gespeichert auf **SD-Karte**, Flash oder EEPROM
* FPGA liest beim Booten die Datei und lädt sich selbst damit neu (d. h. seine Logikschaltung)

### SoC (z. B. Xilinx Zynq mit ARM):

Diese enthalten meist einen ARM-Prozessor + FPGA- oder Peripherieeinheiten. Hier ist der Ablauf:

1. **Boot-ROM** im Chip führt ersten Bootcode aus.
2. Es wird eine Bootquelle geprüft: SD-Karte, eMMC, NAND, QSPI, etc.
3. Bootloader (z. B. U-Boot) wird geladen
4. Bootloader lädt Linux-Kernel oder anderes System (Second-stage bootloader)

Das Ganze ist **hierarchisch**: ROM → 1st-stage Bootloader → 2nd-stage Bootloader → OS.

---

## 📘 Erklärung des STM32-Dokuments des **STM32-Mikrocontrollers**

Der Text bezieht sich auf STM32-Mikrocontroller und beschreibt, wie deren interner Bootloader aktiviert wird.

### Wichtigste Punkte im Zitat:

#### 🔹 Aktivierung des Bootloaders

> "The bootloader is activated by applying one of the patterns described in Table 2."

→ Es gibt bestimmte **Bootkonfigurationen** (z. B. bestimmte Pegel an Boot-Pins, wie BOOT0/BOOT1), die entscheiden, ob der MCU-integrierte Bootloader gestartet wird.

BOOT0/BOOT1:
Diese Pins bestimmen, ob der Mikrocontroller aus dem Flash-Speicher, RAM oder System Memory (Bootloader) startet.
Nach der Auslieferung wird typischerweise BOOT0 = 0 konfiguriert, sodass der Mikrocontroller direkt aus dem Flash-Speicher bootet.

#### 🔹 Dual Boot (Bank2 Option)

> "... bootloader executes Dual Boot mechanism ..."

→ Einige STM32 unterstützen **Dual Bank Flash**, d. h. es gibt zwei Firmware-Versionen (Bank1 & Bank2), und man kann beim Start **umschalten**, z. B. für Firmware-Updates oder Redundanz.

#### 🔹 Bootloader-Selektion

> "... bootloader selection protocol is executed ..."

→ Je nach Chip-Version wird ein bestimmter **Bootloader-Modus** gewählt. Das entscheidet, **welche Schnittstellen** verfügbar sind (USB, UART, SPI, etc.) und **welche Protokolle** unterstützt werden.

#### 🔹 Readout Protection Level 2

> "... MCU does not boot on system memory ..."

→ Wenn **Readout Protection Level 2** aktiviert ist (höchste Sicherheitsstufe), kann der interne Bootloader **nicht mehr verwendet** (Firmware nicht ausgelesen oder überschrieben werden). Auch externe Tools kommen nicht mehr an den Code ran – ideal für Schutz vor Reverse Engineering. Nur ein paar Info-Befehle wie „Get Version“ bleiben zugänglich.

Nach der Aktivierung von Sicherheitsmechanismen wie Readout Protection Level 2 kann die Firmware nicht mehr ausgelesen oder überschrieben werden, aber sie **bleibt ausführbar**.

- **Proprietäre Firmware**:
  - Die meisten kommerziellen Produkte verwenden **proprietäre Firmware**, die nicht öffentlich zugänglich ist.
  - Selbst wenn die Firmware ausgelesen werden kann, bleibt sie urheberrechtlich geschützt und darf nicht ohne Erlaubnis verwendet oder modifiziert werden.

- **Open Source**:
  Wenn die Firmware unter einer Open-Source-Lizenz veröffentlicht wird (z. B. MIT, GPL), kann jeder den Quellcode einsehen, ändern und weiterverwenden. Der Entwickler entscheidet, ob die Firmware öffentlich zugänglich gemacht wird.

- **Ohne Readout Protection**:
  - Wenn keine Sicherheitsmechanismen wie Readout Protection aktiviert sind, können externe Tools wie **ST-Link** oder **JTAG** verwendet werden, um die Firmware auszulesen oder aktualisieren.
  - Dies macht die Firmware jedoch nicht automatisch Open Source. Sie bleibt urheberrechtlich geschützt, und das Auslesen ohne Erlaubnis könnte rechtlich problematisch sein.

---

## 🔄 Vergleich: STM32 Bootloader vs. FPGA/SoC-SD-Karten-Boot

| Aspekt                   | STM32 Bootloader                         | FPGA SD-Karten Boot                      | SoC SD-Karten Boot                             |
| ------------------------ | ---------------------------------------- | ---------------------------------------- | ---------------------------------------------- |
| Wo liegt der Bootloader? | Im internen ROM                          | Nicht vorhanden (reines Bitstream-Laden) | In ROM oder als 1st-Stage Bootloader           |
| Aktivierung              | Über BOOT-Pins oder Software-Jump        | Immer bei Power-on                       | Über Boot-Pins oder eFuses                     |
| Bootmedium               | UART, USB, SPI, CAN, etc.                | SD-Karte, SPI-Flash                      | SD-Karte, QSPI, NAND, eMMC                     |
| Sicherheitsebenen        | Readout Protection (Level 0–2)           | Kaum, außer externe Verschlüsselung      | Secure Boot, Verschlüsselung, Signaturen       |
| Flexibilität             | Eingeschränkt (nur bestimmte Protokolle) | Sehr niedrig – nur Konfigurationsdaten   | Sehr hoch – volles Linux möglich               |
| Updatefähig              | Ja, per Bootloader                       | Nur durch externes Flashen               | Ja, via SD/Net/USB durch Bootloader wie U-Boot |

---

## Fazit

* **STM32 Bootloader** ist ein einfacher, im ROM liegender Mechanismus zur Kommunikation und Firmware-Programmierung, mit beschränkter Funktion und optionalem Schutz.
* **FPGAs** laden eine reine Konfiguration (kein Code!) von SD oder Flash – sie haben **keinen Bootloader im klassischen Sinn**.
* **SoCs** mit ARM und SD-Boot verwenden **komplexere, mehrstufige Bootloader**, oft mit echten Betriebssystemen und Sicherheitsfeatures.


---

### **Offizielle Dokumentationen**
- **STM32 Bootloader**:
  - [STM32 Application Note AN2606](https://www.st.com/resource/en/application_note/an2606-stm32-microcontroller-system-memory-boot-mode-stmicroelectronics.pdf)
    - Diese Application Note beschreibt die Bootloader-Funktionalität und unterstützten Schnittstellen für STM32-Mikrocontroller.
  - [STM32 Reference Manual](https://www.st.com/en/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus.html)
    - Enthält detaillierte Informationen zu BOOT-Pins, Flash-Speicher und Sicherheitsmechanismen.

- **FPGA Bootvorgang**:
  - [Xilinx FPGA Configuration Guide](https://www.xilinx.com/support/documentation/user_guides/ug570-ultrascale-configuration.pdf)
    - Beschreibt den Bootvorgang und die Konfiguration von Xilinx FPGAs.
  - [Intel FPGA Configuration Handbook](https://www.intel.com/content/www/us/en/docs/programmable/683472/current.html)
    - Detaillierte Informationen zur Konfiguration von Intel FPGAs.

- **SoC Bootloader**:
  - [Xilinx Zynq-7000 Boot Guide](https://www.xilinx.com/support/documentation/user_guides/ug585-Zynq-7000-TRM.pdf)
    - Beschreibt den mehrstufigen Bootprozess von Zynq-SoCs.
  - [U-Boot Documentation](https://u-boot.readthedocs.io/)
    - U-Boot ist ein weit verbreiteter Bootloader für SoCs und bietet viele Funktionen wie Secure Boot und Firmware-Updates.

---

### ** Technische Artikel und Tutorials**
- **Bootloader allgemein**:
  - [Was ist ein Bootloader?](https://www.electronics-tutorials.ws/embedded/bootloader.html)
    - Ein einfaches Tutorial, das die Grundlagen eines Bootloaders erklärt.
  - [STM32 Bootloader Tutorial](https://controllerstech.com/stm32-bootloader/)
    - Praktische Anleitung zur Verwendung des STM32-Bootloaders.

- **FPGA und SoC Bootvorgang**:
  - [FPGA Configuration Basics](https://www.fpga4fun.com/FPGA_Config.html)
    - Einführung in die Konfiguration von FPGAs.
  - [SoC Bootloader Explained](https://www.embedded.com/bootloaders-explained/)
    - Artikel über die Funktionsweise von Bootloadern in SoCs.

---

### **Bücher**
- **Embedded Systems**:
  - "Embedded Systems: Introduction to ARM Cortex-M Microcontrollers" von Jonathan W. Valvano.
    - Enthält eine Einführung in Bootloader und Mikrocontroller-Programmierung.
- **FPGA Design**:
  - "FPGA Prototyping by Verilog Examples" von Pong P. Chu.
    - Beschreibt die Konfiguration und den Bootvorgang von FPGAs.
- **SoC Design**:
  - "Designing Embedded Systems and the Internet of Things (IoT) with the ARM Cortex-M Microcontroller" von Perry Xiao.
    - Behandelt Bootloader und SoC-Design.

---

### **Community und Open-Source**
- **STM32 Community**:
  - [STM32 Forum](https://community.st.com/s/)
    - Diskussionsforum für STM32-Entwickler.
- **FPGA Community**:
  - [Xilinx Community](https://forums.xilinx.com/)
    - Forum für Fragen zu Xilinx FPGAs.
- **U-Boot GitHub Repository**:
  - [U-Boot Source Code](https://github.com/u-boot/u-boot)
    - Open-Source-Code für den U-Boot-Bootloader.

---
