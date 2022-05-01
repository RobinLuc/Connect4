/*
 *display.c
 */
#include "mtxdisp.h"
#include "switch.h"
#include "placeMove.h"

void displayWinner(int isWinner,int player)
{
    uint8_t gWon[8][3]={//figure of the green won
                                {0xFF,0x00,0xFF},
                                {0x99,0x66,0x99},
                                {0x00,0xFF,0x00},
                                {0x00,0xFF,0x00},
                                {0x81,0x7E,0x81},
                                {0xC3,0x3C,0xC3},
                                {0xE7,0x18,0xE7},
                                {0xFF,0x00,0xFF}
    };
    uint8_t rWon[8][3]={//figure of the red won
                                {0xFF,0xFF,0x00},
                                {0x99,0x99,0x66},
                                {0x00,0x00,0xFF},
                                {0x00,0x00,0xFF},
                                {0x81,0x81,0x7E},
                                {0xC3,0xC3,0x3C},
                                {0xE7,0xE7,0x18},
                                {0xFF,0xFF,0x00}
    };
    uint8_t draw[8][3]={//figure of the draw
                                {0x00,0x00,0x00},
                                {0x66,0x66,0x66},
                                {0xFF,0xFF,0xFF},
                                {0xFF,0xFF,0xFF},
                                {0x7E,0x7E,0x7E},
                                {0x3C,0x3C,0x3C},
                                {0x18,0x18,0x18},
                                {0x00,0x00,0x00}
    };
    if(isWinner)//if someone won
    {
        if(player==GREEN)
            lightMtx(gWon);//light the green won figure if green won
        else
        lightMtx(rWon);//light the red won figure if red won
    }
    else
        lightMtx(draw);//light the draw figure if draw
    return 0;
}

