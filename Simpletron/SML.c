#include "SML.h"

int32_t accumulator = 0;
int32_t memoryRegisters[100] = {0};

void printMemory(int32_t *memory, int8_t size){
    for (size_t i = 0; i < MEMORY_SPACE; i++)
    {
        printf("%d ? :\t",i);
        scanf("%d",&accumulator);
        fflush(stdin);
        memoryRegisters[i] = accumulator;
        printf("Array[%d], memoryRegister = %d\n",i,memoryRegisters[i]);
    }
}
