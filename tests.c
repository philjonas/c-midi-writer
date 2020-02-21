// #include <stdlib.h>
// #include <stdio.h>
#include <string.h>

#include "utils.h"

void test_long_to_char_array()
{
    unsigned int array_len = 4;
    unsigned int bpm = 120;
    unsigned long int bpm_ms = get_bpm_in_milisecs(bpm);
    unsigned char *pdest;

    pdest = long_to_char_array(bpm_ms, array_len);

    printf("0: %x\n", pdest[0]);
    printf("1: %x\n", pdest[1]);
    printf("2: %x\n", pdest[2]);
    printf("3: %x\n", pdest[3]);
    printf("Decimal: %d, Hexadecimal: %x BPM:%d\n", (int)bpm_ms, (unsigned int)bpm_ms, (int)bpm);
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

void test_curiosities()
{
    unsigned int i = 300;
    unsigned char c;
    c = i; // this will take values between 0 and 255
    printf("300 in char: %d = %x\n", c, c);

    // slicing byte "23" out of "1234"
    printf("%x\n", (0x1234 >> 4) & 0xff);
}
