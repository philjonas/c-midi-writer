#include <stdint.h>
#include <stdio.h>

int write_midi(const char* filename, unsigned int* midi_hex, size_t midi_length)
{

    printf("II---%x\n", midi_hex[0]);
    FILE *fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        return 1;
    }

    fwrite(&midi_hex, midi_length, sizeof(char), fp);
    fclose(fp);

    return 0;
}
