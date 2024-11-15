//POLULU T-

#include <QTRSensors.h>

QTRSensorsRC qtrrc((unsigned char[]) {2, 3, 4, 5, 6}, 5); // 5 sensors on pins 2-6
unsigned int sensorValues[5];

void setup() {
    Serial.begin(9600);
    qtrrc.calibrate(); // Calibrate the sensors
}

void loop() {
    qtrrc.readCalibrated(sensorValues);
    int position = qtrrc.readLine(sensorValues); // Get line position

    Serial.print("Line Position: ");
    Serial.println(position);
    delay(100);
}
