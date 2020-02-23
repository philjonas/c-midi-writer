#ifndef UTILS_PHIL
#define UTILS_PHIL

#include <stddef.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

#define CLAMP(val, min, max) (((val) > (max)) ? (max) : ((val) < (min) ? (min) : (val)))

#define ARRAY_LENGTH(array) (sizeof((array)) / sizeof((array)[0]))

#define ARRAY_CONCAT(TYPE, A, An, B, Bn) \
    (TYPE *)array_concat((const void *)(A), (An), (const void *)(B), (Bn), sizeof(TYPE))

#define BYTE_IN_BITS 8
#define BYTE_MASK 0xff
#define SIXTY_MILLION 60000000

void *array_concat(const void *, size_t, const void *, size_t, size_t);

void *long_to_char_array(unsigned long int, unsigned int);

unsigned long int get_bpm_in_milisecs(unsigned int);

#endif // UTILS_PHIL
