#include <RTClib.h>

RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Konnte RTC nicht finden");
    Serial.flush();
    while (1) delay(10);
  }

  // Zeit einstellen
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}
 
void loop() {
  delay(1000);
  DateTime time = rtc.now();
  Serial.println(String("DateTime::TIMESTAMP_TIME:\t")+time.timestamp(DateTime::TIMESTAMP_FULL));
  int minute = time.minute();
  if (minute == 53){
    Serial.println("Alarm! Alarm!");
  }
}
