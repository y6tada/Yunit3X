#include "mbed.h"

DigitalIn IR_DI[16] = {
    DigitalIn(PB_6),
    DigitalIn(PC_7),
    DigitalIn(PA_9),
    DigitalIn(PA_7),
    DigitalIn(PA_6),
    DigitalIn(PB_8),
    DigitalIn(PB_9),
    DigitalIn(PA_5),
    DigitalIn(PC_1),
    DigitalIn(PC_3),
    DigitalIn(PC_0),
    DigitalIn(PC_2),
    DigitalIn(PB_0),
    DigitalIn(PA_0),
    DigitalIn(PA_1),
    DigitalIn(PA_4)
};
Timer IRTimer;
/* ------------------------------------------------------------------------------------------ */
const int timeout = 835;
/* ------------------------------------------------------------------------------------------ */
static int IR_Distance;
static int IR_Degree;
static int IR_ActiveSensorCount;
/* ------------------------------------------------------------------------------------------ */
void IR_sortData(void)
{
    // All PulseWidth valiable set to zero
    int IR_PulseWidth[16];
    for (int RST = 0; RST < 16; RST++) { IR_PulseWidth[RST] = 0; }
    /* get 16 IRSensor's Low-Pulse width by Integration reading     */
    IRTimer.reset();
    IRTimer.start();
    while (IRTimer.read_us() < timeout)
    {
        for (int i = 0; i < 16; ++i) {
            if (! IR_DI[i])
                IR_PulseWidth[i] ++;
        }
    }
    IRTimer.stop();
    /* Get the longest Low-Pulse width Sensor's number              */
    /* Get the active sensors count                                 */
    int IR_MaxPulse = 0;
    IR_ActiveSensorCount = 0;
    
    for (int CT16 = 0; CT16 < 16; CT16 ++)
    {
        if (IR_PulseWidth[CT16] > IR_MaxPulse) {
            IR_MaxPulse = IR_PulseWidth[CT16];
            /* Get degree                                           */
            IR_Degree = CT16;
        }
        if (IR_PulseWidth[CT16] > 0)
            IR_ActiveSensorCount ++;
    }
    
    /* Get the distance between Robot and Ball                      */
    if (IR_ActiveSensorCount == 0) {
        IR_Distance = 0;
        IR_Degree      = 0;
    }
    
    else if (IR_ActiveSensorCount < 3)
        IR_Distance = 4;
    else if (IR_ActiveSensorCount < 4)
        IR_Distance = 3;
    else if (IR_ActiveSensorCount < 7)
        IR_Distance = 2;
    else
        IR_Distance = 1;
}
/* ------------------------------------------------------------------------------------------ */
int GetIR(int DataNo)
{
    switch (DataNo)
    {
        case 0:
            switch (IR_Degree)
            {
                case  0: return  1 ; break;
                case  1: return  2 ; break;
                case  2: return  3 ; break;
                case  3: return  4 ; break;
                case  4: return  5 ; break;
                case  5: return  6 ; break;
                case  6: return  7 ; break;
                case  7: return  8 ; break;
                    
                case 15: return -1 ; break;
                case 14: return -2 ; break;
                case 13: return -3 ; break;
                case 12: return -4 ; break;
                case 11: return -5 ; break;
                case 10: return -6 ; break;
                case 9 : return -7 ; break;
                case 8 : return -8 ; break;
            }
        break;

        case 1:
            if (IR_Degree > 7)
                return IR_Degree - 16;
            else
                return IR_Degree + 1;
            break;

        case 2:
            return IR_Distance;
            break;
            
        case 3:
            return IR_ActiveSensorCount;
            break;
    }
    return 0;
}
/* ------------------------------------------------------------------------------------------ */