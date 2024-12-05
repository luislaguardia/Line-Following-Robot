// dec 5 (test)

#include <QTRSensors.h>

#define NUM_SENSORS 5
#define TIMEOUT 2500
#define EMITTER_PIN QTR_NO_EMITTER_PIN

QTRSensorsAnalog qtr((unsigned char[]){A0, A1, A2, A3, A4}, NUM_SENSORS, TIMEOUT, EMITTER_PIN);

// PID Constants
float Kp = 1.0;
float Ki = 0.0;
float Kd = 0.0;

// Variables for PID control
int error = 0;
int lastError = 0;
int integral = 0;

// Motor control pins
const int leftMotorSpeedPin = 5;
const int leftMotorDirPin = 4;
const int rightMotorSpeedPin = 6;
const int rightMotorDirPin = 7;

const int baseSpeed = 100;

void setup() {
    pinMode(leftMotorSpeedPin, OUTPUT);
    pinMode(leftMotorDirPin, OUTPUT);
    pinMode(rightMotorSpeedPin, OUTPUT);
    pinMode(rightMotorDirPin, OUTPUT);

    Serial.begin(9600);
    Serial.println("Calibrating...");
    for (int i = 0; i < 400; i++) {  // Run calibration for 4 seconds
        qtr.calibrate();
        delay(10);
    }
    Serial.println("Calibration complete!");
}

void loop() {
    unsigned int sensorValues[NUM_SENSORS];
    int position = qtr.readLine(sensorValues);

    error = position - 2000;

    int proportional = error;
    integral += error;
    int derivative = error - lastError;

    int correction = Kp * proportional + Ki * integral + Kd * derivative;

    int leftSpeed = baseSpeed + correction;
    int rightSpeed = baseSpeed - correction;

    leftSpeed = constrain(leftSpeed, 0, 255);
    rightSpeed = constrain(rightSpeed, 0, 255);

    setMotorSpeeds(leftSpeed, rightSpeed);

    lastError = error;
}

void setMotorSpeeds(int leftSpeed, int rightSpeed) {
    if (leftSpeed > 0) {
        digitalWrite(leftMotorDirPin, HIGH);
        analogWrite(leftMotorSpeedPin, leftSpeed);
    } else {
        digitalWrite(leftMotorDirPin, LOW);
        analogWrite(leftMotorSpeedPin, -leftSpeed);
    }

    if (rightSpeed > 0) {
        digitalWrite(rightMotorDirPin, HIGH);
        analogWrite(rightMotorSpeedPin, rightSpeed);
    } else {
        digitalWrite(rightMotorDirPin, LOW);
        analogWrite(rightMotorSpeedPin, -rightSpeed);
    }
}
