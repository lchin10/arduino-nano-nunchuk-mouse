#include <Wire.h>
#include "ArduinoNunchuk.h"

#define BAUDRATE 19200

ArduinoNunchuk nunchuk = ArduinoNunchuk();

// SCL is connected to A5
// SDA is connected to A4
// +3.3V connected to +
// GND connected to -

void setup()
{
  Serial.begin(BAUDRATE);
  nunchuk.init();
  Serial.println("STRTM");
}

void loop()
{
  nunchuk.update();

  // Serial.print("X: ");
  // Serial.print(nunchuk.analogX, DEC);
  // Serial.print(' ');
  // Serial.print("Y: ");  
  // Serial.print(nunchuk.analogY, DEC);
  // Serial.print(' ');
  // Serial.print("Acc X: ");
  // Serial.print(nunchuk.accelX, DEC);
  // Serial.print(' ');
  // Serial.print("Acc Y: ");
  // Serial.print(nunchuk.accelY, DEC);
  // Serial.print(' ');
  // Serial.print("Acc Z: ");
  // Serial.print(nunchuk.accelZ, DEC);
  // Serial.print(' ');
  // Serial.print("Z btn: ");
  // Serial.print(nunchuk.zButton, DEC);
  // Serial.print(' ');
  // Serial.print("C btn: ");
  // Serial.println(nunchuk.cButton, DEC);

  int xDistance = (nunchuk.analogX - 128)/10;
  int yDistance = -(nunchuk.analogY - 128)/10;
  // Serial.print(xDistance);
  // Serial.print(", ");
  // Serial.println(yDistance);
  
  delay(10);
  Serial.print("DATAL,");
  Serial.print(xDistance);
  Serial.print(',');
  Serial.print(yDistance);
  Serial.print(',');
  if (nunchuk.cButton == 1) {
    Serial.print("L");
  } else {
    Serial.print("");
  }
  Serial.print(',');
  if (nunchuk.zButton == 1) {
    Serial.println("R");
  } else {
    Serial.println("");
  }

  // if (nunchuk.cButton == 1) {
  //   delay(100);
  //   Serial.println("DATAB,L");
  // }

  // if (nunchuk.zButton == 1) {
  //   delay(100);
  //   Serial.println("DATAB,R");
  // }

  // if ((xDistance != 0) || (yDistance != 0)) {
  //   Mouse.move(xDistance, yDistance);
  // }

  // if (nunchuk.cButton == 1) {
  //   if (!Mouse.isPressed(MOUSE_LEFT)) {
  //     Mouse.press(MOUSE_LEFT);
  //   }
  // } else {
  //   if (Mouse.isPressed(MOUSE_LEFT)) {
  //     Mouse.release(MOUSE_LEFT);
  //   }
  // }

  // delay(responseDelay);
}