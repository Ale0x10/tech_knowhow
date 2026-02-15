
Wieso statische speicherverwaltung bei Embedded?

Die Antwort hängt stark vom Kontext ab. In der Embedded-Entwicklung wird **statische Speicherzuweisung** oft bevorzugt, aber in anderen Bereichen kann sie auch Nachteile haben. Hier ist eine differenzierte Betrachtung:

---

## 🧠 Vorteile der statischen Zuweisung (z. B. in Embedded-C)

- **Vorhersagbarer Speicherverbrauch**  
  → Du weißt zur Compile-Zeit, wie viel RAM gebraucht wird

- **Keine Fragmentierung**  
  → Kein Heap, keine dynamische Allokation → keine Speicherlöcher

- **Schneller Zugriff**  
  → Stack- und globale Variablen sind schneller als `malloc()`-basierter Heap

- **Sicherheit in Echtzeitsystemen**  
  → Keine Laufzeitüberraschungen durch fehlgeschlagene Allokation

---

## ⚠️ Warum man es *nicht immer* statisch machen sollte

### 🔹 1. **Flexibilität fehlt**
- Du kannst keine Datenstrukturen mit dynamischer Größe erstellen (z. B. Listen, Bäume, Buffers)
- Beispiel: Ein statisches Array `int arr[100];` ist fix – du kannst nicht zur Laufzeit auf 1000 erhöhen

### 🔹 2. **Speicherverschwendung**
- Du musst oft „auf Verdacht“ zu viel reservieren
- → Wenn du nur 10 Elemente brauchst, aber 100 reservierst, ist das ineffizient

### 🔹 3. **Kein dynamisches Verhalten**
- Du kannst keine Objekte zur Laufzeit erzeugen oder löschen
- → In komplexeren Anwendungen (z. B. GUI, Netzwerk-Stacks) ist das hinderlich

### 🔹 4. **Kein polymorphes Verhalten**
- In C++ z. B. kannst du mit `new` dynamisch Objekte erzeugen, die zur Laufzeit ihren Typ ändern

---

## 📌 Fazit

- In **Embedded-Systemen** ist statische Zuweisung oft **Pflicht**, weil Ressourcen knapp und Verhalten vorhersehbar sein muss
- In **Desktop-, Server- oder High-Level-Anwendungen** ist **dynamische Zuweisung** oft unverzichtbar für Flexibilität und Effizienz

---
