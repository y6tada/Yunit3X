#ifndef __GCEEPROM__
#define __GCEEPROM__

#include <Arduino.h>

class GCEEPROM {
public:
    static size_t write(uint8_t value, unsigned char address = 0);
    static size_t write(int8_t value, unsigned char address = 0);
    static size_t write(uint16_t value, unsigned char address = 0);
    static size_t write(int16_t value, unsigned char address = 0);
    static size_t write(uint32_t value, unsigned char address = 0);
    static size_t write(int32_t value, unsigned char address = 0);
    static size_t write(const __FlashStringHelper *value, unsigned char address = 0);
    static size_t write(const char value[], unsigned char address = 0);
    static size_t write(double value, unsigned char address = 0);
    
    static int8_t   readChar(unsigned char address = 0);
    static uint8_t  readUChar(unsigned char address = 0);
    static int16_t  readInt(unsigned char address = 0);
    static uint16_t readUInt(unsigned char address = 0);
    static int32_t  readLong(unsigned char address = 0);
    static uint32_t readULong(unsigned char address = 0);
    static int64_t  readLongLong(unsigned char address = 0);
    static uint64_t readULongLong(unsigned char address = 0);
};

#endif
