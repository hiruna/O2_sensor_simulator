/*
O2 Sensor Simulator

Code by Hiruna Wijesinghe
Last Modified: 231115 @ 1751


*/

#include <SPI.h>
#include <SD.h>

int val = 0;
void setup() {
  pinMode(9,OUTPUT); //voltage out to the ECU
  pinMode(5,INPUT); //potentiometer pin
  Serial.begin(9600);//DEBUG
}

void loop() {
  val = analogRead(5);
  Serial.println(val);//DEBUG
  val = map(val, 0, 1023, 0, 50); //value 0 and 50 can be changed according to the desired voltage output
  Serial.print("new val: ");
  Serial.println(val);//DEBUG
  analogWrite(9,val); 
  delay(1000);
}
