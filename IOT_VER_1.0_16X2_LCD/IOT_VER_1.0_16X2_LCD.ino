// install required library
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display(address is 0x27 and a  16x2 lcd attached)
void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0); // set cursor to 1st row
  lcd.print("Hello, LCD12C!"); // print      data in 1st row
  lcd.setCursor(2,1); // set cursor to 2nd row
  lcd.print("IDEAXA");// print data in 2nd row
  
}
void loop()
{
}
