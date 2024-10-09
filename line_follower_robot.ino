int mot1 = 9;
int mot2 = 6;
int mot3 = 5;
int mot4 = 3;

int leftSensor = 13; // Left sensor pin
int rightSensor = 12; // Right sensor pin

int leftState = 0;
int rightState = 0;

void FORWARD(void);
void LEFT(void);
void RIGHT(void);
void STOP(void);

void setup()
{
  pinMode(mot1, OUTPUT);
  pinMode(mot2, OUTPUT);
  pinMode(mot3, OUTPUT);
  pinMode(mot4, OUTPUT);

  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  digitalWrite(leftSensor, HIGH);  // Activate pull-up resistors if needed
  digitalWrite(rightSensor, HIGH); 
}

void loop() 
{
  // Read the sensor states
  leftState = digitalRead(leftSensor);
  rightState = digitalRead(rightSensor);

  // Logic for following the line
  if (leftState == 0 && rightState == 0) {
    FORWARD();  // Move forward when both sensors are on the line
  }
  else if (leftState == 0 && rightState == 1) {
    LEFT();  // Turn left when only the left sensor is on the line
  }
  else if (leftState == 1 && rightState == 0) {
    RIGHT(); // Turn right when only the right sensor is on the line
  }
  else {
    STOP();  // Stop if both sensors are off the line
  }
}

void FORWARD(void)
{
  analogWrite(mot1, 255);  // Move forward (left motor)
  analogWrite(mot2, 0);
  analogWrite(mot3, 255);  // Move forward (right motor)
  analogWrite(mot4, 0);
}

void LEFT(void)
{
  analogWrite(mot1, 0);    // Stop left motor
  analogWrite(mot2, 255);  // Turn left by moving the right motor
  analogWrite(mot3, 255);  // Keep right motor forward
  analogWrite(mot4, 0);
}

void RIGHT(void)
{
  analogWrite(mot1, 255);  // Keep left motor forward
  analogWrite(mot2, 0);
  analogWrite(mot3, 0);    // Stop right motor
  analogWrite(mot4, 255);  // Turn right by moving the left motor
}

void STOP(void)
{
  analogWrite(mot1, 0);  // Stop all motors
  analogWrite(mot2, 0);
  analogWrite(mot3, 0);
  analogWrite(mot4, 0);
}
