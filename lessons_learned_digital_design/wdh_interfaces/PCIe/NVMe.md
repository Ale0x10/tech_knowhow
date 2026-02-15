NVMe - Non-Volatile-Memory

NVMe ist ein ein herstellerunabhängiges Protokoll zur Anbindung von Massenspeichern mit PCIe.
NVMe regelt die Kommunikation zwischen dem Betriebssystem und dem Speichermedium. Mit diesem Protokoll lassen sich sämtliche NVMe-Geräte ähnlich wie USB über einen einheitlichen Treiber ansprechen, der in den Betriebssystemen enthalten ist.

Ursprünglich hatte AHCI diese Aufgaben, ein Protokoll zwischen dem Host-Controller auf dem Mainboard und einer Festplatte. Doch der Zugriff auf einen Flash-Speicher funktioniert anders, als bei einer herkömmlichen Festplatten. Während bei Festplatten eine gewisse Zeit zum Positionieren des Schreib-Lese-Kopfes und dem Drehen der Platte vergeht, ist die Verzögerung beim Zugriff auf den Flash-Speicher geringfügig.
NVMe ist aber nur dann effektiv, wenn sehr viele parallele, konkurrierende Zugriffe erfolgen können.

https://www.elektronik-kompendium.de/sites/com/0904051.htm