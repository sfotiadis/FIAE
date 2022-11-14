/*
 * SerialTest
 * 
 * Demonstriert die Serial Funktionalität
 * 
 *  - gibt jeden Sekunde den Namen aus
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

// Tasterbezogene Variablen
int tasterPin = 7;        
int tasterStatus = LOW;     
int tasterZaehler = 0;

// Zeitbezogene Variablen
int startZeit = millis();  // Ermittle Millisekunden seit Programmstart
int vergangeneZeit = 0;


void setup() {
  Serial.begin(9600);
  pinMode(tasterPin, INPUT); //weist tasterPin als Input aus
}

void loop() {
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
