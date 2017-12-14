#include "GCEEPROM.h"
#include <avr/eeprom.h>

/* Write Functions */

size_t GCEEPROM::write(uint8_t value, unsigned char address)
{
    eeprom_busy_wait();
    eeprom_write_byte(reinterpret_cast<unsigned char *>(address), static_cast<char>(value));
    return 1;
}

size_t GCEEPROM::write(int8_t value, unsigned char address)
{
    eeprom_busy_wait();
    eeprom_write_byte(reinterpret_cast<unsigned char *>(address), value);
    return 1;
}

size_t GCEEPROM::write(uint16_t value, unsigned char address)
{
    write(static_cast<int8_t>(value >> 8), address);
    write(static_cast<int8_t>(value), address + 1);
    return 2;
}

size_t GCEEPROM::write(int16_t value, unsigned char address)
{
    write(static_cast<int8_t>(value >> 8), address);
    write(static_cast<int8_t>(value), address + 1);
    return 2;
}

size_t GCEEPROM::write(uint32_t value, unsigned char address)
{
    write(static_cast<int8_t>(value >> 16), address);
    write(static_cast<int8_t>(value >> 8), address + 1);
    write(static_cast<int8_t>(value), address + 2);
    return 3;
}

size_t GCEEPROM::write(int32_t value, unsigned char address)
{
    write(static_cast<int8_t>(value >> 16), address);
    write(static_cast<int8_t>(value >> 8), address + 1);
    write(static_cast<int8_t>(value), address + 2);
    return 3;
}

size_t GCEEPROM::write(const __FlashStringHelper *value, unsigned char address)
{
    return write(reinterpret_cast<const char *>(value), address);
}

size_t GCEEPROM::write(const char *value, unsigned char address)
{
    char *c = const_cast<char *>(value);
    size_t size = 0;
    while (*c != '\0') {
        write(*c, address);
        size++;
        address++;
    }
    return size;
}

size_t GCEEPROM::write(double value, unsigned char address)
{
    return write(static_cast<int>(value));
}

/* Read Functions */

int8_t GCEEPROM::readChar(unsigned char address)
{
    eeprom_busy_wait();
    return eeprom_read_byte(reinterpret_cast<unsigned char *>(address));
}

uint8_t GCEEPROM::readUChar(unsigned char address)
{
    eeprom_busy_wait();
    return eeprom_read_byte(reinterpret_cast<unsigned char *>(address));
}

int16_t GCEEPROM::readInt(unsigned char address)
{
    return readChar(address) << 8 | readChar(address + 1);
}

uint16_t GCEEPROM::readUInt(unsigned char address)
{
    return readUChar(address) << 8 | readUChar(address + 1);
}

int32_t GCEEPROM::readLong(unsigned char address)
{
    return readChar(address) << 16 | readChar(address + 1) << 8 | readChar(address + 2);
}

uint32_t GCEEPROM::readULong(unsigned char address)
{
    return readUChar(address) << 16 | readUChar(address + 1) << 8 | readUChar(address + 2);
}

int64_t GCEEPROM::readLongLong(unsigned char address)
{
    return readChar(address) << 32 | readChar(address + 1) << 16 | readChar(address + 2) << 8 | readUChar(address + 3);
}

uint64_t GCEEPROM::readULongLong(unsigned char address)
{
    return readUChar(address) << 32 | readUChar(address + 1) << 16 | readUChar(address + 2) << 8 | readUChar(address + 3);
}
