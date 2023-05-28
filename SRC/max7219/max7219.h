#ifndef _MAX7219_H_
#define _MAX7219_H_
#include <Arduino.h>
#include <SPI.h>

  class max7219Matrix{
    private:
      void send_cmd(uint8_t addres, uint8_t data);
    public:
      void init_max7219();
      void setup_bright(uint8_t bright);
      void setup_decode_mode(uint8_t mode);
      void setup_scan_limit(uint8_t scanLimit);
      void shut_down(uint8_t data);
      void setup_display_test(uint8_t data);
      void send_pattern(const uint8_t (&pattern)[8]);
  };

#endif