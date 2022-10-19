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
int detectorStatus;

void setup() {
  Serial.begin(9600);
  
  pinMode(2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  detectorStatus = digitalRead(2);
}

void loop() {
  int detectorReading = digitalRead(2);
  if (detectorReading != detectorStatus) {
    if (detectorReading == HIGH) {
  
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.println("object opened");
  
    } else {
  
      digitalWrite(LED_BUILTIN, LOW);
      Serial.println("object closed");

  
    }
    detectorStatus = detectorReading;
  }
}
