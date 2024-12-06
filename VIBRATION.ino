#include <Wire.h>
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);


const int vibrationPin = 12; 
int vibrationState = LOW;   

void setup() {

  lcd.init();               
  lcd.backlight();          
  lcd.setCursor(0, 0);      
  lcd.print("Vibration");   
  lcd.setCursor(0, 1);      
  lcd.print("Sensor Ready");


  pinMode(vibrationPin, INPUT);
}

void loop() {

  vibrationState = digitalRead(vibrationPin);


  if (vibrationState == HIGH) {
    lcd.clear();              
    lcd.setCursor(0, 0);      
    lcd.print("Vibration");   
    lcd.setCursor(0, 1);      
    lcd.print("Detected!");   
    delay(5000);               
  } else {
    lcd.clear();               
    lcd.setCursor(0, 0);       
    lcd.print("No Vibration");
    lcd.setCursor(0, 1);
    lcd.print("Detected");
    delay(500);
  }
}
