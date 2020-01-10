#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"

// example taken from http://www.rosettacode.org/wiki/Array_concatenation#C

void *array_concat(const void *a, size_t an, const void *b, size_t bn, size_t s)
{
    char *p = malloc(s * (an + bn));
    memcpy(p, a, an * s);
    memcpy(p + an * s, b, bn * s);
    return p;
}

void *long_to_char_array(unsigned long int long_int, unsigned int array_len)
{
    char *pdest = malloc(sizeof(char) * array_len);
    for (int i = 0; i < array_len; i++)
    {
        pdest[array_len - 1 - i] = (long_int >> (BYTE_IN_BITS * i)) & BYTE_MASK;
    }
    return pdest;
}

// TODO: move tests to their own place
void test_long_to_char_array()
{
    unsigned int i = 4;
    unsigned long int l = 5000;
    unsigned char *pdest;

    pdest = long_to_char_array(l, i);

    printf("0: %x\n", pdest[0]);
    printf("1: %x\n", pdest[1]);
    printf("2: %x\n", pdest[2]);
    printf("3: %x\n", pdest[3]);
    printf("%d, %x\n", (int)l, (unsigned int)l);
}

int test_array_concat(void)
{
    char *total = ARRAY_CONCAT(char, "1234", 4, "5678", 4);
    char end_str[] = {'\0'};
    char *total2 = ARRAY_CONCAT(char, total, 8, end_str, 1);

    printf("%s\n", total2);

    free(total);
    return 0;
}
