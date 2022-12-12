# Hinderniserkennung Mittels des Ultraschallsensors HC-SR04

## Was ist Schall/Ultraschall?

Mit Schall bezeichnet man mechanische Schwingungen in einem elastischen Medium (Gas, Flüssigkeit, Festkörper). Dabei sind meist Schwingungen gemeint, die im Menschlichen Hörbereich (16-20.000 Hz) liegen. 
Ultraschall bezeichnet hingegen Schall, dessen Frequenzen zwischen 20 kHz und 1 GHz liegen und damit für das menschliche Gehör nicht wahrnehmbar sind. 

## Abstandsmessung mit Ultraschall

Der Ultraschall Sensor strahlt einen kurzen Schallimpuls aus. Dieser verbreitet sich mit Schallgeschwindigkeit (ca. 343,2 m/s) in der Luft. Trifft er auf ein Objekt, wir der Schall zum Sensor zurückgeworfen. Die gemessene Zeit in Mikrosekunden zwischen Aussenden des Schallimpulses und Empfangen des Echos, lässt sich die Distanz berechnen.

z.B. 200 µs * 0.034 cm/µs * 1/2 (für hin und zurück) = 3,4 Meter

## HC-SR04 Trigpin und Echopin

Der Trigpin wird dazu verwendet, einen Ultraschallimpuls auszulösen. Dabei wird der Pin für mindestens 10 Mikrosekunden auf HIGH gesetzt. Sobald die Signalflanke fällt, sendet der Sensor nach 250 µs ein 40 kHz Signal für die Dauer von 200 µs.
Der Echopin wird beim Aussenden ders Impulses auf HIGH gesetzt und verbleibt in diesem Zustand so lange, bis das Echo empfangen wurde.
Die Dauer, in der der Echopin auf HIGH ist wird dazu genutzt, um die Distanz zu berechnen.

## HC-SR04 TTL-Pegel

Von Transistor-Transistor-Logik; TTL-Schaltkreise werden i.d.R. mit einer Versorgungsspannung von 5V betrieben. Die Schaltkreise sind so dimensioniert, dass der HIGH-Pegel (> 2.4 V) als eine logische 1 definiert ist und der LOW-Pegel (< 0.8 V) als eine logische 0.

