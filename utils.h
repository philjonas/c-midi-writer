#ifndef UTILS
#define UTILS

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define ARRAY_LENGTH(array) (sizeof((array)) / sizeof((array)[0]))

#define ARRAY_CONCAT(TYPE, A, An, B, Bn) \
    (TYPE *)array_concat((const void *)(A), (An), (const void *)(B), (Bn), sizeof(TYPE))

void *array_concat(const void *, size_t, const void *, size_t, size_t);

int test_array_concat(void);

#endif