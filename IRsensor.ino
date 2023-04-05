
int irPin = 3; // Pin to which the IR sensor is connected

void setup() {
  Serial.begin(9600);
}

void loop() {
  int irVal = analogRead(irPin); // Read the analog value from the IR sensor
  Serial.println(irVal); // Print the value to the serial monitor
  delay(1000); // Wait for 1 second before reading again
}
