#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SUIT 4 
#define FACES 13
#define CARDS 52

void shuffle(unsigned int wDeck[][FACES]);
void deal(unsigned int wDeck[][FACES], const char *wFaces[], const char *wSuit[]);

int main(void){
    unsigned int deck[SUIT][FACES] = {0};

    srand(time(NULL));
    shuffle(deck);

    const char *suit[SUIT] = {"Hearts","Diamonds","Clubs","Spades"};

    const char *face[FACES] = {"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King"};

    deal(deck, face, suit);
    return 0;
}

void shuffle(unsigned int wDeck[][FACES]){
    for(unsigned char card = 1; card <= CARDS; ++card){
        unsigned char row;
        unsigned char column;

        do{
            row = rand() % SUIT;
            column = rand() % FACES;
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