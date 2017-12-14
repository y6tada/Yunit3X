#include "mbed.h"

#include "MOTOR_MoveCP_PP.h"
#include "MOTOR_PID.h"

#include "SENSOR_IRsensor.h"
#include "SENSOR_USDsensor.h"

#define SPEED_Cycle 25
#define POS_Y 		50
#define SPEED1 40 / 0.75
#define SPEED2 0.60

static int speed = 0;

void MOVE_BUD(void)
{
    if ((GetUSD(1) - GetUSD(3)) < -12 || (GetUSD(1) - GetUSD(3)) > 12 || GetUSD(2) > POS_Y)
    {
        if (speed <= SPEED_Cycle) speed ++;
        
        MoveCP(
               atan2( (GetUSD(1) - GetUSD(3)) , -GetUSD(2) + POS_Y) * 180 / M_PI
               ,(double)speed / SPEED1
               ,PID(0)
               );
    }
    else
    {
        MovePP(PID(0), 0);
        speed = 0;
    }
}

void MOVE_BUD2(void)
{
    if ((GetUSD(1) - GetUSD(3)) < -12 || (GetUSD(1) - GetUSD(3)) > 12 || GetUSD(2) > POS_Y)
    {
		MoveCP(
            atan2( (GetUSD(1) - GetUSD(3)) , -GetUSD(2) + POS_Y) * 180 / M_PI
           ,SPEED2
           ,PID(0)
		);
    }
    else
        MovePP(PID(0), 0);
}