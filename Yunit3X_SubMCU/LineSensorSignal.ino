AnalogIn LINE_R (A1);
AnalogIn LINE_L (A2);
AnalogIn LINE_B (A3);

#define EMERGENCY_CALL_HIGH 2000
#define EMERGENCY_CALL_LOW  1000

const unsigned int DecisionTime = 35;

bool 			LS_R, LS_L, LS_B;
uint8_t 		ThreeSensorShift;
unsigned int 	BreakUpTime_ms;
unsigned int 	RunTime_ms;
long 			DeltaTimer_ms;

void LINESENSOR_SIGNAL_OUTPUT(unsigned int ComparateValue)
{

	setComparator(ComparateValue, &LS_R, &LS_L, &LS_B);

	if (LS_B || LS_L || LS_R) {

		DeltaTimer_ms = millis();
		do {
			tone(toneOUT, EMERGENCY_CALL_HIGH);

			setOutputSignal (7);
			setComparator(ComparateValue, &LS_R, &LS_L, &LS_B);
			ThreeSensorShift = (LS_B << 2 | LS_L << 1 | LS_R);

		} while (millis() < DeltaTimer_ms + DecisionTime);


		BreakUpTime_ms = 100;
		while (true) {

			setComparator(ComparateValue, &LS_R, &LS_L, &LS_B);
			if (LS_B || LS_L || LS_R) {
				BreakUpTime_ms = 100;
				setOutputSignal(ThreeSensorShift);
				tone(toneOUT, EMERGENCY_CALL_LOW);
			}
			else {
				BreakUpTime_ms --;
			}

			while (millis() < RunTime_ms);
			RunTime_ms = millis();

			if (BreakUpTime_ms <= 0) break;
		}

		noTone(toneOUT);
		setOutputSignal(0);
	}
	else {
		noTone(toneOUT);
		setOutputSignal(0);
	}

}


void setOutputSignal(uint8_t ShiftData)
{
	switch (ShiftData) {
		case 1:
			digitalWrite(SIGNAL_R ,1);
			digitalWrite(SIGNAL_L ,0);
			digitalWrite(SIGNAL_B ,0);
			break;

		case 2:
			digitalWrite(SIGNAL_R ,0);
			digitalWrite(SIGNAL_L ,1);
			digitalWrite(SIGNAL_B ,0);
			break;

		case 4:
			digitalWrite(SIGNAL_R ,0);
			digitalWrite(SIGNAL_L ,0);
			digitalWrite(SIGNAL_B ,1);
			break;

		case 3:
			digitalWrite(SIGNAL_R ,1);
			digitalWrite(SIGNAL_L ,1);
			digitalWrite(SIGNAL_B ,0);
			break;

		case 5:
			digitalWrite(SIGNAL_R ,1);
			digitalWrite(SIGNAL_L ,0);
			digitalWrite(SIGNAL_B ,1);
			break;

		case 6:
			digitalWrite(SIGNAL_R ,0);
			digitalWrite(SIGNAL_L ,1);
			digitalWrite(SIGNAL_B ,1);
			break;

		case 7:
			digitalWrite(SIGNAL_R ,1);
			digitalWrite(SIGNAL_L ,1);
			digitalWrite(SIGNAL_B ,1);
			break;

		default:
			digitalWrite(SIGNAL_R ,0);
			digitalWrite(SIGNAL_L ,0);
			digitalWrite(SIGNAL_B ,0);
			break;
	}

}

void setComparator(unsigned int value, bool *Right, bool *Left, bool *Back)
{
	*Right = (LINE_R > value) ? true : false;
	*Left  = (LINE_L > value) ? true : false;
	*Back  = (LINE_B > value) ? true : false;
}