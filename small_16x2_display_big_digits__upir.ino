// simple project using Arduino UNO and 16x2 character display to display BIG DIGITS
// created by upir, 2023
// youtube channel: https://www.youtube.com/upir_upir

// FULL TUTORIAL: https://youtu.be/SXSujfeN_QI
// Source files: https://github.com/upiir/character_display_big_digits

// Links related to this project:
// 16x2 OLED Character Display IIC - https://s.click.aliexpress.com/e/_DBft6KH
// Arduino UNO - https://s.click.aliexpress.com/e/_AXDw1h
// Arduino breadboard prototyping shield - https://s.click.aliexpress.com/e/_ApbCwx
// 16x2 displays with IIC - https://s.click.aliexpress.com/e/_9Hl3JV
// 16x2 display with RGB backlight - https://s.click.aliexpress.com/e/_9wgpeb
// character creator - https://tusindfryd.github.io/screenduino/
// custom characters simplest project - https://wokwi.com/projects/294395602645549578
// Character map: https://docs.wokwi.com/parts/wokwi-lcd1602#font


// My other videos with 16x2 character display:
// Arduino Gauge in 11 Minutes - https://youtu.be/upE17NHrdPc
// Smooth Arduino 16x2 Gauge - https://youtu.be/cx9CoGqpsfg
// DIY Battery Indicator - https://youtu.be/Mq0WBPKGRew
// 1 DISPLAY 3 SENSORS - https://youtu.be/lj_7UmM0EPY





#include <LiquidCrystal_I2C.h>     // if you don´t have I2C version of the display, use LiquidCrystal.h library instead

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
//LiquidCrystal_I2C lcd(0x3f,16,2);    // set the LCD address to 0x3f for a 16 chars and 2 line display
// if you don´t know the I2C address of the display, use I2C scanner first (https://playground.arduino.cc/Main/I2cScanner/)



// most of the code below is generated from Excel, please see video / GitHub for details
// ------------------------------------------------------------------------------------------------------

// current_font_digits is storing 4 parts for every digit, this array is only needed once in the sketch
byte current_font_digits[10][4];
byte buffer[8];

// ------------------------------------------------------------------------------------------------------
// code below is auto generated from Excel spreadsheet


// set eight special characters for the font: real   - updated to be stored in program memory to save some space
const byte real_00[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte real_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 2/8
const byte real_02[8] PROGMEM = {B11100,B00010,B00010,B00001,B00001,B00010,B00010,B11100}; // bits for special character 3/8
const byte real_03[8] PROGMEM = {B00111,B01000,B01000,B10000,B10000,B01000,B01000,B00111}; // bits for special character 4/8
const byte real_04[8] PROGMEM = {B11100,B00100,B00100,B00100,B01000,B01000,B10000,B10000}; // bits for special character 5/8
const byte real_05[8] PROGMEM = {B10000,B10000,B10000,B10000,B10000,B10000,B10000,B10000}; // bits for special character 6/8
const byte real_06[8] PROGMEM = {B10000,B10000,B10000,B10000,B10000,B01000,B01000,B00111}; // bits for special character 7/8
const byte real_07[8] PROGMEM = {B00011,B00100,B00100,B01000,B01000,B10000,B10000,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte real_digits[10][4] = { {254,254,3,2}, { 254,5,254,5}, { 0,2,3,1}, { 0,2,1,2}, { 7,1,254,5}, { 7,0,1,2}, { 7,0,6,2}, { 0,4,254,5}, { 3,2,3,2}, { 3,2,1,4 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_real () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = real_digits[i][j];
  }
 }
 memcpy_P(buffer,real_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,real_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,real_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,real_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,real_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,real_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,real_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,real_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: real_bold   - updated to be stored in program memory to save some space
const byte real_bold_00[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte real_bold_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 2/8
const byte real_bold_02[8] PROGMEM = {B11100,B01110,B00110,B00111,B00111,B00110,B01110,B11100}; // bits for special character 3/8
const byte real_bold_03[8] PROGMEM = {B00111,B01110,B01100,B11100,B11100,B01100,B01110,B00111}; // bits for special character 4/8
const byte real_bold_04[8] PROGMEM = {B11110,B00110,B00110,B00110,B01100,B01100,B11000,B11000}; // bits for special character 5/8
const byte real_bold_05[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11000}; // bits for special character 6/8
const byte real_bold_06[8] PROGMEM = {B11000,B11000,B11000,B11000,B11100,B01100,B01110,B00111}; // bits for special character 7/8
const byte real_bold_07[8] PROGMEM = {B00011,B00110,B00110,B01100,B01100,B11000,B11000,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte real_bold_digits[10][4] = { {254,254,3,2}, { 254,5,254,5}, { 0,2,3,1}, { 0,2,1,2}, { 7,1,254,5}, { 7,0,1,2}, { 7,0,6,2}, { 0,4,254,5}, { 3,2,3,2}, { 3,2,1,4 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_real_bold () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = real_bold_digits[i][j];
  }
 }
 memcpy_P(buffer,real_bold_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,real_bold_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,real_bold_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,real_bold_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,real_bold_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,real_bold_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,real_bold_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,real_bold_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: rounded   - updated to be stored in program memory to save some space
const byte rounded_00[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte rounded_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 2/8
const byte rounded_02[8] PROGMEM = {B11100,B00010,B00001,B00001,B00001,B00001,B00010,B11100}; // bits for special character 3/8
const byte rounded_03[8] PROGMEM = {B00111,B01000,B10000,B10000,B10000,B10000,B01000,B00111}; // bits for special character 4/8
const byte rounded_04[8] PROGMEM = {B00000,B00000,B00000,B10000,B10000,B10000,B10000,B11111}; // bits for special character 5/8
const byte rounded_05[8] PROGMEM = {B10000,B10000,B10000,B10000,B10000,B10000,B10000,B10000}; // bits for special character 6/8
const byte rounded_06[8] PROGMEM = {B00001,B00010,B00100,B01000,B00000,B00000,B00000,B00000}; // bits for special character 7/8
const byte rounded_07[8] PROGMEM = {B10000,B10000,B10000,B10000,B10000,B01000,B00100,B00011}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte rounded_digits[10][4] = { {254,254,3,2}, { 6,5,254,5}, { 0,2,3,1}, { 0,2,1,2}, { 7,4,254,5}, { 3,0,1,2}, { 3,0,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,1,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_rounded () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = rounded_digits[i][j];
  }
 }
 memcpy_P(buffer,rounded_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,rounded_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,rounded_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,rounded_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,rounded_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,rounded_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,rounded_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,rounded_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: rounded_bold   - updated to be stored in program memory to save some space
const byte rounded_bold_00[8] PROGMEM = {B11111,B11111,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte rounded_bold_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B11111,B11111}; // bits for special character 2/8
const byte rounded_bold_02[8] PROGMEM = {B11100,B11110,B00111,B00011,B00011,B00111,B11110,B11100}; // bits for special character 3/8
const byte rounded_bold_03[8] PROGMEM = {B00111,B01111,B11100,B11000,B11000,B11100,B01111,B00111}; // bits for special character 4/8
const byte rounded_bold_04[8] PROGMEM = {B00000,B00000,B00000,B11000,B11000,B11000,B11111,B11111}; // bits for special character 5/8
const byte rounded_bold_05[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11000}; // bits for special character 6/8
const byte rounded_bold_06[8] PROGMEM = {B00011,B00111,B01110,B01100,B00000,B00000,B00000,B00000}; // bits for special character 7/8
const byte rounded_bold_07[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B01100,B00111,B00011}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte rounded_bold_digits[10][4] = { {254,254,3,2}, { 6,5,254,5}, { 0,2,3,1}, { 0,2,1,2}, { 7,4,254,5}, { 3,0,1,2}, { 3,0,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,1,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_rounded_bold () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = rounded_bold_digits[i][j];
  }
 }
 memcpy_P(buffer,rounded_bold_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,rounded_bold_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,rounded_bold_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,rounded_bold_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,rounded_bold_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,rounded_bold_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,rounded_bold_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,rounded_bold_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: skewed   - updated to be stored in program memory to save some space
const byte skewed_00[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte skewed_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 2/8
const byte skewed_02[8] PROGMEM = {B11111,B00001,B00001,B00001,B00010,B00100,B01000,B10000}; // bits for special character 3/8
const byte skewed_03[8] PROGMEM = {B00001,B00010,B00100,B01000,B10000,B10000,B10000,B11111}; // bits for special character 4/8
const byte skewed_04[8] PROGMEM = {B11111,B10000,B10000,B10000,B10000,B10000,B10000,B11111}; // bits for special character 5/8
const byte skewed_05[8] PROGMEM = {B10000,B10000,B10000,B10000,B10000,B10000,B10000,B10000}; // bits for special character 6/8
const byte skewed_06[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 7/8
const byte skewed_07[8] PROGMEM = {B11111,B10000,B10000,B10000,B10000,B10000,B10000,B10000}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte skewed_digits[10][4] = { {254,254,4,2}, { 254,5,254,5}, { 0,2,3,1}, { 0,2,1,2}, { 3,1,254,5}, { 7,0,6,2}, { 7,0,4,2}, { 0,2,254,5}, { 4,2,4,2}, { 7,2,0,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_skewed () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = skewed_digits[i][j];
  }
 }
 memcpy_P(buffer,skewed_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,skewed_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,skewed_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,skewed_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,skewed_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,skewed_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,skewed_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,skewed_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: skewed_bold   - updated to be stored in program memory to save some space
const byte skewed_bold_00[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte skewed_bold_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 2/8
const byte skewed_bold_02[8] PROGMEM = {B11111,B00011,B00011,B00011,B00010,B00100,B01000,B10000}; // bits for special character 3/8
const byte skewed_bold_03[8] PROGMEM = {B00001,B00010,B00100,B01000,B11000,B11000,B11000,B11111}; // bits for special character 4/8
const byte skewed_bold_04[8] PROGMEM = {B11111,B11000,B11000,B11000,B11000,B11000,B11000,B11111}; // bits for special character 5/8
const byte skewed_bold_05[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11000}; // bits for special character 6/8
const byte skewed_bold_06[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 7/8
const byte skewed_bold_07[8] PROGMEM = {B11111,B11000,B11000,B11000,B11000,B11000,B11000,B11000}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte skewed_bold_digits[10][4] = { {254,254,4,2}, { 254,5,254,5}, { 0,2,3,1}, { 0,2,1,2}, { 3,1,254,5}, { 7,0,6,2}, { 7,0,4,2}, { 0,2,254,5}, { 4,2,4,2}, { 7,2,0,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_skewed_bold () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = skewed_bold_digits[i][j];
  }
 }
 memcpy_P(buffer,skewed_bold_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,skewed_bold_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,skewed_bold_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,skewed_bold_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,skewed_bold_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,skewed_bold_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,skewed_bold_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,skewed_bold_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: dots_small   - updated to be stored in program memory to save some space
const byte dots_small_00[8] PROGMEM = {B10101,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte dots_small_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B10101}; // bits for special character 2/8
const byte dots_small_02[8] PROGMEM = {B10101,B00000,B00001,B00000,B00000,B00001,B00000,B10101}; // bits for special character 3/8
const byte dots_small_03[8] PROGMEM = {B10101,B00000,B10000,B00000,B00000,B10000,B00000,B10101}; // bits for special character 4/8
const byte dots_small_04[8] PROGMEM = {B10101,B00000,B10000,B00000,B00000,B10000,B00000,B10000}; // bits for special character 5/8
const byte dots_small_05[8] PROGMEM = {B10000,B00000,B10000,B00000,B00000,B10000,B00000,B10000}; // bits for special character 6/8
const byte dots_small_06[8] PROGMEM = {B10101,B00000,B00000,B00000,B00000,B00000,B00000,B10101}; // bits for special character 7/8
const byte dots_small_07[8] PROGMEM = {B10000,B00000,B10000,B00000,B00000,B10000,B00000,B10101}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte dots_small_digits[10][4] = { {4,5,7,5}, { 254,5,254,5}, { 6,2,3,6}, { 0,2,1,2}, { 7,1,254,5}, { 3,6,6,2}, { 3,6,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,6,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_dots_small () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = dots_small_digits[i][j];
  }
 }
 memcpy_P(buffer,dots_small_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,dots_small_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,dots_small_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,dots_small_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,dots_small_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,dots_small_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,dots_small_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,dots_small_07, 8);
 lcd.createChar(7 , buffer);
}






// set eight special characters for the font: dots_big   - updated to be stored in program memory to save some space
const byte dots_big_00[8] PROGMEM = {B11011,B11011,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte dots_big_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B11011,B11011}; // bits for special character 2/8
const byte dots_big_02[8] PROGMEM = {B11011,B11011,B00000,B00011,B00011,B00000,B11011,B11011}; // bits for special character 3/8
const byte dots_big_03[8] PROGMEM = {B11011,B11011,B00000,B11000,B11000,B00000,B11011,B11011}; // bits for special character 4/8
const byte dots_big_04[8] PROGMEM = {B11011,B11011,B00000,B11000,B11000,B00000,B11000,B11000}; // bits for special character 5/8
const byte dots_big_05[8] PROGMEM = {B11000,B11000,B00000,B11000,B11000,B00000,B11000,B11000}; // bits for special character 6/8
const byte dots_big_06[8] PROGMEM = {B11011,B11011,B00000,B00000,B00000,B00000,B11011,B11011}; // bits for special character 7/8
const byte dots_big_07[8] PROGMEM = {B11000,B11000,B00000,B11000,B11000,B00000,B11011,B11011}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte dots_big_digits[10][4] = { {4,5,7,5}, { 254,5,254,5}, { 6,2,3,6}, { 0,2,1,2}, { 7,1,254,5}, { 3,6,6,2}, { 3,6,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,6,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_dots_big () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = dots_big_digits[i][j];
  }
 }
 memcpy_P(buffer,dots_big_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,dots_big_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,dots_big_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,dots_big_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,dots_big_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,dots_big_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,dots_big_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,dots_big_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: dashed   - updated to be stored in program memory to save some space
const byte dashed_00[8] PROGMEM = {B11011,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte dashed_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11011}; // bits for special character 2/8
const byte dashed_02[8] PROGMEM = {B11011,B00001,B00000,B00001,B00001,B00000,B00001,B11011}; // bits for special character 3/8
const byte dashed_03[8] PROGMEM = {B11011,B10000,B00000,B10000,B10000,B00000,B10000,B11011}; // bits for special character 4/8
const byte dashed_04[8] PROGMEM = {B11011,B10000,B00000,B10000,B10000,B00000,B10000,B10000}; // bits for special character 5/8
const byte dashed_05[8] PROGMEM = {B10000,B10000,B00000,B10000,B10000,B00000,B10000,B10000}; // bits for special character 6/8
const byte dashed_06[8] PROGMEM = {B11011,B00000,B00000,B00000,B00000,B00000,B00000,B11011}; // bits for special character 7/8
const byte dashed_07[8] PROGMEM = {B10000,B10000,B00000,B10000,B10000,B00000,B10000,B11011}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte dashed_digits[10][4] = { {4,5,7,5}, { 254,5,254,5}, { 6,2,3,6}, { 0,2,1,2}, { 7,1,254,5}, { 3,6,6,2}, { 3,6,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,6,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_dashed () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = dashed_digits[i][j];
  }
 }
 memcpy_P(buffer,dashed_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,dashed_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,dashed_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,dashed_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,dashed_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,dashed_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,dashed_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,dashed_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: dashed_bold   - updated to be stored in program memory to save some space
const byte dashed_bold_00[8] PROGMEM = {B11011,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte dashed_bold_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11011}; // bits for special character 2/8
const byte dashed_bold_02[8] PROGMEM = {B11011,B00011,B00000,B00011,B00011,B00000,B00011,B11011}; // bits for special character 3/8
const byte dashed_bold_03[8] PROGMEM = {B11011,B11000,B00000,B11000,B11000,B00000,B11000,B11011}; // bits for special character 4/8
const byte dashed_bold_04[8] PROGMEM = {B11011,B11000,B00000,B11000,B11000,B00000,B11000,B11000}; // bits for special character 5/8
const byte dashed_bold_05[8] PROGMEM = {B11000,B11000,B00000,B11000,B11000,B00000,B11000,B11000}; // bits for special character 6/8
const byte dashed_bold_06[8] PROGMEM = {B11011,B00000,B00000,B00000,B00000,B00000,B00000,B11011}; // bits for special character 7/8
const byte dashed_bold_07[8] PROGMEM = {B11000,B11000,B00000,B11000,B11000,B00000,B11000,B11011}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte dashed_bold_digits[10][4] = { {4,5,7,5}, { 254,5,254,5}, { 6,2,3,6}, { 0,2,1,2}, { 7,1,254,5}, { 3,6,6,2}, { 3,6,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,6,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_dashed_bold () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = dashed_bold_digits[i][j];
  }
 }
 memcpy_P(buffer,dashed_bold_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,dashed_bold_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,dashed_bold_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,dashed_bold_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,dashed_bold_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,dashed_bold_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,dashed_bold_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,dashed_bold_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: angled   - updated to be stored in program memory to save some space
const byte angled_00[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte angled_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 2/8
const byte angled_02[8] PROGMEM = {B11111,B00001,B00001,B00001,B00001,B00001,B00001,B11111}; // bits for special character 3/8
const byte angled_03[8] PROGMEM = {B11111,B10000,B10000,B10000,B10000,B10000,B10000,B11111}; // bits for special character 4/8
const byte angled_04[8] PROGMEM = {B11111,B00001,B00001,B00001,B00001,B00001,B00001,B00001}; // bits for special character 5/8
const byte angled_05[8] PROGMEM = {B10000,B10000,B10000,B10000,B10000,B10000,B10000,B10000}; // bits for special character 6/8
const byte angled_06[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 7/8
const byte angled_07[8] PROGMEM = {B00001,B00001,B00001,B00001,B00001,B00001,B00001,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte angled_digits[10][4] = { {254,254,3,2}, { 254,5,254,5}, { 0,4,3,6}, { 0,4,1,2}, { 3,1,254,5}, { 3,0,1,2}, { 5,254,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,254,7 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_angled () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = angled_digits[i][j];
  }
 }
 memcpy_P(buffer,angled_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,angled_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,angled_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,angled_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,angled_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,angled_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,angled_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,angled_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: angled_bold   - updated to be stored in program memory to save some space
const byte angled_bold_00[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte angled_bold_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 2/8
const byte angled_bold_02[8] PROGMEM = {B11111,B00011,B00011,B00011,B00011,B00011,B00011,B11111}; // bits for special character 3/8
const byte angled_bold_03[8] PROGMEM = {B11111,B11000,B11000,B11000,B11000,B11000,B11000,B11111}; // bits for special character 4/8
const byte angled_bold_04[8] PROGMEM = {B11111,B00011,B00011,B00011,B00011,B00011,B00011,B00011}; // bits for special character 5/8
const byte angled_bold_05[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11000}; // bits for special character 6/8
const byte angled_bold_06[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 7/8
const byte angled_bold_07[8] PROGMEM = {B00011,B00011,B00011,B00011,B00011,B00011,B00011,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte angled_bold_digits[10][4] = { {254,254,3,2}, { 254,5,254,5}, { 0,4,3,6}, { 0,4,1,2}, { 3,1,254,5}, { 3,0,1,2}, { 5,254,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,254,7 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_angled_bold () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = angled_bold_digits[i][j];
  }
 }
 memcpy_P(buffer,angled_bold_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,angled_bold_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,angled_bold_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,angled_bold_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,angled_bold_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,angled_bold_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,angled_bold_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,angled_bold_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: blocks   - updated to be stored in program memory to save some space
const byte blocks_00[8] PROGMEM = {B11111,B11111,B11111,B11111,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte blocks_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B11111,B11111,B11111,B11111}; // bits for special character 2/8
const byte blocks_02[8] PROGMEM = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B00000}; // bits for special character 3/8
const byte blocks_03[8] PROGMEM = {B00000,B11111,B11111,B11111,B11111,B11111,B11111,B11111}; // bits for special character 4/8
const byte blocks_04[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 5/8
const byte blocks_05[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 6/8
const byte blocks_06[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 7/8
const byte blocks_07[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte blocks_digits[10][4] = { {255,255,255,255}, { 254,255,254,255}, { 0,255,255,1}, { 0,255,1,255}, { 255,1,254,255}, { 255,0,1,255}, { 255,0,255,255}, { 0,255,254,255}, { 2,2,3,3}, { 255,255,1,255 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_blocks () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = blocks_digits[i][j];
  }
 }
 memcpy_P(buffer,blocks_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,blocks_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,blocks_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,blocks_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,blocks_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,blocks_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,blocks_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,blocks_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: blocks_crossed   - updated to be stored in program memory to save some space
const byte blocks_crossed_00[8] PROGMEM = {B11111,B11111,B11111,B11111,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte blocks_crossed_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B11111,B11111,B11111,B11111}; // bits for special character 2/8
const byte blocks_crossed_02[8] PROGMEM = {B11110,B11101,B11011,B10111,B01111,B11111,B11111,B11111}; // bits for special character 3/8
const byte blocks_crossed_03[8] PROGMEM = {B11111,B11111,B11111,B11111,B11110,B11101,B11111,B11111}; // bits for special character 4/8
const byte blocks_crossed_04[8] PROGMEM = {B11111,B11111,B10111,B01111,B11111,B11111,B11111,B11111}; // bits for special character 5/8
const byte blocks_crossed_05[8] PROGMEM = {B11111,B11111,B11111,B11110,B11101,B11011,B10111,B01111}; // bits for special character 6/8
const byte blocks_crossed_06[8] PROGMEM = {B11110,B11101,B11111,B11111,B11111,B11111,B11111,B11111}; // bits for special character 7/8
const byte blocks_crossed_07[8] PROGMEM = {B11111,B11111,B11111,B11111,B11111,B11111,B10111,B01111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte blocks_crossed_digits[10][4] = { {255,7,6,255}, { 254,2,254,255}, { 0,255,2,1}, { 0,5,1,255}, { 2,1,254,255}, { 255,0,1,2}, { 255,0,3,4}, { 0,255,254,5}, { 3,4,3,4}, { 3,4,1,255 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_blocks_crossed () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = blocks_crossed_digits[i][j];
  }
 }
 memcpy_P(buffer,blocks_crossed_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,blocks_crossed_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,blocks_crossed_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,blocks_crossed_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,blocks_crossed_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,blocks_crossed_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,blocks_crossed_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,blocks_crossed_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: blocks_cut   - updated to be stored in program memory to save some space
const byte blocks_cut_00[8] PROGMEM = {B11111,B11111,B11111,B11111,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte blocks_cut_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B11111,B11111,B11111,B11111}; // bits for special character 2/8
const byte blocks_cut_02[8] PROGMEM = {B00001,B00011,B00111,B01111,B11111,B11111,B11111,B11111}; // bits for special character 3/8
const byte blocks_cut_03[8] PROGMEM = {B11111,B11111,B11111,B11111,B01111,B00111,B00011,B00001}; // bits for special character 4/8
const byte blocks_cut_04[8] PROGMEM = {B10000,B11000,B11100,B11110,B11111,B11111,B11111,B11111}; // bits for special character 5/8
const byte blocks_cut_05[8] PROGMEM = {B11111,B11111,B11111,B11111,B11110,B11100,B11000,B10000}; // bits for special character 6/8
const byte blocks_cut_06[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00001,B00011,B00111}; // bits for special character 7/8
const byte blocks_cut_07[8] PROGMEM = {B11100,B11000,B10000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte blocks_cut_digits[10][4] = { {2,255,255,5}, { 254,2,254,255}, { 0,5,2,1}, { 0,255,1,5}, { 2,1,254,255}, { 255,0,1,5}, { 2,7,255,5}, { 0,255,254,5}, { 255,5,2,255}, { 2,255,6,5 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_blocks_cut () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = blocks_cut_digits[i][j];
  }
 }
 memcpy_P(buffer,blocks_cut_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,blocks_cut_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,blocks_cut_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,blocks_cut_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,blocks_cut_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,blocks_cut_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,blocks_cut_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,blocks_cut_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: classic   - updated to be stored in program memory to save some space
const byte classic_00[8] PROGMEM = {B11111,B11000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte classic_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B11000,B11111}; // bits for special character 2/8
const byte classic_02[8] PROGMEM = {B11111,B00011,B00011,B00011,B00011,B00011,B00011,B11111}; // bits for special character 3/8
const byte classic_03[8] PROGMEM = {B11111,B11000,B11000,B11000,B11000,B11000,B11000,B11111}; // bits for special character 4/8
const byte classic_04[8] PROGMEM = {B00001,B00010,B00100,B00000,B00000,B00000,B00000,B00000}; // bits for special character 5/8
const byte classic_05[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11000}; // bits for special character 6/8
const byte classic_06[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 7/8
const byte classic_07[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte classic_digits[10][4] = { {254,254,3,2}, { 4,5,254,5}, { 6,2,3,6}, { 0,2,1,2}, { 7,1,254,5}, { 3,6,6,2}, { 3,6,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,6,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_classic () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = classic_digits[i][j];
  }
 }
 memcpy_P(buffer,classic_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,classic_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,classic_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,classic_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,classic_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,classic_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,classic_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,classic_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: classic_bold   - updated to be stored in program memory to save some space
const byte classic_bold_00[8] PROGMEM = {B11111,B11000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte classic_bold_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B11000,B11111}; // bits for special character 2/8
const byte classic_bold_02[8] PROGMEM = {B11111,B00111,B00111,B00111,B00111,B00111,B00111,B11111}; // bits for special character 3/8
const byte classic_bold_03[8] PROGMEM = {B11111,B11100,B11100,B11100,B11100,B11100,B11100,B11111}; // bits for special character 4/8
const byte classic_bold_04[8] PROGMEM = {B00001,B00011,B00111,B00000,B00000,B00000,B00000,B00000}; // bits for special character 5/8
const byte classic_bold_05[8] PROGMEM = {B11100,B11100,B11100,B11100,B11100,B11100,B11100,B11100}; // bits for special character 6/8
const byte classic_bold_06[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 7/8
const byte classic_bold_07[8] PROGMEM = {B11100,B11100,B11100,B11100,B11100,B11100,B11100,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte classic_bold_digits[10][4] = { {254,254,3,2}, { 4,5,254,5}, { 6,2,3,6}, { 0,2,1,2}, { 7,1,254,5}, { 3,6,6,2}, { 3,6,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,6,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_classic_bold () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = classic_bold_digits[i][j];
  }
 }
 memcpy_P(buffer,classic_bold_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,classic_bold_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,classic_bold_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,classic_bold_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,classic_bold_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,classic_bold_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,classic_bold_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,classic_bold_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: classic_serif   - updated to be stored in program memory to save some space
const byte classic_serif_00[8] PROGMEM = {B11111,B11111,B11000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte classic_serif_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B11000,B11111,B11111}; // bits for special character 2/8
const byte classic_serif_02[8] PROGMEM = {B11111,B00011,B00011,B00011,B00011,B00011,B00011,B11111}; // bits for special character 3/8
const byte classic_serif_03[8] PROGMEM = {B11111,B11000,B11000,B11000,B11000,B11000,B11000,B11111}; // bits for special character 4/8
const byte classic_serif_04[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B11111,B11111}; // bits for special character 5/8
const byte classic_serif_05[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11000}; // bits for special character 6/8
const byte classic_serif_06[8] PROGMEM = {B11111,B11111,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 7/8
const byte classic_serif_07[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte classic_serif_digits[10][4] = { {254,254,3,2}, { 254,5,254,5}, { 6,2,3,4}, { 0,2,1,2}, { 7,1,254,5}, { 3,6,4,2}, { 3,6,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,4,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_classic_serif () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = classic_serif_digits[i][j];
  }
 }
 memcpy_P(buffer,classic_serif_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,classic_serif_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,classic_serif_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,classic_serif_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,classic_serif_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,classic_serif_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,classic_serif_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,classic_serif_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: tron   - updated to be stored in program memory to save some space
const byte tron_00[8] PROGMEM = {B11111,B11000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte tron_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B11000,B11111}; // bits for special character 2/8
const byte tron_02[8] PROGMEM = {B11111,B00011,B00011,B00011,B00011,B00011,B00011,B00011}; // bits for special character 3/8
const byte tron_03[8] PROGMEM = {B11111,B11000,B11000,B11000,B11000,B11000,B11000,B11111}; // bits for special character 4/8
const byte tron_04[8] PROGMEM = {B11111,B11000,B11000,B11000,B11000,B11000,B11000,B11000}; // bits for special character 5/8
const byte tron_05[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11000}; // bits for special character 6/8
const byte tron_06[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 7/8
const byte tron_07[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte tron_digits[10][4] = { {4,2,7,255}, { 254,5,254,5}, { 0,2,3,6}, { 0,2,1,255}, { 7,1,254,5}, { 3,6,1,255}, { 3,6,3,255}, { 0,2,254,5}, { 3,2,3,255}, { 3,2,254,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_tron () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = tron_digits[i][j];
  }
 }
 memcpy_P(buffer,tron_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,tron_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,tron_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,tron_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,tron_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,tron_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,tron_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,tron_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: tron_bold   - updated to be stored in program memory to save some space
const byte tron_bold_00[8] PROGMEM = {B11111,B11000,B00000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte tron_bold_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B00000,B11000,B11111}; // bits for special character 2/8
const byte tron_bold_02[8] PROGMEM = {B11111,B00111,B00111,B00111,B00111,B00111,B00111,B00111}; // bits for special character 3/8
const byte tron_bold_03[8] PROGMEM = {B11111,B11100,B11100,B11100,B11100,B11100,B11100,B11111}; // bits for special character 4/8
const byte tron_bold_04[8] PROGMEM = {B11111,B11100,B11100,B11100,B11100,B11100,B11100,B11100}; // bits for special character 5/8
const byte tron_bold_05[8] PROGMEM = {B11100,B11100,B11100,B11100,B11100,B11100,B11100,B11100}; // bits for special character 6/8
const byte tron_bold_06[8] PROGMEM = {B11111,B00000,B00000,B00000,B00000,B00000,B00000,B11111}; // bits for special character 7/8
const byte tron_bold_07[8] PROGMEM = {B11100,B11100,B11100,B11100,B11100,B11100,B11100,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte tron_bold_digits[10][4] = { {4,2,7,255}, { 254,5,254,5}, { 0,2,3,6}, { 0,2,1,255}, { 7,1,254,5}, { 3,6,1,255}, { 3,6,3,255}, { 0,2,254,5}, { 3,2,3,255}, { 3,2,254,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_tron_bold () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = tron_bold_digits[i][j];
  }
 }
 memcpy_P(buffer,tron_bold_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,tron_bold_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,tron_bold_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,tron_bold_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,tron_bold_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,tron_bold_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,tron_bold_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,tron_bold_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: square_two   - updated to be stored in program memory to save some space
const byte square_two_00[8] PROGMEM = {B11111,B11111,B11000,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte square_two_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B11000,B11111,B11111}; // bits for special character 2/8
const byte square_two_02[8] PROGMEM = {B11111,B11111,B00011,B00011,B00011,B00011,B11111,B11111}; // bits for special character 3/8
const byte square_two_03[8] PROGMEM = {B11111,B11111,B11000,B11000,B11000,B11000,B11111,B11111}; // bits for special character 4/8
const byte square_two_04[8] PROGMEM = {B00001,B00011,B00111,B00000,B00000,B00000,B00000,B00000}; // bits for special character 5/8
const byte square_two_05[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B11000,B11000,B11000}; // bits for special character 6/8
const byte square_two_06[8] PROGMEM = {B11111,B11111,B00000,B00000,B00000,B00000,B11111,B11111}; // bits for special character 7/8
const byte square_two_07[8] PROGMEM = {B11000,B11000,B11000,B11000,B11000,B11000,B11111,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte square_two_digits[10][4] = { {254,254,3,2}, { 4,5,254,5}, { 6,2,3,6}, { 0,2,1,2}, { 7,1,254,5}, { 3,6,6,2}, { 3,6,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,6,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_square_two () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = square_two_digits[i][j];
  }
 }
 memcpy_P(buffer,square_two_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,square_two_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,square_two_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,square_two_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,square_two_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,square_two_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,square_two_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,square_two_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: square_three   - updated to be stored in program memory to save some space
const byte square_three_00[8] PROGMEM = {B11111,B11111,B11100,B00000,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte square_three_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B00000,B11100,B11111,B11111}; // bits for special character 2/8
const byte square_three_02[8] PROGMEM = {B11111,B11111,B00111,B00111,B00111,B00111,B11111,B11111}; // bits for special character 3/8
const byte square_three_03[8] PROGMEM = {B11111,B11111,B11100,B11100,B11100,B11100,B11111,B11111}; // bits for special character 4/8
const byte square_three_04[8] PROGMEM = {B00001,B00011,B00111,B01111,B00000,B00000,B00000,B00000}; // bits for special character 5/8
const byte square_three_05[8] PROGMEM = {B11100,B11100,B11100,B11100,B11100,B11100,B11100,B11100}; // bits for special character 6/8
const byte square_three_06[8] PROGMEM = {B11111,B11111,B00000,B00000,B00000,B00000,B11111,B11111}; // bits for special character 7/8
const byte square_three_07[8] PROGMEM = {B11100,B11100,B11100,B11100,B11100,B11100,B11111,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte square_three_digits[10][4] = { {255,255,3,2}, { 4,5,254,5}, { 6,2,3,6}, { 0,2,1,2}, { 7,1,254,5}, { 3,6,6,2}, { 3,6,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,6,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_square_three () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = square_three_digits[i][j];
  }
 }
 memcpy_P(buffer,square_three_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,square_three_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,square_three_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,square_three_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,square_three_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,square_three_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,square_three_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,square_three_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: square_four   - updated to be stored in program memory to save some space
const byte square_four_00[8] PROGMEM = {B11111,B11111,B11100,B11100,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte square_four_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B11100,B11100,B11111,B11111}; // bits for special character 2/8
const byte square_four_02[8] PROGMEM = {B11111,B11111,B01111,B01111,B01111,B01111,B11111,B11111}; // bits for special character 3/8
const byte square_four_03[8] PROGMEM = {B11111,B11111,B11110,B11110,B11110,B11110,B11111,B11111}; // bits for special character 4/8
const byte square_four_04[8] PROGMEM = {B00001,B00011,B00111,B01111,B00000,B00000,B00000,B00000}; // bits for special character 5/8
const byte square_four_05[8] PROGMEM = {B11110,B11110,B11110,B11110,B11110,B11110,B11110,B11110}; // bits for special character 6/8
const byte square_four_06[8] PROGMEM = {B11111,B11111,B00000,B00000,B00000,B00000,B11111,B11111}; // bits for special character 7/8
const byte square_four_07[8] PROGMEM = {B11110,B11110,B11110,B11110,B11110,B11110,B11111,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte square_four_digits[10][4] = { {255,255,3,2}, { 4,5,254,5}, { 6,2,3,6}, { 0,2,1,2}, { 7,1,254,5}, { 3,6,6,2}, { 3,6,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,6,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_square_four () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = square_four_digits[i][j];
  }
 }
 memcpy_P(buffer,square_four_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,square_four_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,square_four_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,square_four_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,square_four_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,square_four_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,square_four_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,square_four_07, 8);
 lcd.createChar(7 , buffer);
}




// set eight special characters for the font: square_five   - updated to be stored in program memory to save some space
const byte square_five_00[8] PROGMEM = {B11111,B11111,B11111,B11100,B00000,B00000,B00000,B00000}; // bits for special character 1/8
const byte square_five_01[8] PROGMEM = {B00000,B00000,B00000,B00000,B11100,B11111,B11111,B11111}; // bits for special character 2/8
const byte square_five_02[8] PROGMEM = {B11111,B11111,B11111,B01111,B01111,B11111,B11111,B11111}; // bits for special character 3/8
const byte square_five_03[8] PROGMEM = {B11111,B11111,B11111,B11110,B11110,B11111,B11111,B11111}; // bits for special character 4/8
const byte square_five_04[8] PROGMEM = {B00001,B00011,B00111,B01111,B01111,B00000,B00000,B00000}; // bits for special character 5/8
const byte square_five_05[8] PROGMEM = {B11110,B11110,B11110,B11110,B11110,B11110,B11110,B11110}; // bits for special character 6/8
const byte square_five_06[8] PROGMEM = {B11111,B11111,B11111,B00000,B00000,B11111,B11111,B11111}; // bits for special character 7/8
const byte square_five_07[8] PROGMEM = {B11110,B11110,B11110,B11110,B11110,B11111,B11111,B11111}; // bits for special character 8/8

// special character used for the individual digits, each digit is made from 4 special characters. Character 254 is empty, character 255 is fully filled rectangle
byte square_five_digits[10][4] = { {255,255,3,2}, { 4,5,254,5}, { 6,2,3,6}, { 0,2,1,2}, { 7,1,254,5}, { 3,6,6,2}, { 3,6,3,2}, { 0,2,254,5}, { 3,2,3,2}, { 3,2,6,2 } };

// switch font = set special characters and populate current_font_digits with digits from the selected font
void set_font_square_five () {
 for (int i=0; i<10; i++) {
  for (int j=0; j<4; j++) {
   current_font_digits[i][j] = square_five_digits[i][j];
  }
 }
 memcpy_P(buffer,square_five_00, 8);
 lcd.createChar(0 , buffer);
 memcpy_P(buffer,square_five_01, 8);
 lcd.createChar(1 , buffer);
 memcpy_P(buffer,square_five_02, 8);
 lcd.createChar(2 , buffer);
 memcpy_P(buffer,square_five_03, 8);
 lcd.createChar(3 , buffer);
 memcpy_P(buffer,square_five_04, 8);
 lcd.createChar(4 , buffer);
 memcpy_P(buffer,square_five_05, 8);
 lcd.createChar(5 , buffer);
 memcpy_P(buffer,square_five_06, 8);
 lcd.createChar(6 , buffer);
 memcpy_P(buffer,square_five_07, 8);
 lcd.createChar(7 , buffer);
}




// ------------------------------------------------------------------------------------------------------
// end copy from Excel




// draw_big_digits is only needed once in the sketch
// this function draws a single digit on the xpos, ypos, taking 2x2 cells (using 4 special characters)
// before calling this function, make sure to set the font to populate the current_font_digits array and set special characters
void draw_big_digit(byte digit, byte xpos, byte ypos) {
  lcd.setCursor(xpos,ypos);           
  lcd.write(current_font_digits[digit][0]);
  lcd.write(current_font_digits[digit][1]);
  lcd.setCursor(xpos,ypos+1);           
  lcd.write(current_font_digits[digit][2]);
  lcd.write(current_font_digits[digit][3]);
}
// ------------------------------------------------------------------------------------------------------



void setup() {
  lcd.init();    // initialize the 16x2 lcd module
  lcd.backlight();  // enable backlight for the LCD module
}

int counter; // counter to switch between the fonts


void loop() {

  // switching between fonts
  // it´s done like this, because I thought that for a real project, you will only use perhaps one or two font styles and delete the rest

  counter++;
  if (counter > 24) {counter=1;}

  lcd.clear(); // clear LCD before switching font

  // set one of the 24 provided fonts...
  switch (counter) {
  case 1:
    set_font_real();
    break;
  case 2:
    set_font_real_bold();
    break;
  case 3:
    set_font_rounded();
    break;
  case 4:
    set_font_rounded_bold();
    break;
  case 5:
    set_font_skewed();
    break;
  case 6:
    set_font_skewed_bold();
    break;    
  case 7:
    set_font_dots_small();
    break;       
  case 8:
    set_font_dots_big();
    break;    
  case 9:
    set_font_dashed();
    break;   
  case 10:
    set_font_dashed_bold();
    break;    
  case 11:
    set_font_angled();
    break;     
  case 12:
    set_font_angled_bold();
    break;     
  case 13:
    set_font_blocks();
    break;   
  case 14:
    set_font_blocks_crossed();
    break;   
  case 15:
    set_font_blocks_cut();
    break;    
  case 16:
    set_font_classic();
    break;  
  case 17:
    set_font_classic_bold();
    break;  
  case 18:
    set_font_classic_serif();
    break;     
  case 19:
    set_font_tron();
    break; 
  case 20:
    set_font_tron_bold();
    break;                                             
  case 21:
    set_font_square_two();
    break;        
  case 22:
    set_font_square_three();
    break;        
  case 23:
    set_font_square_four();
    break;        
  case 24:
    set_font_square_five();
    break;                
  default:
    // if nothing else matches, do the default
    break;
}


  // draw five digits, wait a second, draw another five digits, wait a second, switch font, repeat... 
    
  draw_big_digit(0, 1, 0);  // draw digit 0
  draw_big_digit(1, 4, 0);  // draw digit 1
  draw_big_digit(2, 7, 0);  // draw digit 2
  draw_big_digit(3, 10, 0); // draw digit 3
  draw_big_digit(4, 13, 0); // draw digit 4
  
  delay(1000);  // wait one second
  
  draw_big_digit(5, 1, 0);  // draw digit 5
  draw_big_digit(6, 4, 0);  // draw digit 6
  draw_big_digit(7, 7, 0);  // draw digit 7
  draw_big_digit(8, 10, 0); // draw digit 8
  draw_big_digit(9, 13, 0); // draw digit 9
  
  delay(1000);  // wait one second

  

}
