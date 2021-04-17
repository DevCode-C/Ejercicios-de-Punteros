#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

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

    #define ADD         30 //   Add a word from a specific location in memory to the word in the accumulator (leave result in accumulator).
    
    #define SUBTRACT    31 //   Subtract a word from a specific location in memory from the word in the accumulator (leave result in accumulator).
    
    #define DIVIDE      32 //   Divide a word from a specific location in memory into the word in the accumulator (leave result in accumulator).

    #define MULTIPLY    33 //   Multiply a word from a specific location in memory by the word in the accumulator (leave result in accumulator).

    /*
        Transfer-of-control operations:
    */

    #define BRANCH      40 //   Branch to a specific location in memory.

    #define BRANCHNEG   41 //   Branch to a specific location in memory if the accumulator is negative.
    
    #define BRANCHZERO  42 //   Branch to a specific location in memory if the accumulator is zero.
    
    #define HALT        43 //   Halt—i.e., the program has completed its task.


    /*
        Memory Space
    */
    #define MEMORY_SPACE    100

    /*
        MACROS
    */
    #define CLS     system("clear")

    /*
        Operations
    */

    void printMemory(int32_t *memory, int8_t size);

    void setData(int32_t *memory, int8_t size, int8_t *operation, int8_t *operand);

    void readOperation(int32_t *memory, int8_t size, int8_t *operation, int8_t *operand);

    void showMemory(int32_t *memory, int8_t size);

    /*
        Operations Functions
    */

    void read(int32_t *memory, int8_t *operand, int8_t *counter);

    void write(int32_t *memory, int8_t *operand, int8_t *counter);  

    void load(int32_t *memory, int8_t *operand, int8_t *accumulator);

    void store(int32_t *memory, int8_t *operand, int8_t *accumulator);

    void add(int32_t *memory, int8_t *operand, int8_t *accumulator);

    void substract(int32_t *memory, int8_t *operand, int8_t *accumulator);

    void divide(int32_t *memory, int8_t *operand, int8_t *accumulator);

    void multiply(int32_t *memory, int8_t *operand, int8_t *accumulator);

    void branch(int32_t *memory, int8_t *operand, int8_t *counter);

    void branchNeg(int32_t *memory, int8_t *operand, int8_t *counter, int8_t *accumulator);

    void branchZero(int32_t *memory, int8_t *operand, int8_t *counter, int8_t *accumulator);

    void halt(void);

#endif