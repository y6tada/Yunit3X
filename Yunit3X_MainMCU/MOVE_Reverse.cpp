#include "mbed.h"

int REVERSE(int data)
{
    switch (data)
    {
        case 1:	return -8;	break;
        case 2:	return -7;	break;
        case 3:	return -6;	break;
        case 4:	return -5;	break;
        case 5:	return -4;	break;
        case 6:	return -3;	break;
        case 7:	return -2;	break;
        case 8:	return -1;	break;
            
        case -8: return 1;	break;
        case -7: return 2;	break;
        case -6: return 3;	break;
        case -5: return 4;	break;
        case -4: return 5;	break;
        case -3: return 6;	break;
        case -2: return 7;	break;
        case -1: return 8;	break;
    }
    return 0;
}

int REVERSE_LeftDisable(int data)
{
	switch (data) {
		case 1:	return -8;	break;
		case 2:	return -7;	break;
		case 3:	return -6;	break;
		case 4:	return -5;	break;
		case 5:	return -4;	break;
		case 6:	return -3;	break;
		case 7:	return -2;	break;
		case 8:	return -1;	break;
			
		case -8: return -8;	break;
		case -7: return -7;	break;
		case -6: return -6;	break;
		case -5: return -5;	break;
		case -4: return -4;	break;
		case -3: return -3;	break;
		case -2: return -2;	break;
		case -1: return -1;	break;
	}
	return 0;
}

int REVERSE_RightDisable (int data)
{
	switch (data) {
		case 1:	return 1;	break;
		case 2:	return 2;	break;
		case 3:	return 3;	break;
		case 4:	return 4;	break;
		case 5:	return 5;	break;
		case 6:	return 6;	break;
		case 7:	return 7;	break;
		case 8:	return 8;	break;
			
		case -8: return -8;	break;
		case -7: return -7;	break;
		case -6: return -6;	break;
		case -5: return -5;	break;
		case -4: return -4;	break;
		case -3: return -3;	break;
		case -2: return -2;	break;
		case -1: return -1;	break;
	}
	return 0;
}