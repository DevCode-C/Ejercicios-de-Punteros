#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#ifndef __MAZEMAP_H
#define __MAZEMAP_H 1


#define ROW     12
#define COLUMN  12

#define PLAYER  '@'

/*
    Muestra el mapa de la mazeZone
*/
void showMazeZone(uint8_t (*mazeZoneArray)[COLUMN]);

 /* Funcion que busca el espacio de memoria donde se encuentra alojado el caracter deseado.
    No es necesario los dos GetPosition, con solo uno es suficiente.
 */
void searchDoor_memorySpace(uint8_t (*mazeZoneArray)[COLUMN], uint8_t **GetPosition_X, uint8_t **GetPosition_Y);

/*
    Cambia el caracter en la posicion de memoria dada por el usuario
*/
void positionChange_memorySpace(uint8_t **SetPositio_X, uint8_t **SetPositio_Y, uint8_t CharacterPlayer);

/*
    Funcion que busca dentro del array, el caracter deseado
    Retorna a travez de los punteros, el valor para X y Y.
*/
void searchDoor(uint8_t (*mazeZoneArray)[COLUMN], uint8_t *GetPosition_X, uint8_t *GetPosition_Y);

void positionChange(uint8_t SetPosition_X, uint8_t SetPosition_y, uint8_t CharacterPlayer);


#endif