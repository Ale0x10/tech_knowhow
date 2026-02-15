Achtung folgender Inhalt der Datei wurde optisch mittels LLM aufbereitet:

## Quellen für nachfolgende Zusammenfassung: 

- https://www.generic.de/blog/dry-vs-kiss-clean-code-prinzipien
- https://t2informatik.de/wissen-kompakt/clean-code/
- https://www.adesso.de/de/news/blog/clean-code-prinzipien-und-die-messbarkeit-durch-metriken.jsp#:~:text=Das%20%E2%80%9EOpen%20Closed%20Principle%20(OCP,Vererbung
- https://www.ionos.de/digitalguide/websites/web-entwicklung/was-ist-clean-code/#:~:text=Code%20so%20einfach%20wie%20m%C3%B6glich,nicht%20auch%20einfacher%20l%C3%B6sen%20k%C3%B6nnen.
- https://clean-code-developer.de/das-wertesystem/
- https://clean-code-developer.de/die-grade/roter-grad/#:~:text=Noch%20wichtiger%20aber%20ist%2C%20dass%20auch%20andere,ob%20tats%C3%A4chlich%20die%20einfachste%20L%C3%B6sung%20verwendet%20wurde.
- https://www.capgemini.com/de-de/insights/blog/clean-code/#:~:text=Tipp%201:%20Clean%20Code%20Principles,Practices%E2%80%9C%20sind%20eine%20gute%20Basis.
- https://www.ratbacher.de/blog/clean-code/#:~:text=Was%20ist%20Clean%20Code?,aber%20die%20oben%20genannten%20Bedingungen.
- https://www.pureconsultant.de/de/softwareentwicklung/clean-code/#:~:text=Lesbarkeit:%20Code%20sollte%20f%C3%BCr%20andere%20Entwickler%20verst%C3%A4ndlich,Zusammenarbeit%20und%20verringert%20die%20Einarbeitungszeit%20neuer%20Teammitglieder.
- https://x-works.at/blog-posts/clean-code#:~:text=entsprechend%20markiert%20werden.-,Klassen,m%C3%B6glichst%20wenig%20Abh%C3%A4ngigkeiten%20zwischen%20Klassen).
- https://www.it-schulungen.com/wir-ueber-uns/wissensblog/was-ist-clean-code-und-welche-tools-und-loesungen-gibt-es-dafuer.html
- https://www.softway.de/blog-lesen/werte-prinzipien-praktiken-ccd




# 🧼 Clean Code Prinzipien

Clean Code Prinzipien zielen darauf ab, Code zu schreiben, der **leicht lesbar**, **verständlich** und **wartbar** ist.  
Sie umfassen Praktiken wie:

- die Einhaltung von Konventionen  
- die Vermeidung unnötiger Komplexität  
- die Verwendung aussagekräftiger Namen  
- die Aufteilung des Codes in kleine, fokussierte Funktionen und Klassen

---

## 🔑 Wichtige Prinzipien und Praktiken

### ✅ KISS – *Keep It Simple, Stupid*
> Code sollte so einfach wie möglich gehalten werden – ohne unnötige Komplexität. (Kein Overengineering – lieber klarer Code als cleverer Code) 

### ✅ DRY – *Don't Repeat Yourself*
> Vermeide Redundanz, indem du Code nicht wiederholst, sondern Funktionen oder Klassen wiederverwendest. (Wiederverwendbare Funktionen, Templates, Makros)

### ✅ SRP – *Single Responsibility Principle*
> Jede Klasse oder Funktion sollte **nur eine spezifische Aufgabe** haben.

### ✅ SOLID Principles
Eine Reihe von Prinzipien für objektorientierte Programmierung:

| Prinzip | Bedeutung | Beispiel in C++ |
|--------|-----------|------------------|
| **S** – Single Responsibility | Eine Klasse sollte nur eine Aufgabe haben | Trennung von `Logger` und `FileWriter` |
| **O** – Open/Closed (OCP) | Offen für Erweiterung, geschlossen für Modifikation | Virtuelle Methoden, Vererbung |
| **L** – Liskov Substitution | Subklassen sollen sich wie ihre Basisklassen verhalten | `Shape* s = new Circle();` sollte funktionieren |
| **I** – Interface Segregation | Keine überladenen Interfaces | Kleine, spezialisierte Interfaces |
| **D** – Dependency Inversion | High-Level-Module sollten nicht von Low-Level-Modulen abhängen | Abstraktion über Interfaces und `std::function` |

Ein Klassiker für objektorientiertes Design:
---
### ✅ Boy Scout Rule
> Lass den Code **immer in einem besseren Zustand zurück**, als du ihn vorgefunden hast.

---

## 📚 Weitere Clean Code Praktiken

### 🔍 Lesbarkeit
- Verwende **aussagekräftige Namen** für Variablen, Funktionen und Klassen  
- Kommentiere sparsam – nur dort, wo komplexe Abläufe erklärt werden müssen

### 📏 Funktionslänge
> Funktionen sollten **kurz und prägnant** sein – idealerweise nicht länger als eine Bildschirmseite ohne Scrollen.

### 📦 Klassenlänge
> Klassen sollten ebenfalls kompakt sein – empfohlen sind **200–500 Zeilen** als Obergrenze.

### 🔁 Wiederverwendbarkeit
> Entwerfe Code so, dass er **leicht wiederverwendet** werden kann – z. B. durch modulare Funktionen oder Klassen.

### 🧪 Testbarkeit
> Schreibe Code, der **leicht zu testen** ist – durch klare Struktur und Modularität.
> Trennung von Logik und I/O, z. B. durch Dependency Injection mit Interfaces oder Funktionszeigern

---

## 🎯 Ziele von Clean Code

- **Verbesserte Lesbarkeit und Verständlichkeit**  
  > Andere Entwickler (und du selbst in der Zukunft) können den Code schnell erfassen und verstehen.

- **Erhöhte Wartbarkeit**  
  > Einfacherer Code ist leichter zu warten, zu ändern und zu erweitern.

- **Reduzierung von Fehlern**  
  > Durch Prinzipien wie DRY und KISS werden Fehlerquellen minimiert.

- **Verbesserte Zusammenarbeit**  
  > Klare Codebasis erleichtert die Teamarbeit.

- **Höhere Codequalität**  
  > Clean Code führt zu **robusterer und zuverlässigerer Software**.

---

## Good to know:

**Spezifische Details zu Clean Code und Kritik:**
 > https://www.youtube.com/watch?v=Sgz2w_-dPjE






## Weitere Prinzipien: 

### 🧠 **More**
- **YAGNI** – *You Ain’t Gonna Need It*: Nur das implementieren, was wirklich gebraucht wird
- **Law of Demeter** – *Talk only to your immediate friends*: Keine tiefen Objektketten wie `a->b->c->doSomething()`
- **COC** – *Convention over configuration*: Standardverhalten durch Konventionen, nicht durch manuelle Einstellungen. Statt `config.setPath("...")` einfach `config.load()` mit Default-Pfad

### 🧱 **Layered Architecture** 
- Trennung in **Presentation**, **Business Logic**, **Data Access**
- In C++ oft über Namespaces, Module, Libraries

### 🧠 **RAII & Resource Management**
- **RAII** – *Resource Acquisition Is Initialization*: Ressourcen (z. B. Speicher, Dateien) werden im Konstruktor erworben und im Destruktor freigegeben
- Zentrale C++-Philosophie für Speicher- und Ressourcenmanagement

### 🧰 **Design Patterns**
- Wiederkehrende Lösungen für typische Probleme:
  - **Factory**, **Strategy**, **Observer**, **Decorator**
  - In C++ oft mit Templates, Vererbung oder Lambdas umgesetzt

---
