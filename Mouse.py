# This Python code is an extension script for the Air Mouse using Arduino and MPU6050.
# Visit the Github page for the Arduino code and other information related to the project.
# https://github.com/rupava/Air-Mouse-Using-Arduino-and-MPU6050
# -By Rupava Baruah


import serial
from serial import Serial
from pynput.mouse import Button, Controller

import serial.tools.list_ports

mouse = Controller()
try:
  ser = serial.Serial('/dev/cu.usbserial-1430',baudrate = 19200)      # Setting Serial port number and baudrate
  isPressedL = 0                                                      # Bools to keep track of pressed buttons
  isPressedR = 0
  while 1:                                                            # While loop to continuesly scan and read data from serial port and execute
      dump = ser.readline()                                           # Reading Serial port
      dump = str(dump)                                                # Converting byte data into string
      dump = dump[2:-5]                                               # Cleaning up the raw data recieved from serial port
      data = dump.split(',')                                          # Spliting up the data to individual items in a list. the first item being the data identifier
      print(data)
      if data[0] == "DATAL":                                          # Checking if the identifier is "DATAL" which the Arduino sends data
          mouse.move(int(data[1]), int(data[2]))                      # Moving the mouse by using the X and Y values after converting them into integer
          if data[3] == 'L' and isPressedR == 0:                      # If the Left button is pressed and the Right one is not currently pressed
              mouse.press(Button.left)                                # The corresponding button is released and the bool is updated
              isPressedL = 1
          elif data[4] == 'R' and isPressedL == 0:                    # If the Right button is pressed and the Left one is not currently pressed
              mouse.press(Button.right)                               # The corresponding button is released and the bool is updated
              isPressedR = 1                                          # Note: if both buttons are pressed, the first button pressed will be active, and the other will stay released
          elif data[3] == '' and isPressedL == 1:                     # If the Left button is released after previously being pressed
              mouse.release(Button.left)                              # The corresponding button is released and the bool is updated
              isPressedL = 0
          elif data[4] == '' and isPressedR == 1:                     # If the Right button is released after previously being pressed
              mouse.release(Button.right)                             # The corresponding button is released and the bool is updated
              isPressedR = 0

except:
  print("Mouse not found or disconnected.")
  k=input("Press any key to exit.")