#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;
LiquidCrystal_I2C lcd(0x27, 20, 6); ////Instance d'écran

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  lcd.init();
  RTC.begin();
  RTC.adjust(DateTime(__DATE__, __TIME__));
  lcd.backlight();
 
}

void loop() {
  DateTime now = RTC.now();

  int day = now.day();
  int month = now.month();
  int year = now.year();
  int hour = now.hour();
  int minute = now.minute();
  int second = now.second();

  char Kebab[18];

  lcd.setCursor(0,0);
  
  sprintf(Kebab,"%.2d/%.2d/%.4d", day, month, year);
  lcd.print(Kebab);
  
  lcd.setCursor(5,2);
  sprintf(Kebab,"%.2d:%.2d:%.2d",hour, minute, second);
  lcd.print(Kebab);
  
}
