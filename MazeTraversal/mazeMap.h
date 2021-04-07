#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#ifndef __MAZEMAP_H
#define __MAZEMAP_H 1


#define ROW     12
#define COLUMN  12

#define PLAYER  '@'


void showMazeZone(uint8_t (*mazeZoneArray)[COLUMN]);

void searchDoor(uint8_t (*mazeZoneArray)[COLUMN], uint8_t **GetPosition_X, uint8_t **GetPosition_Y);

#endif