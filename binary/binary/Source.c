#include <stdio.h>
#include <stddef.h>


// C Program for the binary
// representation of a given number

size_t countBits(unsigned value)
{
    int counter = 0;
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (value & i) ? counter++ : NULL;
    return counter;
}

// Driver Code
int main(void)
{
    countBits(4);
    printf("\n");
    countBits(1234);
}