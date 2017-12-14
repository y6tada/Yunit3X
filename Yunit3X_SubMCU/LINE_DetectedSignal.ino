#define EMERGENCY_CALL 1000

void LINE_Detected(void)
{
	// ------------------------------------------------------------------------- //
	if (analogRead(A1) > LineSensorVal)
	{
		digitalWrite(SIGNAL_R ,1);
		digitalWrite(SIGNAL_B  ,0);
		digitalWrite(SIGNAL_L  ,0);

		int TIME_CT = 0;
		while (TIME_CT < 200)
		{
			if (analogRead(A1) > LineSensorVal && analogRead(A2) > LineSensorVal)
				goto A2_A1;
			if (analogRead(A1) > LineSensorVal && analogRead(A3) > LineSensorVal)
				goto A1_A3;

			TIME_CT ++;
		}

		TIME_CT = 0;
		while (TIME_CT < 120)
		{
			tone(14 , EMERGENCY_CALL);
			if (analogRead(A1) > LineSensorVal)
				TIME_CT = 100;
			else if (analogRead(A2) > LineSensorVal)
				TIME_CT = 50;
			else if (analogRead(A3) > LineSensorVal)
				TIME_CT = 0;
			else
			{
				if (analogRead(A4) < 800)
					digitalWrite(KICKER_OUT ,HIGH);
				else
					digitalWrite(KICKER_OUT ,LOW);

				TIME_CT ++;
			}
		}

		digitalWrite(SIGNAL_R ,0);
		digitalWrite(SIGNAL_B  ,0);
		digitalWrite(SIGNAL_L  ,0);
	}
	// ------------------------------------------------------------------------- //
	else if (analogRead(A3) > LineSensorVal)
	{
		digitalWrite(SIGNAL_R ,0);
		digitalWrite(SIGNAL_B  ,0);
		digitalWrite(SIGNAL_L  ,1);

		int TIME_CT = 0;
		while (TIME_CT < 200)
		{
			if (analogRead(A1) > LineSensorVal && analogRead(A3) > LineSensorVal)
				goto A1_A3;
			if (analogRead(A2) > LineSensorVal && analogRead(A3) > LineSensorVal)
				goto A2_A3;

			TIME_CT ++;
		}

		TIME_CT = 0;
		while (TIME_CT < 120)
		{
			tone(14 , EMERGENCY_CALL);

			if (analogRead(A3) > LineSensorVal)
				TIME_CT = 100;
			else if (analogRead(A2) > LineSensorVal)
				TIME_CT = 50;
			else if (analogRead(A1) > LineSensorVal)
				TIME_CT = 0;
			else
			{
				if (analogRead(A4) < 800)
					digitalWrite(KICKER_OUT ,HIGH);
				else
					digitalWrite(KICKER_OUT ,LOW);

				TIME_CT ++;
			}
		}
		
		digitalWrite(SIGNAL_R ,0);
		digitalWrite(SIGNAL_B  ,0);
		digitalWrite(SIGNAL_L  ,0);
	}
	// ------------------------------------------------------------------------- //
	else if (analogRead(A2) > LineSensorVal)
	{
		digitalWrite(SIGNAL_R ,0);
		digitalWrite(SIGNAL_B  ,1);
		digitalWrite(SIGNAL_L  ,0);

		int TIME_CT = 0;
		while (TIME_CT < 200)
		{
			if (analogRead(A2) > LineSensorVal && analogRead(A1) > LineSensorVal)
				goto A2_A1;
			if (analogRead(A2) > LineSensorVal && analogRead(A3) > LineSensorVal)
				goto A2_A3;

			TIME_CT ++;
		}

		TIME_CT = 0;
		while (TIME_CT < 180)
		{
			tone(14 , EMERGENCY_CALL);

			if (analogRead(A2) > LineSensorVal)
				TIME_CT = 90;
			else if (analogRead(A1) > LineSensorVal || analogRead(A3) > LineSensorVal)
				TIME_CT = 0;
			else
			{
				if (analogRead(A4) < 800)
					digitalWrite(KICKER_OUT ,HIGH);
				else
					digitalWrite(KICKER_OUT ,LOW);

				TIME_CT ++;
			}
		}

		digitalWrite(SIGNAL_R ,0);
		digitalWrite(SIGNAL_B  ,0);
		digitalWrite(SIGNAL_L  ,0);
	}
	// ------------------------------------------------------------------------- //
	else if (analogRead(A2) > LineSensorVal && analogRead(A1) > LineSensorVal)
	{
		A2_A1:

		digitalWrite(SIGNAL_R ,1);
		digitalWrite(SIGNAL_B  ,1);
		digitalWrite(SIGNAL_L  ,0);

		int TIME_CT = 0;
		while (TIME_CT < 350)
		{
			tone(14 , EMERGENCY_CALL);

			if (analogRead(A2) > LineSensorVal || analogRead(A1) > LineSensorVal)
				TIME_CT = 150;
			else if (analogRead(A3) > LineSensorVal)
				TIME_CT = 0;
			else
			{
				if (analogRead(A4) < 800)
					digitalWrite(KICKER_OUT ,HIGH);
				else
					digitalWrite(KICKER_OUT ,LOW);

				TIME_CT ++;
			}
		}

		digitalWrite(SIGNAL_R ,0);
		digitalWrite(SIGNAL_B  ,0);
		digitalWrite(SIGNAL_L  ,0);
	}
	// ------------------------------------------------------------------------- //
	else if (analogRead(A2) > LineSensorVal && analogRead(A3) > LineSensorVal)
	{
		A2_A3:

		digitalWrite(SIGNAL_R ,0);
		digitalWrite(SIGNAL_B  ,1);
		digitalWrite(SIGNAL_L  ,1);

		int TIME_CT = 0;
		while (TIME_CT < 350)
		{
			tone(14 , EMERGENCY_CALL);

			if (analogRead(A2) > LineSensorVal || analogRead(A3) > LineSensorVal)
				TIME_CT = 150;
			else if (analogRead(A1) > LineSensorVal)
				TIME_CT = 0;
			else 
			{
				if (analogRead(A4) < 800)
					digitalWrite(KICKER_OUT ,HIGH);
				else
					digitalWrite(KICKER_OUT ,LOW);

				TIME_CT ++;
			}
		}

		digitalWrite(SIGNAL_R ,0);
		digitalWrite(SIGNAL_B  ,0);
		digitalWrite(SIGNAL_L  ,0);
	}
	// ------------------------------------------------------------------------- //
	else if (analogRead(A1) > LineSensorVal && analogRead(A3) > LineSensorVal)
	{
		A1_A3:

		digitalWrite(SIGNAL_R ,1);
		digitalWrite(SIGNAL_B  ,0);
		digitalWrite(SIGNAL_L  ,1);

		int TIME_CT = 0;
		while (TIME_CT < 350)
		{
			tone(14 , EMERGENCY_CALL);

			if (analogRead(A1) > LineSensorVal || analogRead(A3) > LineSensorVal)
				TIME_CT = 150;
			else if (analogRead(A2) > LineSensorVal)
				TIME_CT = 0;
			else
			{
				if (analogRead(A4) < 800)
					digitalWrite(KICKER_OUT ,HIGH);
				else
					digitalWrite(KICKER_OUT ,LOW);

				TIME_CT ++;
			}
		}

		digitalWrite(SIGNAL_R ,0);
		digitalWrite(SIGNAL_B  ,0);
		digitalWrite(SIGNAL_L  ,0);
	}
	// ------------------------------------------------------------------------- //
}