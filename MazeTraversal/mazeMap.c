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

void searchDoor(uint8_t (*mazeZoneArray)[COLUMN], uint8_t *GetPosition_X, uint8_t *GetPosition_Y){
    for (uint8_t j = 0; j < ROW; j++){
        if(mazeZoneArray[j][0] == '.'){
            *GetPosition_Y = j;
            *GetPosition_X = 0;
            break;
        }       
    }
}

void positionChange(uint8_t (*mazeZoneArray)[COLUMN] ,uint8_t SetPosition_X, uint8_t SetPosition_y, uint8_t CharacterPlayer){
    mazeZoneArray[SetPosition_y][SetPosition_X] = CharacterPlayer;
}

uint8_t playerDisplacement(uint8_t *InitialPosition_X, uint8_t *InitialPosition_Y, uint8_t (*mazeZoneArray)[COLUMN]){
    uint8_t state = BUSY_STATE;
    uint8_t direction = UP;
    uint8_t wallPosition;

    positionChange(mazeZoneArray,*InitialPosition_X,*InitialPosition_Y,PLAYER);
    showMazeZone(mazeZoneArray);
    
    return state;
}
