int mood = 0;                     // the toy's mood state
const int neutralMood = 10;       // the neutral mood state
int buttonState = 0;              // Button current state
bool buttonPressed = false;       // Has the button been pressed or not

unsigned long touchedTimer = 0;   // the timer used for record the last touched point time
unsigned long reducedTimer = 0;   // the timer used for record the last reduced point time
const long touchInterval = 5000;  // the interval for decrease the mood
const long reduceInterval = 1000; // the interval for decrease the mood

const int buttonPin = 2;          // the button pin
const int RledPin = 9;
const int GledPin = 10;
const int BledPin = 11;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(RledPin, OUTPUT);
  pinMode(GledPin, OUTPUT);
  pinMode(BledPin, OUTPUT);

  // initialize the mood state
  mood = neutralMood;
}

// the loop routine runs over and over again forever:
void loop() {
  showLEDState(mood);

  // Check if the button is pressed or not
  buttonState = digitalRead(buttonPin);

  // If the button is clicked
  if (buttonState == HIGH && !buttonPressed) {
    // increase the mood
    mood = mood + 1;
    if (mood > 20) mood = 20;       // limit maximum
    // update the touched Timer
    touchedTimer = millis();
    buttonPressed = true;
  }

  if (buttonState == LOW && buttonPressed) {
    buttonPressed = false;
  }

  // Check if the timer from the last time user touch is longer than interval or not
  unsigned long currentTimer = millis();
  if (currentTimer - touchedTimer >= touchInterval) {
    // reduce the point
    if (currentTimer - reducedTimer >= reduceInterval) {
      mood = mood - 1;
      if (mood < 0) mood = 0;
      reducedTimer = currentTimer;
    }
  }
}

// ----- Display LED state based on mood -----
void showLEDState(int m) {
  float brightnessInterval = 255.0 / 10.0;

  if (m >= neutralMood) {
    analogWrite(RledPin, 255);
    analogWrite(GledPin, brightnessInterval * (m - neutralMood));
    analogWrite(BledPin, 255 - brightnessInterval * (m - neutralMood));
  } else {
    analogWrite(RledPin, 255 - brightnessInterval * (neutralMood - m));
    analogWrite(GledPin, brightnessInterval * (neutralMood - m));
    analogWrite(BledPin, 255);
  }
}
