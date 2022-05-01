/*
 * Move.c
 */
#include <placeMove.h>
#include "mtxdisp.h"
#include "switch.h"

uint8_t getMove( uint8_t BGR[8][3],int player)
{
    unsigned char val,litLEDs;//val is the status of switch
    volatile long x;
    uint8_t ch=0x02;//start at rightmost position

    do{
        if(ch>0x02)//loop in the fist row from left to right
            ch = ch >> 1;//swift to the right
        else
            ch=0x80;//back to the left

        BGR[0][player]=ch;
        lightMtx(BGR);//light the LED

        for(x=0;x<20000;x++)
            ;//delay

        val=readSwitchDB();//checks the switch status
        litLEDs = BGR[2][GREEN]|BGR[2][RED];//check the row 2 position is not occupied

    }while(val!=DOWN||(litLEDs&ch)!=0);//loop while the switch not down or this position corresponding the position on row 2 is not occupied

    BGR[0][player]=0x00;//clear all on row 0
    return ch;
}

int placeMove(uint8_t BGR[8][3],int player,uint8_t Move)
{
    uint8_t litLeds;
    int row = 7;
    litLeds = BGR[7][RED]|BGR[7][GREEN];//gets the bottom position

    while((litLeds&Move)!=0)//loop until find the empty position
    {
        row--;//check upper one
        litLeds = BGR[row][RED]|BGR[row][GREEN];//get the lowest empty position
    }

    BGR[row][player]|=Move;//add move to the right position
    return row;
}
