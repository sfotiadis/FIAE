/*
  Futterautomat für Trockenfutter

    Versorgt Tiere zu einer festgelegten Zeit mit Trockenfutter.

  Die Schaltung

    - SG90 Servomotor an 5V und GND, Signalpin an 9

    - RTC DS3231

  Weiteres

    - Müslispender

  erstellt am 1. Nov 2022

  von Spiridon Fotiadis
*/

#include "Futterautomat.h"
#include <RTClib.h>


RTC_DS3231 rtc; // Echtzeituhr für Fütterungszeit
int fuetterungszeit = 19;

// Pin an dem der Servomotor angeschlossen wird
int servoPin = 9;

// erstellt ein Objekt aus der Klasse Futterautomat
Futterautomat automat(servoPin);


void setup() {
  while(!Serial);

  Serial.begin(9600);
  
  if (! rtc.begin()) {
    Serial.println("Konnte RTC nicht finden");
    while (1);
  }
  
  Serial.print("Fütterungszeit auf");
  Serial.print(fuetterungszeit);
  Serial.println("Uhr gestellt");
}

void loop() {
  // ermittelt die aktuelle Zeit
  DateTime aktuelleZeit = rtc.now();

  // wenn die Aktuelle Stunde gleich der Fütterungszeit ist
  if(aktuelleZeit.hour() == fuetterungszeit){
    // öffnet sich die Luke für 1 Sekunde
    automat.fuettern(1000);
  }
  

}
