
### Example to CoC:
class Config {
public:
    std::string path = "default.cfg"; // Konvention

    void load() {
        std::ifstream file(path); // Kein Pfad nötig, wenn Konvention genutzt
        // ...
    }
};
//COC – Convention over configuration: config.load()

class App {
public:
    void setup() {
        // Lädt Konfiguration aus "config.json" automatisch
    }

    void run() {
        // Startet mit Standardparametern
    }
};
//COC – Convention over configuration: object.run()

C++ ist traditionell eine Sprache mit viel Kontrolle. Daher wird CoC oft durch:
- Templates mit Defaults
- Namenskonventionen
- Standardverhalten in Konstruktoren
- Frameworks mit automatischer Erkennung
umgesetzt, statt durch explizite „Convention Engines“.


**Convention over Configuration (CoC)** in C++ ist nicht so verbreitet wie in dynamischen Sprachen wie Ruby oder Python, dennoch gibt es durchaus Frameworks und Bibliotheken, die dieses Prinzip unterstützen – oft subtil, durch sinnvolle Defaults und klare Konventionen.

---

## 🧰 C++ Frameworks mit CoC-Ansätzen

Hier sind einige Beispiele:

### 🔹 **Qt Framework**
- Qt verwendet Konventionen für Signal-Slot-Verbindungen, Namensgebung und UI-Strukturen.
- Beispiel: Wenn du eine Methode `on_button_clicked()` definierst, wird sie automatisch mit dem Button-Click-Event verbunden – **ohne explizite Registrierung**.

### 🔹 **CMake + C++ Projektstruktur**
- CMake selbst ist kein C++ Framework, aber viele moderne CMake-Vorlagen nutzen CoC:
  - Standardordner wie `src/`, `include/`, `tests/`
  - Automatische Erkennung von Headern und Quellen
  - Vordefinierte Build-Typen (`Debug`, `Release`)

### 🔹 **Catch2 (für Unit Testing)**
- Catch2 erlaubt Tests ohne explizite Registrierung:
  ```cpp
  TEST_CASE("Factorials are computed", "[factorial]") {
      REQUIRE(factorial(3) == 6);
  }
  ```
  → Kein Setup nötig, Tests werden automatisch erkannt – **CoC pur**.

### 🔹 **Google Test (gTest)**
- Auch hier: Tests folgen Konventionen (`TEST`, `TEST_F`) und werden automatisch ausgeführt.
- Konventionelle Struktur erleichtert Integration in CI/CD.

### 🔹 **Boost Libraries**
- Viele Boost-Komponenten (z. B. `Boost.Program_options`, `Boost.Filesystem`) bieten sinnvolle Defaults und Konventionen.
- Beispiel: `boost::filesystem::temp_directory_path()` liefert automatisch den richtigen Temp-Pfad für das Betriebssystem.

---


Die Prinzipien wie **Convention over Configuration (CoC)** und die **Law of Demeter** wirken in C++ oft nicht als offensichtliche Features, sondern eher als **Designentscheidungen**, die sich in der Struktur, dem Verhalten und der API eines Systems widerspiegeln. Hier sind einige **subtile, aber wirkungsvolle Beispiele**, wie diese Prinzipien in C++ auftauchen:

---

## 🧠 1. **Standardkonstruktoren mit sinnvollen Defaults** *(CoC)*

```cpp
class Logger {
public:
    Logger() : level("INFO"), output("log.txt") {} // Konventionelle Defaults

    void log(const std::string& msg) {
        // schreibt automatisch in "log.txt" mit Level "INFO"
    }

private:
    std::string level;
    std::string output;
};
```

➡️ Der Nutzer muss nichts konfigurieren – die Konventionen sorgen für sinnvolles Verhalten.

---

## 🧠 2. **Automatische Initialisierung durch RAII** *(CoC + Demeter)*

```cpp
class FileHandle {
public:
    FileHandle(const std::string& path) : file(path) {} // Öffnet Datei automatisch
    ~FileHandle() { file.close(); }                     // Schließt automatisch

    std::ifstream& get() { return file; }

private:
    std::ifstream file;
};
```

➡️ Der Nutzer muss sich nicht um `open()` oder `close()` kümmern – das Verhalten folgt Konventionen.  
➡️ Kein `fileManager->getFile()->getStream()->close()` – direkte Verantwortung.

---

## 🧠 3. **Flache Schnittstellen statt tiefer Objektketten** *(Law of Demeter)*

```cpp
class Engine {
public:
    void start() { /* ... */ }
};

class Car {
public:
    void start() {
        engine.start(); // Direkter Zugriff, keine tiefe Kette wie car->engine->start()
    }

private:
    Engine engine;
};
```

➡️ Das Auto startet sich selbst – du musst nicht wissen, wie der Motor funktioniert.

---

## 🧠 4. **Catch2: Automatische Test-Erkennung** *(CoC)*

```cpp
TEST_CASE("Addition works", "[math]") {
    REQUIRE(2 + 2 == 4);
}
```

➡️ Kein `main()` nötig, keine Testregistrierung – Catch2 erkennt alles durch Konvention.

---

## 🧠 5. **Namensbasierte Eventbindung in Qt** *(CoC)*

```cpp
// Methode in einer Qt-Klasse:
void on_button_clicked();
```

➡️ Qt verbindet automatisch das Signal `clicked()` des Buttons mit dieser Methode – **kein explizites Signal-Slot-Mapping nötig**, solange du dich an die Namenskonvention hältst.

---

## 🧠 Fazit

Diese Beispiele zeigen, wie C++-Frameworks und idiomatisches Design **Komplexität reduzieren**, indem sie **Konventionen nutzen** und **tiefe Objektketten vermeiden**. Das macht den Code **lesbarer, wartbarer und robuster**, ohne dass du ständig alles konfigurieren oder durchreichen musst.

---

**konkrete C++-Beispiele** für die vier Mechanismen, durch die **Convention over Configuration (CoC)** in C++ typischerweise umgesetzt wird – subtil, aber effektiv:

---

## 🔧 1. **Templates mit Defaults**

Templates in C++ erlauben es, Verhalten zu parametrisieren – aber durch **Default-Typen oder -Werte** entsteht CoC:

```cpp
template<typename T = int>
class Counter {
public:
    T value = 0;
    void increment() { ++value; }
};
```

➡️ Wenn du `Counter<>` verwendest, bekommst du automatisch einen `int`-Counter – **kein expliziter Typ nötig**, solange du dich an die Konvention hältst.

---

## 🧾 2. **Namenskonventionen**

Frameworks wie Qt oder Test-Frameworks wie Catch2 nutzen Namenskonventionen für automatische Bindung oder Erkennung:

```cpp
// Qt: Methode wird automatisch mit Button-Signal verbunden
void on_submitButton_clicked();
```

➡️ Kein manuelles Signal-Slot-Mapping nötig – **die Konvention reicht aus**, um die Verbindung herzustellen.

Oder bei Catch2:

```cpp
TEST_CASE("Basic math", "[math]") {
    REQUIRE(2 + 2 == 4);
}
```

➡️ Tests werden automatisch erkannt – **kein explizites Registrieren** nötig.

---

## ⚙️ 3. **Standardverhalten in Konstruktoren**

Viele Klassen definieren sinnvolle Defaults direkt im Konstruktor – das ist CoC pur:

```cpp
class Config {
public:
    Config() : path("config.json"), logLevel("INFO") {}

    void load() {
        std::ifstream file(path);
        // ...
    }

private:
    std::string path;
    std::string logLevel;
};
```

➡️ Du musst nichts konfigurieren – die Konventionen sorgen für sinnvolles Verhalten.

---

## 🧠 4. **Frameworks mit automatischer Erkennung**

Frameworks wie **Catch2**, **Google Test**, oder **Qt** erkennen Komponenten automatisch, wenn du dich an Konventionen hältst:

- **Catch2**: Testfälle werden durch Makros erkannt (`TEST_CASE`)
- **Google Test**: `TEST()` und `TEST_F()` registrieren sich selbst
- **Qt**: UI-Elemente und Events werden durch Namensmuster verbunden
- **CMake**: erkennt automatisch Quell- und Headerdateien in `src/` und `include/`

---

## 🎯 Fazit

In C++ entsteht durch **Templates, Konventionen und clevere Frameworks** ein CoC-ähnliches Verhalten, das viel Konfigurationsarbeit abnimmt – **wenn an den Konventionen festgehalten wird**.

Klar! Hier sind einige Quellen, die das Prinzip **Convention over Configuration (CoC)** im Kontext von C++ und verwandten Tools beleuchten:

---

## Quellen: 

### 📚 **1. Wikipedia – Konvention vor Konfiguration**
Die [Wikipedia-Seite zur Konvention vor Konfiguration](https://de.wikipedia.org/wiki/Konvention_vor_Konfiguration) erklärt das Paradigma allgemein und zeigt, wie es die Komplexität von Konfigurationsdateien reduziert – etwa durch Namenskonventionen oder automatische Zuordnungen.

---

### 🛠️ **2. Stack Overflow – CMake und CoC**
In [dieser Diskussion auf Stack Overflow](https://stackoverflow.com/questions/7826239/does-cmake-use-convention-over-configuration) wird CMake als Beispiel für ein Build-System genannt, das teilweise CoC nutzt – etwa durch die Empfehlung von „Out-of-source builds“ und standardisierte Projektstrukturen.

---

### 🧪 **3. GitHub – CoC in Frameworks**
Das [GitHub-Projekt „sofmon/convention“](https://github.com/sofmon/convention) beschreibt CoC als Prinzip zur Reduktion von Boilerplate-Code, Förderung von Konsistenz und Vereinfachung der Wartung – auch wenn es sich nicht direkt auf C++ bezieht, sind die Konzepte übertragbar.

---
