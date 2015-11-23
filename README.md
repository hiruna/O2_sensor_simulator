# O2 Sensor Simulator by hiruna - WIP

This is a very basic prototype to bypass the factory installed O2 Sensor in a motorcycle/car and send custom sensor data to the ECU. The purpose of the prototype was to force the ECU to operate on a static fuel map, enabling the user to change to the prefered Air-fuel ratio.

### BEFORE YOU PERFORM ANY MODIFICATIONS TO YOUR VEHICLE, PLEASE NOTE THAT I AM NOT RESPONSIBLE FOR ANY DAMAGE CAUSED TO YOUR BIKE/CAR.

### Material list
* Car/Bike with O2 Sensor
* Breadboard/jumper wires
* Arduino UNO R3 (or other arduino)
* Potentiometer
* SD Card module (optional)
* 330 ohm resistor
* Duct-tape or electrical tape


Testing was performed on a 2014 Honda CBR500R. The O2 sensor consists of 4 wires that leads into the ECU. Two of the wires are known as "heater" wires (usually same color), and the other 2 wires sends a voltage reading to the ECU, 0.0v - 1.0v (narrowband).

### Prepping up the ECU plug

* Make sure your car/bike is switched off.
* The O2 sensor plug can be identified by examining where the the wire leads from the sensor. Once the plug has been found, unplug it. 

Obviously we will send data to the ECU and not the O2 sensor, so pick up the lead from the ECU and insert breadboard wires into the for pins to extend it. Bend the wires back and tape around the bend in order to secure it. 

* Heater wires can be easily identified by the colors on the wires, they are usually the same color.
* Attach the 330 ohm resistor to the heater wires and secure it with tape.

Attaching the resistor tricks the ECU into think that an O2 sensor is present. 

### Arduino setup

Grab your Arduino R3 (or other) and set up the I/O pins according to my sketch.

* Without data logger - simple voltage output through pin 9 to ECU

```Potentiometer pin : 5```
```Voltage out pin : 9```

* With data logger - voltage output through pin 9 + logging voltages set by user into a text file

```MOSI = Pin 11```
```MISO = Pin 12```
```SCLK = PIN 13```
```Potentiometer pin : 5```
```Voltage out pin : 9```

* Note that in both sketches, ```val = map(val, 0, 1023, 0, 50);``` can be modified to define the range of the output voltage. By simply using a multimeter, the output voltage of pin 9 can be determined. Then using the debug data from the Serial monitor, 0 and 50 can be changed into the desired values.

### ALWAYS MAKE SURE YOU TEST THE OUTPUT VOLTAGE USING A MULTIMETER BEFORE ATTACHING THE ```PIN 9``` WIRE TO THE ECU

* Locate the ```ground wire``` of the sensor plug (from ECU) and attach it to the ```ground``` of the Arduino. The wire attached to ```pin 9``` connects to the remaining wire in the sensor plug (from ECU).

To power up the arduino, I used a 4xAA battery pack.
If everything was setup correctly, the check engine light should not be displayed. Make sure everything is secured well before testing out the vehicle. The user should be able to change the values by using the potentiometer on the go. 

I have only tested the voltages 0.40-0.64 volts. I did experince a sight increase in throttle response. This project is still WIP. Feel free to adapt the code and improve it
