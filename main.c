#include <stdio.h>

#include "endian.h"

int main()
{

    // test_endian();

    unsigned char midi_hex[] = {
        0x4d, 0x54, 0x68, 0x64,                        // MIDI header "MThd"
        0x00, 0x00, 0x00, 0x06,                        //Chunk length
        0x00, 0x01,                                    // format MIDI 1
        0x00, 0x02,                                    // 2 tracks
        0x00, 0x78,                                    // 120 per quarter-note
        0x4d, 0x54, 0x72, 0x6b,                        // Track header "MTrk"
        0x00, 0x00, 0x00, 0x13,                        //Chunk length (17) number of bytes until the end of the track(?)
        0x00, 0xFF, 0x58, 0x04, 0x04, 0x02, 0x18, 0x08,// time signature 4/4
        0x00, 0xFF, 0x51, 0x03, 0x07, 0xA1, 0x20,      // tempo
                                                       //500,000 microsecs per quarter or 120bpm
        0x00, 0xff, 0x2f, 0x00,                        // End of track
        0x4d, 0x54, 0x72, 0x6b,                        // Track header "MTrk"
        0x00, 0x00, 0x00, 0x11,                        //Chunk length (10)  number of bytes until the end of the track(!)
        0x00, 0x91,                                    // delta = 0 // note on - channel 2
        0x3c, 0x40,                                    // middle C - velocity 64
        0x78, 0x3c, 0x00,                              // delta - middle C - velocity 0 (or a note off)
        // 0x38, 0x81, 0x3c, 0x40,
        0x78, 0x3c, 0x40,                              // delta - middle C - velocity 64
        0x78, 0x3c, 0x00,                              // delta - middle C - velocity 0 (or a note off)
        0x00, 0xff, 0x2f, 0x00                         // End of track
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
