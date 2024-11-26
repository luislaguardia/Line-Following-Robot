// for motor control 
// lets keep moving forward

const int motor1Pin1 = 3;
const int motor1Pin2 = 4; 
const int motor2Pin1 = 5; 
const int motor2Pin2 = 6;
const int enablePin1 = 9;
const int enablePin2 = 10;

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);

  moveForward(255); 
}

void loop() {
  delay(5000);    
  stopMotors();  
  delay(2000);        
  moveBackward(200);  
  delay(5000);        
  stopMotors();    
  delay(2000);
}

void moveForward(int speed) {
  analogWrite(enablePin1, speed); 
  analogWrite(enablePin2, speed); 
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW
