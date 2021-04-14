#include <stdlib.h>
#include <stdio.h>
#include "deck.h"




int main(void){
    unsigned int deck[SUIT][FACES] = {0};

    srand(time(NULL));
    shuffle(deck);

    const char *suit[SUIT] = {"Hearts","Diamonds","Clubs","Spades"};

    const char *face[FACES] = {"Ace","Deuce","Three","Four","Five","Six","Seven",\
                                "Eight","Nine","Ten","Jack","Queen","King"};    

    dealHand(deck,face,suit);
    // checkHand(deck,face,suit);
    // printf("\n\n");
    dealHand(deck,face,suit);
    // dealHand(deck,face,suit);
    // checkHand(deck,face,suit);
    
    return 0;
}

