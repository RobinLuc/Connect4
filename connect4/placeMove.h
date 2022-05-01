/*
 * Move.h
 */
#ifndef PLACEMOVE_H_
#define PLACEMOVE_H_

#include <stdint.h>
#define BLUE 0
#define GREEN 1
#define RED 2

uint8_t getMove( uint8_t BGR[8][3],int player);

int placeMove(uint8_t BGR[8][3],int player,uint8_t Move);

#endif
