#include <SPI.h>

#define MAX7219_LOAD 10 // Pin connected to MAX7219 LOAD/CS pin
#define MAX7219_DIN 11 // Pin connected to MAX7219 DIN pin
#define MAX7219_CLK 13 // Pin connected to MAX7219 CLK pin

// Function to send a single command to the MAX7219
void sendCommand(byte command, byte data) {
  digitalWrite(MAX7219_LOAD, LOW); // Select MAX7219
  SPI.transfer(command); // Send command
  SPI.transfer(data); // Send data
  digitalWrite(MAX7219_LOAD, HIGH); // Deselect MAX7219
}

// Function to initialize the MAX7219
void initMAX7219() {
  sendCommand(0x09, 0x00); // Decode mode: no decoding for digits 0-7
  sendCommand(0x0A, 0x00); // Intensity: set to maximum brightness (0x00 to 0x0F)
  sendCommand(0x0B, 0x07); // Scan limit: display digits 0-7
  sendCommand(0x0C, 0x01); // Enable display: turn on
  sendCommand(0x0F, 0x00); // Display test: disable
}

// Function to display a pattern on the 8x8 LED dot matrix
void displayPattern(byte pattern[]) {
  for (byte i = 0; i < 8; i++) {
    sendCommand(i + 1, pattern[i]);
  }
}

void setup() {
  pinMode(MAX7219_LOAD, OUTPUT);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  initMAX7219();
}

void loop() {
  // Example pattern: heart shape
  byte pattern[] = {
    0b00000000,
    0b01100110,
    0b11111111,
    0b11111111,
    0b01111110,
    0b00111100,
    0b00011000,
    0b00000000
  };

  displayPattern(pattern);

  delay(1000); // Wait for 1 second
}
