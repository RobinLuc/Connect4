/*
 * mtxdisp.c
 */
#include <stdint.h>
#include "mtxdisp.h"

void initMtx(void)
{
	MTXDIR |= MTXDATA + MTXCLK + MTXLATCH; ////Makes Data,Latch and Clk pins outputs
	MTXOUT &= ~(MTXDATA + MTXCLK);//Makes Data and Clk low
	MTXOUT |= MTXLATCH;  //Make Latch high as it is active low
}

void clearMtx(void)
{//clocks in 8*3*8(192) lows to matrix (Clears matrix)

	int x;
	MTXOUT &= ~MTXLATCH;  //Latch low 
	MTXOUT &= ~MTXDATA;   //Data low
	
	for (x=1; x<=192;x++)
	{
		MTXOUT |= MTXCLK; //Clk high
		MTXOUT &= ~MTXCLK;//Clk low
	}
	
	MTXOUT |= MTXLATCH; //Latch high
}

void lightMtx(const uint8_t mtxBuf[8][3])
{// displays mtxBuf values on matrix displays
	
	int x,colour,row;
	uint8_t val;

	MTXOUT &= ~MTXLATCH;  //Latch low 

	for(row=7;row>=0;row--)  //for each row from 7 downto 0
	{
		for(colour=2;colour>=0; colour--)
		{//for each colour from 2 downto 0
			val = mtxBuf[row][colour];

			for (x=1; x<=8;x++)  //for each bit in val shift it out
			{
				if (val&BIT0) // is LSb of val high
					MTXOUT |= MTXDATA; //Data high
				else
					MTXOUT &= ~MTXDATA; //Data low

				MTXOUT |= MTXCLK; //Clk high
				MTXOUT &= ~MTXCLK;//Clk low
				val>>=1;
			}
		}
	}
	MTXOUT |= MTXLATCH; //Latch high
}


