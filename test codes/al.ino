// for testing
// check the notes


// Pin definitions
const int leftSensorPin = 2;   // Left IR sensor pin
const int rightSensorPin = 3;  // Right IR sensor pin
const int motorLeftForward = 4; // Left motor forward pin
const int motorLeftBackward = 5; // Left motor backward pin
const int motorRightForward = 6; // Right motor forward pin
const int motorRightBackward = 7; // Right motor backward pin

void setup() {
    // Set pin modes
    pinMode(leftSensorPin, INPUT);
    pinMode(rightSensorPin, INPUT);
    pinMode(motorLeftForward, OUTPUT);
    pinMode(motorLeftBackward, OUTPUT);
    pinMode(motorRightForward, OUTPUT);
    pinMode(motorRightBackward, OUTPUT);
}

void loop() {
    int leftSensorValue = digitalRead(leftSensorPin);
    int rightSensorValue = digitalRead(rightSensorPin);
    
    // Both sensors on the line
    if (leftSensorValue == HIGH && rightSensorValue == HIGH) {
        moveForward();
    }
    // Only left sensor is on the line
    else if (leftSensorValue == HIGH) {
        turnRight();
    }
    // Only right sensor is on the line
    else if (rightSensorValue == HIGH) {
        turnLeft();
    }
    // No sensors on the line
    else {
        stopMotors();
    }
}

void moveForward() {
    digitalWrite(motorLeftForward, HIGH);
    digitalWrite(motorLeftBackward, LOW);
    digitalWrite(motorRightForward, HIGH);
    digitalWrite(motorRightBackward, LOW);
}

void turnRight() {
    digitalWrite(motorLeftForward, HIGH);
    digitalWrite(motorLeftBackward, LOW);
    digitalWrite(motorRightForward, LOW);
    digitalWrite(motorRightBackward, LOW);
}

void turnLeft() {
    digitalWrite(motorLeftForward, LOW);
    digitalWrite(motorLeftBackward, LOW);
    digitalWrite(motorRightForward, HIGH);
    digitalWrite(motorRightBackward, LOW);
}

void stopMotors() {
    digitalWrite(motorLeftForward, LOW);
    digitalWrite(motorLeftBackward, LOW);
    digitalWrite(motorRightForward, LOW);
    digitalWrite(motorRightBackward, LOW);
}
