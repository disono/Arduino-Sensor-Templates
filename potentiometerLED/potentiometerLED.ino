// the analog input pin attach to
int analogPin = A0;

// the LED attach to
int ledPin = 9;

// variable to store the value coming from sensor
int inputValue = 0;

// variable to store the output value
int outputValue = 0;

void setup() {

}

void loop() {
  // read the value from the sensor
  inputValue = analogRead(analogPin);

  // convert from 0 to 1023 proportional to the number of a number of from 0 to 255
  outputValue = map(inputValue, 0, 1023, 0, 255);

  // turn the LED on depend on the output value
  analogWrite(ledPin, outputValue);
}
