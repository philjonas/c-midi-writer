#include "utils.h"

// example taken from http://www.rosettacode.org/wiki/Array_concatenation#C
void *array_concat(const void *arrayA, size_t arrayA_size,
                   const void *arrayB, size_t arrayB_size, size_t sizeOfType)
{
    char *p = malloc(sizeOfType * (arrayA_size + arrayB_size));
    memcpy(p, arrayA, arrayA_size * sizeOfType);
    memcpy(p + arrayA_size * sizeOfType, arrayB, arrayB_size * sizeOfType);
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

char* remove_blanks(char *text)
{
    static char blank[100];
    int c = 0, d = 0;

    while (text[c] != '\0')
    {
        if (text[c] != ' ')
        {
            blank[d] = text[c];
            d++;
        }
        c++;
    }
    blank[d] = '\0';
    return blank;
}
