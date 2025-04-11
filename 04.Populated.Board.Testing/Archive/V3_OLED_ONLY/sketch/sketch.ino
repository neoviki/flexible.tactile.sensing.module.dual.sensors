/*

Tested with my prototype flex BMP Split PCB, It works perfect. 
Hardware used : Arduino DUE


Tested With BMP It is working perfect

*/
#include "oled_display_lib_bmp_test.h"
#include <Arduino.h>
#include <Wire.h>
#include "SparkFunBMP384.h"
#define PIN_WIRE_SDA         (20u)
#define PIN_WIRE_SCL         (21u)

BMP384 pressureSensor;

//BMP384_I2C_ADDRESS_DEFAULT; // 0x77

//BMP384_I2C_ADDRESS_SECONDARY; // 0x76



//IC1
#define IC1 0x76
#define IC2 0x77


/*IC on top of the PCB I designed*/
#define IC_TOP    IC2

/*IC on bottom of the PCB I designed*/
#define IC_BOTTOM IC1

void status_bmp_top(int s)
{
  if(s == 1){
      print_oled_sensor_top(1);
  }else{
      print_oled_sensor_top(0);
  }
}

void status_bmp_bottom(int s)
{
  if(s == 1){
      print_oled_sensor_bottom(1);
  }else{
      print_oled_sensor_bottom(0);
  }
}


void test_bmp_top()
{
    int i;
    Wire.end();
    delay(300);
    Wire.begin();

    for(i=0;i<5;i++){
        if(pressureSensor.beginI2C(IC_TOP) != BMP3_OK){
          status_bmp_top(0);
        }else{
          status_bmp_top(1);	//SUCCESS
        }
        delay(100);
    }

    return;
}

void test_bmp_bottom()
{
    int i;
    Wire.end();
    delay(300);
    Wire.begin();

    for(i=0;i<5;i++){
        if(pressureSensor.beginI2C(IC_BOTTOM) != BMP3_OK){
            status_bmp_bottom(0);
        }else{
            status_bmp_bottom(1); //SUCCESS
        }
        delay(100);
    }

    return;
}

void setup()
{

    pinMode(21, OUTPUT);  
    
    for (int i = 0; i < 8; i++) {    
      digitalWrite(21, HIGH);    
      delayMicroseconds(3);    
      digitalWrite(21, LOW);    
      delayMicroseconds(3);  
    } 
    
    pinMode(21, INPUT);
    init_oled();
}

void loop()
{
	test_bmp_top();
	test_bmp_bottom(); 
}
