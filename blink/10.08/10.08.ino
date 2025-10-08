const int RledPin = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if(sensorValue > 500){
    digitalWrite(RledPin, LOW);
  }
  else{
    digitalWrite(RledPin, HIGH);
  }
  delay(1);
}
