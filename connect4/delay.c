/*
 * delay.c
 */
#include "delay.h"
void delay(unsigned long ms)
{
    unsigned long t;
    for(t=ms;t>0;t--);
}



