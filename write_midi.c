#include <stdint.h>
#include <stdio.h>

#include "write_midi.h"

int write_midi(const char *filename, const unsigned char hex_array[], size_t midi_length)
{

    FILE *fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        return 1;
    }

    fwrite(hex_array, midi_length, sizeof(char), fp);
    fclose(fp);

    return 0;
}
