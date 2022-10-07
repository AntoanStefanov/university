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
    char copyy[100];
    strcpy(copyy, sentence);
    // creating copy bcs sentence is const.

    char* pch;
    pch = strtok(copyy, " ");
    int resultIndex = 0;
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

        for (unsigned pchIndex = 0; pchIndex < strlen(pch); pchIndex++) {
            char charr = pch[pchIndex];
            result[resultIndex] = charr;
            resultIndex++;
        }
        result[resultIndex] = ' ';
        resultIndex++;
        //strcat(result, pch); this adds it AT THE END ON EVEN EMPTY ARR
        //strcat(result, " ");
        pch = strtok(NULL, " ");
    }
    if (resultIndex > 0) {
        resultIndex--;
        result[resultIndex] = '\0'; // this removes all MMMM, allocated memory for other symbols.
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
    //const char str[] = "";
    const char* sentence = "This is another test";
    char submitted[30 * 14 + 1];
    spin_words(sentence, (char*)&submitted);
    // spin_words func
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//int main()
//{
//
//    char s[100];
//    scanf("%[^\n]%*c", &s);
//
//    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//    printf("Hello, World!");
//    printf("Aaa:%s", s);
//    return 0;
//}


//int main()
//{
//
//    char ch;
//    scanf("%c", &ch);
//
//    char string[100];
//    getchar();
//    scanf("%[^\n]%*c", string);
//
//    char sentence[100];
//    scanf("%[^\n]%*c", sentence);
//
//    printf("%c\n", ch);
//    printf("%s\n", string);
//    printf("%s", sentence);
//
//
//    return 0;
//}