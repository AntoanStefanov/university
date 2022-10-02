#include <stddef.h>
#include <stdio.h>



void divisors(unsigned n, size_t* z, unsigned* array) {
    *z = 0;

    for (int i = 2; i <= (n / 2); i++)
    {
        if (n % i == 0)
            array[(*z)++] = i;
    }
}

int main() {
    unsigned a[2] = {3, 5};
    divisors(12, 2, a); // results in {2, 3, 4, 6}
    divisors(25); // results in {5}
    divisors(13); // results in NULL



    return 0;
}