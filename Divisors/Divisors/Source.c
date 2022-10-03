#include <stddef.h>
#include <stdio.h>
#include <string.h>
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
    char* next_token = NULL;
    char* token;
    token = strtok_s(sentence, " ", &next_token);
    int indexCounter = 0;
    while (token) {
        if (strlen(token) >= 5) {
            _strrev(token);
        }
        for (int i = 0; i < strlen(token); i++) {
            result[indexCounter] = token[i];
            indexCounter++;
        }
        result[indexCounter] = ' ';
        indexCounter++;
        token = strtok_s(NULL, " ", &next_token);

    }
    result[strlen(result) - 1] = '\0';
    printf("%s", result);
    printf("A");
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
    char res[3000];
    char str[] = "Hey fellow warriors";
    spin_words(str, res);
    // spin_words func

    return 0;
}
