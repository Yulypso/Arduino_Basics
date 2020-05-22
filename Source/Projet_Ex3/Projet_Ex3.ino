#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <time.h>

LiquidCrystal_I2C lcd(0x27, 20, 6);
unsigned int year = 2019;
unsigned int month = 12;
unsigned int day = 30;
unsigned int hour = 23;
unsigned int minute = 59;
unsigned second = 57;

char temps[17];

void setup()
{
   lcd.init();
   lcd.begin(20,6);
   lcd.backlight();
}

void loop()
{
  lcd.setCursor(2,3);
   lcd.print("Boris / Thierry");
   
  char time[17];
  second++;
  if(second == 60)
  {
    second = 00;
    minute++;
    
    if(minute == 60)
    {
      minute = 00;
      hour++;
      
      if(hour == 24)
      {
        hour = 0;
        day++;
        
        if(day == 31)
        {
          day=1;
          month++;
          
          if(month == 13)
          {
            month = 1;
            year++;
           }
         }
       }
    }
  }

  
  lcd.setCursor(0,0);
  sprintf(time,"%.2d/%.2d/%.4d", day, month, year);
  lcd.print(time);
  
  lcd.setCursor(5,2);
  sprintf(time,"%.2d:%.2d:%.2d",hour, minute, second);
  lcd.print(time);
  delay(1000);
}
