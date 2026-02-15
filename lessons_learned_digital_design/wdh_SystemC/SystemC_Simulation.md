# 🔁 **Thema: Delta-Zyklen in SystemC – Simulation ohne Zeitfortschritt**


1. Delta-Zyklen dienen dazu, parallele Abläufe in Hardware möglichst realitätsnah und deterministisch in einer seriellen Softwareumgebung zu simulieren. Daher ohne das Simulationszeit vergeht.

2. Durch die Verwendung von Delta-Zyklen können mehrere Prozesse, die auf dasselbe Ereignis reagieren, nacheinander abgearbeitet werden, ohne dass sich die Simulationszeit verändert.

3. Die Simulationszeit in SystemC ist eine künstlich geführte, modellierte Zeit und steht in keinem direkten Zusammenhang zur realen Ausführungszeit auf dem Computer.

4. Die Simulationszeit gibt Aufschluss darüber, wie lange ein Vorgang auf einem realen Hardwareziel wie einem FPGA dauern würde – nicht darüber, wie lange die Simulation tatsächlich auf dem PC läuft.

5. Delta-Zyklen ermöglichen eine zeitlich korrekte und konfliktfreie Ausführung paralleler Prozesse, die sich in einer rein seriellen Ausführung gegenseitig beeinflussen könnten.

6. Die reale Ausführungszeit der Simulation hängt von Faktoren wie Compiler, CPU-Leistung und Optimierungen ab, ist aber unabhängig von der modellierten Simulationszeit.

---

## 📚 ** Ressourcen**

Delta-Zyklen sind ein zentrales Konzept in SystemC, um parallele Prozesse deterministisch zu simulieren:

- 📘 [LearnSystemC.com: Delta Cycle Erklärung](https://learnsystemc.com/basic/delta_cycle)  
  Diese Seite erklärt, dass ein Delta-Zyklus aus **Evaluate- und Update-Phasen** besteht und **mehrere Delta-Zyklen bei gleicher Simulationszeit** auftreten können.

- 🧠 [Doulos Tutorial: Primitive Channels und Simulation Kernel](https://www.doulos.com/knowhow/systemc/systemc-tutorial/primitive-channels-and-the-kernel/)  
  Hier wird gezeigt, wie SystemC – ähnlich wie VHDL – **Signaländerungen verzögert verarbeitet**, um **deterministisches Verhalten** sicherzustellen. Delta-Zyklen entstehen, wenn Prozesse auf Ereignisse reagieren, ohne dass die Simulationszeit voranschreitet.

- 💬 [Accellera Forum: Diskussion zu Delta-Zyklen](https://forums.accellera.org/topic/7084-where-are-the-delta-cycles-coming-from/)  
  Eine tiefgehende Diskussion über die Entstehung von Delta-Zyklen während der Initialisierungs- und Evaluierungsphasen. Besonders hilfreich, wenn du verstehen willst, wie der Scheduler in SystemC arbeitet.

---

## ⚙️ **SystemC & Duty Cycles – was steckt dahinter?**

In SystemC geht es nicht direkt um „Duty Cycles“ im klassischen Sinne (also das Verhältnis von Ein- zu Ausschaltzeit bei einem Signal), sondern eher um **delta cycles** und die **zeitliche Modellierung von Ereignissen**. Das ist entscheidend für die Simulationseffizienz.

### 🔄 Was sind Delta Cycles?
- Ein **Delta Cycle** ist ein Simulationsschritt, **bei dem keine reale Zeit vergeht**.
- Er dient dazu, **alle Ereignisse innerhalb eines Zeitpunkts** korrekt und deterministisch abzuarbeiten.
- Beispiel: Wenn mehrere Prozesse auf ein Ereignis reagieren, wird das in mehreren Delta-Zyklen abgearbeitet, **ohne dass die Simulationszeit voranschreitet**.

### 🚀 Warum macht das die Simulation schneller?
- SystemC simuliert **nicht jede Nanosekunde einzeln**, sondern **arbeitet Ereignisse effizient in logischen Schritten ab**.
- Durch diese **event-driven Simulation** kann man **komplexe Hardwaremodelle schneller durchrechnen**, weil unnötige Zeitfortschritte vermieden werden.
- Besonders bei **TLM (Transaction-Level Modeling)** ist das extrem performant, da man auf Signalebene abstrahiert und nur relevante Transaktionen simuliert.

---

## 🧩 Fazit

- **SystemC simuliert schneller**, weil es **zeitlose Delta-Zyklen** nutzt und nur relevante Ereignisse verarbeitet.


---

## 🧠 ** Kurze zusammenfassende Anleitung für PCB-Design mit EMV-Fokus**

Das ist ein super Punkt – und genau hier liegt der Unterschied zwischen **realer Ausführungszeit** (also was dein Computer braucht, um etwas zu berechnen) und der **Simulationszeit**, die in SystemC modelliert wird. Lass uns das auseinandernehmen:

---

## 🕰️ **Reale Zeit vs. Simulationszeit**

- **Reale Zeit**: Das ist die Zeit, die dein Computer tatsächlich braucht, um die Simulation auszuführen – also CPU-Zeit, Speicherzugriffe, Compilerlaufzeit etc.
- **Simulationszeit**: Das ist die **modellierte Zeit innerhalb der Simulation**. Sie repräsentiert die Zeit, die in deinem Hardwaremodell vergeht – z. B. Nanosekunden auf einem Chip.

> In SystemC ist die Simulationszeit **eine abstrakte Größe**, die **nicht direkt mit der realen Ausführungszeit korreliert**.

---

## 🔁 **Delta-Zyklen – das Geheimnis hinter der „stillstehenden“ Zeit**

Ein **Delta-Zyklus** ist ein Simulationsschritt, bei dem **die Simulationszeit nicht voranschreitet**. Warum?

### 📦 Beispiel: Mehrere Prozesse reagieren auf ein Ereignis

Stell dir vor, du hast drei Prozesse:
- `P1` wartet auf ein Ereignis `E`
- `P2` wartet ebenfalls auf `E`
- `P3` löst `E` aus

Wenn `E` ausgelöst wird, passiert Folgendes:

1. **Delta-Zyklus 0**: `E` wird ausgelöst → `P1` und `P2` werden aktiviert.
2. **Delta-Zyklus 1**: `P1` wird ausgeführt → erzeugt vielleicht ein neues Ereignis `E2`.
3. **Delta-Zyklus 2**: `P2` wird ausgeführt → reagiert eventuell auf `E2`.

➡️ **Die Simulationszeit bleibt bei z. B. 10ns**, obwohl mehrere Prozesse nacheinander abgearbeitet werden. Jeder dieser Schritte ist ein **Delta-Zyklus**, also ein „logischer Tick“, **ohne Zeitfortschritt**.

---

## 🧠 Warum ist das wichtig?

- In Hardware passieren viele Dinge **gleichzeitig** (parallel).
- Dein Computer kann aber nur **seriell rechnen**.
- Delta-Zyklen erlauben es, diese Gleichzeitigkeit **deterministisch und korrekt** zu simulieren.
- So wird z. B. verhindert, dass ein Prozess „zu früh“ auf eine Änderung reagiert, die erst im nächsten logischen Schritt gültig ist.

---

## 🧪 Analogie: Theaterprobe

Stell dir vor, du inszenierst ein Theaterstück:
- Die Uhr auf der Bühne zeigt **20:00 Uhr**.
- Du probst Szene für Szene, wer was sagt, wer wohin geht.
- Obwohl du **mehrere Durchläufe machst**, bleibt die Uhr auf der Bühne bei **20:00 Uhr** stehen.

➡️ Genauso funktioniert die Simulation: **mehrere logische Schritte**, aber **keine Zeit vergeht** im Modell.


---

## Beispiel

Ein kleines Beispiel in SystemC, das die Idee von Delta-Zyklen und Simulationszeit vs. reale Ausführungszeit verdeutlicht. Wir simulieren zwei Prozesse, die auf ein Ereignis reagieren – und beobachten, wie die Simulationszeit nicht voranschreitet, obwohl mehrere Schritte passieren.

Siehe extra Datei delta_cycles.cpp zum ausführen.

🧪 Beispiel: Zwei Prozesse reagieren auf ein Ereignis

```cpp
#include <systemc.h>

SC_MODULE(Testbench) {
    sc_event trigger_event;

    void process1() {
        wait(trigger_event);  // wartet auf das Ereignis
        cout << "Process 1 reagiert bei Zeit: " << sc_time_stamp() << endl;
    }

    void process2() {
        wait(trigger_event);  // wartet ebenfalls
        cout << "Process 2 reagiert bei Zeit: " << sc_time_stamp() << endl;
    }

    void starter() {
        cout << "Starter löst Ereignis aus bei Zeit: " << sc_time_stamp() << endl;
        trigger_event.notify();  // löst das Ereignis aus
    }

    SC_CTOR(Testbench) {
        SC_THREAD(process1);
        SC_THREAD(process2);
        SC_THREAD(starter);
    }
};

int sc_main(int argc, char* argv[]) {
    Testbench tb("tb");
    sc_start();  // startet die Simulation
    return 0;
}
```

---

## 🔍 Was passiert hier?

- `starter` löst das Ereignis `trigger_event` aus.
- `process1` und `process2` warten beide auf dieses Ereignis.
- Sobald das Ereignis ausgelöst wird, **werden beide Prozesse aktiviert** – aber **nicht gleichzeitig**, sondern **nacheinander in Delta-Zyklen**.
- Die Ausgabe zeigt, dass **alle Reaktionen bei derselben Simulationszeit** stattfinden, z. B. `0 s`.

---

## 🧠 Warum ist das spannend?

- Obwohl dein Computer **mehrere Schritte ausführt**, bleibt die **Simulationszeit konstant**.
- Das erlaubt eine **deterministische und parallele Modellierung**, wie sie in echter Hardware vorkommt.
- Du kannst also komplexe Interaktionen simulieren, ohne dass du künstlich Zeit „verlierst“.

---

das Beispiel kann erweitert werden – z. B. mit `notify(SC_ZERO_TIME)` oder `notify(10, SC_NS)` – um zu zeigen, wie sich die Simulationszeit gezielt verändern lässt.

---

Die **SystemC-Simulationszeit** ist zwar dazu da, die **zeitliche Struktur** eines Hardwaredesigns abzubilden, aber sie entspricht **nicht exakt** der **realen Ausführungszeit (Latenz) auf dem FPGA**. Hier ist, warum:

---

## 🧠 Was bedeutet „Simulationszeit“?

Die Simulationszeit in SystemC ist eine **modellierte Zeit**, die du selbst steuerst – z. B. durch `wait(10, SC_NS)` oder `wait(clk.posedge_event())`. Sie dient dazu, den **zeitlichen Ablauf von Hardwareprozessen** zu beschreiben.

- Sie ist **nicht abhängig** von der tatsächlichen Rechenzeit auf deinem PC.
- Und sie ist **nicht automatisch identisch** mit der realen Zeit, die ein FPGA für denselben Vorgang brauchen würde.

---

## 🧩 Warum ist die Simulationszeit trotzdem nützlich?

Sie erlaubt dir:
- **Timing-Verhalten zu modellieren**, z. B. Latenzen, Taktzyklen, Synchronisation.
- **Verzögerungen realistisch darzustellen**, z. B. Speicherzugriffe oder FSM-Zustandswechsel.
- **Testbenches zu schreiben**, die auf bestimmte Zeitpunkte reagieren.

Aber:  
➡️ Die Simulationszeit ist **nur so genau wie dein Modell**.  
➡️ Wenn du z. B. eine Multiplikation als `result = a * b;` modellierst, aber auf dem FPGA dafür **3 Takte** nötig wären, musst du das **explizit durch `wait(3)` oder `wait(30, SC_NS)` abbilden**.

---

## 📉 Warum ist sie nicht exakt?

Laut [Springer’s SystemC-Grundlagenkapitel](https://link.springer.com/content/pdf/10.1007/978-0-387-69958-5_5.pdf) gibt es drei Zeitarten in der Simulation:

| Zeittyp             | Bedeutung                                                                 |
|---------------------|----------------------------------------------------------------------------|
| **Wall-clock time** | Wie lange die Simulation auf deinem PC dauert                             |
| **Processor time**  | Wie viel CPU-Zeit tatsächlich für die Simulation verwendet wurde           |
| **Simulated time**  | Die modellierte Zeit im Design – z. B. 10 ns, 100 ns, etc.                 |

➡️ Nur die **Simulated time** ist relevant für das Verhalten auf dem FPGA – aber sie ist **nicht automatisch identisch** mit der tatsächlichen Ausführungszeit auf realer Hardware.

---

## 🧠 Fazit

- ✅ Die Simulationszeit **repräsentiert** die FPGA-Zeit – aber **nur, wenn du sie korrekt modellierst**.
- ❌ Sie ist **nicht automatisch identisch** mit der realen Ausführungszeit auf dem FPGA.
- 🔧 Du musst selbst dafür sorgen, dass dein Modell die **richtige Anzahl an Taktzyklen, Latenzen und Verzögerungen** enthält.


In SystemC müssen **die zeitlichen Abläufe selbst modelliert werden**, und das geschieht typischerweise mit `wait()`-Anweisungen. SystemC ist kein Synthese-Tool, sondern eine **Modellierungs- und Simulationssprache**, also liegt es an dir, das **Timing-Verhalten deiner Hardware** explizit zu beschreiben.

---

## 🛠️ Wie du mit `wait()` arbeitest

Hier sind die häufigsten Varianten:

- **Taktgesteuert**:  
  ```cpp
  wait(clk.posedge_event()); // Warten auf steigende Flanke
  ```

- **Zeitgesteuert**:  
  ```cpp
  wait(10, SC_NS); // Warten für 10 Nanosekunden
  ```

- **Mehrere Takte simulieren**:  
  ```cpp
  for (int i = 0; i < 3; ++i)
      wait(clk.posedge_event()); // z. B. 3 Takte Verzögerung
  ```

---

## 🧩 Beispiel: Multiplizierer mit 3-Takt-Latenz

Angenommen, dein FPGA-Modul braucht **3 Takte**, um eine Multiplikation durchzuführen. Dann könntest du das so modellieren:

```cpp
void multiply_process() {
    while (true) {
        wait(clk.posedge_event()); // Eingabe übernehmen
        int a = input_a.read();
        int b = input_b.read();

        wait(3); // Simuliere 3 Takte Rechenzeit
        output.write(a * b);
    }
}
```

---

## 🧠 Warum das wichtig ist

Wenn das Timing **nicht selbst modelliert wird**, dann:
- sieht das Design in der Simulation **viel schneller aus**, als es in Wirklichkeit ist.
- kannst du **Timingfehler** oder **Race Conditions** übersehen.
- wird die Testbench **nicht realistisch** – z. B. wenn  auf das Ergebnis gewartet wird, das eigentlich noch gar nicht fertig sein dürfte.

---



Tatsächlich ist ein häufig diskutiertes Thema in der Hardwareentwicklung mit SystemC: **Soll man das Timing direkt in SystemC modellieren oder erst später in HDL einbauen?**

---

## 🧠 Idee: Timing erst nach HDL-Konvertierung einbauen

Das klingt erstmal effizient:
- **SystemC ohne Timing** = schnellere Simulation (z. B. „Loosely-Timed“ Modelle)
- **HDL später mit Timing** = realistische Hardwarebeschreibung

Aber: Das hat **Vor- und Nachteile**, die du kennen solltest.

---

## ✅ Vorteile, wenn du Timing später einbaust

- **Schnellere Simulation**: Ohne `wait()`-Aufrufe läuft die SystemC-Simulation deutlich schneller.
- **Einfachere Verifikation**: Du kannst die Funktionalität testen, ohne dich um Taktzyklen zu kümmern.
- **Flexibilität**: Du kannst Timing später je nach Zielplattform (z. B. FPGA vs. ASIC) anpassen.

---

## ⚠️ Nachteile und Risiken

### 1. **Fehlende Realitätsnähe**
Ohne Timing kannst du:
- **Race Conditions** übersehen
- **Datenabhängigkeiten** falsch einschätzen
- **Pipelining-Effekte** ignorieren

➡️ Das führt zu Designs, die **funktional korrekt**, aber **nicht synthesefähig** oder **nicht performant** sind.

---

### 2. **Fehlende Timing-Validierung**
Wenn du Timing erst im HDL einbaust:
- musst du **nachträglich testen**, ob dein Design die gewünschten Taktzyklen einhält.
- kannst du **Timingfehler** erst spät erkennen – was teuer wird.

➡️ Besonders kritisch bei **komplexen FSMs**, **Speicherzugriffen** oder **arithmetischen Einheiten**.

---

### 3. **Verlust von Synchronisationslogik**
SystemC erlaubt dir, **Synchronisation über `wait()` und Events** zu modellieren. Wenn du das weglässt, fehlt dir:
- die Möglichkeit, **realistische Kommunikationspfade** zu simulieren
- die Chance, **Timing Bottlenecks frühzeitig zu erkennen**

---

## 🧩 Empfehlung: Hybrid-Modellierung

Viele Entwickler nutzen einen **zweistufigen Ansatz**:

1. **Loosely-Timed SystemC-Modell** für schnelle funktionale Simulation
2. **Timed SystemC-Modell** mit `wait()`-Aufrufen für realistische Timing-Analyse  
   (z. B. für kritische Module wie Divider, Speichercontroller, Bus-Interfaces)

➡️ So bekommst du **schnelle Tests** UND **realistische Ergebnisse**.

---

Wenn du magst, kann ich dir ein Beispiel zeigen, wie man ein Modul zuerst „loosely-timed“ und dann „accurately-timed“ modelliert – z. B. ein gepipelter Multiplizierer oder ein UART-Modul. Sag einfach, was dich gerade interessiert.



Klar! Ich zeige dir jetzt zwei Varianten eines einfachen Moduls in **SystemC**: einmal **loosely-timed** (ohne echtes Timing) und einmal **accurately-timed** (mit realistischem Taktverhalten). So kannst du direkt vergleichen, wie sich das auf Simulation, Designqualität und spätere Synthese auswirkt.

---

## 🧪 Beispielmodul: Multiplizierer

Wir nehmen ein Modul, das zwei Zahlen multipliziert und das Ergebnis ausgibt. In der Realität würde ein FPGA dafür z. B. **3 Takte** brauchen.

---

### 🟢 **Loosely-Timed Version** (schnelle Simulation, kein echtes Timing)

```cpp
SC_MODULE(MultiplierLooselyTimed) {
    sc_in<int> a, b;
    sc_out<int> result;

    void compute() {
        result.write(a.read() * b.read());
    }

    SC_CTOR(MultiplierLooselyTimed) {
        SC_METHOD(compute);
        sensitive << a << b;
    }
};
```

🔍 **Merkmale:**
- Keine `wait()`-Anweisung → sofortige Berechnung
- Ideal für **funktionale Tests**
- Simulation ist **sehr schnell**
- Aber: **nicht realistisch** für Hardware-Timing

---

### 🔵 **Accurately-Timed Version** (realistische Taktverzögerung)

```cpp
SC_MODULE(MultiplierAccuratelyTimed) {
    sc_in<bool> clk;
    sc_in<int> a, b;
    sc_out<int> result;

    void compute() {
        while (true) {
            wait(); // Warten auf nächsten Takt
            int op_a = a.read();
            int op_b = b.read();

            wait(3); // Simuliere 3 Takte Rechenzeit
            result.write(op_a * op_b);
        }
    }

    SC_CTOR(MultiplierAccuratelyTimed) {
        SC_THREAD(compute);
        sensitive << clk.pos();
    }
};
```

🔍 **Merkmale:**
- Nutzt `wait()` für Taktsteuerung und Latenz
- Simulation ist **langsamer**, aber **realistisch**
- Ideal für **Timinganalyse**, **Pipelining**, **Synthesevorbereitung**

---

## 🧠 Vergleich: Loosely vs. Accurately Timed

| Kriterium              | Loosely-Timed                  | Accurately-Timed                   |
|------------------------|-------------------------------|------------------------------------|
| **Simulationstempo**   | Sehr schnell                   | Langsamer                          |
| **Realismus**          | Gering                         | Hoch                               |
| **Timinganalyse**      | Nicht möglich                  | Möglich                            |
| **Synthesefähigkeit**  | Eingeschränkt                  | Gut vorbereitet                    |
| **Fehlererkennung**    | Funktional                     | Funktional + Timingfehler möglich  |

---

## 🧩 Fazit

- Nutze **Loosely-Timed**, wenn du schnell testen willst, ob dein Algorithmus funktioniert.
- Nutze **Accurately-Timed**, wenn du wissen willst, ob dein Design **realistisch auf einem FPGA läuft** – inkl. Taktverhalten, Latenzen und Ressourcen.

