// the number of the key pin
int keyPin = 12;

// the number of led pin
int ledPin = 13;

void setup() {
  // initialize the key pin as input
  pinMode(keyPin, INPUT);

  // initialize the led pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the state of the key value
  // and check if the key is pressed
  // if it is, the state is HIGH
  if (digitalRead(keyPin) == HIGH) {
    // turn on the led
    digitalWrite(ledPin, HIGH);
  } else {
    // turn off the led
    digitalWrite(ledPin, LOW);
  }
}
