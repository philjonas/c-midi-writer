#ifndef SCALES_PHIL
#define SCALES_PHIL

#include "chunk_writer.h"
#include "write_midi.h"

#define MAX_SCALE_SIZE 15

typedef struct
{
  char *name;
  unsigned int length;
  unsigned int notes[MAX_SCALE_SIZE];
} Scale;

Scale scales[] = {
    { "Acoustic scale", 8, {0,2,4,6,7,9,10,12,} },
};

void writeAllScales();

#endif // SCALES_PHIL
