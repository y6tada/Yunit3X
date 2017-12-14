#include "Arduino.h"
#include "wiring_private.h"
#include "pins_arduino.h"

class AnalogIn {
    uint8_t pin = 0;
#if defined(ADCSRB) && defined(MUX5)
    uint8_t adcsrbVal = 0;
#endif
#if defined(ADMUX)
    uint8_t admuxVal = 0;
#endif  
    
public:
    AnalogIn(uint8_t pin);
    inline __attribute__((always_inline)) int read() {
#if defined(ADCSRB) && defined(MUX5)
        // the MUX5 bit of ADCSRB selects whether we're reading from channels
        // 0 to 7 (MUX5 low) or 8 to 15 (MUX5 high).
        ADCSRB = adcsrbVal;
#endif
        
        // set the analog reference (high two bits of ADMUX) and select the
        // channel (low 4 bits).  this also sets ADLAR (left-adjust result)
        // to 0 (the default).
#if defined(ADMUX)
        ADMUX = admuxVal;
#endif
        
        // start the conversion
        ADCSRA |= 1 << ADSC;
        
        // ADSC is cleared when the conversion finishes
        while (ADCSRA & 1 << ADSC);
        
        // we have to read ADCL first; doing so locks both ADCL
        // and ADCH until ADCH is read.  reading ADCL second would
        // cause the results of each conversion to be discarded,
        // as ADCL and ADCH would be locked when it completed.
        return ADCL | ADCH << 8;
    }
    inline __attribute__((always_inline)) operator int() {
        return read();
    }
};
