#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "SML.h"

extern int32_t accumulator;
extern int32_t memoryRegisters[100];

int main(void){
    printMemory(memoryRegisters,MEMORY_SPACE);
}