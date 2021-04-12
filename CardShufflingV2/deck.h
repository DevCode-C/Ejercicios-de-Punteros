#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef __DECK__H
#define __DECK__H

    #define     SUIT        4 
    #define     FACES       13
    #define     CARDS       52
    #define     DEAL_HAND   5

    void shuffle(unsigned int wDeck[][FACES]);
    void deal(unsigned int wDeck[][FACES], const char *wFaces[], const char *wSuit[]);

    void dealHand(unsigned int wDeck[][FACES],const char *wFaces[], const char *wSuit[]);

    void printDeck(unsigned int wDeck[][FACES]);

    void checkHand(unsigned int wDeck[][FACES], const char *wFaces[], const char *wSuit[]);

#endif