/*
 * main.c
 */
#include <msp430.h> 
#include <stdint.h>
#include "mtxdisp.h"
#include "placeMove.h"
#include "switch.h"
#include "playerWon.h"
#include "displayWinner.h"

int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;// Stop watchdog timer
    initialiseSwitch();//set up switch for reading
    initMtx();//init switches and matrix etc

    uint8_t store[3]={0xff,0x00,0x00};
    int i;
    for(i=0;i<8;i++)//counter for counting 8 rounds of a game
    {

        /*uint8_t BGR[8][3]={    {0x01,0x00,0x00},//Original LEDs
                               {0xFF,0x00,0x00},
                               {0x01,0x54,0xA8},
                               {0x01,0x54,0xAA},
                               {0x01,0xAA,0x54},
                               {0x01,0xAA,0x54},
                               {0x01,0x54,0xAA},
                               {0x01,0x54,0xAA}};*/
        uint8_t BGR[8][3]={    {0x01,0x00,0x00},//Original LEDs
                               {0xFF,0x00,0x00},
                               {0x01,0x00,0x00},
                               {0x01,0x00,0x00},
                               {0x01,0x00,0x00},
                               {0x01,0x00,0x00},
                               {0x01,0x00,0x00},
                               {0x01,0x00,0x00}};

        clearMtx();
        lightMtx(BGR);

        BGR[1][BLUE] = store[BLUE];
        BGR[1][GREEN] = store[GREEN];
        BGR[1][RED] = store[RED];

        int player = RED;
        int numMoves = 0;//counter for counting moves number
        int row;//row of the matrix
        uint8_t move,isWinner;

        do{
            if(player==RED)//alternate between red and green of players
                player= GREEN;
            else
                player = RED;

            move = getMove(BGR,player);//makes a move
            row= placeMove(BGR,player,move);//places a move

            numMoves++;//increment of the moves
            lightMtx(BGR);//lights the LED
            isWinner = playerWon(BGR,player,move,row);//Judeges whether someone won

        }while(numMoves<42&&!isWinner);//loops until draw or someone won

        if(isWinner)//if some player win
            store[player] |= 0x80>>i;//which one won, moving the LED with which one's colour
        else
        {
            store[RED] |= 0x80>>i;//it is draw, move a white LED combined with green, red, blue
            store[GREEN] |= 0x80>>i;
        }

        displayWinner(isWinner,player);//display the figure of the winner

    }
    return 0;
 }
