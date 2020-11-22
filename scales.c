#include "scales.h"

unsigned char *scale_to_array(Scale scale)
{
    static unsigned char payload[MAX_NUMBER_OF_BYTES];
    for (unsigned int i = 0; i < scale.length; i++)
    {
        for (unsigned int j = 0; j < 6; j++)
        {
            switch (j % 6)
            {
            case 0:
            case 3:
                payload[i] = QUARTER_NOTE;
                break;
            case 1:
            case 4:
                payload[i] = MIDDLE_C + scale.notes[i];
                break;
            case 2:
                payload[i] = VELOCITY_ON;
                break;
            case 5:
                payload[i] = VELOCITY_OFF;
                break;
            default:
                break;
            }
        }
    }

    return payload;
}
