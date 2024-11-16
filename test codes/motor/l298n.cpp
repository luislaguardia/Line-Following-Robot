#define IN1 12  // Motor 1 IN1
#define IN2 14  // Motor 1 IN2
#define IN3 27  // Motor 2 IN3
#define IN4 26  // Motor 2 IN4

#define LEFT_SENSOR_PIN 32  // Left sensor
#define RIGHT_SENSOR_PIN 33  // Right sensor

#define THRESHOLD 1000

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(LEFT_SENSOR_PIN, INPUT);
  pinMode(RIGHT_SENSOR_PIN, INPUT);

  stopMotors();
}

void loop() {
  int leftSensorValue = digitalRead(LEFT_SENSOR_PIN);
  int rightSensorValue = digitalRead(RIGHT_SENSOR_PIN);

  if (leftSensorValue == LOW && rightSensorValue == LOW) {
    moveForward();
  }
  else if (leftSensorValue == LOW && rightSensorValue == HIGH) {
    turnRight();
  }
  else if (leftSensorValue == HIGH && rightSensorValue == LOW) {
    turnLeft();
  }
  else {
    stopMotors();
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
