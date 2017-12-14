#include "32U4_UI_LINEv3.h"
// ------------------------------------------------------------------------------------------------ //
#define SERIAL_BAUD_PC      115200
int  LineSensorVal = 200;
RGB_LCD LCD;

void setup()
{
    Serial.begin(SERIAL_BAUD_PC);
    pinModeInitialize();
    LCD.begin(16, 2);

    EC_init();
}


bool isRunning = true;
void loop()
{
    if (! digitalRead(SW_RED) && digitalRead(SW_GRN))
    {
        if (! isRunning) {

            noTone(toneOUT);

            LCD.clear();
            LCD.setCursor(3,0);
            LCD.print("Running...");

            LCD.setCursor(0,1);
            LCD.print("FAST_SPEED_MODE");

            digitalWrite(RED_SW,HIGH);
            digitalWrite(GRN_SW,LOW );
        } isRunning = true;

        LINESENSOR_SIGNAL_OUTPUT(LineSensorVal);
        digitalWrite(KICKER_OUT, (analogRead(A4) < 800) ? HIGH : LOW );
    }
    // ---------------------------------------------------------------------------------- //
    else if (! digitalRead(SW_GRN) && digitalRead(SW_RED))
    {
        if (! isRunning) {

            noTone(toneOUT);

            LCD.clear();
            LCD.setCursor(3,0);
            LCD.print("Running...");

            LCD.setCursor(0,1);
            LCD.print("LOW_SPEED_MODE");

            digitalWrite(RED_SW,LOW );
            digitalWrite(GRN_SW,HIGH);
        } isRunning = true;

        LINESENSOR_SIGNAL_OUTPUT(LineSensorVal);
        digitalWrite(KICKER_OUT, (analogRead(A4) < 800) ? HIGH : LOW );

    }
    // ---------------------------------------------------------------------------------- //
    else if (digitalRead(SW_RED) && digitalRead(SW_GRN))
    {
        if (isRunning) {

            noTone(toneOUT);

            LCD.clear();
            LCD.setCursor(5,0);
            LCD.print("Ready...");

            digitalWrite(RED_SW,LOW);
            digitalWrite(GRN_SW,LOW);
            digitalWrite(KICKER_OUT ,LOW);
        } isRunning = false;

        LINESENSOR_SIGNAL_OUTPUT(LineSensorVal);
        UI_MODE();
    }
}


// ---------------------------------------------------------------------------------- //
void pinModeInitialize()
{
    pinMode(EC_SW  ,INPUT );
    pinMode(RED_SW ,OUTPUT);
    pinMode(GRN_SW ,OUTPUT);

    pinMode(KICKER_OUT ,OUTPUT);

    pinMode(Nucleo_PA_12,OUTPUT);
    pinMode(Nucleo_PA_11,OUTPUT);
    pinMode(Nucleo_PB_12,OUTPUT);
    
    pinMode(ECA   ,INPUT_PULLUP);
    pinMode(ECB   ,INPUT_PULLUP);

    pinMode(SW_RED,INPUT_PULLUP);
    pinMode(SW_GRN,INPUT_PULLUP);

    pinMode(HMCmc_calSIG,OUTPUT);    
}