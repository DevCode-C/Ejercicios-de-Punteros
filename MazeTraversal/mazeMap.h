#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#ifndef __MAZEMAP_H
#define __MAZEMAP_H 1


#define ROW     12
#define COLUMN  12

#define PLAYER  '@'

#define UP      1
#define DOWN    2
#define RIGHT   3
#define LEFT    4

#define BUSY_STATE 1
#define FREE_STATE 0

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

void positionChange(uint8_t (*mazeZoneArray)[COLUMN] ,uint8_t SetPosition_X, uint8_t SetPosition_y, uint8_t CharacterPlayer);

/*
    Realiza el moviemiento dentro del mazeArray, ademas de verificar la direccion del jugador para el desplazamiento
    sin perder la orientacion.
*/
uint8_t playerDisplacement(uint8_t *InitialPosition_X, uint8_t *InitialPosition_Y, uint8_t (*mazeZoneArray)[COLUMN]);

#endif