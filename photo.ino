int light;

void setup() {
   pinMode(5,OUTPUT);
   Serial.begin(9600);
}

void loop(){
  light = analogRead(A0);

  if(light<100){
    digitalWrite(5, HIGH);
  }else{
    digitalWrite(5, LOW);
  }
  Serial.println(light);
  delay(100);
}
