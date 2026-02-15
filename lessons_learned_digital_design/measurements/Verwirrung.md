

> Der **Rückstrompfad ist realer Strom in der Referenzfläche**,
> aber er wird **vom EM-Feld der Signalleitung bestimmt** –
> nicht einfach vom „nächstgelegenen Masseanschluss“.

---

# 1. Rückstrom ist nicht nur „irgendeine Masseleitung“

Früher (DC-Denken):

* Strom geht **hin über Signal**
* kommt **irgendwie über GND zurück**

Bei schnellen Flanken gilt aber:

> Strom folgt dem **Weg minimaler Impedanz** 
    (Z = R + jX = Wirkwiderstand(Resistanz) + koplexer_Blindwiderstand(Reaktanz) = \[ \underline{Z} = |\underline{Z}| \cdot e^{j\varphi} \])
> (nicht minimaler Widerstand).

Und dieser Weg wird durch das **elektromagnetische Feld** festgelegt.

---

# 2. Was passiert physikalisch bei einer Leiterbahn über GND-Plane?

Eine typische Mikrostreifen- oder Stripline-Struktur bildet:

* einen **geschlossenen Stromkreis**
* mit **Signalstrom oben**
* **Rückstrom direkt darunter in der Massefläche**

Warum genau darunter?

Weil dort:

* das **magnetische Feld minimal** wird
* die **Induktivität klein** ist
* somit die **Impedanz minimal** ist

Das ist klassische Feldtheorie, z. B. beschrieben in
*High-Speed Digital Design* von **Howard Johnson**.

---

# 3. Feldsicht vs. Stromsicht – beides ist richtig

Du fragst sinngemäß:

> Fließt der Strom wirklich dort
> oder ist das nur das „andere Ende des Feldes“?

Antwort:

### Beides gleichzeitig richtig

**Feldsicht:**

* Energie bewegt sich im **EM-Feld zwischen Signal und Referenz**.
* Beschrieben durch den **John Henry Poynting-Vektor**.

**Stromsicht (Leiter):**

* Um die Randbedingungen der Maxwell-Gleichungen zu erfüllen,
  fließt **realer Verschiebungs- und Leitungsstrom** in der Referenzfläche.
* Dieser konzentriert sich **unter der Signalleitung**.

➡️ Also:

* Nicht nur „gedankliches Gegenfeld“
* sondern **physikalisch messbarer Strom**.

---

# 4. Warum das im PCB-Layout so kritisch ist

Wenn der direkte Rückstrompfad **unterbrochen** wird:

z. B. durch

* GND-Split
* Via ohne Referenz-Via
* Layerwechsel ohne Massekopplung

dann muss der Rückstrom:

* **Umweg nehmen**
* Schleifenfläche wird größer
* Induktivität steigt

Folgen:

* Überschwingen / Ringing
* Jitter
* EMV-Abstrahlung

Genau deshalb ist „durchgehende Referenzebene“
die **wichtigste SI-Layoutregel**.

---

# 5. Intuitives Bild zum Mitnehmen

Stell dir Signal + Rückstrom wie einen **sehr flachen Koax** vor:

* obere Leiterbahn = Innenleiter
* GND-Plane darunter = Außenleiter

Solange dieser „Koax“ geschlossen bleibt → gutes Signal.
Wenn du ihn aufschneidest → EM-Probleme.

---

Wenn du möchtest, kann ich dir als Nächstes eine **grafische Feldskizze** machen:

* Mikrostrip mit sauberem Rückstrom
* vs. GND-Split mit gestörter Feldführung

Das macht den Unterschied sofort visuell klar.
