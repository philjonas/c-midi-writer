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

int test_array_concat(void)
{
    const int a[] = {1, 1, 1, 1};
    const int b[] = {2, 2, 2, 2};
    unsigned int i;

    int *total = ARRAY_CONCAT(int, a, 4, b, 4);

    for (i = 0; i < 8; i++)
        printf("%d\n", total[i]);

    free(total);
    return 0;
}
