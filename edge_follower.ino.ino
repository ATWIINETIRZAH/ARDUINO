int rightSensor = 2; // pin for right IR sensor
int leftSensor = 3; // pin for left IR sensor
int rightMotor = 5; // pin for right motor
int leftMotor = 6; // pin for left motor

void setup() {
  pinMode(rightSensor, INPUT);
  pinMode(leftSensor, INPUT);
  pinMode(rightMotor, OUTPUT);
  pinMode(leftMotor, OUTPUT);
}

void loop() {
  int rightValue = digitalRead(rightSensor);
  int leftValue = digitalRead(leftSensor);

  if (rightValue == LOW && leftValue == LOW) { // both sensors on edge
    digitalWrite(rightMotor, HIGH); // turn right
    digitalWrite(leftMotor, LOW);
  } else if (rightValue == HIGH && leftValue == LOW) { // right sensor off edge
    digitalWrite(rightMotor, HIGH); // turn right
    digitalWrite(leftMotor, LOW);
  } else if (rightValue == LOW && leftValue == HIGH) { // left sensor off edge
    digitalWrite(rightMotor, LOW); // turn left
    digitalWrite(leftMotor, HIGH);
  } else { // both sensors off edge or on black surface
    digitalWrite(rightMotor, HIGH); // go straight
    digitalWrite(leftMotor, HIGH);
  }
}
