#include "mbed.h"
#include "Robots.h"

const int GoalDegrGain 	= 1;
const int SPEED1 		= 40 / 0.70;
const int SPEED2 		= 20 / 0.80;


const int HLDtimeout = 40;

PwmOut Dribbler_PWM(PA_3);

LPFilter DribGoal_MAV(3);

Serial		pc			(USBTX , NC);
Serial		U4_CPS		(NC , PA_10);

DigitalIn   SW_RED      (PC_8);
DigitalIn   SW_GRN      (PC_5);

DigitalIn   LINE_R      (PA_12);
DigitalIn   LINE_L      (PA_11);
DigitalIn   LINE_B      (PB_12);
/* ------------------------------------------------------------------------------------------ */

void AllSensors_sortData(void)
{
    CPS_sortData( U4_CPS.getc() );
    IR_sortData();
    USD_sortData(11000);
}

void sensotTest()
{
	while (true) {
		if (!SW_RED && !SW_GRN) {
			
			MovePP(0, 0);
			
			int R = LINE_R;
			int L = LINE_L;
			int B = LINE_B;
			
			pc.printf("%d\t%d\t%d\n" ,R ,L, B);
//			pc.printf("%d\t%d\t%d\n" ,GetUSD(4) ,GetUSD(5), GetUSD(3));
			
			//		pc.printf("%d\n" ,GetIR(2));
			//		pc.printf("%d\t%d\t%d\t%d\n" ,GetUSD(1) ,GetUSD(2), GetUSD(3), GetUSD(5));
			
		}
		else {
			
		}
	}
}
/* ------------------------------------------------------------------------------------------ */


int main(void)
{
	
    KickerTimer_START();
	pc.baud(115200);
    U4_CPS.baud(115200);
    U4_CPS.attach(AllSensors_sortData , Serial::RxIrq);
    ThreeMotorInit(50);
	Timer HLDtimer;
	
//	sensotTest();
	
	static int	speed			= 0;
    static int8_t GoalDegr		= 0;
	static uint8_t HLD_count	= 0;
	static int ballTrackDeg		= 0;
    
    while (true) {

        if (! SW_GRN && ! SW_RED) {
			
            MovePP(0, 0);
            KICKER_Enable();
			Dribbler_PWM = 0.0;
            speed = 0;
        }
        else {
			
			if (GetIR(0) > -2 && GetIR(0) < 2 && GetIR(2) == 1) {
				Dribbler_PWM = 1.0;
			}
			else {
				Dribbler_PWM = 0.0;
			}
			
			ballTrackDeg =  BallTracking(SetTD(GetIR(1),GetIR(2)), 3.0);
			
			/* -----------------------------------------------------------------------------*/
            if (LINE_R || LINE_L || LINE_B) {
				
                OUTOB_BAUNDS();
                speed = 0;
            }
			/* -----------------------------------------------------------------------------*/
            else if (SW_GRN && ! SW_RED) {
				
                if (GetIR(2) > 0) {
					
                    if (HLDsensor_IN) {
						
						if (HLD_count > 180) {
							HLD_count = 0;
							
							HLDtimer.start();
							HLDtimer.reset();
							while (HLDsensor_IN && HLDtimer.read_ms() <= HLDtimeout) {
								if (HLDtimer.read_ms() >= HLDtimeout) KICKER_Enable();
							}
							HLDtimer.stop();
						}
						else {
							HLD_count ++;
							if (GetUSD(5) > 36) GoalDegr = 40;
							else if (GetUSD(5) > 15) GoalDegr = 20;
							
							if (GetUSD(5) < -50) GoalDegr = -40;
							else if (GetUSD(5) < -36) GoalDegr = -20;
						}
                    }
                    else {
						HLD_count = 0;
						
						if (GetUSD(5) > 35 && GetUSD(4) > 80)
							GoalDegr = 10;
						else if (GetUSD(5) < -25 && GetUSD(4) > 80)
							GoalDegr = -10;
						else
							GoalDegr = 0;
                    }
					
					MoveCP (
						ballTrackDeg,
						(double)speed / SPEED1,
						PID(DribGoal_MAV.setMAV(GoalDegr))
					);
					if (speed <= 40) speed ++;
					
                }
                else {
                    speed = 0;
                    MOVE_BUD();
                }
            }
			/* ------------------------------------------------------------------------------ */
			else if (SW_RED && ! SW_GRN) {
				
				if (GetIR(2) > 0) {
					
					if (GetUSD(5) > 15 && GetUSD(4) > 60)
						GoalDegr = 15;
					else if (GetUSD(5) < -15 && GetUSD(4) > 60)
						GoalDegr = -15;
					else
						GoalDegr = 0;
					
					if (HLDsensor_IN) {
						
						if (HLD_count > 180) {
							
							HLD_count = 0;
							
							HLDtimer.start();
							HLDtimer.reset();
							
							while (HLDsensor_IN && HLDtimer.read_ms() <= HLDtimeout) {
								if (HLDtimer.read_ms() >= HLDtimeout) KICKER_Enable();
							} HLDtimer.stop();
						}
						else {
							
							HLD_count ++;
							if (GetUSD(5) > 36) GoalDegr = 40;
							else if (GetUSD(5) > 15) GoalDegr = 20;
							
							if (GetUSD(5) < -50) GoalDegr = -40;
							else if (GetUSD(5) < -36) GoalDegr = -20;
						}
					}
					else {
						
						HLD_count = 0;
						GoalDegr = 0;
					}
					
					MoveCP (
							ballTrackDeg,
							(double)speed / SPEED2,
							PID(DribGoal_MAV.setMAV(GoalDegr))
							);
					if (speed <= 20) speed ++;
					
				}
				else {
					speed = 0;
					MOVE_BUD();
				}
			}
            /* ------------------------------------------------------------------------------ */
        }
    }
}
