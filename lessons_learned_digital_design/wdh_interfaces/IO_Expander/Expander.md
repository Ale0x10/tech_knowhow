Ein **I/O‑Expander** (Input/Output‑Expander) ist ein kleiner Chip, der einem Mikrocontroller **zusätzliche Ein‑ und Ausgänge** verschafft – sozusagen *mehr Pins über I²C oder SPI*.

Wenn dein Mikrocontroller zu wenige Pins hat oder du viele Taster, LEDs, Relais oder Sensoren anschließen willst, ist ein I/O‑Expander die elegante Lösung.

---

# 🧠 **Was macht ein I/O‑Expander genau?**
Er übersetzt ein digitales Protokoll (meist **I²C** oder **SPI**) in **mehrere zusätzliche GPIO‑Pins**.

Du bekommst also z. B.:
- 8 zusätzliche Pins  
- 16 zusätzliche Pins  
- manchmal sogar 32 Pins  

Diese Pins kannst du wie normale Mikrocontroller‑Pins verwenden:
- als **Eingang** (Taster, Schalter, Sensoren)  
- als **Ausgang** (LEDs, Relais, Treiberstufen)

---

# 🔌 **Wie funktioniert das?**
Der Mikrocontroller spricht über I²C oder SPI mit dem Expander:

```
MCU → I²C/SPI → I/O‑Expander → Pins → LEDs/Taster/etc.
```

Der Expander hat interne Register, die du beschreibst oder ausliest:
- „Pin 3 = HIGH“
- „Pin 7 = Eingang“
- „Lese Pin 5 aus“

Der Expander kümmert sich um die elektrische Umsetzung.

---

# 🧩 **Warum braucht man sowas?**
Weil Mikrocontroller oft **zu wenige Pins** haben.

Beispiele:
- Ein ESP32 hat viele Funktionen, aber nicht viele freie GPIOs  
- Ein Arduino Uno hat nur 14 digitale Pins  
- Ein Display, ein Sensor und ein paar LEDs – und schon sind alle Pins weg

Ein I/O‑Expander löst das Problem über den Bus.

---

# 🔧 **Typische I/O‑Expander‑Chips**
| Chip | Bus | Anzahl Pins | Besonderheiten |
|------|-----|-------------|----------------|
| **PCF8574** | I²C | 8 | sehr verbreitet, billig |
| **MCP23017** | I²C | 16 | Interrupts, sehr flexibel |
| **MCP23S17** | SPI | 16 | schneller als I²C |
| **SX1509** | I²C | 16 | PWM, LED‑Funktionen integriert |

---

# ⭐ **Wichtig: Ein I/O‑Expander ist selbst ein I²C‑Slave**
Er hat:
- eine eigene I²C‑Adresse  
- interne Register  
- eine I²C‑Schnittstelle  

Die angeschlossenen Geräte (LEDs, Taster, Relais) **sprechen kein I²C** – der Expander übernimmt die Arbeit.

---

# 🎯 **Kurz gesagt**
> Ein I/O‑Expander erweitert deinen Mikrocontroller um zusätzliche digitale Ein‑ und Ausgänge, die du über I²C oder SPI steuerst.

---

