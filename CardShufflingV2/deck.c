#include "deck.h"

void shuffle(unsigned int wDeck[][FACES]){
    for(unsigned char card = 1; card <= CARDS; ++card){
        unsigned char row;
        unsigned char column;

        do{
            row = rand() % SUIT;
            column = rand() % FACES;
            // printf("ROW: %d \tCOLUMN: %d\n",row,column);
        } while (wDeck[row][column] != 0);
        
        wDeck[row][column] = card;
    }
}


void deal(unsigned int wDeck[][FACES], const char *wFaces[], const char *wSuit[]){
    for(unsigned char card = 1; card <=CARDS; ++card){
        for(unsigned char row = 0; row < SUIT; ++row){
            for(unsigned char column = 0; column < FACES; ++column){
                if (wDeck[row][column] == card){
                    printf("%5s of %-8s%c", wFaces[column], wSuit[row],card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
}

void printDeck(unsigned int wDeck[][FACES]){
    for (unsigned char i = 0; i < SUIT; i++){
        for (unsigned char j = 0; j < FACES; j++){
            printf("%s\t",wDeck[SUIT][FACES]);
        }
        printf("\n");
        
    }
    
}