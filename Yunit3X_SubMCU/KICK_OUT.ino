void KICK_OUT(void)
{
    if (analogRead(A4) < 800) digitalWrite(KICKER_OUT ,HIGH);
    else digitalWrite(KICKER_OUT ,LOW);
}
