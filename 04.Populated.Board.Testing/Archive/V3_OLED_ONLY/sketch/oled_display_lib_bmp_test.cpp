/*Works Perfect
  Board: Arduino Due
  Display: 0.91 inch display, see the images for reference

  just change DISPLAY_ON_I2C to I2C0 or I2C1 to choose different I2C

*/

#include "oled_display_lib_bmp_test.h"
#include <U8g2lib.h>

#define DISPLAY_HORIZANTAL U8G2_R0
#define DISPLAY_VERTICAL   U8G2_R1

#define I2C0 U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C       /*SDA0, SCL0*/
#define I2C1 U8G2_SSD1306_128X32_UNIVISION_F_2ND_HW_I2C   /*SDA1, SCL1*/

//#define DISPLAY_ON_I2C I2C0
#define DISPLAY_ON_I2C I2C1

DISPLAY_ON_I2C u8g2(DISPLAY_HORIZANTAL);


void gotoxy(int x, int y , String text)
{
  u8g2.setFont( u8g2_font_helvB08_tr);
  u8g2.setCursor(x, y);
  u8g2.print(text);
  u8g2.sendBuffer();

}




void line1(String text)
{
  //gotoxy(5,12, text);
  gotoxy(25, 28, text);
  delay(100);
  clear_oled();
}

void line2(String text)
{
  //gotoxy(5,30, text);
  gotoxy(25, 28, text);
  delay(100);
  clear_oled();
}


void clear_oled()
{
  //u8g2.clearBuffer();
  //gotoxy(35, 28, "CLEAR");
  //delay(200);
  u8g2.clearBuffer();
  //gotoxy(20, 28, "TESTING");
  //delay(100);
  //u8g2.clearBuffer();

}

void print_oled_sensor_top(int s)
{
  if (s == 1) {
    line1("[ TOP ] -> [ PASS ]");
  } else {
    line1("[ TOP ] -> [ FAIL   ]");
  }

}

void print_oled_sensor_bottom(int s)
{
  if (s == 1) {
    line2("[ BOT ] -> [ PASS ]");
  } else {
    line2("[ BOT ] -> [ FAIL   ]");
  }

}


void init_oled()
{
  u8g2.begin();
}
