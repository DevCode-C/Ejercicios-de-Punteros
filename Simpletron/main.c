#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "SML.h"

extern int32_t accumulator;
extern int32_t memoryRegisters[MEMORY_SPACE];

int8_t operation    = 0;
int8_t operand      = 0;

int main(void){
    getData(memoryRegisters,MEMORY_SPACE,&operation,&operand);

    // printMemory(memoryRegisters,MEMORY_SPACE);
    readOperation(memoryRegisters, MEMORY_SPACE, &operation, &operand);
}