// for motor control 
// lets keep moving forward

// update 11/36/2024 - ;

// notes  => 

// Motor Control Pins
const int motor1Pin1 = 3;  // Motor 1 forward
const int motor1Pin2 = 4;  // Motor 1 backward
const int motor2Pin1 = 5;  // Motor 2 forward
const int motor2Pin2 = 6;  // Motor 2 backward
const int enablePin1 = 9;  // Motor 1 speed control (PWM)
const int enablePin2 = 10; // Motor 2 speed control (PWM)

void setup() {
  // Initialize motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);

  // Start motors moving forward
  moveForward(255); // Move forward at full speed
}

void loop() {
  // Continuous motor actions
  delay(5000);        // Move forward for 5 seconds
  stopMotors();       // Stop for 2 seconds
  delay(2000);        
  moveBackward(200);  // Move backward at 80% speed
  delay(5000);        
  stopMotors();       // Stop for 2 seconds
  delay(2000);
}

// Function to move forward
void moveForward(int speed) {
  analogWrite(enablePin1, speed); // Set speed for Motor 1
  analogWrite(enablePin2, speed); // Set speed for Motor 2
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

// Function to move backward
void moveBackward(int speed) {
  analogWrite(enablePin1, speed); // Set speed for Motor 1
  analogWrite(enablePin2, speed); // Set speed for Motor 2
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

// Function to stop all motors
void stopMotors() {
  analogWrite(enablePin1, 0); // Stop Motor 1
  analogWrite(enablePin2, 0); // Stop Motor 2
}
