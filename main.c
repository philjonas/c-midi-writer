#include <stdio.h>

#include "utils.h"
#include "midi_example.h"
#include "write_midi.h"

int main()
{
    test_array_concat();
    test_long_to_char_array();

    unsigned int i = 300;
    unsigned char c;
    c = i; // this will take values between 0 and 255
    printf("300 in char: %d = %x\n", c, c);

    printf("%x\n", (0x1234 >> 4) & 0xff);

    printf("MIDI header: %s\n", MIDI_ANNOTATED_HEX);

    write_midi("c42.mid", MIDI_ANNOTATED_HEX, ARRAY_LENGTH(MIDI_ANNOTATED_HEX));
    return 0;
}
