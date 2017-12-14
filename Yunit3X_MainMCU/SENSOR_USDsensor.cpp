#include "mbed.h"
#include "LPFilter.hpp"
/* ------------------------------------------------------------------------------------------ */
/* UltraSonic Distance Sensors                                                                */
/* These sensors are connect to STM32 Nucleo board                                            */
/* Right */
// PA_15
/* Back  */
// PB_7
/* Left  */
// PC_13
/* ------------------------------------------------------------------------------------------ */
const int TrigTime_us = 5;
/* ------------------------------------------------------------------------------------------ */
DigitalInOut USD_R_pin(PA_15);
DigitalInOut USD_B_pin(PB_7 );
DigitalInOut USD_L_pin(PC_13);

LPFilter	MavUSD_R(15);
LPFilter	MavUSD_B(15);
LPFilter	MavUSD_L(15);

Timer SonicSensorTimer;
/* ------------------------------------------------------------------------------------------ */
static int USD_R_cm;
static int USD_B_cm;
static int USD_L_cm;

static int USD_X_PosRL;
static int USD_X_SumRL;
/* ------------------------------------------------------------------------------------------ */
void USD_sortData(int timeout)
{
    USD_R_pin.output(); USD_B_pin.output(); USD_L_pin.output();
    
    USD_R_pin = 1; USD_B_pin = 1; USD_L_pin = 1;
    wait_us( TrigTime_us );
    USD_R_pin = 0; USD_B_pin = 0; USD_L_pin = 0;
    
    USD_R_pin.input(); USD_B_pin.input(); USD_L_pin.input();
    
    SonicSensorTimer.reset();
    SonicSensorTimer.start();
    
    USD_R_cm = 0;
    USD_B_cm = 0;
    USD_L_cm = 0;
    
    while (SonicSensorTimer.read_us() <= timeout) {
        if (USD_R_pin) { USD_R_cm = SonicSensorTimer.read_us(); }
        if (USD_B_pin) { USD_B_cm = SonicSensorTimer.read_us(); }
        if (USD_L_pin) { USD_L_cm = SonicSensorTimer.read_us(); }
    }
    
    USD_R_cm = (USD_R_cm - 630) / 61;
    USD_B_cm = (USD_B_cm - 630) / 61;
    USD_L_cm = (USD_L_cm - 630) / 61;
    
    USD_X_PosRL = (USD_L_cm - USD_R_cm);
	USD_X_SumRL = (USD_L_cm + USD_R_cm);
}
/* ------------------------------------------------------------------------------------------ */
int GetUSD(int DataNo)
{
    /* -------------------------------------------------------------------------------------- */
    switch (DataNo) {
        case 1:
            return MavUSD_R.setMAV(USD_R_cm);
            break;
            //
        case 2:
            return MavUSD_B.setMAV(USD_B_cm);
            break;
            //
        case 3:
            return MavUSD_L.setMAV(USD_L_cm);
            break;
            //
        case 4:
            return USD_X_SumRL;
            break;
            //
        case 5:
            return USD_X_PosRL;
            break;
    }
    return 0;
    /* -------------------------------------------------------------------------------------- */
}
/* ------------------------------------------------------------------------------------------ */