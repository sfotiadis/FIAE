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
int pin = A1;
int relay = 1;

int detectorStatus;

void setup() {
  Serial.begin(9600);
  
  pinMode(pin, INPUT_PULLUP);
  pinMode(relay, OUTPUT);         // relay for alarm
  pinMode(LED_BUILTIN, OUTPUT);

  detectorStatus = digitalRead(pin);
}

void loop() {
  int detectorReading = digitalRead(pin);
  if (detectorReading != detectorStatus) {
    if (detectorReading == HIGH) {
  
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(relay, HIGH);
      Serial.println("object opened");
  
    } else {
  
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(relay, LOW);
      Serial.println("object closed");

  
    }
    detectorStatus = detectorReading;
  }
}
