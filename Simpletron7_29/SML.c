#include "SML.h"

void welcome(void)
{
    printf("*** Welcome to Simpletron! ***\n"\
            "*** Please enter your program one instruction ***\n"\
            "*** (or data word) at a time. I will type the ***\n"\
            "*** location number and a question mark (?). ***\n"\
            "*** You then type the word for that location. ***\n"\
            "*** Type the sentinel -99999 to stop entering ***\n"
            "*** your program. ***\n");
}

void showMemory(int32_t *memory, int8_t size)
{
    for (uint8_t i = 0; i < size; i++)
    {
        printf("Memory[%d] = ?: %d \n",i,memory[i]);
    }
    
}

void read(int32_t *memory, int8_t *operand, uint16_t *counter)
{
    scanf("%d",&memory[*operand]);
    *counter += 1;
}

void write(int32_t *memory, int8_t *operand, uint16_t *counter)
{
    printf("%d",memory[*operand]);
    *counter += 1;
}

void load(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter)
{
    *accumulator = memory[*operand];
    *counter += 1;
}

void store(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter)
{
    memory[*operand] = *accumulator;
    *counter += 1;
}

void add(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter)
{
    *accumulator += memory[*operand];
    *counter += 1;
}

void substract(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter)
{
    *accumulator -= memory[*operand];
    *counter += 1;
}

void divide(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter)
{
    if (memory[*operand] != 0)
    {
        *accumulator /= memory[*operand];
        *counter += 1; 
    }
    else
    {
        perror("*** Attempt to divide by zero ***\n"\
                "*** Simpletron execution abnormally terminated ***\n");
    }
    
    
}

void multiply(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter)
{
    *accumulator *= memory[*operand];
    *counter += 1;
}

void remaind(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter)
{
    *accumulator %= memory[*operand];
    *counter += 1;
}

void exponetation(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter)
{
    *accumulator = pow((double)*accumulator,(double)memory[*operand]);
    *counter += 1;
}

void branch(int32_t *memory, int8_t *operand, uint16_t *counter)
{
    *counter = *operand;
}

void branchNeg(int32_t *memory, int8_t *operand, uint16_t *counter, int32_t *accumulator)
{
    if (*accumulator < 0)
    {
        *counter = *operand;
    }
    else
    {
        *counter += 1;
    }
    
    
}

void branchZero(int32_t *memory, int8_t *operand, uint16_t *counter, int32_t *accumulator)
{
    if (*accumulator == 0)
    {
        *counter = *operand;
    }
    else
    {
        *counter += 1;
    }
    
    
}

void halt(void)
{
    printf("*** Simpletron execution terminated ***\n");
}

void loadImplementation(int32_t *memory, int32_t *acummulator, uint16_t *instructionCounter,\
                            int32_t *instructionRegister, uint8_t *operatioCode, int8_t *operand)
{
    int32_t word        = 0;
    uint8_t counter     = 0;
    do
    {
        printf("%d ?  ",counter);
        scanf("%d",&word);
        memory[counter] = word;
        counter++;
    } while (word != -9999);
    printf("*** Program loading completed ***\n");
    printf("*** Program execution begins *** \n\n");
}

void executeImplementation(int32_t *memory, int32_t *acummulator, uint16_t *instructionCounter,\
                                int32_t *instructionRegister, uint8_t *operatioCode, int8_t *operand)
{
    do
    {        
        *instructionRegister     = memory[*instructionCounter];
        *operatioCode            = *instructionRegister / 100;
        *operand                 = *instructionRegister % 100;
        printf("%d ?  %d\t",*instructionCounter,*instructionRegister);
        switch (*operatioCode)
        {
        case READ:
            read(memory,operand,instructionCounter);
            break;
        case WRITE:
            write(memory,operand,instructionCounter);
            break;
        case LOAD:
            load(memory, operand, acummulator, instructionCounter);
            break;
        case STORE:
            store(memory,operand,acummulator, instructionCounter);
            break;
        case ADD:
            add(memory,operand,acummulator, instructionCounter);
            break;
        case SUBTRACT:
            substract(memory,operand,acummulator, instructionCounter);
            break;
        case DIVIDE:
            divide(memory,operand,acummulator, instructionCounter);
            break;
        case MULTIPLY:
            multiply(memory,operand,acummulator, instructionCounter);
            break;
        case BRANCH:
            branch(memory,operand,instructionCounter);
            break;
        case BRANCHNEG:
            branchNeg(memory,operand,instructionCounter,acummulator);
            break;
        case BRANCHZERO:
            branchZero(memory,operand,instructionCounter,acummulator);
            break;
        case HALT:
            halt();
            break;

        default:
            // operatioCode = HALT;
            printf("No existe el comando\n");
            *instructionCounter += 1;
            break;
        }
        printf("\n");
    } while (*operatioCode != HALT);
}

void dumpImplementation(int32_t *memory, int32_t *acummulator, uint16_t *instructionCounter,\
                            int32_t *instructionRegister, uint8_t *operatioCode, int8_t *operand)
{
    printf("REGISTERS:\nAcummulator\t\t%+05ld\n"\
            "instructionCounter\t%02ld\n"\
            "instructionRegister\t%+05ld\n"\
            "operatioCode\t\t%02ld\n"\
            "operand\t\t\t%02ld\n\n",\
            *acummulator,*instructionCounter,*instructionRegister,*operatioCode,*operand);

    printf("MEMORY:\n");
    printf("\t 0\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\n");
    for (unsigned char i = 0; i < SIZE; i++){
        if(i%10==0){
            printf("\n");
            printf("%d",i);
        }
        printf("\t %+05ld",memory[i]);
    }
}