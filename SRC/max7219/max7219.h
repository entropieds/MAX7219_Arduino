#ifndef _MAX7219_H_
#define _MAX7219_H_
#include <Arduino.h>
#include <SPI.h>

  class max7219Matrix{
    private:
      void send_cmd(byte adres, byte data);
    public:
      void init_max7219();
      void setup_bright(byte bright);
      void setup_decode_mode(byte mode);
      void setup_scan_limit(byte scanLimit);
      void shut_down(byte data);
      void setup_display_test(byte data);
      void send_pattern(byte pattern[]);
  };

#endif