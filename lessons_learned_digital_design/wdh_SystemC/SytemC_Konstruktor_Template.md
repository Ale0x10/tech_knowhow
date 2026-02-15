Der **Konstruktor** in SystemC (wie auch in C++) ist eine spezielle Methode, die beim **Erzeugen eines Moduls** automatisch aufgerufen wird. Er dient dazu, das Modul **zu initialisieren** – also z. B.:

- Prozesse zu registrieren (`SC_METHOD`, `SC_THREAD`, etc.)
- Ports und interne Variablen vorzubereiten
- ggf. Parameter zu übergeben

---

## 🧠 Warum ist der Konstruktor wichtig?

Ohne Konstruktor würde dein Modul **keine Prozesse enthalten**, und damit auch **nichts tun**. SystemC braucht diese Registrierung, um zu wissen, **welche Funktionen bei welchen Ereignissen ausgeführt werden sollen**.

---

## 🛠️ Beispiel

```cpp
SC_MODULE(MyModule) {
    sc_in<bool> clk;
    sc_in<int> a, b;
    sc_out<int> result;

    void compute() {
        result.write(a.read() + b.read());
    }

    SC_CTOR(MyModule) {
        SC_METHOD(compute);
        sensitive << a << b;
    }
};
```

🔍 Hier passiert im Konstruktor:
- `SC_METHOD(compute)` registriert die Methode `compute` als Prozess
- `sensitive << a << b` sagt: „Starte `compute`, wenn sich `a` oder `b` ändern“

---

## 🧩 Was passiert ohne Konstruktor?

Wenn du den Konstruktor weglässt oder keine Prozesse registrierst:
- Dein Modul wird zwar erzeugt, aber **führt keine Aktionen aus**
- Die Simulation läuft, aber **es passiert nichts**

---

Wie man in SystemC einen **Konstruktor mit Parametern** verwendet, um ein Modul flexibel zu gestalten – z. B. mit **konfigurierbarer Latenz** oder **Bitbreite**. Das ist nützlich, wenn Module wiederverwendet oder für verschiedene Zielplattformen anpasst werden.

---

## 🧪 Beispiel: Multiplizierer mit konfigurierbarer Latenz

Wir bauen ein Modul, das zwei Zahlen multipliziert – aber die **Latenz**, also die Anzahl der Takte bis zum Ergebnis, wird **beim Erzeugen des Moduls als Parameter übergeben**.

### 🔧 Header-Datei (Multiplier.h)

```cpp
#include <systemc.h>

SC_MODULE(Multiplier) {
    sc_in<bool> clk;
    sc_in<int> a, b;
    sc_out<int> result;

    int latency; // Konfigurierbare Latenz

    void compute() {
        while (true) {
            wait(); // Warten auf Takt
            int op_a = a.read();
            int op_b = b.read();

            for (int i = 0; i < latency; ++i)
                wait(); // Simuliere Rechenzeit

            result.write(op_a * op_b);
        }
    }

    // Konstruktor mit Parameter
    Multiplier(sc_module_name name, int latency_param)
        : sc_module(name), latency(latency_param)
    {
        SC_THREAD(compute);
        sensitive << clk.pos();
    }
};
```

---

## 🧩 Verwendung im Testbench

```cpp
int sc_main(int argc, char* argv[]) {
    sc_signal<int> sig_a, sig_b, sig_result;
    sc_clock clk("clk", 10, SC_NS);

    // Multiplizierer mit 3 Taktlatenz
    Multiplier mult("mult", 3);

    // Portbindung
    mult.clk(clk);
    mult.a(sig_a);
    mult.b(sig_b);
    mult.result(sig_result);

    // Testcode hier...
    sc_start(100, SC_NS);
    return 0;
}
```

---

## 🔍 Vorteile dieser Konstruktor-Strategie

| Vorteil                        | Bedeutung                                               |
|-------------------------------|----------------------------------------------------------|
| **Flexibilität**              | Du kannst dieselbe Modulklasse mit verschiedenen Latenzen verwenden |
| **Wiederverwendbarkeit**      | Ideal für Bibliotheken oder parametrische Designs        |
| **Klarheit im Design**        | Parameter sind explizit und nicht hartcodiert            |
| **Synthesevorbereitung**      | Du kannst später die Latenz als generisches HDL-Parameter übergeben |

---

Perfekt! Dann zeige ich dir, wie du in **SystemC mit Templates** arbeitest – z. B. um Module mit **variabler Bitbreite**, **Datentypen** oder sogar **konfigurierbarer Funktionalität** zu erstellen. Templates machen dein Design **flexibel**, **wiederverwendbar** und **parametrisierbar**, ähnlich wie generics in VHDL oder Verilog.

---

## 🧪 Beispiel: Multiplizierer mit Template für Bitbreite

```cpp
#include <systemc.h>

template <int WIDTH>
SC_MODULE(MultiplierTemplate) {
    sc_in<sc_uint<WIDTH>> a, b;
    sc_out<sc_uint<2 * WIDTH>> result;

    void compute() {
        result.write(a.read() * b.read());
    }

    SC_CTOR(MultiplierTemplate) {
        SC_METHOD(compute);
        sensitive << a << b;
    }
};
```

🔍 **Was passiert hier?**
- `WIDTH` ist ein Template-Parameter, z. B. 8, 16, 32 Bit.
- Die Eingänge `a` und `b` sind `sc_uint<WIDTH>`.
- Das Ergebnis ist `sc_uint<2 * WIDTH>` – weil Multiplikation die Bitbreite verdoppeln kann.

---

## 🧩 Verwendung im Testbench

```cpp
int sc_main(int argc, char* argv[]) {
    sc_signal<sc_uint<8>> sig_a, sig_b;
    sc_signal<sc_uint<16>> sig_result;

    MultiplierTemplate<8> mult("mult");

    mult.a(sig_a);
    mult.b(sig_b);
    mult.result(sig_result);

    // Testcode hier...
    sc_start(100, SC_NS);
    return 0;
}
```

➡️ Du kannst das Modul später einfach mit `MultiplierTemplate<16>` oder `MultiplierTemplate<32>` instanziieren – ohne den Code zu ändern.

---

## 🧠 Vorteile von Templates in SystemC

| Vorteil                  | Bedeutung                                               |
|--------------------------|----------------------------------------------------------|
| **Flexibilität**         | Ein Modul für viele Bitbreiten oder Datentypen           |
| **Wiederverwendbarkeit** | Ideal für Bibliotheken oder IP-Blöcke                    |
| **Typensicherheit**      | Compiler prüft alles zur Compilezeit                     |
| **Performance**          | Keine Laufzeitkosten – alles wird zur Compilezeit aufgelöst |

---

## 🔧 Erweiterungsidee: Template + Parameter

Du kannst auch **Templates mit Konstruktorparametern kombinieren**, z. B. für Latenz:

```cpp
template <int WIDTH>
SC_MODULE(MultiplierTimed) {
    sc_in<bool> clk;
    sc_in<sc_uint<WIDTH>> a, b;
    sc_out<sc_uint<2 * WIDTH>> result;

    int latency;

    void compute() {
        while (true) {
            wait(); // Takt
            sc_uint<WIDTH> op_a = a.read();
            sc_uint<WIDTH> op_b = b.read();

            for (int i = 0; i < latency; ++i)
                wait(); // Simuliere Rechenzeit

            result.write(op_a * op_b);
        }
    }

    MultiplierTimed(sc_module_name name, int latency_param)
        : sc_module(name), latency(latency_param)
    {
        SC_THREAD(compute);
        sensitive << clk.pos();
    }
};
```

---

Nun ein komplexeres Beispiel – das zeigt, wie mächtig Templates in SystemC sein können, wenn man sie mit Vererbung, mehreren Parametern und modularer Funktionalität kombiniert. Mit einem **parametrisierbaren ALU-Modul**, das verschiedene Operationen (Addition, Subtraktion, Multiplikation, logische Operationen) unterstützt und über Templates konfiguriert.                                                                          

---

## 🧠 Ziel: Template-basierte ALU mit konfigurierbarer Bitbreite & Operationstyp

Wir erstellen eine ALU, die:
- über einen Template-Parameter `WIDTH` die Bitbreite bestimmt,
- über einen Template-Parameter `OPERATION` die Funktion auswählt (z. B. `ADD`, `SUB`, `MUL`, `AND`, `OR`),
- zur Compilezeit entscheidet, welche Operation ausgeführt wird – ohne Laufzeitkosten.

---

## ⚙️ Schritt 1: Operationstypen definieren

```cpp
enum class OperationType {
    ADD,
    SUB,
    MUL,
    AND,
    OR
};
```

---

## 🧪 Schritt 2: Template-Modul für die ALU

```cpp
#include <systemc.h>

template <int WIDTH, OperationType OPERATION>
SC_MODULE(ALU) {
    sc_in<sc_uint<WIDTH>> a, b;
    sc_out<sc_uint<WIDTH>> result;

    void compute() {
        sc_uint<WIDTH> op_a = a.read();
        sc_uint<WIDTH> op_b = b.read();
        sc_uint<WIDTH> res;

        if constexpr (OPERATION == OperationType::ADD) {
            res = op_a + op_b;
        } else if constexpr (OPERATION == OperationType::SUB) {
            res = op_a - op_b;
        } else if constexpr (OPERATION == OperationType::MUL) {
            res = op_a * op_b;
        } else if constexpr (OPERATION == OperationType::AND) {
            res = op_a & op_b;
        } else if constexpr (OPERATION == OperationType::OR) {
            res = op_a | op_b;
        }

        result.write(res);
    }

    SC_CTOR(ALU) {
        SC_METHOD(compute);
        sensitive << a << b;
    }
};
```

🧩 **Besonderheit:** `if constexpr` sorgt dafür, dass nur der relevante Code zur Compilezeit eingebunden wird – keine unnötigen Verzweigungen zur Laufzeit.

---

## 🧪 Schritt 3: Instanziierung im Testbench

```cpp
int sc_main(int argc, char* argv[]) {
    sc_signal<sc_uint<16>> sig_a, sig_b, sig_result;

    ALU<16, OperationType::MUL> alu_mul("alu_mul");
    alu_mul.a(sig_a);
    alu_mul.b(sig_b);
    alu_mul.result(sig_result);

    // Beispielwerte setzen
    sig_a.write(7);
    sig_b.write(3);

    sc_start(1, SC_NS);

    std::cout << "Result: " << sig_result.read() << std::endl;

    return 0;
}
```

---

## 🧠 Erweiterungsideen

Du willst noch mehr Komplexität? Hier sind ein paar Ideen:

| Erweiterungsidee            | Beschreibung                                                                 |
|-----------------------------|------------------------------------------------------------------------------|
| **Pipeline-Tiefe als Parameter** | Template-Parameter für Latenz, z. B. `PIPE_DEPTH`, mit `wait()`-Schleifen simulieren |
| **Datentyp als Template**   | Statt `sc_uint<WIDTH>` → `typename T`, z. B. `sc_int`, `float`, `double`     |
| **Vererbung für Varianten** | Verschiedene ALU-Typen als abgeleitete Klassen mit speziellem Verhalten     |
| **Template-Metaprogramming**| Operationen zur Compilezeit auswählen und optimieren                        |

---

