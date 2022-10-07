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

size_t secondSolveCountBits(unsigned value)
{
    size_t bit;

    bit = 0;
    while (value) {
        if (value % 2 != 0)
            bit++;
        value /= 2;
    }
    return bit;
}

// Driver Code
int main(void)
{
    secondSolveCountBits(4);
    countBits(4);
    countBits(1234);
}