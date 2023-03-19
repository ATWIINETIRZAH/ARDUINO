// Define pins
int left = 2; 
int middle = 3; 
int right = 4; 
//define motors
int leftMotor1 = 5; 
int leftMotor2 = 6; 
int rightMotor1 = 10; 
int rightMotor2 = 11; 

// Define variables
int leftSensor;
int middleSensor;
int rightSensor;

void setup() {
  // Set pins as input/output
  pinMode(left, INPUT);
  pinMode(middle, INPUT);
  pinMode(right, INPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
}

void loop() {
  // Read sensor values
  leftSensor = digitalRead(left);
  middleSensor = digitalRead(middle);
  rightSensor = digitalRead(right);

  // If all sensors are on the line
  if (leftSensor == HIGH && middleSensor == HIGH && rightSensor == HIGH) {
    // Move forward
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
  }
  // If the left sensor is on the line
  else if (leftSensor == HIGH) {
    // Turn left
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, HIGH);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
  }
  // If the right sensor is on the line
  else if (rightSensor == HIGH) {
    // Turn right
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, HIGH);
  }
  // If the middle sensor is on the line
  else if (middleSensor == HIGH) {
    // Move forward
    digitalWrite(leftMotor1, HIGH);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, HIGH);
    digitalWrite(rightMotor2, LOW);
  }
  // If all sensors are off the line
  else {
    // Stop
    digitalWrite(leftMotor1, LOW);
    digitalWrite(leftMotor2, LOW);
    digitalWrite(rightMotor1, LOW);
    digitalWrite(rightMotor2, LOW);
  }
}
