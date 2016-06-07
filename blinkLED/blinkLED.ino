// the number of the LEN pin
int ledPin = 9;
int brightness = 0;
int fadeAmount = 5;

void setup() {
  // initialize the digital pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  analogWrite(ledPin, brightness);

  brightness = brightness + fadeAmount;

  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount;
  }

  delay(30);
}
