#include <stdlib.h>

#include "chunk_writer.h"
#include "utils.h"

void writeHeaderTrack(Chunk *header, unsigned int numberOfTracks)
{
    // numberOfTracks must be between 1 and 16
    numberOfTracks = (unsigned int)CLAMP(numberOfTracks, 1, 16);

    unsigned char headerBytes[] = {
        /* MIDI header */
        0x4d, 0x54, 0x68, 0x64, // MIDI header "MThd"
        0x00, 0x00, 0x00, 0x06, // Chunk length
        0x00, 0x01,             // format MIDI 1
        0x00, numberOfTracks,   // number of instrumental tracks
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

void writeTempoTrack(Chunk *tempoTrk, unsigned int bpm,
                     unsigned int nBts, unsigned int bTyp)
{
    // Beats per Minute
    bpm = (unsigned int)CLAMP(bpm, 20, 200);
    // Number of Beats
    nBts = (unsigned int)CLAMP(nBts, 1, 16);
    // Type of Beat
    bTyp = (unsigned int)CLAMP(bTyp, 1, 16);

    // tempo = nBts / 2 ** bTyp
    // 4/4 = 4 / 2 ** 2

    unsigned long bpm_ms = get_bpm_in_milisecs(bpm);
    // get_bpm_in_milisecs will vary between 300,000 and 3,000,000
    // those values will need only 3 bytes to store them
    unsigned char *ba = long_to_char_array(bpm_ms, 3);
    unsigned char *mt = long_to_char_array(MIDI_TRACK_START, 4);
    unsigned char *et = long_to_char_array(MIDI_TRACK_END, 4);

    unsigned char tempoBytes[] = {
        /* Tempo track */
        mt[0], mt[1], mt[2], mt[3], // Track header "MTrk"
        0x00, 0x00, 0x00, 0x13,     // Chunk length // 19 bytes until track end
        0x00, 0xFF, 0x58, 0x04,     // delta time // time signature event (4/4)
        nBts, bTyp, 0x18, 0x08,     // beats // beat Type // 24 MIDI clocks // 8 32nd notes in a quarter
        0x00, 0xFF, 0x51, 0x03,     // delta time // tempo event
        ba[0], ba[1], ba[2],        // bpm in miliseconds
        et[0], et[1], et[2], et[3]  // End of track
    };

    tempoTrk->size = ARRAY_LENGTH(tempoBytes);
    unsigned char *p = malloc(sizeof(char) * tempoTrk->size);

    for (int i = 0; i < tempoTrk->size; i++)
    {
        p[i] = tempoBytes[i];
    }

    tempoTrk->chunk_ptr = p;

    free(ba);
    free(mt);
    free(et);
}

void writeMusicTrack(Chunk *musicTrk)
{
    // TODO: add inputs to this function, controlling notes or sth

    unsigned char *mt = long_to_char_array(MIDI_TRACK_START, 4);
    unsigned char *et = long_to_char_array(MIDI_TRACK_END, 4);

    unsigned char musicBytes[] = {
        /* Tempo track */
        mt[0], mt[1], mt[2], mt[3], // Track header "MTrk"
        0x00, 0x80, 0x00, 0x00,     // Chunk length // hacky way to avoid calculating track size
        0x00, 0x91,                 // delta time = 0 // note on // channel 2
        0x3c, 0x40,                 // middle C // velocity 64
        0x78, 0x3c, 0x00,           // delta time // middle C // velocity 0 (or a note off)
        0x78, 0x3c, 0x40,           // delta time // middle C // velocity 64
        0x78, 0x3c, 0x00,           // delta time // middle C // velocity 0 (or a note off)
        0x78, 0x3c, 0x40,           // delta time // middle C // velocity 64
        0x78, 0x3c, 0x00,           // delta time // middle C // velocity 0 (or a note off)
        0x78, 0x3c, 0x40,           // delta time // middle C // velocity 64
        0x78, 0x3c, 0x00,           // delta time // middle C // velocity 0 (or a note off)
        et[0], et[1], et[2], et[3]  // End of track
    };

    musicTrk->size = ARRAY_LENGTH(musicBytes);
    unsigned char *p = malloc(sizeof(char) * musicTrk->size);

    for (int i = 0; i < musicTrk->size; i++)
    {
        p[i] = musicBytes[i];
    }

    musicTrk->chunk_ptr = p;

    free(mt);
    free(et);
}
