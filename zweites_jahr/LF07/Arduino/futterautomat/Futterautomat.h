/*
  Futterautomat Klasse, teil des Projekts Futterautomat für Trockenfutter

  erstellt am 1. Nov 2022

  von Spiridon Fotiadis
*/

#ifndef Futterautomat_h
#define Futterautomat_h
#include "Arduino.h"
#include <Servo.h>

class Futterautomat {
public:
  Futterautomat(int servoPin);
  void fuettern(int milisekunden);
private:
  Servo futterluke;
  int pos = 0;
  int end_pos = 180;
  int steps = 10;
};
#endif
