/*
 *playerWon.c
 */
#include "mtxdisp.h"
#include "switch.h"

//horizontal
int playerWon( uint8_t BGR[8][3],int player,uint8_t move,int row)
{
    unsigned char b,r;
    unsigned int count=0;//counter

    for(b = 0x80;b>0x01;b=b>>1) //for each bit in b from left to right
    {
        if(BGR[row][player]&b)//chech whether lit in this player colour
        {
            count++;//counter++
            if(count>=4)
                return 1;//won
        }
        else
            count=0;//continues
    }

    //Vertical Test
    if (row<=4)  //check whether has enough room below
    {
      if ((BGR[row+1][player]&move)&&     //check row+1
          (BGR[row+2][player]&move)&&     //check row+2
          (BGR[row+3][player]&move))     //check row+3
          return 1;
    }

    //Diagonal Test bottom left to top right

    //find bottom left start pos
    b = move;
    r = row;
    while (b<0x80 && r<7)//build the borders
    {
       b<<=1;//reaching to bottom left
       r++;
    }

    //count 4
    count=0;//count from 0
    while(b>0x01 && r>1)//bulid the borders
    {
       if(BGR[r][player]&b) //check whether a light LED in this player colour
       {
          count++;
          if (count==4)//won
             return 1;
       }
       else
          count=0;//count from 0 over again

       b>>=1;//reaching to top right
       r--;
    }

    //Diagonal Test bottom right to top left

    //find bottom right start pos
    b = move;
    r = row;
    while (b>0x02 && r<7)//bulid the borders
    {
       b>>=1;//reaching to bottom right
       r++;
    }

    //count 4
    count=0;
    while(b!=0x00 && r>1)//bulid the borders
    {
       if(BGR[r][player]&b) //check whether a light LED in this player colour
       {
          count++;
          if (count==4)
             return 1;//won
       }
       else
          count=0;//count from 0 over again

       b<<=1;//reaching to top left
       r--;
    }
    return 0;
}


