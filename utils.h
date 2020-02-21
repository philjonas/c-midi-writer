#ifndef UTILS_PHIL
#define UTILS_PHIL

#include <stddef.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define ARRAY_LENGTH(array) (sizeof((array)) / sizeof((array)[0]))

#define BYTE_IN_BITS 8

#define BYTE_MASK 0xff

#define SIXTY_MILLION 60000000

#define ARRAY_CONCAT(TYPE, A, An, B, Bn) \
    (TYPE *)array_concat((const void *)(A), (An), (const void *)(B), (Bn), sizeof(TYPE))

void *array_concat(const void *, size_t, const void *, size_t, size_t);

void *long_to_char_array(unsigned long int, unsigned int);

unsigned long int get_bpm_in_milisecs(unsigned int);

int bound_int(int, int, int);

#endif
