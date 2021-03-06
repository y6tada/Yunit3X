// ---------------------------------------------------------------------------- //
// ---------------------------------------------------------------------------- //
void EC_init()
/* Setup rotary encoder, initial input and pinMode setup 						*/
{
    curDat = 0;
    if(digitalRead(ECA))
        befDat |= 2;
    if(digitalRead(ECB))  
        befDat |= 1;
    
    /* LED enables when this digital pins becomes HIGH                          */
    pinMode(RGBEC_R,OUTPUT);
    pinMode(RGBEC_G,OUTPUT);
    pinMode(RGBEC_B,OUTPUT);
}
// ---------------------------------------------------------------------------- //
void EC_BackWord()
/* Read the incremental type rotary encoder 									*/
/* Return the value of rotation number of steps 								*/
{
    byte dat;
    signed char val;
    
    curDat = 0;
    if(digitalRead(ECA)) {
        curDat |= 2;
    }
    if(digitalRead(ECB)) {
        curDat |= 1;
    }

    if(befDat == curDat) {
        if(!inputMatch) {   
            matchCnt++;
            if(matchCnt >= 5) {
                inputMatch = true;
                val = checkEnc(curDat);
                if(val != 0) {
                    Count += val;
                    tone(toneOUT, tone_H * 3, 15);
                    delay(15);
                }
            }
        }
    }
    else
    {  
        befDat = curDat;
        matchCnt = 0;
        inputMatch = false;
    }
}
// ---------------------------------------------------------------------------- //
signed char checkEnc(byte dat)
{
    rotPat <<= 2;
    rotPat |= (dat & 0x03);
    
    switch (rotPat)
    {
    	case 0x4B:
    	return 1;
    	break;
    	//
    	case 0x87:
    	return -1;
    	break;
    	//
    	default:
    	return 0;
    	break;
    }
}
// ---------------------------------------------------------------------------- //
