#ifndef CHUNK_WRITER
#define CHUNK_WRITER

#define MIDI_TRACK_START 0x4d54726b
#define MIDI_TRACK_END 0x00ff2f00

typedef struct
{
  int size;
  unsigned char *chunk_ptr;
} Chunk;

void writeHeaderTrack(Chunk *, unsigned int);

void writeTempoTrack(Chunk *, unsigned int, unsigned int, unsigned int);

void writeMusicTrack(Chunk *);

#endif // CHUNK_WRITER
