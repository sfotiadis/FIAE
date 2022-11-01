/*
  Futterautomat Klasse, teil des Projekts Futterautomat für Trockenfutter

  erstellt am 1. Nov 2022

  von Spiridon Fotiadis
*/

#include "Futterautomat.h"
#include <Servo.h>

Servo futterluke;

int start_pos = 0;
const int end_pos = 180;
const int steps = 10;

Futterautomat::Futterautomat(int servoPin) { 
  // übergebenen Pin der Futterluke zuweisen
  futterluke.attach(servoPin); 
}

void Futterautomat::fuettern(int milisekunden) {
  // Futterluke schrittweise oeffnen
  for (start_pos = 0; start_pos <= end_pos; start_pos += steps) {  
    futterluke.write(start_pos);             
    delay(15);                            
  }
  
  delay(milisekunden);  
                     
  // Futterluke schrittweise schließen
  for (start_pos = end_pos; start_pos >= 0; start_pos -= steps) {
    futterluke.write(start_pos);                  
    delay(15);
  }
}
