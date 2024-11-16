// Basic Motor Test Code for ESP32 with L298N:

// Motor control pins connected to L298N
#define IN1 12  // Motor 1 IN1
#define IN2 14  // Motor 1 IN2
#define IN3 27  // Motor 2 IN3
#define IN4 26  // Motor 2 IN4

void setup() {
  // Set motor control pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Start with motors stopped
  stopMotors();
}

void loop() {
  // Test forward motion (both motors forward)
  moveForward();
  delay(2000);  // Move forward for 2 seconds

  // Test backward motion (both motors backward)
  moveBackward();
  delay(2000);  // Move backward for 2 seconds

  // Test stop (both motors stop)
  stopMotors();
  delay(2000);  // Stop for 2 seconds

  // Repeat the cycle
}

void moveForward() {
  // Motor 1 forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  
  // Motor 2 forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  // Motor 1 backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  
  // Motor 2 backward
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  // Motor 1 stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  
  // Motor 2 stop
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
