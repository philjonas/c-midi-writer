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

unsigned long int get_bpm_in_milisecs(unsigned int bpm)
{
    return SIXTY_MILLION / bpm;
}
