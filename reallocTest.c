#include <stdio.h>
#include <stdlib.h>

int main(){

    int size = 20;
    // allocate and initialise memory for 8 ints in the pointer
    int * pArray = malloc( size * sizeof(int) );
    // put 1 to 8 in the array
    for (int i = 0; i < size; i++)
    {
        *(pArray + i) = i + 1;
    }
    // print out the values in the array
    int A = 0;
    while (A!=size){
        printf("%i ",*(pArray + A));
        A++;
    }
    printf("\n");

    int L = 0;
    while( (size - L) !=1){
        //reallocate the memory as smaller
        pArray = realloc(pArray,  (size - L)* sizeof(int));
        L++;

        A = 0;
        while (A!=size){
            printf("%i ",*(pArray + A));
            A++;
        }
        printf("\n");
    }


    A = 0;
    while (A!=size){
        printf("%i ",*(pArray + A));
        A++;
    }



    


    printf("\n\n\n");
    return 0;
}