#ifndef CHUNK_WRITER
#define CHUNK_WRITER

typedef struct
{
  int size;
  unsigned char *chunk_ptr;
} Chunk;

void writeHeaderTrack(Chunk *, unsigned int);

void writeTempoTrack(Chunk *, unsigned int, unsigned int, unsigned int);

#endif // CHUNK_WRITER
