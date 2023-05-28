#include "max7219.h"

#define DECODE_MODE   0x09  // Decode mode addres
#define INTENSITY     0x0A  // Intensity addres
#define SCAN_LIMIT    0x0B  // Scan limit addres
#define Shutdown      0x0C  // Shutdown display addres
#define DISPLAY_TEST  0x0F  // Display test addres

#define MAX7219_LOAD 10 // Pin connected to MAX7219 LOAD/CS pin
#define MAX7219_DIN 11 // Pin connected to MAX7219 DIN pin
#define MAX7219_CLK 13 // Pin connected to MAX7219 CLK pin


/**/


void max7219Matrix::send_cmd(uint8_t addres, uint8_t data){
  digitalWrite(MAX7219_LOAD, LOW);
  SPI.transfer(addres);
  SPI.transfer(data);
  digitalWrite(MAX7219_LOAD, HIGH);
}

void max7219Matrix::init_max7219(){
  pinMode(MAX7219_LOAD, OUTPUT);
  max7219Matrix::setup_decode_mode(0);
  max7219Matrix::setup_bright(0x00);
  max7219Matrix::setup_scan_limit(0x07);
  max7219Matrix::shut_down(0);
  max7219Matrix::setup_display_test(0x00);
}

void max7219Matrix::setup_bright(uint8_t bright){
  max7219Matrix::send_cmd(INTENSITY, bright);
}

void max7219Matrix::setup_decode_mode(uint8_t mode){
  if(mode == 0)
   max7219Matrix::send_cmd(DECODE_MODE, 0x00);
  else 
    max7219Matrix::send_cmd(DECODE_MODE, 0x01);
}

void max7219Matrix::setup_scan_limit(uint8_t scanLimit){
  max7219Matrix::send_cmd(SCAN_LIMIT, scanLimit);
}

void max7219Matrix::shut_down(uint8_t data){
  if(data == 0)
    max7219Matrix::send_cmd(Shutdown, 0x01);
  else
    max7219Matrix::send_cmd(Shutdown, 0x00);
}

void max7219Matrix::setup_display_test(uint8_t data){
  if(data == 0)
    max7219Matrix::send_cmd(DISPLAY_TEST, 0x00);
  else
    max7219Matrix::send_cmd(DISPLAY_TEST, 0x01);
}

void max7219Matrix::send_pattern(uint8_t* pattern, uint8_t size){
  if (size < 8){
    uint8_t newArray[] = {0, 0, 0, 0, 0, 0, 0, 0};
    for(uint8_t i = 0; i < 8; ++i){
      if(i < size)
        newArray[i] = *(pattern + i);
      max7219Matrix::select_dot(i + 1, newArray[i]);
    }
  } else{
    for(uint8_t i = 0; i < size; ++i){
      max7219Matrix::select_dot(i + 1, *(pattern + i));
    }
  }
}

void max7219Matrix::select_dot(uint8_t collum, uint8_t row){
  max7219Matrix::send_cmd(collum, row);
}
