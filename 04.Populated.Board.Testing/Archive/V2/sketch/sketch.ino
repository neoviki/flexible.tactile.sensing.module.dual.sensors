/*

Tested with my prototype flex BMP Split PCB, It works perfect. 
Hardware used : Arduino DUE


*/

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

void test_bmp_top()
{
    int i;
    Wire.end();
    delay(300);
    Wire.begin();

    for(i=0;i<5;i++){
        if(pressureSensor.beginI2C(IC_TOP) != BMP3_OK){
            Serial.println("BMP384 [TEST] [ TOP    ] [ FAIL ]");
        }else{
		        Serial.println("BMP384 [TEST] [ TOP    ] [ PASS ]");			
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
			      Serial.println("BMP384 [TEST] [ BOTTOM ] [ FAIL ]");
        }else{
    		    Serial.println("BMP384 [TEST] [ BOTTOM ] [ PASS ]");
        }
        delay(100);
    }

    return;
}

void setup()
{
    Serial.begin(115200);
    Serial.println("BMP384 I2C TESTER INIT");

    pinMode(21, OUTPUT);  
    
    for (int i = 0; i < 8; i++) {    
      digitalWrite(21, HIGH);    
      delayMicroseconds(3);    
      digitalWrite(21, LOW);    
      delayMicroseconds(3);  
    } 
    
    pinMode(21, INPUT);
    
}

void loop()
{
	test_bmp_top();
	test_bmp_bottom(); 
  delay(100);
}
