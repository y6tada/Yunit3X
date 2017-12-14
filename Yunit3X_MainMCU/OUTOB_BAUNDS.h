#include "mbed.h"
#include "MOTOR_PID.h"
#include "MOTOR_MoveCP_PP.h"
#include "SENSOR_USDsensor.h"
#include "SENSOR_IRsensor.h"
#include "SENSOR_CPSsensor.h"
#include "SENSOR_USDsensor.h"
#include "MOVE_Reverse.h"
#include "MOVE_BallUnDetect.h"
#include "function_setData.h"

extern void OUTOB_BAUNDS(void);

extern Serial pc;

extern DigitalIn   	LINE_R;
extern DigitalIn   	LINE_L;
extern DigitalIn   	LINE_B;

extern DigitalIn	SW_RED;
extern DigitalIn	SW_GRN;

const int in_max 	= 300;
const int out_max 	= 200;