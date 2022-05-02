int buzzer = 6;
int smokeA5 = A5;

// Your threshold value. You might need to change it.
int sensorThres = 300;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(smokeA5, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA5);

  Serial.print("Pin A5: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    tone(buzzer, HIGH); // Can be placed as HIGH, LOW i.e 1000, 200
  
  }
  else
  {
    noTone(buzzer);
  }
  delay(100);
}
