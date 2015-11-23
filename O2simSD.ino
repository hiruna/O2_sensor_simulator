/*
O2 Sensor Simulator with Data Logger

Code by Hiruna Wijesinghe
Last Modified: 231115 @ 1812

*/

#include <SPI.h>
#include <SD.h>

/*
Not required to initialize as and input or output
This is predefined in the SD Library.

MOSI = Pin 11
MISO = Pin 12
SCLK = PIN 13
*/
int CSP = 10;
int count = 0;
int voltage = 0;
void setup()
{
  Serial.begin(9600);
  Serial.println("Initializing Card");
  pinMode(CSP, OUTPUT);
  pinMode(8, OUTPUT);  //to draw power to card
  digitalWrite(8, HIGH);
  pinMode(9,OUTPUT); //voltage out to the ECU
  pinMode(5,INPUT); //potentiometer pin
  
  if (!SD.begin(CSP))
  {
      Serial.println("Error");
      return;
  }
  Serial.println("OK");
  
}

void loop()
{
	
  File sensorLog = SD.open("log.txt", FILE_WRITE);
  if (sensorLog)
  {
    voltage = analogRead(5);
    Serial.println(voltage);//DEBUG
    voltage = map(voltage, 0, 1023, 0, 50); //value 0 and 50 can be changed according to the desired voltage output
    Serial.print("new voltage: ");
    Serial.println(voltage);//DEBUG
    analogWrite(9,voltage); 
    
    sensorLog.print(count);
    sensorLog.print(",");
    sensorLog.println(voltage);
    sensorLog.close();
    count++;
    /*
    SAMPLE OUTPUT TO FILE:
    
    0,23
    0,23
    0,23
    0,41
    */
  }
  else
  {
    Serial.println("File read error");
  }
  delay(500);
}
