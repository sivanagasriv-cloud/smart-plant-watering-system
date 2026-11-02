const int sensorPin = A0;
const int relayPin = 7;

int threshold = 600;

void setup() {
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);

  // Many relay modules are active LOW
  digitalWrite(relayPin, HIGH); // Pump OFF
}

void loop() {
  int moisture = analogRead(sensorPin);

  Serial.print("Soil reading: ");
  Serial.println(moisture);

  if (moisture > threshold) {
    digitalWrite(relayPin, LOW);  // Pump ON
  } else {
    digitalWrite(relayPin, HIGH); // Pump OFF
  }

  delay(1000);
}
