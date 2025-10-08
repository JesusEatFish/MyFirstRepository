const int RledPin = 9;
const int GledPin = 10;
const int BledPin = 11;
int brightness = 0;
int fadeAmount = 5;
int ledcolor = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(ledcolor == 0){
    analogWrite(RledPin, brightness);
    analogWrite(GledPin, 255);
    analogWrite(BledPin, 255);
  }
  if(ledcolor == 1){
    analogWrite(RledPin, 255);
    analogWrite(GledPin, brightness);
    analogWrite(BledPin, 255);
  }
  if(ledcolor == 2){
    analogWrite(RledPin, 255);
    analogWrite(GledPin, 255);
    analogWrite(BledPin, brightness);
  }
  brightness = grightness = fadeAmount;
  if(brightness <=0||brightness >= 255){
    fadeAmount = -fadeAmount;
      if(brightness >= 255){
        ledcolor = ledcolor + 1;
          if(ledcolor > 2)
          ledcolor = 0;
      }
  }
  delay(30);
}
