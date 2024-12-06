#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int moisturePin = A3; 
int sensorValue = 0;
int moisturePercentage = 0;

void setup() {
  lcd.init(); 
  lcd.backlight(); 
  lcd.setCursor(0, 0);
  lcd.print("Moisture Level:");
  delay(100);
}

void loop() {
  sensorValue = analogRead(moisturePin); 
  moisturePercentage = map(sensorValue, 1023, 0, 0, 100); 
  lcd.setCursor(0, 1); 
  lcd.print("Moisture: ");
  lcd.print(moisturePercentage);
  lcd.print("%   ");   
  delay(100); 
}
