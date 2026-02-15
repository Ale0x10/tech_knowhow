⚠ Typische EMV-Fehlerquellen

🧠 Fehlende EMV-Planung
- EMV wird erst nachträglich berücksichtigt — statt von Anfang an im Designprozess.
- „Wir machen das später mit Ferrit und Alufolie“ ist leider kein belastbares Konzept.

🧵 Kabel- und Verdrahtungsfehler
- Leitungen parallel geführt → erhöht Kopplung und Störanfälligkeit.
- Schirmung nicht 360° angebunden → hohe Impedanz, schlechte Ableitung.
- Schirmanschluss zu weit entfernt vom Gerät → Störströme fließen durch halbe Anlage.

🧰 Gehäusefehler
- Schranktüren nicht mehrfach geerdet → wirken wie Antennen.
- Montageplatten nicht niederimpedant verbunden → Rückströme finden keine saubere Masseführung.

💾 Platinendesign
- Keine durchgehenden Masseflächen → Rückströme streuen, Schleifen entstehen.
- Lange, ungeschirmte Hochfrequenzleitungen → wirken wie Sendeantennen.
- Unsaubere Layerstruktur → Rückstrompfade unterbrochen, große Schleifenflächen.

🔌 Frequenzumrichter & Leistungselektronik
- Falsche Platzierung im Schaltschrank → Störströme koppeln in Netzleitungen.
- Motorleitungen nicht verdrillt oder geschirmt → Gleichtaktstörungen und Streufelder.

---

🛡 Bonus: EMV-Mythen, die man besser vergisst
- „Ein Ferrit löst alles“ → Nope. Nur wenn man die Ursache kennt.
- „EMV ist Magie“ → Nein, es ist Physik mit klaren Regeln.
- „CE-Zeichen heißt EMV-konform“ → Nicht unbedingt. Kombinationen von Geräten können neue Probleme erzeugen.

---


#Mixed-Signal-Platinen:
---

🎛 Mixed-Signal-Platinendesign: Die Feinheiten im Überblick

🔹 1. Trennung von Analog und Digital
- Physikalische Trennung: Platziere analoge und digitale Schaltungsteile räumlich getrennt — idealerweise mit klarer Blockstruktur.
- Signalfluss beachten: Vermeide, dass digitale Signale durch analoge Bereiche geroutet werden.
- Keine Kreuzungen: Digitale Leitungen sollten nicht über analoge Masseflächen geführt werden (Stichwort: Rückstrompfade!).

🔹 2. Masseführung & Erdung
- Einheitliche Massefläche bevorzugt: Moderne Mixed-Signal-ICs kommen oft besser mit einer gemeinsamen Massefläche zurecht.
- Stitching-Vias: Verbinde Masseflächen regelmäßig mit Vias, um Rückströme sauber zu führen.
- Via-Fence: Um kritische analoge Bereiche herum → schützt vor digitalem Übersprechen.

🔹 3. Layer-Stackup
| Layer | Funktion |
|-------|----------|
| 1     | Signale (analog/digital getrennt) |
| 2     | Massefläche (durchgehend) |
| 3     | Power-Plane (analog/digital getrennt) |
| 4     | Hilfssignale / Routing |

- Power & Ground nebeneinander: Erhöht die Interplane-Kapazität → bessere HF-Entkopplung.
- Keine Masseunterbrechungen unter Signalleitungen!

🔹 4. Bauteilplatzierung
- HF-Bauteile (z. B. Quarze, ADCs) möglichst nah an zugehörigen ICs.
- Entkopplungskondensatoren direkt an Versorgungspins → kurze Wege zur Masse.
- Digitale ICs zentral platzieren → bessere Wärmeverteilung und kürzere Leitungen.

🔹 5. Routing-Regeln
- Kurze, direkte Signalwege → weniger Schleifenfläche, weniger EMI.
- Analog zwischen Masseflächen routen (Stripline-Konfiguration).
- Guard-Traces zwischen empfindlichen analogen Leitungen.
- Keine unnötigen Layerwechsel → vermeidet Induktivität durch Vias.

🔹 6. Stromversorgung
- Separate Versorgung für analog/digital, wenn möglich.
- Ferrite & LC-Filter zur Entkopplung zwischen Bereichen.
- Sternförmige Versorgungstopologie → reduziert Rückkopplung.

---