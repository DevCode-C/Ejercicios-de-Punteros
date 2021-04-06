#include <stdlib.h>
#include <stdio.h>

#define SIZE 10 

void BubbleSort(int * const array, const short int size);
void swap(int *element1Ptr, int *element2Ptr);

int main(void){
    int a[SIZE] = {2, 6, 4, 8, 10, 12, 89, 68, 45, 37};
    printf("Data items in original order\n");

    for (char i = 0; i < SIZE; i++){
        printf("%4d",a[(int)i]);
    }
    printf("\n");
    BubbleSort(a,SIZE);   
    printf("Data in ascending order\n");
    for (char i = 0; i < SIZE; i++){
        printf("%4d",a[(int)i]);
    }
    printf("\n");
    return 0;
}

void BubbleSort(int * const array, const short int size){
    for (unsigned char i = 0; i < size - 1; i++){
        for (unsigned char j = 0; j < size - 1; j++){
            if(array[j]<array[j+1]){
                swap(&array[j],&array[j+1]);
            }
        }
        
    }
    
}

void swap(int *element1Ptr, int *element2Ptr){
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold;
}