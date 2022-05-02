/*
PIR sensor tester
*/
int ledPin = 5; // choose the pin for the LED
int inputPin = 7; // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int val = 0; // variable for reading the pin status
int buzzer = 6;
int smokeA5 = A5;

void setup() {
pinMode(ledPin, OUTPUT); // declare LED as output
pinMode(inputPin, INPUT); // declare sensor as input
pinMode(buzzer, OUTPUT);
  pinMode(smokeA5, INPUT);
  Serial.begin(9600);
   pinMode(5,OUTPUT);
   Serial.begin(9600);
}
int sensorThres = 1000;
int light;

void loop() {
val = digitalRead(inputPin); // read input value
if (val == HIGH) { // check if the input is HIGH
digitalWrite(ledPin, HIGH); // turn LED ON
if (pirState == LOW) {
// we have just turned on
Serial.println("Motion detected!");
// We only want to print on the output change, not state
pirState = HIGH;
}
} else {
digitalWrite(ledPin, LOW); // turn LED OFF
if (pirState == HIGH) {
// we have just turned of
Serial.println("Motion ended!");
// We only want to print on the output change, not state
pirState = LOW;
}
}



 
  light = analogRead(A0);

  if(light<100){
    digitalWrite(5, HIGH);
  }else{
    digitalWrite(5, LOW);
  }
  Serial.print("photosensitive:");
  Serial.println(light);
  delay(100);





  int analogSensor = analogRead(smokeA5);

  Serial.print("Pin A5: ");
  Serial.println(analogSensor);
  // Checks if it has reached the threshold value
  if (analogSensor < sensorThres)
  {
    tone(buzzer, HIGH); // Can be placed as HIGH, LOW i.e 1000, 200
  
  }
  else
  {
    noTone(buzzer);
  }
  delay(100);
}
