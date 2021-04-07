#include <stdlib.h>
#include <stdio.h>
#include "mazeMap.h"
/*
    La relacion entre coordenada y el array de mazeZone es:
              Coordenadas[ Y ][  X   ] 
                mazeZone[ROW][COLUMN

*/


extern uint8_t mazeZone[ROW][COLUMN]; //Declaramos como extern a mazeZone
// uint8_t Position_X;
// uint8_t Position_Y;
                                    //Declaramos dos punteros para obtener las posiciones de memoria delntro del mazeZone
uint8_t *ptrPosition_X;             //Posicion de memoria en coordenadas x
uint8_t *ptrPosition_y;             //Posicion de memoria en coordenadas y

int main(void){
    showMazeZone(mazeZone);         //Funcion usada para mostrar por pantalla el mapa
    printf("Direccion del punto X: %p\n Direccion del punto y: %p\n",&ptrPosition_X,&ptrPosition_y);
   
    searchDoor_memorySpace(mazeZone,&ptrPosition_X,&ptrPosition_y);     //Funcion usada que busca la entrada

    printf("Caracter del punto X: %c\n Caracter del punto y: %c\n",*ptrPosition_X,*ptrPosition_y);
    printf("Direccion del punto X: %p\n Direccion del punto y: %p\n",ptrPosition_X,ptrPosition_y);

    printf("Direccion del array mazeZone[0][0]: %p\n Direccion del array mazeZone[0][3]: %p\n",&mazeZone[0][0],&mazeZone[2][0]);

    positionChange_memorySpace(&ptrPosition_X,&ptrPosition_y,PLAYER);
    showMazeZone(mazeZone);
    return 0;
}
