#include "mbed.h"

/* Three motor drivers DigitalOut pins and PWM pins setup --------------------- */
DigitalOut  MotorR_A    (PB_4 );
DigitalOut  MotorR_B    (PB_15);
PwmOut      MotorR_PWM  (PB_10);

DigitalOut  MotorL_A    (PB_13);
DigitalOut  MotorL_B    (PA_8 );
PwmOut      MotorL_PWM  (PB_1 );

DigitalOut  MotorB_A    (PB_5 );
DigitalOut  MotorB_B    (PB_3 );
PwmOut      MotorB_PWM  (PB_14);
/* ---------------------------------------------------------------------------- */
/* Three Motor-Driver's PWM frequency setup ----------------------------------- */
void ThreeMotorInit(int us)
{
    MotorR_PWM.period_us(us);
    MotorB_PWM.period_us(us);
    MotorL_PWM.period_us(us);
}
/* Right side motor control --------------------------------------------------- */
static void MOTOR_R(double speed)
{
    if (speed < 0)
    {
        MotorR_A = 1;
        MotorR_B = 0;
        MotorR_PWM = -1 * speed;
    }
    else if (speed > 0)
    {
        MotorR_A = 0;
        MotorR_B = 1;
        MotorR_PWM = speed;
    }
    else
    {
        MotorR_A = 0;
        MotorR_B = 0;
        MotorR_PWM = 0;
    }
}
/* Left side motor control ---------------------------------------------------- */
static void MOTOR_L(double speed)
{
    if (speed < 0)
    {
        MotorL_A = 1;
        MotorL_B = 0;
        MotorL_PWM = -1 * speed;
    }
    else if (speed > 0)
    {
        MotorL_A = 0;
        MotorL_B = 1;
        MotorL_PWM = speed;
    }
    else
    {
        MotorL_A = 0;
        MotorL_B = 0;
        MotorL_PWM = 0;
    }
}
/* Back side motor control ---------------------------------------------------- */
static void MOTOR_B(double speed)
{
    if (speed < 0)
    {
        MotorB_A = 1;
        MotorB_B = 0;
        MotorB_PWM = -1 * speed;
    }
    else if (speed > 0)
    {
        MotorB_A = 0;
        MotorB_B = 1;
        MotorB_PWM = speed;
    }
    else
    {
        MotorB_A = 0;
        MotorB_B = 0;
        MotorB_PWM = 0;
    }
}
/* Robot's three motors control ----------------------------------------------- */
void MoveCP(int degree, double pwr, double fixed_CPS)
{
    MOTOR_R( sin( (degree - 60.0 ) / 180.0 * 3.14) * pwr + fixed_CPS );
    MOTOR_B( sin( (degree - 180.0) / 180.0 * 3.14) * pwr + fixed_CPS );
    MOTOR_L( sin( (degree - 300.0) / 180.0 * 3.14) * pwr + fixed_CPS );
}
/* ---------------------------------------------------------------------------- */
void MovePP(double moment, int BreakEnable)
{
    if (BreakEnable)
    {
        MotorR_A = 1;
        MotorR_B = 1;
        MotorR_PWM = 0;
        //
        MotorB_A = 1;
        MotorB_B = 1;
        MotorB_PWM = 0;
        //
        MotorL_A = 1;
        MotorL_B = 1;
        MotorL_PWM = 0;
    }
    else
    {
        MOTOR_R(moment);
        MOTOR_L(moment);
        MOTOR_B(moment);
    }
}
/* ---------------------------------------------------------------------------- */