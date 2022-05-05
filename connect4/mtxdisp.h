/*
 * mtxdisp.h
 *
 *  Created on: 27 Oct 2016
 *      Author: mgill1
 */

#ifndef MTXDISP_H
#define MTXDISP_H

#include <msp430.h>
#include <stdint.h>

#define MTXDIR P1DIR
#define MTXOUT P1OUT
#define MTXDATA BIT7
#define MTXCLK BIT5
#define MTXLATCH BIT4

void initMtx(void);
void clearMtx(void);
void lightMtx(const uint8_t mtxBuf[8][3]);

#endif /* MTXDISP_H */
