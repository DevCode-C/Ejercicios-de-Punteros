#include "mazeMap.h"

uint8_t mazeZone[ROW][COLUMN]=  {{'#','#','#','#','#','#','#','#','#','#','#','#',},
                                 {'#','.','.','.','#','.','.','.','.','.','.','#',},
                                 {'.','.','#','.','#','.','#','#','#','#','.','#',},
                                 {'#','#','#','.','#','.','.','.','.','#','.','#',},
                                 {'#','.','.','.','.','#','#','#','.','#','.','.',},
                                 {'#','#','#','#','.','#','#','#','.','#','.','#',},
                                 {'#','.','.','#','.','#','#','#','.','#','.','#',},
                                 {'#','#','.','#','.','#','#','#','.','#','.','#',},
                                 {'#','.','.','.','.','.','.','.','.','#','.','#',},
                                 {'#','#','#','#','#','#','.','#','#','#','.','#',},
                                 {'#','.','.','.','.','.','.','#','.','.','.','#',},
                                 {'#','#','#','#','#','#','#','#','#','#','#','#',}};

void showMazeZone(uint8_t (*mazeZoneArray)[COLUMN]){
    for(int i=0;i<ROW;i++){
        for (int j = 0; j < COLUMN; j++){
            printf("%4c",mazeZoneArray[i][j]);
        }
        printf("\n");   
    }
    // printf("%4c\n",PLAYER);
}

void searchDoor_memorySpace(uint8_t (*mazeZoneArray)[COLUMN], uint8_t **GetPosition_X, uint8_t **GetPosition_Y){
    for (uint8_t i = 0; i < COLUMN; i++){
        if(mazeZoneArray[i][0]=='.'){
            *GetPosition_Y = &mazeZoneArray[i][0];
        }
    }
    *GetPosition_X = &mazeZoneArray[0][0];
}

void positionChange_memorySpace(uint8_t **SetPositio_X, uint8_t **SetPositio_Y, uint8_t CharacterPlayer){
    **SetPositio_Y = CharacterPlayer;
}



