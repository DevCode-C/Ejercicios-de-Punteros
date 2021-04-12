#include "deck.h"

void shuffle(unsigned int wDeck[][FACES])
{
    for(unsigned char card = 1; card <= CARDS; ++card)
    {
        unsigned char row;
        unsigned char column;

        do
        {
            row = rand() % SUIT;
            column = rand() % FACES;

        } while (wDeck[row][column] != 0);
        
        wDeck[row][column] = card;
    }
}


void deal(unsigned int wDeck[][FACES], const char *wFaces[], const char *wSuit[])
{
    for(unsigned char card = 1; card <=CARDS; ++card)
    {
        for(unsigned char row = 0; row < SUIT; ++row)
        {
            for(unsigned char column = 0; column < FACES; ++column)
            {
                if (wDeck[row][column] == card)
                {
                    printf("%5s of %-8s%c", wFaces[column], wSuit[row],card % 2 == 0 ? '\n' : '\t');
                }
            }
        }
    }
}

void printDeck(unsigned int wDeck[][FACES])
{
    for (unsigned char i = 1; i <= SUIT; i++)
    {
        for (unsigned char j = 0; j < FACES; j++)
        {
            printf("%s\t",wDeck[SUIT][FACES]);
        }
        printf("\n");
        
    }
    
}

void dealHand(unsigned int wDeck[][FACES],const char *wFaces[], const char *wSuit[]){
    static unsigned char    card    = 1;
    unsigned char           count   = 0;

    while (count != DEAL_HAND)
    {
        for (unsigned char row = 0; row < SUIT; row++)
        {
            for (unsigned char column = 0; column < FACES; column++)
            {
                if (wDeck[row][column] == card)
                {
                    printf("%5s of %-8s%c", wFaces[column], wSuit[row],card % 2 == 0 ? '\n' : '\t');
                }
            }
        }  
        card++;
        count++;
    }
    printf("\n");
    checkHand(wDeck,wFaces,wSuit);
}

void checkHand(unsigned int wDeck[][FACES], const char *wFaces[], const char *wSuit[]){
    static unsigned char    card                = 1;
    unsigned char           count               = 0;
    unsigned char           wFacesCount[FACES]  = {0};
    unsigned char           wSuitCount[SUIT]    = {0};

    unsigned char   pairs       = 0;
    // unsigned char   Twopairs    = 0;
    // unsigned char   ThreeJacks  = 0;
    // unsigned char   FourAces    = 0;
    // unsigned char   flush       = 0;
    unsigned char   straight    = 0;
    
    while (count != DEAL_HAND)
    {
        for (unsigned char row = 0; row < SUIT; row++)
        {
            for (unsigned char column = 0; column < FACES; column++)
            {
                if (wDeck[row][column] == card)
                {
                    wFacesCount[column]++;
                    wSuitCount[row]++;
                }
            }
            
        }
        card++;
        count++;
    }   

    for (size_t i = 0; i < FACES; i++)
    {
        // printf("Numero de veces:%d, Numero: %s\n",wFacesCount[i],wFaces[i]);
        if (wFacesCount[i]>1)
        {
            pairs++;   
            // printf("\nYou have a pair\n");
        }
        else if (wFacesCount[i]==4)
        {
            pairs = 2;
            // printf("\nYou have two pair\n");
        }

        if (wFacesCount[i] != 0)
        {
            straight++;
            if (straight == 5)
            {
                printf("\nYou have a Straigth\n");
            }
        }
        else
        {
            straight = 0;
        }
        
    }
    if (pairs==1)
    {
        printf("\nYou have a pair\n");
    }
    else if (pairs ==2)
    {
        printf("\nYou have two pair\n");
    }
    
    

    if (wFacesCount[10]==3)
    {
        printf("\nYou have three of a kind \n");
    }
    if (wFacesCount[0]==4)
    {
        printf("\nYou have four of a kind \n");
    }
    
    printf("\n\n");
    for (size_t i = 0; i < SUIT; i++)
    {
        if (wSuitCount[i] == 5)
        {
            printf("\nYou have a flush \n");
        }
        
        // printf("Numero de veces:%d, carta: %s\n",wSuitCount[i],wSuit[i]);
    }
    
}