#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "chunk_writer.h"

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

void test_write_midi()
{
    int tracks = 2;
    Chunk header;
    writeHeaderTrack(&header, tracks);

    int i = 0;
    int end = header.size;

    printf("BPM 20 = %d\n", get_bpm_in_milisecs(20));
    printf("BPM 200 = %d\n", get_bpm_in_milisecs(200));

    printf("HEADER\n");
    while (i < end)
    {
        unsigned char* pt = header.chunk_ptr + i;
        unsigned char pv = *pt;
        printf("%02x\n", pv);
        ++i;
    }

    Chunk tempo;
    writeTempoTrack(&tempo, 120, 4, 2);

    i = 0;
    end = tempo.size;

    printf("TEMPO\n");
    while (i < end)
    {
        printf("%02x\n", tempo.chunk_ptr[i]);
        ++i;
    }
}
