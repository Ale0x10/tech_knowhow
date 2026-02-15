# Smart Pointern in C++

📚 Offizielle Dokumentation & Referenzen

1. **cppreference: `std::unique_ptr`**
   Beschreibung, Memberfunktionen, Eigenschaften etc.
   ([en.cppreference.com][1])

2. **cppreference: `std::shared_ptr`**
   Funktionen, Verhalten bei Referenzzählung etc.
   ([en.cppreference.com][2])

3. **Microsoft Docs: Smart pointers (Modern C++)**
   Überblick über smart pointers, Unique, Shared, Weak, RAII etc.
   ([Microsoft Learn][3])

4. **Boost: Smart Pointers**
   Historie, zusätzliche Varianten, wie `intrusive_ptr` etc.
   ([boost.org][4])

5. **Chromium Smart Pointer Guidelines**
   Richtlinien, wie man smart pointers sicher und idiomatisch nutzt.
   ([chromium.org][5])

---

[1]: https://en.cppreference.com/w/cpp/memory/unique_ptr.html?utm_source=chatgpt.com "std::unique_ptr"
[2]: https://en.cppreference.com/w/cpp/memory/shared_ptr.html?utm_source=chatgpt.com "std::shared_ptr"
[3]: https://learn.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170&utm_source=chatgpt.com "Smart pointers (Modern C++)"
[4]: https://www.boost.org/doc/libs/1_44_0/libs/smart_ptr/smart_ptr.htm?utm_source=chatgpt.com "Smart Pointers"
[5]: https://www.chromium.org/developers/smart-pointer-guidelines/?utm_source=chatgpt.com "Smart Pointer Guidelines"

---

📚  📖 Deutschsprachige Quellen

1. **Intelligente Zeiger (Modern C++) – Microsoft Docs auf Deutsch**
   Der Artikel erklärt `unique_ptr`, `shared_ptr` und `weak_ptr`, wie und wann man sie verwendet, inklusive Beispielcode. ([Microsoft Learn][1])

2. **Smart Pointer: sichere Speicherverwaltung in C++ umsetzen – ComputerWeekly**
   Ein aktueller Überblick über die Verwendung von Smart Pointern, welche Vorteile sie bieten, und was sich mit neueren C++-Versionen geändert hat. ([Computer Weekly][2])

3. **Smart-Pointer – Sven Johannsen**
   Ein etwas älterer, aber gut erklärter Artikel mit Fokus auf RAII und allgemeinem Verständnis, auch mit Codebeispielen. ([sven-johannsen.de][3])

4. **Wikipedia: Intelligenter Zeiger**
   Gibt eine allgemein verständliche Definition, Vor- und Nachteile, verschiedene Typen und Kontext. Nicht so tief wie Docs, aber gut, wenn du einen Überblick möchtest. ([de.wikipedia.org][4])

---

[1]: https://learn.microsoft.com/de-de/cpp/cpp/smart-pointers-modern-cpp?view=msvc-170&utm_source=chatgpt.com "Intelligente Zeiger (Modern C++)"
[2]: https://www.computerweekly.com/de/tipp/Smart-Pointer-sichere-Speicherverwaltung-in-C-umsetzen?utm_source=chatgpt.com "Smart Pointer: sichere Speicherverwaltung in C++ umsetzen"
[3]: https://www.sven-johannsen.de/programmierung/smartpointer.html?utm_source=chatgpt.com "Smart-Pointer - Sven Johannsen -"
[4]: https://de.wikipedia.org/wiki/Intelligenter_Zeiger?utm_source=chatgpt.com "Intelligenter Zeiger"

---

# **Smart Pointer** – ein Kernkonzept in **C++**, aber auch in anderen Sprachen gibt es ähnliche Mechanismen (Rust, Swift, etc.)

---

## 🔹 1. Motivation

In C++ muss man Speicher oft manuell verwalten:

```cpp
int* p = new int(5);
// ... benutzen ...
delete p;
```

👉 Problem: leicht Fehler zu machen → **Memory Leaks**, **Double Deletes**, **Dangling Pointers**.
**Smart Pointer** sind Klassen, die automatisch Ressourcen freigeben (RAII: *Resource Acquisition Is Initialization*).

---

## 🔹 2. Grundidee

Ein Smart Pointer ist ein Objekt, das sich **wie ein Zeiger verhält**, aber zusätzlich Verantwortung übernimmt:

* Speicher automatisch freigeben
* ggf. Referenzzählung durchführen
* Ownership (Besitz) ausdrücken

---

## 🔹 3. Arten von Smart Pointern (C++11 und neuer)

### ✅ `std::unique_ptr`

* Besitzt das Objekt **exklusiv**.
* Wenn der `unique_ptr` zerstört wird, wird das Objekt gelöscht.
* **Nicht kopierbar**, nur verschiebbar (`std::move`).

```cpp
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(42);
    std::cout << *ptr << "\n";

    // Ownership übertragen:
    auto ptr2 = std::move(ptr);
    // ptr ist jetzt leer
}
```

👉 Verwendung: wenn nur **ein Besitzer** existiert.

---

### ✅ `std::shared_ptr`

* Mehrere `shared_ptr`s können dasselbe Objekt besitzen.
* Implementiert **Referenzzählung**.
* Das Objekt wird automatisch gelöscht, wenn der letzte Besitzer zerstört ist.

```cpp
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> a = std::make_shared<int>(100);
    std::shared_ptr<int> b = a; // Referenzzähler +1
    std::cout << *a << " " << *b << "\n"; 
} // Objekt wird am Ende automatisch gelöscht
```

👉 Verwendung: wenn Ownership **geteilt** werden muss.

⚠️ Gefahr: **Zyklische Referenzen** → Speicherleck (siehe `weak_ptr`).

---

### ✅ `std::weak_ptr`

* Kein Besitzer, sondern nur ein **schwacher Verweis** auf ein `shared_ptr`.
* Verhindert Zyklus-Leaks.
* Muss mit `lock()` in ein `shared_ptr` umgewandelt werden, bevor man es benutzt.

```cpp
#include <memory>
#include <iostream>

struct Node {
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev; // verhindert Zyklus
};

int main() {
    auto n1 = std::make_shared<Node>();
    auto n2 = std::make_shared<Node>();

    n1->next = n2;
    n2->prev = n1; // weak_ptr verhindert Leak
}
```

---

## 🔹 4. Vorteile von Smart Pointern

* ✅ Automatische Speicherverwaltung (kein `delete` mehr nötig)
* ✅ Klare Semantik von Ownership
* ✅ Integration mit C++-Standardbibliothek (`make_unique`, `make_shared`)
* ✅ Exception-sicher (kein Leak bei Exceptions)

---

## 🔹 5. Vergleich zu anderen Sprachen

* **Rust**: Ownership ist direkt in die Sprache eingebaut → `Box`, `Rc`, `Arc`, `Weak`.
* **Swift**: ARC (*Automatic Reference Counting*) ähnlich wie `shared_ptr`.
* **Python/Java**: Garbage Collector übernimmt alles (ähnlich wie shared\_ptr, aber ohne explizite Kontrolle).

---

## 🔹 6. Wann welchen Smart Pointer verwenden?

* `unique_ptr`: Standardwahl für dynamische Ressourcen (schnell, klar).
* `shared_ptr`: wenn mehrere Teile des Codes die Ressource nutzen müssen.
* `weak_ptr`: um Referenzzyklen bei `shared_ptr` zu vermeiden.

---

👉 Merksatz:

* **Besitz genau einer Stelle?** → `unique_ptr`
* **Mehrere Besitzer?** → `shared_ptr`
* **Verweis ohne Besitz?** → `weak_ptr`

---

Soll ich dir als nächstes auch ein **praktisches Beispiel mit allen drei Smart Pointern zusammen** schreiben, damit du die Unterschiede direkt im Code siehst?

