#include "SML.h"

int32_t accumulator = 0;
int32_t memoryRegisters[MEMORY_SPACE] = {0};

void printMemory(int32_t *memory, int8_t size)
{
    for (size_t i = 0; i < MEMORY_SPACE; i++)
    {
        printf("Array[%d], memoryRegister = %d\n",i,memoryRegisters[i]);
    }
}

void getData(int32_t *memory, int8_t size, int8_t *operation, int8_t *operand)
{
    int32_t tmp = 0;
    for (uint8_t i = 0; i < size; i++)
    {
        printf("%d ? :\t",i);
        scanf("%d",&tmp);

        *operation = (int8_t)(tmp/100);
        *operand = (int8_t)(tmp%100); 

        if ((tmp == -9999 ) || (*operation == HALT))
        {
            memory[i] = 4300;
            break;
        }
        else
        {
            memory[i] = tmp;
        }
        
    }
    
}

void readOperation(int32_t *memory, int8_t size, int8_t *operation, int8_t *operand)
{
    bool state = true;
    uint8_t counter = 0;
    do
    {
        *operation  = (uint8_t)(memory[counter]/100);
        *operand    = (uint8_t)(memory[counter]%100);
        printf("Array[%d], memoryRegister = %d\n",counter,memory[counter]);
        if (*operation == HALT)
        {
            state = false;
        }
        else
        {
            counter++;
        }
        
        
    } while (state == true);
        
}
