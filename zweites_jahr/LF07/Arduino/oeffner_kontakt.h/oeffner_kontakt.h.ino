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
int doorSensor = A1;
int motionDetector = A2;
int relay = 1;

int doorStatus;
int detectorStatus

void setup() {
  Serial.begin(9600);
  
  pinMode(doorSensor, INPUT_PULLUP);
  pinMode(motionDetector, INPUT)
  pinMode(relay, OUTPUT);         //relay for alarm
  pinMode(LED_BUILTIN, OUTPUT);

  doorStatus = digitalRead(doorSensor);
  detectorStatus = digitalRead(motionDetector);


}

int check_door(){
  int doorReading = digitalRead(doorSensor);
  if (doorReading != doorStatus) {
    if (doorReading == HIGH) {
  
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(relay, HIGH);
      Serial.println("object opened");
  
    } else {
  
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(relay, LOW);
      Serial.println("object closed");

  
    }
    doorStatus = doorReading;
  }
  return  1;
}

int check_motion(){
  int detectorReading = digitalRead(motionDetector);

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
  return  1;
}

void loop() {

}
