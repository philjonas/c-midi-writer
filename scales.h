#ifndef SCALES_PHIL
#define SCALES_PHIL

#define NUMBER_OF_SCALES 44
#define MAX_SCALE_SIZE 15
#define BYTES_PER_NOTE 8
#define MAX_NUMBER_OF_BYTES MAX_SCALE_SIZE * BYTES_PER_NOTE
#define MIDDLE_C 0x3c
#define QUARTER_NOTE 0x78
#define VELOCITY_64 0x40
#define NOTE_ON_CH_2 0x91
#define NOTE_OFF_CH_2 0x81

typedef struct
{
    char *name;
    int length;
    int notes[MAX_SCALE_SIZE];
} Scale;

static const Scale scales[NUMBER_OF_SCALES] =
{
    { "Acoustic Scale", 8, {0,2,4,6,7,9,10,12,} },
    { "Aeolian Mode Or Natural Minor Scale", 8, {0,2,3,5,7,8,10,12,} },
    { "Altered Scale", 8, {0,1,3,4,6,8,10,12,} },
    { "Augmented Scale", 7, {0,3,4,7,8,11,12,} },
    { "Bebop Dominant Scale", 9, {0,2,4,5,7,9,10,11,12,} },
    { "Blues Scale", 7, {0,3,5,6,7,10,12,} },
    { "Chromatic Scale", 13, {0,1,2,3,4,5,6,7,8,9,10,11,12,} },
    { "Dorian Mode", 8, {0,2,3,5,7,9,10,12,} },
    { "Double Harmonic Scale", 8, {0,1,4,5,7,8,11,12,} },
    { "Enigmatic Scale", 8, {0,1,4,6,8,10,11,12,} },
    { "Flamenco Mode", 8, {0,1,4,5,7,8,11,12,} },
    { "Gypsy Scale", 8, {0,2,3,6,7,8,10,12,} },
    { "Half Diminished Scale", 8, {0,2,3,5,6,8,10,12,} },
    { "Harmonic Major Scale", 8, {0,2,4,5,7,8,11,12,} },
    { "Harmonic Minor Scale", 8, {0,2,3,5,7,8,11,12,} },
    { "Hirajoshi Scale", 6, {0,4,6,7,11,12,} },
    { "Hungarian Gypsy Scale", 8, {0,2,3,6,7,8,11,12,} },
    { "Hungarian Minor Scale", 8, {0,2,3,6,7,8,11,12,} },
    { "In Scale", 6, {0,1,5,7,8,12,} },
    { "Insen Scale", 6, {0,1,5,7,10,12,} },
    { "Ionian Mode Or Major Scale", 8, {0,2,4,5,7,9,11,12,} },
    { "Istrian Scale", 7, {0,1,3,4,6,7,12,} },
    { "Iwato Scale", 6, {0,1,5,6,10,12,} },
    { "Locrian Mode", 8, {0,1,3,5,6,8,10,12,} },
    { "Lydian Augmented Scale", 8, {0,2,4,6,8,9,11,12,} },
    { "Lydian Mode", 8, {0,2,4,6,7,9,11,12,} },
    { "Major Locrian Scale", 8, {0,2,4,5,6,8,10,12,} },
    { "Major Pentatonic Scale", 6, {0,2,4,7,9,12,} },
    { "Melodic Minor Scale", 15, {0,2,3,5,7,9,11,12,10,8,7,5,3,2,0,} },
    { "Melodic Minor Scale Ascending", 8, {0,2,3,5,7,9,11,12,} },
    { "Minor Pentatonic Scale", 6, {0,3,5,7,10,12,} },
    { "Mixolydian Mode Or Adonai Malakh Mode", 8, {0,2,4,5,7,9,10,12,} },
    { "Neapolitan Major Scale", 8, {0,1,3,5,7,9,11,12,} },
    { "Neapolitan Minor Scale", 8, {0,1,3,5,7,8,11,12,} },
    { "Octatonic Scale", 9, {0,2,3,5,6,8,9,11,12,} },
    { "Persian Scale", 8, {0,1,4,5,6,8,11,12,} },
    { "Pfluke Scale", 8, {0,2,3,6,7,9,11,12,} },
    { "Phrygian Dominant Scale", 8, {0,1,4,5,7,8,10,12,} },
    { "Phrygian Mode", 8, {0,1,3,5,7,8,10,12,} },
    { "Prometheus Scale", 7, {0,2,4,6,9,10,12,} },
    { "Tritone Scale", 7, {0,1,4,6,7,10,12,} },
    { "Ukrainian Dorian Scale", 8, {0,2,3,6,7,9,10,12,} },
    { "Whole Tone Scale", 7, {0,2,4,6,8,10,12,} },
    { "Yo Scale", 6, {0,3,5,7,10,12,} },
};

unsigned char *scale_to_array(Scale);

#endif // SCALES_PHIL
