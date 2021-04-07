#include <stdlib.h>
#include <stdio.h>
#include "mazeMap.h"

extern uint8_t mazeZone[ROW][COLUMN]; //Declaramos como extern a mazeZone
// uint8_t Position_X;
// uint8_t Position_Y;
                                    //Declaramos dos punteros para obtener las posiciones de memoria delntro del mazeZone
uint8_t *ptrPosition_X;             //Posicion de memoria en coordenadas x
uint8_t *ptrPosition_y;             //Posicion de memoria en coordenadas y

int main(void){
    showMazeZone(mazeZone);         //Funcion usada para mostrar por pantalla el mapa
    printf("Direccion del punto X: %p\n Direccion del punto y: %p\n",&ptrPosition_X,&ptrPosition_y);
   
    searchDoor(mazeZone,&ptrPosition_X,&ptrPosition_y);     //Funcion usada que busca la entrada

    printf("Direccion del punto X: %c\n Direccion del punto y: %c\n",*ptrPosition_X,*ptrPosition_y);
    printf("Direccion del punto X: %p\n Direccion del punto y: %p\n",ptrPosition_X,ptrPosition_y);
    return 0;
}
