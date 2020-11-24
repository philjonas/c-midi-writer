#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "utils.h"
#include "midi_example.h"
#include "write_midi.h"
#include "tests.h"
#include "scales.h"

int main (int argc, char **argv)
{
    int c;
    const char * fileName = "c42.mid";
    if(argc > 1)
    {
        // TODO: these flags could be more meaningful
        while ((c = getopt(argc, argv, "abcdef")) != -1)
        {
            switch (c)
            {
            case 'a':
                test_array_concat();
                break;
            case 'b':
                test_long_to_char_array();
                break;
            case 'c':
                test_curiosities();
                break;
            case 'd':
                test_write_midi();
                break;
            case 'e':
                test_remove_blanks();
                break;
            case 'f':
                // writing and reading the example byte array
                write_midi(fileName, MIDI_ANNOTATED_HEX, ARRAY_LENGTH(MIDI_ANNOTATED_HEX));
                read_midi(fileName, ARRAY_LENGTH(MIDI_ANNOTATED_HEX));
                break;
            case '?':
                if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                             "Unknown option character `\\x%x'.\n",
                             optopt);
                return 1;
            default:
                break;
            }
        }
    }
    else
    {
        test_write_scales();
    }
    return 0;
}
