/*
  Wired open/closed sensor

    This program uses pinMode(INPUT_PULLUP) to read the status of an NC open/closed sensor. 
    
    On opening/closing the status will be printed to the Serial Monitor.

  The circuit:

  - NC Reed Magnet Sensor attached from pin 2 to ground

  - built-in LED

  created 19 Okt 2022

  by Spiridon Fotiadis
*/
int contactPin = A1;
int realyPin = 1;
int signalLed = LED_BUILTIN;

int doorStatus;

void setup() {
  Serial.begin(9600);
  
  pinMode(contactPin, INPUT_PULLUP);
  pinMode(realyPin, OUTPUT);         // relay for alarm
  pinMode(signalLed, OUTPUT);

  doorStatus = digitalRead(contactPin);
}

void loop() {
  checkDoor();
  
}

void checkDoor(){
  int contactStatus = digitalRead(contactPin);
  if (contactStatus != doorStatus) {
    if (contactStatus == HIGH) {
  
      digitalWrite(signalLed, HIGH);
      digitalWrite(realyPin, HIGH);
      Serial.println("object opened");
    } else {
  
      digitalWrite(signalLed, LOW);
      digitalWrite(realyPin, LOW);
      Serial.println("object closed");
    }
    doorStatus = contactStatus;
    delay(100);
  }
}