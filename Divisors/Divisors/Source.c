#include <stddef.h>
#include <stdio.h>



void divisors(unsigned n, size_t* z, unsigned* array) {
    *z = 0;

    for (int i = 2; i <= (n / 2); i++)
    {
        if (n % i == 0)
            array[(*z)++] = i;
    }
    printf("a");
}

int main() {
    unsigned arr[4];
    unsigned b[1];
    unsigned c[] = { NULL };
    size_t z;
    divisors(12, &z, arr); // results in {2, 3, 4, 6}
    divisors(25, &z, b); // results in {5}
    divisors(13, &z, c); // results in NULL
    printf("check");



    return 0;
}

#include <stdbool.h>

bool is_pangram(const char* str_in) {

    //  <----  hajime!

}