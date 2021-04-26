#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include "SML.h"

/*Arrays*/
int32_t memoryRegisters[SIZE] = {0};
/**/

/*Private variables*/
int32_t     accumulatorM             = 0;
uint16_t    instructionCounterM      = 0;
int32_t     instructionRegisterM     = 0;
uint8_t     operatioCodeM            = 0;
int8_t      operandM                 = 0;
/**/


int main(void){
    welcome();
    
    loadImplementation(memoryRegisters,&accumulatorM,&instructionCounterM,\
                        &instructionRegisterM,&operatioCodeM,&operandM);

    executeImplementation(memoryRegisters,&accumulatorM,&instructionCounterM,\
                        &instructionRegisterM,&operatioCodeM,&operandM);

    // dumpImplementation(memoryRegisters,&accumulatorM,&instructionCounterM,\
    //                     &instructionRegisterM,&operatioCodeM,&operandM);
    
}