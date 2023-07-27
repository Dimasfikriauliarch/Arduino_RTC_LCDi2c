#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#include "RTClib.h"
RTC_DS1307 rtc;
int led = 9;
int potensio = A2;
char nama2hari[7][12] = {"Min", "Sen", "Sel", "Rab", "Kam", "Jum", "Sab"};
void setup () 
{
  Serial.begin(9600);
  lcd.begin (20,4);  // Set lcd 
  lcd.backlight();
  pinMode(led, OUTPUT);
   
if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }
if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}
void loop () 
{
int nilai = analogRead(potensio);
nilai = map(nilai,0,1023,0,255);
analogWrite(led,nilai);
Serial.print("nilai led: ");
Serial.print(nilai);
Serial.println();

    DateTime now = rtc.now();
    lcd.setCursor(0, 1);
    lcd.print("JAM:");
    lcd.print(" ");
    lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());
    lcd.print("  ");
    
    
    Serial.print("JAM: ");
    Serial.print(now.hour());
    Serial.print(":");
    Serial.print(now.minute());
    Serial.print(":");
    Serial.print(now.second());
    Serial.print(" ");
    


    lcd.setCursor(0, 0);
    lcd.print("Tanggal:");
    lcd.print(" ");
    lcd.print(now.day());
    lcd.print('-');
    lcd.print(now.month());
    lcd.print('-');
    lcd.print(now.year());
    lcd.print("  ");   

    Serial.print("Tanggal: ");
    Serial.print(now.day());
    Serial.print(":");
    Serial.print(now.month());
    Serial.print(":");
    Serial.print(now.year());
    Serial.print(" ");
    Serial.println();
    delay(1000);
}
