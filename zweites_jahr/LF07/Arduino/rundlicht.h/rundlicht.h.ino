/*
  Rundlicht mit einer LED

    Hierbei soll ein Rundlicht, ähnlich wie bei einem
    Fahrzeug der Müllabfuhr, mit einer am Arduino 
    angeschlossenen externen LED simuliert werden.

  Die Schaltung

    In Reihe von Pin 13 hin zu GND (Masse):

    - Vorwiderstand (160 Ohm) 

    - Rote LED (1,8 V)


  erstellt am 18 Okt 2022

  von Spiridon Fotiadis
*/

int led = 13; // Pin für externe LED definieren

//Leuchtdauer festlegen
int lang = 500;
int schritte = 8;
int kurz = lang / schritte;


void blinken(int dauer, int wiederholung) {
  for (int i = 0; i<= wiederholung; i++) {
    digitalWrite(led, HIGH);   // LED einschalten
    delay(dauer);              // übergebene Dauer warten
    digitalWrite(led, LOW);    // LED ausschalten
    delay(kurz/2);             // die Hälfte von kurz warten
  }
}

void setup() {                
  pinMode(led, OUTPUT);   // Pin 13 als output festlegen
}

void loop() {
  blinken(kurz, schritte); // blinkt kurz
  digitalWrite(led, HIGH); // LED einschalten
  delay(lang);             // wartet lang (das Licht ist auf der anderen Seite)
  blinken(kurz, schritte); // blinkt kurz
  delay(lang);             // wartet lang
}
