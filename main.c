#include <stdio.h>

#include "endian.h"
#include "midi_example.h"
#include "midi_writer.h"

int main()
{

    // test_endian();
    // need to pass array length
    size_t midi_length = sizeof(midi_hex);
    write_midi("c42.mid", (unsigned int *)midi_hex, midi_length);
    printf("I----%x\n", midi_hex[0]);
/*
    FILE *fp = fopen("c42.mid", "wb");

    if (fp == NULL)
    {
        return 1;
    }

    fwrite(&midi_hex, sizeof(midi_hex), sizeof(char), fp);
    fclose(fp);

    return 0;*/
}
