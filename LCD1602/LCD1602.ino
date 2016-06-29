#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// the string to print on the LCD
char array_working[] = "Working...";

// the value of delay time
int tim = 250;

// pontentiometer
int SENSOR_PIN = 0;

// inilialize the library with the numbers of the interface pins
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  // set up the LCD's number of columns and rows
  lcd.begin(16, 2);
}

void loop() {
  // sensor
  int sensorValue = analogRead(SENSOR_PIN);
  lcd.setCursor(0, 1);
  if (sensorValue > 500) {
    lcd.print(sensorValue);
    lcd.print("     ");
    delay(100);
  } else {
    // set the cursor to column 15, line 0
    lcd.setCursor(15, 0);
  
    for (int positionCounter = 0; positionCounter < 26; positionCounter++) {
      // scrolls the contents of the display one space to the left
      lcd.scrollDisplayLeft();
  
      // print a message to the LCD
      if (array_working[positionCounter]) {
        lcd.print(array_working[positionCounter]);
      }
  
      // wait for 250 microseconds
      delay(tim);
    }
  
    // clears the LCD screen and positions the cursor in the upper-left corner
    lcd.clear();
    
    // set the cursor to column 15, line 1
    lcd.setCursor(15, 1);
  }
}
