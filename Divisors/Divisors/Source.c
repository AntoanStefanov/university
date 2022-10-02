#include <stddef.h>
#include <string.h>
#include <stdio.h>

//  assign divisors to array[]
//  set *length to the number of divisors

void divisors(int* n) {
    size_t* length;
    unsigned array[];

    int counter = 0;
    for (unsigned i = 2; i < n; i++) {
        if (n % 2 == 0) {
            array[counter] = i;
            counter++;
        }
    }
    length = counter;
}
int x = 12, y = 25, z = 13;
divisors(x); // results in {2, 3, 4, 6}
divisors(y); // results in {5}
divisors(z); // results in NULL

