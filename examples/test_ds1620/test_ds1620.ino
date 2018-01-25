/*
 * 
 * Test sketch for DS1620
 * 
 * HW Required: DS1620 Connected to Arduino Uno as described below.
 * Voltage source: 5V
 * Expected Result: Log in Serial Monitor of degrees in Celsius and Farenheit.
 * 
 * Author: Kike Ramirez
 * Date: 21/1/2018
 * 
 */


#include <stdlib.h>
#include <DS1620.h>


// Set the appropriate digital I/O pin connections.
// See the datasheet for more details.
static const uint8_t RST_PIN = 7;  // pin 3 on DS1620
static const uint8_t CLK_PIN = 8;  // pin 2 on DS1620
static const uint8_t DQ_PIN  = 9;  // pin 1 on DS1620


DS1620 ds1620(RST_PIN, CLK_PIN, DQ_PIN);


void setup()
{
  Serial.begin(9600);
  delay(100);

  ds1620.config();
}


void loop()
{
  const float temp_c = ds1620.temp_c();
  const float temp_f = temp_c * 9/5.0 + 32;

  Serial.print(temp_f, 1);  // 1 decimal place
  Serial.print("F ");
  Serial.print(temp_c, 1);
  Serial.println("C");
}
