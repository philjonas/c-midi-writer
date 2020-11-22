#ifndef WRITE_MIDI
#define WRITE_MIDI

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void write_midi(const char *, const unsigned char[], size_t);

void read_midi(const char *, size_t);

#endif
