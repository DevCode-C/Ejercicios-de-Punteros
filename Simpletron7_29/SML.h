#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

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

    #define NEWLINE     22 // 

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

    void read(double *memory, int8_t *operand, uint16_t *counter);

    void write(double  *memory, int8_t *operand, uint16_t *counter);  

    void load(double  *memory, int8_t *operand, double *accumulator, uint16_t *counter);

    void store(double  *memory, int8_t *operand, double *accumulator, uint16_t *counter);

    void newline(double  *memory,uint16_t *counter);

    void add(double  *memory, int8_t *operand, double *accumulator, uint16_t *counter);

    void substract(double  *memory, int8_t *operand, double *accumulator, uint16_t *counter);

    void divide(double  *memory, int8_t *operand, double *accumulator, uint16_t *counter);

    void multiply(double  *memory, int8_t *operand, double *accumulator, uint16_t *counter);

    void remaind(double  *memory, int8_t *operand, double *accumulator, uint16_t *counter);

    void exponetation(double  *memory, int8_t *operand, double *accumulator, uint16_t *counter);

    void branch(double  *memory, int8_t *operand, uint16_t *counter);

    void branchNeg(double  *memory, int8_t *operand, uint16_t *counter, double *accumulator);

    void branchZero(double  *memory, int8_t *operand, uint16_t *counter, double *accumulator);

    void halt(void);

    /*Main functions*/
    void loadImplementation(double  *memory, double *acummulator, uint16_t *instructionCounter,\
                            int32_t *instructionRegister, uint8_t *operatioCode, int8_t *operand);

    void executeImplementation(double  *memory, double *acummulator, uint16_t *instructionCounter,\
                                int32_t *instructionRegister, uint8_t *operatioCode, int8_t *operand);

    void dumpImplementation(double *memory, double *acummulator, uint16_t *instructionCounter,\
                            int32_t *instructionRegister, uint8_t *operatioCode, int8_t *operand);
    /**/

    int16_t ConversionHex_to_Dec(char character);
#endif