#include <stdlib.h>

#include "chunk_writer.h"
#include "utils.h"

void writeHeaderTrack(Chunk *header, unsigned int numberOfTracks)
{
    ;

    // numberOfTracks must be between 1 and 16
    numberOfTracks = (unsigned int)bound_int(numberOfTracks, 1, 16);

    unsigned char headerBytes[] = {
        /* MIDI header */
        0x4d, 0x54, 0x68, 0x64, // MIDI header "MThd"
        0x00, 0x00, 0x00, 0x06, // Chunk length
        0x00, 0x01,             // format MIDI 1
        0x00, numberOfTracks,   // 2 tracks
        0x00, 0x78,             // 120 ticks per quarter-note
    };

    header->size = ARRAY_LENGTH(headerBytes);
    unsigned char *p = malloc(sizeof(char) * header->size);

    for (int i = 0; i < header->size; i++)
    {
        p[i] = headerBytes[i];
    }

    header->chunk_ptr = p;
}

void writeTempoTrack(Chunk *tempoTrk, unsigned int bpm, unsigned int nBts, unsigned int bTyp)
{
    // Beats per Minute
    bpm = (unsigned int)bound_int(bpm, 20, 200);
    // Number of Beats
    nBts = (unsigned int)bound_int(nBts, 1, 16);
    // Type of Beat
    bTyp = (unsigned int)bound_int(bTyp, 1, 16);

    // tempo = nBts / 2 ** bTyp
    // 4/4 = 4 / 2 ** 2

    // get_bpm_in_milisecs will vary between 300,000 and 3,000,000
    // those values will need only 3 bytes to store them
    unsigned int bpm_array_len = 3;
    unsigned long bpm_ms = get_bpm_in_milisecs(bpm);
    unsigned char *ba = long_to_char_array(bpm_ms, bpm_array_len);

    unsigned char tempoBytes[] = {
        /* Tempo track */
        0x4d, 0x54, 0x72, 0x6b, // Track header "MTrk"
        0x00, 0x00, 0x00, 0x13, // Chunk length // 19 bytes until track end
        0x00, 0xFF, 0x58, 0x04, // delta time // time signature event (4/4)
        nBts, bTyp, 0x18, 0x08, // 4 beats // 2 ** 2 = 4 // 24 MIDI clocks // 8 32nd notes in a quarter
        0x00, 0xFF, 0x51, 0x03, // delta time // tempo event
        ba[0], ba[1], ba[2],       // 500,000 microsecs per quarter note or 120bpm
        0x00, 0xff, 0x2f, 0x00  // End of track
    };

    tempoTrk->size = ARRAY_LENGTH(tempoBytes);
    unsigned char *p = malloc(sizeof(char) * tempoTrk->size);

    for (int i = 0; i < tempoTrk->size; i++)
    {
        p[i] = tempoBytes[i];
    }

    tempoTrk->chunk_ptr = p;
}
