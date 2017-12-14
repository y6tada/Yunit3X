#include "mbed.h"
#include "SENSOR_CPSsensor.h"
#include "MOTOR_PID.h"

#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
/* ---------------------------------------------------------------------------- */
const double Kp = 1.2 * 1;
const double Kd = 0.8 * 1;
/* PD fixed motors control ---------------------------------------------------- */

double PID(int8_t ofset)
{
    double fixed_SPEED;
    
    if (ofset == 0)
    {
        fixed_SPEED = (
			  (double)GetCPS(0) / 100.0 * Kp
			+ (double)GetCPS(1) / -10.0 * Kd
    	);
    }
    else
    {
        fixed_SPEED = (
             (double)(GetCPS(0) - ofset) / 100.0 * Kp
           + (double)GetCPS(1) / -10.0 * Kd
		);
    }
    
    return constrain(fixed_SPEED, -1.00, 1.00);
}