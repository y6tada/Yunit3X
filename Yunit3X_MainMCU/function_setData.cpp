#include "mbed.h"
#include "function_setData.h"

int Set16MODE(int deg)
{
    if (deg < 0)
        deg += 16;
    
    return deg;
}
//
int U_GetDeg(int deg)
{
    if (deg < 0)
        deg += 16;
    
    deg += 1;
    
    if (deg > 16)
        deg -= 16;
    else if(deg < 0)
        deg += 16;
    
    return deg;
}
//
int D_GetDeg(int deg)
{
    if (deg < 0)
        deg += 16;
    
    deg -= 1;
    
    if (deg > 16)
        deg -= 16;
    else if(deg < 0)
        deg += 16;
    
    return deg;
}