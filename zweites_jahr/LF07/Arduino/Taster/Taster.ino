/*
  Tasterbetrieb
  
    Hierbei soll eine LED in einer gewählten Betriebsart
    
    mit Hilfe eines Tasters gesteuert werden.
    
  Die Schaltungen

    1.
    
    Tastschalter (generisch) an 5V

    auf der Ausgangsseite des Tasters:

    - 10 kOhm Pulldown-Widerstand zu GND (Masse);

    parallel dazu:

    - Verbindung zu Pin 7

    
    2.
    
    Die Eingebaute LED oder eine in Reihe geschaltet von Pin 13 hin zu GND (Masse):
    
    - Vorwiderstand (160 Ohm) 
    
    - Rote LED (1,8 V)
    
  erstellt am 8 Nov 2022
  von Spiridon Fotiadis
*/

// Konstanten
const int tasterPin = 7;            // der Pin des Tasters
const int ledPin =  13;    // der Pin der LED

// Variable Zustände:
// Komponenten
int tasterStatus = LOW;         // gelesener Tasterstatus
int alterTasterStatus = LOW;    // gespeicherter Tasterstatus
int ledStatus = LOW;            // Zustand der LED 

// Zeiten
int startZeit = 0;        // Zeit seit Start des Arduinos, in der der Tastert gedrückt wurde
int vergangeneZeit = 0;   // vergangene Zeit

void tippBetrieb() {
  // wenn der Taster gedrückt wird LED ein, sonst aus
  if (tasterStatus == HIGH) {
    digitalWrite(ledPin, HIGH); //LED einschalten
  } else {
    digitalWrite(ledPin, LOW); //LED ausschalten
  }
}

void toggleBetrieb() {
  // wenn der Taster gedrückt wird
  if (tasterStatus == HIGH) {
    ledStatus = !ledStatus;          //LED Status invertieren 
    digitalWrite(ledPin, ledStatus); //LED Pin auf Status setzen
    
    while(tasterStatus == HIGH) {
      delay(20);
      tasterStatus = digitalRead(tasterPin);
    }
  }
  delay(50);
}

void checkBetrieb() {
  // Sobald sich der Tasterstatus verändert
  if (tasterStatus != alterTasterStatus) {
    if(tasterStatus == HIGH) {
      startZeit = millis();  // bei HIGH wird die Zeit neu gesetzt
    } else {
      // bei LOW wird die vergangene Zeit überprüft
      if(vergangeneZeit >= 1000 && vergangeneZeit <= 2000){
        // zwischen 1 und 2 Sekunden LED einschalten
        digitalWrite(ledPin, HIGH);
      }
      if(vergangeneZeit >= 4000 && vergangeneZeit <= 5000) {
        // zwischen 4 und 5 Sekunden LED ausschalten
        digitalWrite(ledPin, LOW);
      }

      // Zeiten zurücksetzen
      startZeit = 0;
      vergangeneZeit = 0;
    }

    // Status speichern
    alterTasterStatus = tasterStatus;
    
  } else {
    // wenn der Tasterstatus gleich bleibt
    if(tasterStatus == HIGH){
      // Solang der Taster gedrückt ist, wird die vergangene Zeit aktualisiert
      vergangeneZeit = millis() - startZeit;
    }
  }
}

void checkBetrieb2() {
  // wenn der Taster gedrückt wird
  if (tasterStatus == HIGH) {
    // Startzeit festhalten
    int start = millis(); 

    // solange der Taster gedrückt bleibt, bleibt das Programm hier stehen
    while(digitalRead(tasterPin) == HIGH) delay(10); 
    
    // nachdem der Taster losgelassen wird, wird die Zeit aus 
    // der aktuellen Zeit minus der Startzeit ermittelt
    int ende = millis() - start;

    if(ende >= 1000 && ende <= 2000){
      // zwischen 1 und 2 Sekunden LED einschalten
      digitalWrite(ledPin, HIGH);
    }
    if(ende >= 4000 && ende <= 5000) {
      // zwischen 4 und 5 Sekunden LED ausschalten
      digitalWrite(ledPin, LOW);
    }
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);    // Pin als Ausgang für LED setzen
  pinMode(tasterPin, INPUT);  // Pin als Eingang für Taster setzen
}

void loop() {
  // Zustand des Tasters ermitteln
  tasterStatus = digitalRead(tasterPin);
  checkBetrieb();
}
