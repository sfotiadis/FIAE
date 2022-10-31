/*
  Automatic Food Dispenser (WIP)

  Components:
    
    + RTC DS3231
    + cereal dispenser
    + SG90 servo

  created 25 Okt 2022

  by Spiridon Fotiadis
*/

#include <Servo.h>
#include <RTClib.h>

Servo shutter_servo;  // servo object to control the shutter
RTC_DS3231 rtc;       // real time clock

// servo configuration
int servo_pin = 9;
int pos = 0;
int end_pos = 180;
int steps = 10;

// feeding configuration
int feedingTime = 19;

// opens shutter for specified amount of miliseconds
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

  while(!Serial);

  Serial.begin(9600);
  
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  Serial.println("Feeding time set to 19:00");
}

void loop() {
  DateTime now = rtc.now();

  if(now.hour() == feedingTime){
    serve(1000);
  }
}
