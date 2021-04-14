#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "SML.h"

int16_t accumulator = 0;
int16_t memoryRegisters[100] = {0};

int main(void){
    for (size_t i = 0; i < MEMORY_SPACE; i++)
    {
        /* code */
        printf("%d ? :\t",i);
        scanf("%hd",&accumulator);
        fflush(stdin);
        memoryRegisters[i] = accumulator;
        printf("Array[%d], memoryRegister = %d\n",i,memoryRegisters[i]);
    }
    
}