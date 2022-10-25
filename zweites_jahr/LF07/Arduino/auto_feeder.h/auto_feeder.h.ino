/*
  Automatic Food Dispenser (WIP)

  created 25 Okt 2022

  by Spiridon Fotiadis
*/

#include <Servo.h>

Servo shutter_servo;  // servo object to control the shutter

// servo configuration
int servo_pin = 9;
int pos = 0;
int end_pos = 180;
int steps = 10;

int day = 1000*60*60*24

void serve(int miliseconds) {
  for (pos = 0; pos <= end_pos; pos += steps) {  
    shutter_servo.write(pos);             
    delay(15);                            
  }
  delay(miliseconds);                     
  for (pos = end_pos; pos >= 0; pos -= steps) {
    shutter_servo.write(pos);                  
    delay(15);
  }
}

void setup() {
  shutter_servo.attach(servo_pin); 
}

void loop() {
  serve(2000);
  
}
