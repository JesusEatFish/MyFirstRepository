/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

const int buttonPin = 2; //pushButton
const int RledPin = 3; // R
const int GledPin = 4; // G
const int BledPin = 5; // B

int buttonState = 0;
int ledState = LOW;
int ledcolor = 0;
bool ButtonPressed = false;
String currentcolor ="led";
unsigned long previousMillis = 0;
const long interval = 1000;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  
  buttonState = digitalRead(buttonPin);
  Serial.print("Current Color:");
  Serial.println(currentcolor);

  if (buttonState == HIGH && ButtonPressed == false) {
  ledcolor = ledcolor + 1;
  ButtonPressed = true;  // mark it pressed
  delay(200); // debounce (防彈跳)
}

if (buttonState == LOW) {
  ButtonPressed = false; // release
}


  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
  if (ledState == LOW){
      ledState = HIGH;
   } else {
    ledState = LOW;
   }
  }

  else if(ledcolor == 0){
    currentcolor = "LED off";
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
  }

  else if(ledcolor == 1){
    // RED
    currentcolor = "Red";
    if(ledState == LOW){
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }  
  }
  else if(ledcolor == 2){
    // GREEN
    currentcolor = "Green";
    if(ledState == LOW){
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }  
  }
  else if(ledcolor == 3){
    // BLUE
    currentcolor = "Blue";
    if(ledState == LOW){
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }  
  }
  else if(ledcolor == 4){
    // YELLOW
    currentcolor = "Yellow";
    if(ledState == LOW){
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, HIGH);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }  
  }
  else if(ledcolor == 5){
    // PURPLE
    currentcolor = "Purple";
    if(ledState == LOW){
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, LOW);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }  
  }
  else if(ledcolor == 6){
    // CYAN
    currentcolor = "Cyan";
    if(ledState == LOW){
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }  
  }
  else if(ledcolor == 7){
    // WHITE
    currentcolor = "White";
    if(ledState == LOW){
    digitalWrite(RledPin, LOW);
    digitalWrite(GledPin, LOW);
    digitalWrite(BledPin, LOW);
    } else {
    digitalWrite(RledPin, HIGH);
    digitalWrite(GledPin, HIGH);
    digitalWrite(BledPin, HIGH);
    }  
  }
  else if(ledcolor == 8){
    ledcolor = 0;
  }
}
