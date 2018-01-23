# tempSensorThingsBoard v1.0

## Hardware:
* ESP8266
* DS1620 Thermometer/Termostat (library used: https://github.com/msparks/arduino-ds1620)
* Batteries, connections, etc.

## ThingsBoard platform used
* v1.3

## Author
* Kike Ramírez
* 20/1/2018

## License
* MIT

# Hardware connections
Some references and help to implement hardware and program ESP8266 using an Arduino board by yourself.

## ESP8266 Pinout
Check **schematics** in: http://www.esp8266.com/wiki/doku.php
![ESP8266 Pinout](/images/ESP8266-Pinout.png)

## Temperature sensor MAXIM DS1620 Pinout
Check **datasheet** in: https://datasheets.maximintegrated.com/en/ds/DS1620.pdf
![DS1620 Pinout](/images/DS1620-Pinout.jpg)

## Arduino <-> ESP8266 Connection - Uploading Firmware
Check **tutorial**: https://create.arduino.cc/projecthub/ROBINTHOMAS/programming-esp8266-esp-01-with-arduino-011389

![Firmware Upload Schematics](/images/tempSensorThingsBoard_UploadFirmware_bb.png)

## ESP8266 <-> DS1620 Connection - StandAlone Mode
**Final design. v1.0**

* BreadBoard Mode:
  ![StandAlone - BreadBoard](/images/tempSensorThingsBoard_StandAlone_bb.jpg)

* Schematics:
  ![StandAlone Mode Schematics](/images/tempSensorThingsBoard_StandAlone_esquemático.jpg)

* PCB Design:
  ![StandAlone Mode Schematics](/images/tempSensorThingsBoard_StandAlone_pcb.jpg)

* Final render of PCB:
  ![PCB Render Top](/images/PCB_Top.png)
  ![PCB Render Bottom](/images/PCB_Bottom.png)

