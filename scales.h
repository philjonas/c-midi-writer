#ifndef SCALES_PHIL
#define SCALES_PHIL

#define NUMBER_OF_SCALES 1
#define MAX_SCALE_SIZE 15
// each note needs six items to be complete
#define MAX_NUMBER_OF_BYTES MAX_SCALE_SIZE * 6
#define MIDDLE_C 0x3c
#define QUARTER_NOTE 0x78
#define VELOCITY_ON 0x40
#define VELOCITY_OFF 0x00

typedef struct
{
    char *name;
    int length;
    int notes[MAX_SCALE_SIZE];
} Scale;

static const Scale scales[NUMBER_OF_SCALES] =
{
    {"Acoustic scale", 8, {0,2,4,6,7,9,10,12}},
};

unsigned char* scale_to_array(Scale);

#endif // SCALES_PHIL
