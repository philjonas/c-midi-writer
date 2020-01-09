#include <stdio.h>

#include "utils.h"
#include "endian.h"
#include "midi_example.h"
#include "write_midi.h"

int main()
{
    test_endian();
    test_array_concat();

    unsigned int i = 300;
    unsigned char c;
    c = i; // this will take values between 0 and 255
    printf("300 in char: %d = %x\n", c, c);

    printf("MIDI header: %s\n", MIDI_ANNOTATED_HEX);

    write_midi("c42.mid", MIDI_ANNOTATED_HEX, ARRAY_LENGTH(MIDI_ANNOTATED_HEX));
    return 0;
}
