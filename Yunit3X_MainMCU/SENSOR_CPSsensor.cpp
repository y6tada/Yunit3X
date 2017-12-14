#include "mbed.h"

/* ------------------------------------------------------------------------------------------ */
static int U4_CPS_P     = 0;
static int U4_CPS_P_Bef = 0;

static int U4_CPS_D     = 0;
static int U4_CPS_D_Bef = 0;

static int U4_IntgD     = 0;
static int U4_IntgD_Bef = 0;
/* ------------------------------------------------------------------------------------------ */
void CPS_sortData(int CPS_data)
{
    // transform 0~255 to -127~0~127
    if (CPS_data > 127)
        U4_CPS_P = (CPS_data - 255) * -1;
    else
        U4_CPS_P = CPS_data * -1;
    
    U4_CPS_D = U4_CPS_P_Bef - U4_CPS_P;
    
    if (U4_CPS_D >= -1 && U4_CPS_D <= 1)
        U4_CPS_D = 0;
    
    if (U4_CPS_P > 1 || U4_CPS_P < -1) {
        if (U4_CPS_P * U4_CPS_P_Bef < 0)
            U4_IntgD = 0;
        else {
            if (abs(U4_IntgD) < 100)
            U4_IntgD += U4_CPS_P;
        }
    }
    else
        U4_IntgD = 0;
    
    if (U4_CPS_D > 8 || U4_CPS_D < -8)
        U4_CPS_D = U4_CPS_D_Bef;
    
    U4_CPS_P_Bef = U4_CPS_P;
    U4_CPS_D_Bef = U4_CPS_D;
    U4_IntgD_Bef = U4_IntgD;
}
/* ------------------------------------------------------------------------------------------ */
int GetCPS(int DataNo)
{
    /* -------------------------------------------------------------------------------------- */
    switch (DataNo)
    {
        case 0:
            return U4_CPS_P;
            break;
            
        case 1:
            return U4_CPS_D;
            break;
            
        case 2:
            return U4_IntgD;
            break;
    }
    return 0;
    /* -------------------------------------------------------------------------------------- */
}
/* ------------------------------------------------------------------------------------------ */