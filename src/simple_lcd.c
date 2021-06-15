// C language code write for Arduino 1.8.15/Ubuntu
// Run it from Arduino IDE 

#include <LiquidCrystal_I2C.h>        //import library neccessary for lcd-display

LiquidCrystal_I2C lcd(0x3F,16, 2);    // set lcd addres of device for 16 characters and 2 lines

void setup(){
  lcd.init();                         // initialization
  
  lcd.clear();                        // clear LCD screen
  lcd.backlight();                    // use background light to vivid display

  lcd.setCursor(1,0);                 // set defalut position for first word/sentence
  lcd.print("Cisco");                 // print word/sentence

  lcd.setCursor(1,1);                 // set defalut position for second word/sentence
  lcd.print("NTCIP");                 // print word/sentence
}

void loop(){                          // use it if you need continiously clearing and updating screen consistency
  
}