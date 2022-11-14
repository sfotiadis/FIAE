# Serial (library)
 
Ermöglicht die Kommunikation zwischen dem Arduino und dem Computer oder einem anderen Gerät.
Für die Serielle Kommunikation über USB, werden die Pins 0 als RX (Receive) und 1 als TX (Transmit) verwendet. 
Manche Boards, wie der Arduino Mega, verfügen über mehrere solcher Schnittstellen (4 Stück).
   
## Serial Funktionen
*.begin()*
    öffnet den gewählten seriellen Port und setzt die Datenrate(Baud). 
   
*.print()* 
    gibt eine Zeichenkette ohne Zeilenumbruch aus.
  
*.println()* 
    gibt eine Zeichenkette aus und setzt einen Zeilenumbruch.