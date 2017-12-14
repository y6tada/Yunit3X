#include "mbed.h"

#include "SENSOR_IRsensor.h"
#include "SENSOR_USDsensor.h"
#include "MOVE_SetTD.h"

static int moveDegree = 0;
static int InptDegree = 0;

int BallTracking(int InptXVI, int step)
{
    if (InptXVI > 0)
        InptDegree = InptXVI * 22 - 11;
    else if (InptXVI < 0)
        InptDegree = (InptXVI * 22 + 11) + 360;
    
    
    if ((moveDegree - InptDegree) < -1 || (moveDegree - InptDegree) > 1)
        moveDegree -= (double)(moveDegree - InptDegree) / step;
    
    return InptDegree;
}
