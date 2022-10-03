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

char* strrevv(char* str)
{
    if (!str || !*str)
        return str;

    int i = strlen(str) - 1, j = 0;

    char ch;
    while (i > j)
    {
        ch = str[i];
        str[i] = str[j];
        str[j] = ch;
        i--;
        j++;
    }
    return str;
}

void spin_words(const char* sentence, char* result) {
    char* string_a = (char*)sentence;
    char* pch;
    pch = strtok(string_a, " ");
    while (pch != NULL)
    {
        if (strlen(pch) >= 5) {
            // strrevv(pch);
            int i = strlen(pch) - 1, j = 0;

            char ch;
            while (i > j)
            {
                ch = pch[i];
                pch[i] = pch[j];
                pch[j] = ch;
                i--;
                j++;
            }
        }

        strcat(result, pch);
        strcat(result, " ");
        pch = strtok(NULL, " ");
    }
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
    const char str[] = "Hey fellow warriors";
    char res[] = "";
    spin_words(str, res);
    // spin_words func

    return 0;
}
