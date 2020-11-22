#include "scales.h"

void writeAllScales(){
    int tracks = 2;
    Chunk header;
    writeHeaderTrack(&header, tracks);

    Chunk tempo;
    writeTempoTrack(&tempo, 120, 4, 2);

    Chunk music;
    writeMusicTrack(&music);

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

    write_midi("scales.mid", le_midi, header.size + tempo.size + music.size);
    read_midi("scales.mid", header.size + tempo.size + music.size);

    free(midi_header);
    free(le_midi);
    free(header.chunk_ptr);
    free(tempo.chunk_ptr);
    free(music.chunk_ptr);
}
