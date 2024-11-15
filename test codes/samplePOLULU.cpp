//POLULU -TEST

// notes
// Additional Notes

// Calibration is critical: 
// Without calibration, sensor values may not represent 
// the correct reflectance levels.

// Custom tuning: 
// Adjust thresholds in functions like readLine to suit 
// your line-following application.


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
