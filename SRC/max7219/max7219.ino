/********************************/
/* Test sketch for max7219 lib  */
/* Pins connect to arduino:     */
/* pin 10: CS                   */
/* pin 11: DIN                  */
/* pin 13: clk                  */
/********************************/

#include "max7219.h"

max7219Matrix MAX7219;  // create class 

void setup() {
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  MAX7219.init_max7219();
  Serial.begin(9600);
}

void loop() {
  // Example pattern: heart shape
  uint8_t pattern[] = {
    0b00000000,
    0b01100110,
    0b11111111,
    0b11111111,
    0b01111110,
    0b00111100,
    0b00011000,
    0b00000000
  };

  uint8_t size = sizeof(pattern) / sizeof(pattern[0]); // array size
  MAX7219.send_pattern(pattern,size);
  delay(1000); // Wait for 1 second
}
