// the pin that the LED is attached to
int ledPin = 9;

void setup() {
  // declare pin 9 to be an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // loop from 0 to 255
  for (int a = 0; a <= 255; a++) {
      // set the brithness of pin 9
      analogWrite(ledPin, a);

      // wait for 10 micro seconds
      delay(10);
  }

  
  // loop from 255 to 0
  for (int a = 255; a >= 0; a--) {
      // set the brithness of pin 9
      analogWrite(ledPin, a);

      // wait for 10 micro seconds
      delay(10);
  }

  // wait for 1000 micro seconds
  delay(1000);
}
