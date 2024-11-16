// example code for
// 8 sensors
// Motor pins connected to L298N
#define IN1 12  // Motor 1 IN1
#define IN2 14  // Motor 1 IN2
#define IN3 27  // Motor 2 IN3
#define IN4 26  // Motor 2 IN4

// IR sensor pins
#define S1 32  // Left sensor 1
#define S2 33  // Left sensor 2
#define S3 34  // Left sensor 3
#define S4 35  // Center sensor 1
#define S5 36  // Center sensor 2
#define S6 39  // Right sensor 1
#define S7 21  // Right sensor 2
#define S8 22  // Right sensor 3

void setup() {
  // Set motor control pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set sensor pins as inputs
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(S3, INPUT);
  pinMode(S4, INPUT);
  pinMode(S5, INPUT);
  pinMode(S6, INPUT);
  pinMode(S7, INPUT);
  pinMode(S8, INPUT);

  // Start motors in stopped state
  stopMotors();
}

void loop() {
  // Read all sensors
  int leftSensor1 = digitalRead(S1);
  int leftSensor2 = digitalRead(S2);
  int leftSensor3 = digitalRead(S3);
  int centerSensor1 = digitalRead(S4);
  int centerSensor2 = digitalRead(S5);
  int rightSensor1 = digitalRead(S6);
  int rightSensor2 = digitalRead(S7);
  int rightSensor3 = digitalRead(S8);

  // Line following logic based on 8 sensors
  if (leftSensor1 == LOW && leftSensor2 == LOW && leftSensor3 == LOW && centerSensor1 == LOW && centerSensor2 == LOW && rightSensor1 == LOW && rightSensor2 == LOW && rightSensor3 == LOW) {
    // If all sensors are off the line, stop the motors or slow down
    stopMotors();
  } 
  else if (centerSensor1 == LOW && centerSensor2 == LOW) {
    // Both center sensors detect the line (ideal situation), move forward
    moveForward();
  } 
  else if (leftSensor1 == LOW || leftSensor2 == LOW || leftSensor3 == LOW) {
    // Left sensors detect the line, move right to correct
    turnRight();
  } 
  else if (rightSensor1 == LOW || rightSensor2 == LOW || rightSensor3 == LOW) {
    // Right sensors detect the line, move left to correct
    turnLeft();
  }
  else {
    // If the robot is veering too far left or right, apply corrective turns
    if (leftSensor1 == LOW && rightSensor3 == LOW) {
      // Strong left deviation, turn right
      turnRight();
    } 
    else if (rightSensor1 == LOW && leftSensor3 == LOW) {
      // Strong right deviation, turn left
      turnLeft();
    } 
    else {
      // If there's ambiguity, stop or slow down
      stopMotors();
    }
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
