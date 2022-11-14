/*
 * SerialButton
 * 
 * Demonstriert die Serial Funktionalität
 * 
 *  - zählt die Anzahl der Tastendrucke und gibt diese aus
 * 
 * 
 * Die Schaltung
 * 
 *  - Tastschalter (generisch) an 5V
 *   
 *  auf der Ausgangsseite des Tasters:
 *   
 *  - 10 kOhm Pulldown-Widerstand zu GND (Masse);
 *   
 *  parallel zum Widerstand:
 *   
 *  - Verbindung zu Pin 7
 *  
 *************************************************************************  
 *************************************************************************
 *   
 * Serial (allgemein)
 * 
 *  ermöglicht die Kommunikation zwischen dem Arduino 
 *  
 *  und dem Computer oder einem anderen Gerät.
 *  
 *  Für die Serielle Kommunikation über USB, werden die 
 *  
 *  Pins 0 als RX (Receive) und 1 als TX (Transmit) verwendet. 
 *  
 *  Manche Boards, wie der Arduino Mega, verfügen über mehrere 
 *  
 *  solcher Schnittstellen (4 Stück).
 *  
 *   
 * Serial Funktionen
 *
 *  .begin()
 *
 *    öffnet den gewählten seriellen Port und setzt die Datenrate(Baud). 
 *    
 *  .print()
 * 
 *    gibt eine Zeichenkette ohne Zeilenumbruch aus.
 *  
 *  .println()
 * 
 *    gibt eine Zeichenkette aus und setzt einen Zeilenumbruch.
 *  
 */


int tasterPin = 7;

int startZeit = millis();  // Ermittle Millisekunden seit Programmstart
int vergangeneZeit = 0;

int tasterStatus = LOW;
int tasterZaehler = 0;

void setup() {
  Serial.begin(9600);

  pinMode(tasterPin, INPUT);
  
}

void countButtonIfPressed() {
  int gelesenerStatus = digitalRead(tasterPin);
  // wenn der Taster gedrückt ist und vorher aus war
  if(gelesenerStatus == HIGH && tasterStatus == LOW) {
    // Zaehler um eins hochzaehlen
    tasterZaehler++;
    
    // Zaehler ausgeben
    Serial.println(tasterZaehler);  

    // Taster Status auf HIGH setzen
    tasterStatus = HIGH;

  } else if(gelesenerStatus == LOW) {
    // wird ausgeführt, wenn der gelesene Status auf LOW ist

    // tasterStatus wird auf LOW gesetzt (reset)
    tasterStatus = LOW;
    
  }
  // um 50 Millisekunden verzögern um sauber zu wechseln
    delay(50);
}

void loop() {
  countButtonIfPressed();
}
