#include "OUTOB_BAUNDS.h"

#define SIG_R	1
#define SIG_B	2
#define SIG_L	4
#define SIG_RB	6
#define SIG_LB	3
#define SIG_RL	5

Timer TIMER;
Timer TIMER2;

const int		BreakTime	= 220;
const double	BreakRatio	= 0.65;

int defaultXVI = 0;

int speed_out = 0;
int speed_in = 0;


void AntiBaunds(int deg, long time)
{
    speed_out = 0;
    MoveCP(deg, ((float)time / (float)out_max) * 0.8, PID(0));
}


int map16(int data)
{
    if (data < 0 ) return (data + 16);
    else if (data > 16) return (data - 16);
    else return data;
}


void OUTOB_BAUNDS(void)
{
	
	TIMER.start();
	TIMER2.start();
	
	if (LINE_R && LINE_B && LINE_L) {
		
		MovePP(0, 1);
		if (TIMER.read_ms() > 400) {
			while (TIMER.read_ms() < 750) {
				
				MOVE_BUD();
			}
			return;
		}
		
	}
	else if (LINE_R || LINE_B || LINE_L) {
		
		TIMER.reset();
		TIMER2.reset();
		while (TIMER.read_ms() < BreakTime) {
			
			switch (LINE_R << 2 | LINE_B << 1 | LINE_L) {
					
				case SIG_RL:
					
					if (GetUSD(4) > 80) {
						
						if (GetUSD(5) < 0)
							MoveCP(135, BreakRatio, PID(0));
						
						if (GetUSD(5) > 0)
							MoveCP(-135, BreakRatio, PID(0));
					}
					else {
						MoveCP(180, BreakRatio, PID(0));
					}

//					MoveCP(180, BreakRatio, PID(0));
//					break;
					
				case SIG_R:
					
					if (GetUSD(2) > 50) {
						MoveCP(140, BreakRatio, PID(0));
					}
					else {
						MoveCP(90, BreakRatio, PID(0));
					}
					break;
					
				case SIG_L:
					if (GetUSD(2) > 50) {
						MoveCP(-140, BreakRatio, PID(0));
					}
					else {
						MoveCP(-90, BreakRatio, PID(0));
					}
					break;
					
				case SIG_B:
					if (GetUSD(4) > 60) {
						
						if (GetUSD(5) < 0)
							MoveCP(45, BreakRatio, PID(0));
							
						if (GetUSD(5) > 0)
							MoveCP(-45, BreakRatio, PID(0));
					}
					else {
						MoveCP(0, BreakRatio, PID(0));
					}
					break;
					
				case SIG_RB:
					MoveCP(45, BreakRatio, PID(0));
					break;
					
				case SIG_LB:
					MoveCP(-45, BreakRatio, PID(0));
					break;
					
				default:
					defaultXVI = GetIR(1);
/**/				goto nextWhile;
					break;
			}
			
			pc.printf("%d", GetIR(1));
			
			while (TIMER.read_ms() % 13);
		}
		
/**/	nextWhile:
		defaultXVI = GetIR(1);
		TIMER.reset();
		while (true) {
			
			if (!GetIR(0)) return;
			
			if (TIMER.read_ms() > 800) {
				
				break;
			}
			else {
				
				if (defaultXVI == GetIR(1)) {
					MovePP(0, 1);
				}
				else {
					break;
				}
			}

			while (TIMER.read_ms() % 13);
		}
		
	}

	/*
    switch (LINE_R << 2 | LINE_B << 1 | LINE_L)
    {
			
		case 7: // 検出方向判断中のシグナル
			MovePP(0, 1);
			break;
			
			
        case SIG_R:
            while (TIMER.read_ms() < in_max) {
                AntiBaunds( 90, TIMER.read_ms());
            }
            break;
            
        case SIG_B:
            while (TIMER.read_ms() < in_max) {
                AntiBaunds(0  , TIMER.read_ms());
            }
            break;
            
        case SIG_L:
            while (TIMER.read_ms() < in_max) {
                AntiBaunds(-90, TIMER.read_ms());
            }
            break;
            
        case SIG_RB:
            while (TIMER.read_ms() < in_max) {
                AntiBaunds( 45, TIMER.read_ms());
            }
            break;
            
        case SIG_LB:
            while (TIMER.read_ms() < in_max) {
                AntiBaunds(-45, TIMER.read_ms());
            }
            break;
            
        case SIG_RL:
            while (TIMER.read_ms() < in_max) {
                AntiBaunds(180, TIMER.read_ms());
            }
            break;
    }
    
    while (true) {

        MOVE_BUD2();
        if (! SW_GRN && ! SW_RED) break;
        if (!LINE_R && !LINE_L && !LINE_B) break;
    }
	*/
    
    TIMER.stop();
}