#include "utils.h"
#include "midi_example.h"
#include "write_midi.h"
#include "tests.h"
#include "scales.h"

int main()
{
   // test_array_concat();
   // test_long_to_char_array();
   // test_curiosities();
   test_write_midi();

   write_midi("c42.mid", MIDI_ANNOTATED_HEX, ARRAY_LENGTH(MIDI_ANNOTATED_HEX));
   read_midi("c42.mid", ARRAY_LENGTH(MIDI_ANNOTATED_HEX));

   return 0;
}
