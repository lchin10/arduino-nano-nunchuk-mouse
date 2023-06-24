# arduino-nano-nunchuk-mouse

## Overview:
Updated program for using the Wii Nunchuk as a mouse.
The code processes the analog and button data from the Nunchuk and sends it to your computer via serial communication.
The Python script reads the data and moves the mouse relative to the positioning of the analog joystick.
The C button is right click, and the Z button is left click.

Arduino IDE and Python3 must be installed, along with the pynput Python library.
I used an Arduino Nano board, but you can also use any ATMEGA328 based board.
To connect the Wii Nunchuk to the Arduino Nano I used an I2C WiiChuck Adapter Shield Module Board.

## Circuit Diagram:
  ![image](https://github.com/lchin10/arduino-nano-nunchuk-mouse/assets/46639864/b0bf2ab8-c19a-47f1-a0dc-679ef4365a4a)

* c to A5
* c to A4
* '+' to 3V3
* '-' to GND

## Resources:
* https://github.com/rupava/Air-Mouse-Using-Arduino-and-MPU6050
* https://github.com/GabrielBianconi/arduino-nunchuk
* https://github.com/leeassam/arduino-bootcamp/tree/master/Wii_Pan_Tilt/ArduinoNunchukDemo
