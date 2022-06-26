#include <Base64.h>
#include <Wire.h>

char in[12], data[8], pointer = 0;

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  if(pointer == 12){
    Base64.decode(data, in, 12);
    pointer = 0;
    Wire.beginTransmission(0x61);
    Wire.write(data, 5);
    Wire.endTransmission();
    Wire.beginTransmission(0x43);
    Wire.write(data+5, 3);
    Wire.endTransmission();
  }
}

void serialEvent(){
 if(Serial.peek() == 0x24 && Serial.read()) pointer = 0;
 else in[pointer++] = Serial.read();
}
