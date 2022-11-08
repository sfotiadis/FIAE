/*
 * Serial
 * 
 * Demonstriert die Serial Funktionalität
 * 
 *  - gibt jeden Sekunde den Namen aus
 *  
 *  - zählt die Anzahl der Tastendrucke und gibt diese aus
 * 
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

void serialtest() {
  // Ermittle Millisekunden seit Programmstart und speichere zwischen
  int temp = millis();

  // wenn die Differenz zwischen dem letzten speichern und jetzt mehr als eine Sekunde her ist
  if(temp - startZeit >= 1000){
    // die letzte Zeit speichern
    startZeit = temp;
    // Namen ausgeben
    Serial.println("Name Nachname");
  }
}

void serialbutton() {
  int gelesenerStatus = digitalRead(tasterPin);
  // wenn der Taster gedrückt ist und vorher aus war
  if(gelesenerStatus == HIGH && tasterStatus == LOW) {
    // Zaehler um eins hochzaehlen
    tasterZaehler++;
    
    // Zaehler ausgeben
    Serial.println(tasterZaehler);  

    tasterStatus = HIGH;

  } else if(gelesenerStatus == LOW) {
    tasterStatus = LOW;
  }
  // um 50 Millisekunden verzögern um sauber zu wechseln
    delay(50);
}

void loop() {
  serialtest();
  serialbutton();
}
