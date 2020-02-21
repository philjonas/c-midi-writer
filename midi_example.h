#ifndef MIDI_EXAMPLE
#define MIDI_EXAMPLE

static const unsigned char MIDI_ANNOTATED_HEX[] = {
    /* MIDI header */
    0x4d, 0x54, 0x68, 0x64, // MIDI header "MThd"
    0x00, 0x00, 0x00, 0x06, // Chunk length
    0x00, 0x01,             // format MIDI 1
    0x00, 0x02,             // 2 tracks
    0x00, 0x78,             // 120 ticks per quarter-note
    /* Tempo track */
    0x4d, 0x54, 0x72, 0x6b, // Track header "MTrk"
    0x00, 0x00, 0x00, 0x13, // Chunk length // 19 bytes until track end
    0x00, 0xFF, 0x58, 0x04, // delta time // time signature event (4/4)
    0x04, 0x02, 0x18, 0x08, // 4 beats // 2 ** 2 = 4 // 24 MIDI clocks // 8 32nd notes in a quarter
    0x00, 0xFF, 0x51, 0x03, // delta time // tempo event
    0x07, 0xA1, 0x20,       // 500,000 microsecs per quarter note or 120bpm
    0x00, 0xff, 0x2f, 0x00, // End of track
    /* Instrument track 1 */
    0x4d, 0x54, 0x72, 0x6b, // Track header "MTrk"
    0x00, 0x00, 0x00, 0x1f, // Chunk length // 19 bytes until track end
    0x00, 0x91,             // delta time = 0 // note on // channel 2
    0x3c, 0x40,             // middle C // velocity 64
    0x78, 0x3c, 0x00,       // delta time // middle C // velocity 0 (or a note off)
    /*
        0x38, 0x81, 0x3c, 0x40, // alternatively, one could use a note off event
        */
    0x78, 0x3c, 0x40,      // delta time // middle C // velocity 64
    0x78, 0x3c, 0x00,      // delta time // middle C // velocity 0 (or a note off)
    0x78, 0x3c, 0x40,      // delta time // middle C // velocity 64
    0x78, 0x3c, 0x00,      // delta time // middle C // velocity 0 (or a note off)
    0x78, 0x3c, 0x40,      // delta time // middle C // velocity 64
    0x78, 0x3c, 0x00,      // delta time // middle C // velocity 0 (or a note off)
    0x00, 0xff, 0x2f, 0x00 // End of track
};

#endif // MIDI_EXAMPLE
