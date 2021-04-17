#include "SML.h"

int32_t accumulators = 0;
int32_t memoryRegisters[MEMORY_SPACE] = {0};

void printMemory(int32_t *memory, int8_t size)
{
    for (size_t i = 0; i < MEMORY_SPACE; i++)
    {
        printf("Array[%d], memoryRegister = %d\n",i,memoryRegisters[i]);
    }
}

void setData(int32_t *memory, int8_t size, int8_t *operation, int8_t *operand)
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

void showMemory(int32_t *memory, int8_t size)
{
    for (uint8_t i = 0; i < size; i++)
    {
        printf("Memory[%d] = ?: %d \n",i,memory[i]);
    }
    
}

void read(int32_t *memory, int8_t *operand, int8_t *counter)
{
    printf("%d ?: ",*counter);
    scanf("%d",&memory[*operand]);
}

void write(int32_t *memory, int8_t *operand, int8_t *counter)
{
    printf("%d ?: %d",*counter,memory[*counter]);
}

void load(int32_t *memory, int8_t *operand, int8_t *accumulator)
{
    *accumulator = memory[*operand];
}

void store(int32_t *memory, int8_t *operand, int8_t *accumulator)
{
    memory[*operand] = *accumulator;
}

void add(int32_t *memory, int8_t *operand, int8_t *accumulator)
{
    *accumulator += memory[*operand];
}

void substract(int32_t *memory, int8_t *operand, int8_t *accumulator)
{
    *accumulator -= memory[*operand];
}

void divide(int32_t *memory, int8_t *operand, int8_t *accumulator)
{
    if (memory[*operand] != 0)
    {
        *accumulator /= memory[*operand]; 
    }
    else
    {
        perror("Division entre cero\n");
    }
    
    
}

void multiply(int32_t *memory, int8_t *operand, int8_t *accumulator)
{
    *accumulator *= memory[*operand];
}

void branch(int32_t *memory, int8_t *operand, int8_t *counter)
{
    *counter = *operand;
}

void branchNeg(int32_t *memory, int8_t *operand, int8_t *counter, int8_t *accumulator)
{
    if (*accumulator < 0)
    {
        *counter = *operand;
    }
    
}

void branchZero(int32_t *memory, int8_t *operand, int8_t *counter, int8_t *accumulator)
{
    if (*accumulator == 0)
    {
        *counter = *operand;
    }
    
}