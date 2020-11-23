#include "scales.h"

unsigned char *scale_to_array(Scale scale)
{
    static unsigned char payload[MAX_NUMBER_OF_BYTES];
    for (unsigned int i = 0; i < scale.length; i++)
    {
        for (unsigned int j = 0; j < BYTES_PER_NOTE; j++)
        {
            int payloadIndex = i * BYTES_PER_NOTE + j;
            switch (j % BYTES_PER_NOTE)
            {
            case 0:
            case 4:
                payload[payloadIndex] = QUARTER_NOTE;
                break;
            case 2:
            case 6:
                payload[payloadIndex] = MIDDLE_C + scale.notes[i];
                break;
            case 1:
                payload[payloadIndex] = NOTE_ON_CH_2;
                break;
            case 5:
                payload[payloadIndex] = NOTE_OFF_CH_2;
                break;
            default:
                payload[payloadIndex] = VELOCITY_64;
                break;
            }
        }
    }

    return payload;
}
