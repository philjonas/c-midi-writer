#include "tests.h"

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

    printf("BPM 20 = %lu\n", get_bpm_in_milisecs(20));
    printf("BPM 200 = %lu\n", get_bpm_in_milisecs(200));
}

void test_remove_blanks()
{
    char *original = "This Should Have No Blank Spaces";
    char *noBlanks;
    noBlanks = remove_blanks(original);
    printf("%s\n", noBlanks);
}

void test_write_midi()
{
    int tracks = 2;
    Chunk header;
    writeHeaderTrack(&header, tracks);

    Chunk tempo;
    writeTempoTrack(&tempo, 120, 4, 2);

    unsigned char musicBytes[] = {
        0x00, 0x91,       // delta time = 0 // note on // channel 2
        0x3c, 0x40,       // middle C // velocity 64
        0x78, 0x3c, 0x00, // delta time // middle C // velocity 0 (or a note off)
        0x78, 0x3c, 0x40, // delta time // middle C // velocity 64
        0x78, 0x3c, 0x00, // delta time // middle C // velocity 0 (or a note off)
        0x78, 0x3c, 0x40, // delta time // middle C // velocity 64
        0x78, 0x3c, 0x00, // delta time // middle C // velocity 0 (or a note off)
        0x78, 0x3c, 0x40, // delta time // middle C // velocity 64
        0x78, 0x3c, 0x00, // delta time // middle C // velocity 0 (or a note off)
    };

    Chunk music;
    writeMusicTrack(&music, musicBytes, ARRAY_LENGTH(musicBytes));

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

    write_midi("c43.mid", le_midi, header.size + tempo.size + music.size);
    read_midi("c43.mid", header.size + tempo.size + music.size);

    // mega clean-up effort to save the ocean!
    free(midi_header);
    free(le_midi);
    free(header.chunk_ptr);
    free(tempo.chunk_ptr);
    free(music.chunk_ptr);
}

void test_write_scales()
{
    int tracks = 2;
    Chunk header, tempo, music;
    unsigned char *midi_header;
    unsigned char *le_midi;
    unsigned char *musicBytes;
    unsigned int musicBytesLength;

    for (unsigned int i = 0; i < NUMBER_OF_SCALES; i++)
    {
        writeHeaderTrack(&header, tracks);
        writeTempoTrack(&tempo, 120, 4, 2);
        musicBytes = scale_to_array(scales[i]);

        musicBytesLength = scales[i].length * BYTES_PER_NOTE;
        writeMusicTrack(&music, musicBytes, musicBytesLength);

        midi_header = ARRAY_CONCAT(unsigned char,
                                   header.chunk_ptr,
                                   header.size,
                                   tempo.chunk_ptr,
                                   tempo.size);
        le_midi = ARRAY_CONCAT(unsigned char,
                               midi_header,
                               header.size + tempo.size,
                               music.chunk_ptr,
                               music.size);


        char *scaleName = remove_blanks(scales[i].name);
        strcat(scaleName, ".mid");
        write_midi(scaleName, le_midi, header.size + tempo.size + music.size);
        read_midi(scaleName, header.size + tempo.size + music.size);

        free(midi_header);
        free(le_midi);
        free(header.chunk_ptr);
        free(tempo.chunk_ptr);
        free(music.chunk_ptr);
    }
}
