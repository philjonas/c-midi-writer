#include <stdio.h>

#include "endian.h"
#include "midi_example.h"
#include "write_midi.h"

#define ARRAY_LENGTH(array) (sizeof((array)) / sizeof((array)[0]))

int main()
{
    test_endian();
    write_midi("c42.mid", midi_hex, ARRAY_LENGTH(midi_hex));
}
