/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 modified 7 Nov 2016
 by Arturo Guadalupi

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/LiquidCrystalHelloWorld

*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, touchSensor=7;
int touchy=0;
int etattouchy=0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// Leds
// Led Greed
const int lG = 6;
// led RED
const int lR = 8;
//led Yzllow
const int lY = 9;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  pinMode(touchSensor,INPUT);

  pinMode(lG, OUTPUT); //lG est une broche de sortie
  pinMode(lR, OUTPUT); //lR est une broche de sortie
  pinMode(lY, OUTPUT); //lY est une broche de sortie
}


void loop()
{
touchy = digitalRead(touchSensor); // This var is =1 when you press the touchSensor
if (touchy == 1 && etattouchy ==0)
                   {
                  lcd.clear();
                  lcd.setCursor(0,0); // Sets the cursor to col 0 and row 0
                  lcd.print("touchy active "); // Prints Sensor Val: to LCD
                 
                  etattouchy =1;
                  delay(1000);
                  }
                  else if (touchy == 1 && etattouchy ==1) 
                        {lcd.clear();
                        lcd.setCursor(0,0); // Sets the cursor to col 0 and row 0
                        lcd.print("touchy alone "); // Prints Sensor Val: to LCD
                        etattouchy=0;
                        delay(1000);
                        }
 if (etattouchy==1){   digitalWrite(lY, HIGH); //Turn on lY    
                  delay(1000);
                  digitalWrite(lY, LOW); //Turn off lY 
                  digitalWrite(lR, HIGH); //Turn on lR  
                  delay(1000);
                  digitalWrite(lR, LOW); //Turn off lR
                  digitalWrite(lG, HIGH); //Turn on  lG
                  delay(1000);
                  digitalWrite(lG, LOW); //Turn off  lG 
                  }
                  
                  else {
                        digitalWrite(lY, LOW); //Turn off  lG
                        digitalWrite(lR, LOW); //Turn off  lG
                        digitalWrite(lG, LOW); //Turn off  lG
                        }                   
}  
