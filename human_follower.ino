// Define the pins for the sensor
int trigPin = 9;
int echoPin = 10;
 
// Define the pins for the motor
int motorPin1 = 3;
int motorPin2 = 5;
int motorPin3 = 6;
int motorPin4 = 9;
 
// Set the minimum and maximum distance values
long minimumDistance = 5;
long maximumDistance = 20;
 
// Define the speed of the motor
int motorSpeed = 200;
 
void setup() {
  // Initialize the sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
 
  // Initialize the motor pins
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
 
  // Set the motor speed
  analogWrite(motorPin1, motorSpeed);
  analogWrite(motorPin2, motorSpeed);
  analogWrite(motorPin3, motorSpeed);
  analogWrite(motorPin4, motorSpeed);
 
  // Set the serial communication rate
  Serial.begin(9600);
}
 
void loop() {
  // Read the distance from the sensor
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;
 
  // Check if the distance is within the minimum and maximum distance values
  if (distance >= minimumDistance && distance <= maximumDistance) {
    // Move the robot forward
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, HIGH);
    digitalWrite(motorPin4, LOW);
 
    // Print the distance to the serial monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  else if (distance < minimumDistance) {
    // Move the robot backward
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, HIGH);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, HIGH);
 
    // Print the distance to the serial monitor
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
  else {
    // Stop the robot
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    digitalWrite(motorPin3, LOW);
    digitalWrite(motorPin4, LOW);
  }
 
  // Delay before reading the sensor again
  delay(200);
}

