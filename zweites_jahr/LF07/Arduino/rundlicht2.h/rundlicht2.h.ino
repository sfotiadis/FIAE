/*
  Rundlicht mit zwei LEDs

    Hierbei sollen zwei vorder und Rückseite eines Rundlichts, ähnlich wie bei einem

    Fahrzeug der Müllabfuhr, mit zwei am Arduino 

    angeschlossenen externen LEDs simuliert werden.

  Die Schaltung
    
    LED0
    In Reihe von Pin 12 hin zu GND (Masse):

    - Vorwiderstand (160 Ohm) 

    - Rote LED (1,8 V)
    
    LED1
    In Reihe von Pin 13 hin zu GND (Masse):

    - Vorwiderstand (160 Ohm) 

    - Rote LED (1,8 V)

  erstellt am 18 Okt 2022

  von Spiridon Fotiadis
*/

// Pins für externe LEDs definieren
const int led0 = 12; 
const int led1 = 13;

//Einstellungen fürs Leuchtverhalten
int lang = 500;             //lange Dauer
int schritte = 8;           //wie oft es kurz aufblinkt
int kurz = lang / schritte; //kurze Dauer

//angegebene LED blinkt auf
void blinken(int led, int dauer, int schritte) {
  for (int i = 0; i<= wiederholung; i++) {
    digitalWrite(led, HIGH);   // LED einschalten
    delay(dauer);              // übergebene Dauer warten
    digitalWrite(led, LOW);    // LED ausschalten
    delay(kurz/2);             // die Hälfte von kurz warten
  }
}

//rundleuchten wird mit angegebener LED 1simuliert
void rund_blinken(int led) {
  blinken(led, kurz, schritte); // blinkt kurz
  digitalWrite(led, HIGH);      // LED einschalten
  delay(lang);                  // wartet lang (das Licht ist auf der anderen Seite)
  blinken(led, kurz, schritte); // blinkt kurz
}

void setup() {
  // LED-Pins als output festlegen                
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
}

void loop() {
  //LEDs blinken abwechselnd um Vorder- und Rückseite zu simulieren
  rund_blinken(led0);
  rund_blinken(led1);
}
