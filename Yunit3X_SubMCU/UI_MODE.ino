int where = 0;

void UI_MODE(void)
{
    EC_BackWord();

    switch (Count % 4)
    {
        case 0:
        /* ============================== コンパスセンサの設定など ============================== */
            if (where) {

                where = 0;

                EC_RGB(1);
                LCD.setRGB(50,0,0);
                LCD.clear();
                LCD.setCursor(5,0);
                LCD.print("Compass");
                LCD.setCursor(3,1);
                LCD.print("Calibration");
            }

            digitalWrite(HMCmc_calSIG, LOW);

            if (digitalRead(EC_SW))
            {
                bool isHold = false;
                int EC_SWcount = 0;
                while (digitalRead(EC_SW)) {
                    EC_SWcount ++;
                    delay(1);

                    if (EC_SWcount > 300) {
                        isHold = true;
                        MyBeep(1);
                        break;
                    }
                }

                while (digitalRead(EC_SW));

                if (isHold) {

                    digitalWrite(HMCmc_calSIG, 1);
                    while (1) {
                        if (digitalRead(EC_SW)) {
                            digitalWrite(HMCmc_calSIG, 0);
                            tone(14,tone_H *3,100);
                            break;
                        }
                    }
                }
                else {
                    tone(14, tone_H * 3, 100);
                    digitalWrite(HMCmc_calSIG, 1);
                    delay(100);
                    digitalWrite(HMCmc_calSIG, 0);
                    delay(50);
                }
            }

        break;


        case 1:
        /* ============================== シリアルデバッグ出力モード ============================== */
            digitalWrite(HMCmc_calSIG, LOW);

            if (where != 1) {

                where = 1;

                EC_RGB(2);
                LCD.setRGB(0,35,0);
                LCD.clear();
                LCD.setCursor(2,0);
                LCD.print("Serial Output");
            }

            if (digitalRead(EC_SW))
            {
                int EC_SWcount = 0;
                for (int CT = 0; CT < 300; CT++) {
                    if (digitalRead(EC_SW) == 1) { EC_SWcount ++; }
                    delay(1);
                }

                while (digitalRead(EC_SW)) {}
                
                if (EC_SWcount >= 250)
                {
                    Serial.begin(115200);
                    MyBeep(1);

                    while (1)
                    {
                        Serial.print(analogRead(A1));
                        Serial.print("\t");
                        Serial.print(analogRead(A2));
                        Serial.print("\t");
                        Serial.print(analogRead(A3));
                        Serial.print("\t");
                        Serial.println(analogRead(A4));

                        if (digitalRead(EC_SW) == HIGH) { break; }
                    }
                }
                else {
                    tone(14,tone_H *3,100);
                    delay(100);
                }
            }
        break;


        case 2:
        /* ============================== キッカーデモ・モード   ============================== */
            digitalWrite(HMCmc_calSIG, LOW);

            if (where != 2) {

                where = 2;

                EC_RGB(3);
                LCD.setRGB(0,0,60);
                LCD.clear();
                LCD.setCursor(4,0);
                LCD.print("Kick Demo");
            }

            if (digitalRead(EC_SW))
            {
                int EC_SWcount = 0;
                for (int CT = 0; CT < 300; CT++) {
                    if (digitalRead(EC_SW) == 1) { EC_SWcount ++; }
                    delay(1);
                }
                
                while (digitalRead(EC_SW)) {}

                if (EC_SWcount >= 250) {
                    MyBeep(1);
                    while (1)
                    {
                        if (digitalRead(EC_SW) == HIGH) { break; }

                        if (analogRead(A4) < 800)
                            digitalWrite(Nucleo_PC_4 ,HIGH);
                        else
                            digitalWrite(Nucleo_PC_4 ,LOW);
                    }
                }
                else {
                    tone(14,tone_A *4,300);
                    delay(300);
                    digitalWrite(Nucleo_PC_4 ,HIGH);
                    delay(80);
                    digitalWrite(Nucleo_PC_4 ,LOW);
                    delay(150);
                }
            }
        break;


        case 3:
        /* ============================== ラインセンサの閾値設定モード ============================== */
            digitalWrite(HMCmc_calSIG, LOW);
            
            if (where != 3) {

                where = 3;

                EC_RGB(0);
                LCD.setRGB(30,30,30);
                LCD.clear();
                LCD.setCursor(0,0);
                LCD.print("setup LineSensor");
                LCD.setCursor(3,2);
                LCD.print("RED:Detect");
            }            

            if (digitalRead(EC_SW))
            {
                int EC_SWcount = 0;
                for (int CT = 0; CT < 300; CT++) {
                    if (digitalRead(EC_SW)) EC_SWcount ++;
                    delay(1);
                }
                
                while (digitalRead(EC_SW));

                if (EC_SWcount >= 300)
                {
                    MyBeep(1);
                    Count = 0;

                    while (digitalRead(EC_SW) == LOW)
                    {
                        EC_BackWord();

                        if (analogRead(A1) > LineSensorVal || analogRead(A2) > LineSensorVal || analogRead(A3) > LineSensorVal)
                            EC_RGB(1);
                        else
                            EC_RGB(2);

                        LineSensorVal = 200 + Count * -10;
                    }

                    EC_RGB(0);
                    LineSensorVal = 200 + Count * -10;
                    // GCEEPROM::write(LineSensorVal, LineSensorValAddress);

                    Count = 1003;
                }
                else
                {
                    tone(14,tone_H *3,100);
                    delay(100);

                    while (true)
                    {
                        if (analogRead(A1) > LineSensorVal || analogRead(A2) > LineSensorVal || analogRead(A3) > LineSensorVal)
                            EC_RGB(1);
                        else
                            EC_RGB(2);

                        if (digitalRead(EC_SW)) break;
                    }

                    EC_RGB(0);

                    tone(14,tone_F *3,50);
                    delay(50);
                    noTone(14);
                    delay(25);
                    tone(14,tone_F *3,50);
                    delay(50);

                    while (digitalRead(EC_SW)) {}
                }
            }
        break;
// ---------------------------------------------------------------------------------- //
    }
}
