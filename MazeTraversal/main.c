#include <stdlib.h>
#include <stdio.h>
#include "mazeMap.h"

extern unsigned char mazeZone[ROW][COLUMN];

int main(void){
    for(int i=0;i<12;i++){
        for (int j = 0; j < 12; j++){
            printf("%4c",mazeZone[i][j]);
        }
        printf("\n");   
    }
    printf("%4c\n",PLAYER);
    return 0;
}
