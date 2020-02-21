#include <stdio.h>

#include "utils.h"
#include "midi_example.h"
#include "write_midi.h"
#include "tests.h"

int main()
{
    test_array_concat();
    test_long_to_char_array();
    test_curiosities();

    printf("MIDI header: %s\n", MIDI_ANNOTATED_HEX);

    write_midi("c42.mid", MIDI_ANNOTATED_HEX, ARRAY_LENGTH(MIDI_ANNOTATED_HEX));
    return 0;
}
