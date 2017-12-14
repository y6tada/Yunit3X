#include "mbed.h"

DigitalIn   HLDsensor_IN   (PC_4);
DigitalOut  KICKER_OUT  (PC_9);

Timer KickerTImer;
Timeout DisableTimer;
static int KickPointTimer = 0;

static void KcikDisable(void)
{
    KICKER_OUT = 0;
}

void KickerTimer_START(void)
{
    KickerTImer.start();
}

void KICKER_Enable(void)
{
    if (HLDsensor_IN) {
        if (KickerTImer.read_ms() > KickPointTimer + 200) {
            KICKER_OUT = 1;
            KickPointTimer = KickerTImer.read_ms();
            DisableTimer.attach_us(KcikDisable, 50000);
        }
    }
    else {
        KICKER_OUT = 0;
    }
}