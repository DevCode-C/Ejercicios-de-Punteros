#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#ifndef  __SML_H__
#define  __SML_H__
    /*
        Input/output operations:
    */

    #define READ        10 //   Read a word from the terminal into a specific location in memory.

    #define WRITE       11 //   Write a word from a specific location in memory to the terminal.
    
    /*
        Load/store operations:
    */
    
    #define LOAD        20 //   Load a word from a specific location in memory into the accumulator.

    #define STORE       21 //   Store a word from the accumulator into a specific location in memory.

    /*
        Arithmetic operations:
    */

    #define ADD                 30 //   Add a word from a specific location in memory to the word in the accumulator (leave result in accumulator).
    
    #define SUBTRACT            31 //   Subtract a word from a specific location in memory from the word in the accumulator (leave result in accumulator).
    
    #define DIVIDE              32 //   Divide a word from a specific location in memory into the word in the accumulator (leave result in accumulator).

    #define MULTIPLY            33 //   Multiply a word from a specific location in memory by the word in the accumulator (leave result in accumulator).

    #define REMAINDER           34 //   Remaind a word from a specific location in memory by the word in the accumulator (Leave result in accumulator).

    #define EXPONENTIATION      35 // 

    /*
        Transfer-of-control operations:
    */

    #define BRANCH      40 //   Branch to a specific location in memory.

    #define BRANCHNEG   41 //   Branch to a specific location in memory if the accumulator is negative.
    
    #define BRANCHZERO  42 //   Branch to a specific location in memory if the accumulator is zero.
    
    #define HALT        43 //   Halt—i.e., the program has completed its task.

    /*
        MACROS
    */
    #define CLS     system("clear")
    #define SIZE    1000UL

    /*
        Operations
    */

    void welcome(void);
    /*
        Operations Functions
    */

    void read(int32_t *memory, int8_t *operand, uint16_t *counter);

    void write(int32_t *memory, int8_t *operand, uint16_t *counter);  

    void load(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter);

    void store(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter);

    void add(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter);

    void substract(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter);

    void divide(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter);

    void multiply(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter);

    void remaind(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter);

    void exponetation(int32_t *memory, int8_t *operand, int32_t *accumulator, uint16_t *counter);

    void branch(int32_t *memory, int8_t *operand, uint16_t *counter);

    void branchNeg(int32_t *memory, int8_t *operand, uint16_t *counter, int32_t *accumulator);

    void branchZero(int32_t *memory, int8_t *operand, uint16_t *counter, int32_t *accumulator);

    void halt(void);

    /*Main functions*/
    void loadImplementation(int32_t *memory, int32_t *acummulator, uint16_t *instructionCounter,\
                            int32_t *instructionRegister, uint8_t *operatioCode, int8_t *operand);

    void executeImplementation(int32_t *memory, int32_t *acummulator, uint16_t *instructionCounter,\
                                int32_t *instructionRegister, uint8_t *operatioCode, int8_t *operand);

    void dumpImplementation(int32_t *memory, int32_t *acummulator, uint16_t *instructionCounter,\
                            int32_t *instructionRegister, uint8_t *operatioCode, int8_t *operand);
    /**/
#endif