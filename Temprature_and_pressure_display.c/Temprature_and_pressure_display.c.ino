// Displaying pressure and temprature value

#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  
Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);
 lcd.begin(16, 2);  
 lcd.setBacklight(225);

if (!bmp.begin()) {
  lcd.print("######****######");
  lcd.setCursor(0,1);
  lcd.print("     No data");
  while (1) {}
  }
}

void loop() {
    // code to display temprature value
     lcd.setCursor(0,0);
     lcd.print("Temp = ");
     lcd.print(bmp.readTemperature());
     lcd.print(" C");
    
    // code to display atmospheric pressure (Atm) 
     lcd.setCursor(0,1);
     lcd.print("Atm = ");
     lcd.print(bmp.readPressure());
     lcd.print(" Pa");
     delay(1000);
 
}
