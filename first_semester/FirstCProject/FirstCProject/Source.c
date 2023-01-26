#include <stdio.h>
#include <stdlib.h>

int main() {
    // Static
    /*
    int arr[3][3] = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 9, 3}
    };
    printf("%llu\n", sizeof(arr)); // 36 / 4(size of int) = 9 elements
    printf("Num: %d\n", arr[2][1]);
    */

    // Dynamic arr
    int* arr; // Pointer
    int* temp;
    size_t arrSize = 256;
    // calloc is used to allocate a specified amount of memory and then initialize it to zero.
    arr = calloc(arrSize, sizeof(int)); // total number of elements, size of each element.
    if (arr == NULL) {
        fprintf(stderr, "Array not reallocated");
        return 1;
    }
    arr[0] = 17;

    arrSize *= 2; // double arrsize

    //new location in memory(arr-pointer) reassigned 
                //pointer, arrSize in bytes
   
    temp = realloc(arr, arrSize * sizeof(int));
    if (temp != NULL) {
        arr = temp;
    }

    printf("%d", arr[0]);

    free(arr); // deallocate after finishing with dynamic arr.

    return 0;
}
