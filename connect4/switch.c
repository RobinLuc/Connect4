/*
 * switch.c
 */
#include "switch.h"
#include "delay.h"
#include <msp430.h>
unsigned char readSwitchPin(void);

void initialiseSwitch(void)
{
    //put comments here
    P1DIR &= ~BIT3; // Clear bit 3 making P1_3 an input i.e ~BIT3 (11110111 BIN)
    P1OUT |= BIT3; // Set bit 3 of P1OUT to select pullup i.e BIT3(00001000BIN)
    P1REN |= BIT3; // Enable the pullup resister i.e BIT3 (00001000 BIN)
}

unsigned char readSwitchPin(void)
{
    //put comments here
    if( P1IN & BIT3 ) //BIT3 (00001000 BIN)
        return UP; //pin was high (Switch un-pressed)
    else
        return DOWN; //pin was low (Switch pressed)
}

unsigned char readSwitchDB(void)
{
    // put comments here
    static unsigned char lastRead=UP; // assume switch is un-pressed at startup
    unsigned char val;
    val=readSwitchPin(); //read switch

    if( val != lastRead ) //check if it has changed
    {
        delay(200); //wait for 20ms
        val=readSwitchPin(); //read switch

        if(val != lastRead ) //check switch again to make sure it has
        { // really changed
            lastRead = val; //update lastRead
            return val;
        }
    }
    return SAME;
}




