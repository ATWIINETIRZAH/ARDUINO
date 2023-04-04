const int lightPin = A4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lightLevel = analogRead(lightPin);
  Serial.print("Light Level: ");
  Serial.println(lightLevel);
  delay(500);
}

