/* 
  Einparkhilfe

  Komponenten:

    Ultraschall Sensor HC-SR04
    
    Buzzer (generisch)

  erstellt am 9. Dez 2022
  von Spiridon Fotiadis
*/

#define echoPin 2 // Pin 2 als echoPin des HC-SR04 definieren 
#define trigPin 3 // Pin 3 als trigPin des HC-SR04 definieren
#define buzzerPin 7  // Pin 7 als buzzerPin definieren 

// lokale Variablen
long duration; // Variable für die Dauer, die das Echo braucht um zurück zu kommen
int distance;  // Variable für die Distanzmessung 

void setup() {
  pinMode(trigPin, OUTPUT); // trigPin als OUTPUT setzen
  pinMode(echoPin, INPUT);  // echoPin als INPUT setzen
  
  Serial.begin(9600);       
}

void loop() {
  // neutralen trigPin zustand setzen
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // 10 microsekunden lang einen Ultraschall senden 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // echoPin lesen, gibt die Reisedauer des Echos in microsekunden wieder
  duration = pulseIn(echoPin, HIGH);

  // Distanz berechnen
  distance = duration * 0.034 / 2; // Schallgeschwindigkeit geteilt durch zwei für hin und zurück
  
  // Distanz in cm ausgeben
  Serial.print("Distanz: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  // Wenn die Distanz unter einem Meter ist
  if (distance < 100) {
    tone(buzzer, 1000); // wird ein Ton ausgegeben
    delay(40);
    noTone(buzzer);     // Ton wieder ausschalten
    delay(distance*4);  // Distanz mal 4 Milisekunden warten
  }
  delay(100);
}