#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifndef __DECK__H
#define __DECK__H
#define SUIT 4 
#define FACES 13
#define CARDS 52

void shuffle(unsigned int wDeck[][FACES]);
void deal(unsigned int wDeck[][FACES], const char *wFaces[], const char *wSuit[]);

void dealHand(void);

void printDeck(unsigned int wDeck[][FACES]);

void handPairs(void);

void handTwoPairs(void);

void handThreeJack(void);

void handFourAces(void);

void handFlush(void);

void handStraight(void);
#endif