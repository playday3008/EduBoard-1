/*
 Software serial multple serial test

 Receives from the hardware serial, sends to software serial.
 Receives from software serial, sends to hardware serial.
 based on Mikal Hart's example

 The circuit:
 * RX is digital pin 10 (connect to TX of other device)
 * TX is digital pin 11 (connect to RX of other device)

 Library modified by MCUdude to work with "regular" interrupt pins.
 This example code is in the public domain.


 No pins on the ATmega8535, ATmega16 and ATmega32 support
 pin change interrupts, so only "regular" interrupts may be used.
 For the "STANDARD pinout" this is digital pin 2, 10, 11
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial)
    ; // wait for serial port to connect. Needed for native USB port only

  Serial.println("Goodnight moon!");

  // Set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
  mySerial.println("Hello, world?");
}

void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }

  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
