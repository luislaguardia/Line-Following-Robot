// example code for

#define IN1 12  // Motor 1 IN1
#define IN2 14  // Motor 1 IN2
#define IN3 27  // Motor 2 IN3
#define IN4 26  // Motor 2 IN4

// IR sensor pins
#define LEFT_SENSOR_PIN 32  // Left sensor
#define RIGHT_SENSOR_PIN 33  // Right sensor

// Threshold for line detection
#define THRESHOLD 1000

void setup() {
  // Set motor pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set IR sensor pins as inputs
  pinMode(LEFT_SENSOR_PIN, INPUT);
  pinMode(RIGHT_SENSOR_PIN, INPUT);

  // Start motors in stopped state
  stopMotors();
}

void loop() {
  int leftSensorValue = digitalRead(LEFT_SENSOR_PIN);
  int rightSensorValue = digitalRead(RIGHT_SENSOR_PIN);

  // Line following logic
  if (leftSensorValue == LOW && rightSensorValue == LOW) {
    moveForward();  // Both sensors on the line, move forward
  }
  else if (leftSensorValue == LOW && rightSensorValue == HIGH) {
    turnRight();  // Left sensor on the line, turn right
  }
  else if (leftSensorValue == HIGH && rightSensorValue == LOW) {
    turnLeft();  // Right sensor on the line, turn left
  }
  else {
    stopMotors();  // No sensor on the line, stop the robot
  }
}

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
