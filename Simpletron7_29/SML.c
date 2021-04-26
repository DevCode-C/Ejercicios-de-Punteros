#include "SML.h"
#define _OPEN_SYS_ITOA_EXT
#include <stdlib.h>

// extern void itoa();
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

void read(double *memory, int8_t *operand, uint16_t *counter)
{
    scanf("%lf",&memory[*operand]);
    printf("%0.2lf\n",memory[*operand]);
    *counter += 1;
}

void write(double *memory, int8_t *operand, uint16_t *counter)
{
    printf("%0.2lf",memory[*operand]);
    *counter += 1;
}

void load(double *memory, int8_t *operand, double *accumulator, uint16_t *counter)
{
    *accumulator = memory[*operand];
    *counter += 1;
}

void newline(double *memory,uint16_t *counter)
{
    *counter += 1; 
}

void store(double *memory, int8_t *operand, double *accumulator, uint16_t *counter)
{
    memory[*operand] = *accumulator;
    *counter += 1;
}

void add(double *memory, int8_t *operand, double *accumulator, uint16_t *counter)
{
    *accumulator += memory[*operand];
    *counter += 1;
}

void substract(double *memory, int8_t *operand, double *accumulator, uint16_t *counter)
{
    *accumulator -= memory[*operand];
    *counter += 1;
}

void divide(double *memory, int8_t *operand, double *accumulator, uint16_t *counter)
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

void multiply(double *memory, int8_t *operand, double *accumulator, uint16_t *counter)
{
    *accumulator *= memory[*operand];
    *counter += 1;
}

void remaind(double *memory, int8_t *operand, double *accumulator, uint16_t *counter)
{
    *accumulator = remainderl(*accumulator,memory[*operand]);
    // *accumulator %= memory[*operand];
    *counter += 1;
}

void exponetation(double *memory, int8_t *operand, double *accumulator, uint16_t *counter)
{
    *accumulator = pow((double)*accumulator,(double)memory[*operand]);
    *counter += 1;
}

void branch(double *memory, int8_t *operand, uint16_t *counter)
{
    *counter = *operand;
}

void branchNeg(double *memory, int8_t *operand, uint16_t *counter, double *accumulator)
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

void branchZero(double *memory, int8_t *operand, uint16_t *counter, double *accumulator)
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

int16_t ConversionHex_to_Dec(char character)
{
    if (isdigit(character))
    {
        return character - '0';
    }
    return (10 +(toupper(character) - 'A'));
    
}

void loadImplementation(double *memory, double *acummulator, uint16_t *instructionCounter,\
                            int32_t *instructionRegister, uint8_t *operatioCode, int8_t *operand)
{
    uint32_t word       = 0;
    uint16_t counter     = 0;
    // uint8_t palabra[6] = {0};
    do
    {
        printf("%d ?  ",counter);
        // fflush(stdin);
        scanf("%d",&word);
        // word = 0;
        // for (uint8_t i = 0; i < strlen((const char *)palabra); i++)
        // {
        //     if (i>0)
        //     {
        //         word = word << 4;
        //     }
        //     word += ConversionHex_to_Dec(palabra[i]);
        // }
        memory[counter] = (double)word;
        counter++;

    } while (/*word != 1048575 ||*/ word != -9999);
    printf("*** Program loading completed ***\n");
    printf("*** Program execution begins *** \n\n");
}

void executeImplementation(double *memory, double *acummulator, uint16_t *instructionCounter,\
                                int32_t *instructionRegister, uint8_t *operatioCode, int8_t *operand)
{
    do
    {   
        
        // char characterHex[6] = {0};
        // itoa(memory[*instructionCounter],characterHex,16);

        // printf("%s\n",characterHex);

        
        *instructionRegister     = (int32_t)memory[*instructionCounter];
        *operatioCode            = *instructionRegister / 100;
        *operand                 = *instructionRegister % 100;
        printf("%d ?  %d\t",*instructionCounter,*instructionRegister);
        switch (*operatioCode)
        {
        case READ:
            read((double*)memory,operand,instructionCounter);
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
    } while (*operatioCode != HALT || *instructionCounter == 999);
}

void dumpImplementation(double *memory, double *acummulator, uint16_t *instructionCounter,\
                            int32_t *instructionRegister, uint8_t *operatioCode, int8_t *operand)
{
    printf("REGISTERS:\nAcummulator\t\t%+05ld\n"\
            "instructionCounter\t%02ld\n"\
            "instructionRegister\t%+05ld\n"\
            "operatioCode\t\t%02ld\n"\
            "operand\t\t\t%02ld\n\n",\
            *acummulator,*instructionCounter,*instructionRegister,*operatioCode,*operand);

    printf("MEMORY:\n");
    printf("\t 0\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\t 9\t 10\t "\
            "11\t 12\t 13\t 14\t 15\t 16\t 17\t 18\t 19\t");
    for (uint16_t i = 0; i < SIZE; i++){
        if(i%20==0){
            printf("\n");
            printf("%d",i);
        }
        // printf("\t %+05ld",(int64_t)memory[i]);
        printf("\t %+0.2f",memory[i]);
    }
    printf("\n");
}