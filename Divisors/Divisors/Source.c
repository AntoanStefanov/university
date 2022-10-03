#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void divisors(unsigned n, size_t* z, unsigned* array) {
    *z = 0;

    for (int i = 2; i <= (n / 2); i++)
    {
        if (n % i == 0)
            array[(*z)++] = i;
    }
}

//  do not allocate memory for return string
//  assign the value to the pointer "result"

void spin_words(const char* sentence, char* result) {
    char* pch;
    pch = strtok(sentence, " ");
    while (pch != NULL)
    {
        if (strlen(pch) >= 5) {
            strrev(pch);
        }
        strcat(result, pch);
        strcat(result, " ");
        pch = strtok(NULL, " ");
    }
    result[strlen(result) - 1] = '\0';
}

int main() {
    // divisors func
    unsigned arr[4];
    unsigned b[1];
    unsigned c[] = { NULL };
    size_t z;
    divisors(12, &z, arr); // results in {2, 3, 4, 6}
    divisors(25, &z, b); // results in {5}
    divisors(13, &z, c); // results in NULL
    printf("check\n");
    // divisors func

    // spin_words func
    char str[] = "Hey fellow warriors";
    char res[20] = "";
    spin_words(str, res);
    // spin_words func

    return 0;
}
