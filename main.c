#include <stdio.h>

#include "endian.h"

int main()
{

    // test_endian();

    unsigned char midi_hex[] = {
        0x4d, 0x54, 0x68, 0x64, // MIDI header "MThd"
        0x00, 0x00, 0x00, 0x06, //Chunk length
        0x00, 0x01,             // format MIDI 1
        0x00, 0x02,             // 2 tracks
        0x00, 0x78,             // 120 per quarter-note
        0x4d, 0x54, 0x72, 0x6b, // Track header "MTrk"
        0x00, 0x00, 0x00, 0x11, //Chunk length (17) number of bytes until the end of the track(?)
        0x00, 0xf0, 0x0a, 0x41, 0x10, 0x42,
        0x12, 0x40, 0x00, 0x7f, 0x00, 0x41, 0xf7,
        0x00, 0xff, 0x2f, 0x00, // End of track
        0x4d, 0x54, 0x72, 0x6b, // Track header "MTrk"
        0x00, 0x00, 0x00, 0x0c, //Chunk length (10)  number of bytes until the end of the track(!)
        0x00, 0x91,             // note on - channel 2
        0x3c, 0x40,             // middle C - velocity 64
        // 0x38, 0x3c, 0x00,       // delta - middle C - velocity 0 (or a note off)
        0x38, 0x81, 0x3c, 0x40,
        0x00, 0xff, 0x2f, 0x00 // End of track
    };
    FILE *fp = fopen("c42.mid", "wb");

    if (fp == NULL)
    {
        return 1;
    }

    fwrite(&midi_hex, sizeof(midi_hex), 1, fp);
    fclose(fp);

    return 0;
}
