#include "mbed.h"

/* -------------------------------------------------------------------------------- */
#define L1D1	2
#define L1D2	4
#define L1D3	5
#define L1D4	6
#define L1D5	8
#define L1D6	-8
#define L1D7	-7
#define L1D8	-6

#define L2D1	1
#define L2D2	3
#define L2D3	5
#define L2D4	6
#define L2D5	7
#define L2D6	8
#define L2D7	-8
#define L2D8	-7

#define L3D1	1
#define L3D2	3
#define L3D3	4
#define L3D4	5
#define L3D5	6
#define L3D6	7
#define L3D7	8
#define L3D8	-8

#define L4D1	1
#define L4D2	3
#define L4D3	4
#define L4D4	5
#define L4D5	6
#define L4D6	7
#define L4D7	8
#define L4D8	-8
/* -------------------------------------------------------------------------------- */
int SetTD(int XVI, int distance)
{
    switch (distance)
    {
    	/* ************************************************************************ */
        case 1:
            switch (XVI)
            {
                case 1:	return  1 * L1D1;	break;
                case 2:	return  1 * L1D2;	break;
                case 3:	return  1 * L1D3;	break;
                case 4:	return  1 * L1D4;	break;
                case 5:	return  1 * L1D5;	break;
                case 6:	return  1 * L1D6;	break;
                case 7:	return  1 * L1D7;	break;
                case 8:	return  1 * L1D8;	break;
                    
                case -8: return -1 * L1D8;	break;
                case -7: return -1 * L1D7;	break;
                case -6: return -1 * L1D6;	break;
                case -5: return -1 * L1D5;	break;
                case -4: return -1 * L1D4;	break;
                case -3: return -1 * L1D3;	break;
                case -2: return -1 * L1D2;	break;
                case -1: return -1 * L1D1;	break;
            }
        break;
    	/* ************************************************************************ */
        case 2:
            switch (XVI)
            {
                case 1:	return  1 * L2D1;	break;
                case 2:	return  1 * L2D2;	break;
                case 3:	return  1 * L2D3;	break;
                case 4:	return  1 * L2D4;	break;
                case 5:	return  1 * L2D5;	break;
                case 6:	return  1 * L2D6;	break;
                case 7:	return  1 * L2D7;	break;
                case 8:	return  1 * L2D8;	break;
                    
                case -8: return -1 * L2D8;	break;
                case -7: return -1 * L2D7;	break;
                case -6: return -1 * L2D6;	break;
                case -5: return -1 * L2D5;	break;
                case -4: return -1 * L2D4;	break;
                case -3: return -1 * L2D3;	break;
                case -2: return -1 * L2D2;	break;
                case -1: return -1 * L2D1;	break;
            }
        break;
    	/* ************************************************************************ */
        case 3:
            switch (XVI)
            {
                case 1:	return  1 * L3D1;	break;
                case 2:	return  1 * L3D2;	break;
                case 3:	return  1 * L3D3;	break;
                case 4:	return  1 * L3D4;	break;
                case 5:	return  1 * L3D5;	break;
                case 6:	return  1 * L3D6;	break;
                case 7:	return  1 * L3D7;	break;
                case 8:	return  1 * L3D8;	break;
                    
                case -8: return -1 * L3D8;	break;
                case -7: return -1 * L3D7;	break;
                case -6: return -1 * L3D6;	break;
                case -5: return -1 * L3D5;	break;
                case -4: return -1 * L3D4;	break;
                case -3: return -1 * L3D3;	break;
                case -2: return -1 * L3D2;	break;
                case -1: return -1 * L3D1;	break;
            }
        break;
    	/* ************************************************************************ */
        case 4:
            switch (XVI)
            {
                case 1:	return  1 * L4D1;	break;
                case 2:	return  1 * L4D2;	break;
                case 3:	return  1 * L4D3;	break;
                case 4:	return  1 * L4D4;	break;
                case 5:	return  1 * L4D5;	break;
                case 6:	return  1 * L4D6;	break;
                case 7:	return  1 * L4D7;	break;
                case 8:	return  1 * L4D8;	break;
                    
                case -8: return -1 * L4D8;	break;
                case -7: return -1 * L4D7;	break;
                case -6: return -1 * L4D6;	break;
                case -5: return -1 * L4D5;	break;
                case -4: return -1 * L4D4;	break;
                case -3: return -1 * L4D3;	break;
                case -2: return -1 * L4D2;	break;
                case -1: return -1 * L4D1;	break;
            }
        break;
    	/* ************************************************************************ */
    }
    return 0;
}