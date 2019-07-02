#include "ADF4351.h"
#include <SPI.h>

#define clock 18
#define data 23
#define LE 5
#define CE 25

ADF4351 adf4351(clock,data,LE,CE); // declares object PLL of type ADF4351

void setup() {
  Serial.begin(115200);
  adf4351.begin();

  // ref = 100M RFout = 200M
  adf4351.WriteRegister(0x00580005); // default value LD working mode
  adf4351.WriteRegister(0xCC803C); // output divider = 16 // band select clock divider
  adf4351.WriteRegister(0x000004B3); // default Antibacklash pulse width
  adf4351.WriteRegister(0x00010E42); // noise mode, R=4
  adf4351.WriteRegister(0x0008011); // prescaler=4/5、 MOD=25
  adf4351.WriteRegister(0x400000); // int = 128 frac = 0

  Serial.println("All registers have benn written!");
}

void loop() {
  // put your main code here, to run repeatedly: 
  
}