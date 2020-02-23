#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "utils.h"
#include "chunk_writer.h"
#include "write_midi.h"

void test_long_to_char_array()
{
    unsigned int array_len = 4;
    unsigned int bpm = 120;
    unsigned long int bpm_ms = get_bpm_in_milisecs(bpm);
    unsigned char *pdest = long_to_char_array(bpm_ms, array_len);

    printf("0: %x\n", pdest[0]);
    printf("1: %x\n", pdest[1]);
    printf("2: %x\n", pdest[2]);
    printf("3: %x\n", pdest[3]);
    printf("Decimal: %d, Hexadecimal: %x BPM:%d\n", (int)bpm_ms, (unsigned int)bpm_ms, (int)bpm);

    free(pdest);
}

void test_array_concat(void)
{
    char *total = ARRAY_CONCAT(char, "1234", 4, "5678", 4);
    char end_str[] = {'\0'};
    char *total2 = ARRAY_CONCAT(char, total, 8, end_str, 1);

    printf("%s\n", total2);

    free(total);
    free(total2);
}

void test_curiosities()
{
    unsigned int i = 300;
    unsigned char c;
    c = i; // this will take values between 0 and 255
    printf("300 in char: %d = %x\n", c, c);

    // slicing byte "23" out of "1234"
    printf("%x\n", (0x1234 >> 4) & 0xff);

    printf("BPM 20 = %d\n", get_bpm_in_milisecs(20));
    printf("BPM 200 = %d\n", get_bpm_in_milisecs(200));
}

void test_write_midi()
{
    int tracks = 2;
    Chunk header;
    writeHeaderTrack(&header, tracks);

    int i = 0;
    int end = header.size;

    printf("HEADER\n");
    while (i < end)
    {
        printf("%02x\n", header.chunk_ptr[i]);
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

    Chunk music;
    writeMusicTrack(&music);

    i = 0;
    end = music.size;

    printf("MUSIC\n");
    while (i < end)
    {
        printf("%02x\n", music.chunk_ptr[i]);
        ++i;
    }

    unsigned char *midi_header = ARRAY_CONCAT(unsigned char,
                                              header.chunk_ptr,
                                              header.size,
                                              tempo.chunk_ptr,
                                              tempo.size);
    unsigned char *le_midi = ARRAY_CONCAT(unsigned char,
                                          midi_header,
                                          header.size + tempo.size,
                                          music.chunk_ptr,
                                          music.size);

    i = 0;
    end = header.size + tempo.size + music.size;

    printf("MIDI\n");
    while (i < end)
    {
        printf("%02x\n", le_midi[i]);
        ++i;
    }

    write_midi("c43.mid", le_midi, header.size + tempo.size + music.size);

    // mega clean-up effort to save the ocean!
    free(midi_header);
    free(le_midi);
    free(header.chunk_ptr);
    free(tempo.chunk_ptr);
    free(music.chunk_ptr);
}
