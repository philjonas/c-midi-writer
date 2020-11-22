#include "write_midi.h"

void write_midi(const char *filename, const unsigned char hex_array[], size_t midi_length)
{

    FILE *fp = fopen(filename, "wb");

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    fwrite(hex_array, midi_length, sizeof(char), fp);
    fclose(fp);
}

void read_midi(const char *filename, size_t midi_length)
{
    FILE *fp;
    unsigned char ch;

    fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }

    printf("Reading file: %s\n", filename);
    for (int i = 0; i < midi_length; i++)
    {
        ch = fgetc(fp);
        printf("%02X\n", ch);
    }

    fclose(fp);
}
