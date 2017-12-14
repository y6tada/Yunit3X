#ifndef __32U4_UI_LINEv3__
#define __32U4_UI_LINEv3__

#include <Arduino.h>
#include <limits.h>
#include "RGB_LCD.h"
#include "GCEEPROM.h"
#include "AnalogIn.h"

// ------------------------------------------------------------------------------------------------ //
#define ECA     4
#define ECB     5

#define EC_SW   9
#define RGBEC_R 8
#define RGBEC_G 7
#define RGBEC_B 6

byte curDat;
byte befDat   = 0;
byte rotDir   = 0;

int  Count    = 1000;
int  CountX   = 0;

byte inputMatch;
byte matchCnt;

byte rotPat   = 0;

int LED_RevCT = 0;
// ------------------------------------------------------------------------------------------------ //
const int tone_A = 262;
const int tone_S = 294;
const int tone_D = 330;
const int tone_F = 349;
const int tone_G = 392;
const int tone_H = 440;
const int tone_J = 494;
const int tone_K = 523;
// ------------------------------------------------------------------------------------------------ //

/* デジタル非同期通信ポート */
#define Nucleo_PC_8  12 // RED
#define Nucleo_PC_5  11 // GRN
#define Nucleo_PA_12 10 // LINE1
#define Nucleo_PA_11 16 // LINE2
#define Nucleo_PB_12 15 // LINE3
#define Nucleo_PC_4  23 // Kicker
#define Nucleo_PC_6  0  // Dribbler

#define HMCmc_calSIG 18 // 32U4 Micro Signal pin
#define SW_RED       1  // ToggleSwitch RED
#define SW_GRN       17 // ToggleSwitch GREEN
#define toneOUT      14 // Beep

#define LCD_SDA      2
#define LCD_SCL      3

#define RED_SW       Nucleo_PC_8
#define GRN_SW       Nucleo_PC_5

#define SIGNAL_R   	 Nucleo_PA_12
#define SIGNAL_L     Nucleo_PA_11
#define SIGNAL_B     Nucleo_PB_12

#define KICKER_OUT   Nucleo_PC_4
#define DRIBBLER_IN  Nucleo_PC_6

// ------------------------------------------------------------------------------------------------ //
const int LineSensorValAddress  = 5;
const int LineDetectedTone_Hz   = 3000;
const int HoldSensorValue		= 800;
// ------------------------------------------------------------------------------------------------ //

#endif