#ifndef SCALES_PHIL
#define SCALES_PHIL

#define MAX_SCALE_SIZE 15

typedef struct
{
  char *name;
  unsigned int notes[MAX_SCALE_SIZE];
} Scale;

Scale scales[] = {
    { "Acoustic scale", {0,2,4,6,7,9,10,12,} },
    { "Aeolian mode or natural minor scale", {0,2,3,5,7,8,10,12,} },
    { "Altered scale", {0,1,3,4,6,8,10,12,} },
    { "Augmented scale", {0,3,4,7,8,11,12,} },
    { "Bebop dominant scale", {0,2,4,5,7,9,10,11,12,} },
    { "Blues scale", {0,3,5,6,7,10,12,} },
    { "Chromatic scale", {0,1,2,3,4,5,6,7,8,9,10,11,12,} },
    { "Dorian mode", {0,2,3,5,7,9,10,12,} },
    { "Double harmonic scale", {0,1,4,5,7,8,11,12,} },
    { "Enigmatic scale", {0,1,4,6,8,10,11,12,} },
    { "Flamenco mode", {0,1,4,5,7,8,11,12,} },
    { "Gypsy scale", {0,2,3,6,7,8,10,12,} },
    { "Half diminished scale", {0,2,3,5,6,8,10,12,} },
    { "Harmonic major scale", {0,2,4,5,7,8,11,12,} },
    { "Harmonic minor scale", {0,2,3,5,7,8,11,12,} },
    { "Hirajoshi scale", {0,4,6,7,11,12,} },
    { "Hungarian Gypsy scale", {0,2,3,6,7,8,11,12,} },
    { "Hungarian minor scale", {0,2,3,6,7,8,11,12,} },
    { "In scale", {0,1,5,7,8,12,} },
    { "Insen scale", {0,1,5,7,10,12,} },
    { "Ionian mode or major scale", {0,2,4,5,7,9,11,12,} },
    { "Istrian scale", {0,1,3,4,6,7,12,} },
    { "Iwato scale", {0,1,5,6,10,12,} },
    { "Locrian mode", {0,1,3,5,6,8,10,12,} },
    { "Lydian augmented scale", {0,2,4,6,8,9,11,12,} },
    { "Lydian mode", {0,2,4,6,7,9,11,12,} },
    { "Major Locrian scale", {0,2,4,5,6,8,10,12,} },
    { "Major pentatonic scale", {0,2,4,7,9,12,} },
    { "Melodic minor scale", {0,2,3,5,7,9,11,12,10,8,7,5,3,2,0,} },
    { "Melodic minor scale ascending", {0,2,3,5,7,9,11,12,} },
    { "Minor pentatonic scale", {0,3,5,7,10,12,} },
    { "Mixolydian mode or Adonai malakh mode", {0,2,4,5,7,9,10,12,} },
    { "Neapolitan major scale", {0,1,3,5,7,9,11,12,} },
    { "Neapolitan minor scale", {0,1,3,5,7,8,11,12,} },
    { "Octatonic scale", {0,2,3,5,6,8,9,11,12,} },
    { "Persian scale", {0,1,4,5,6,8,11,12,} },
    { "Pfluke scale", {0,2,3,6,7,9,11,12,} },
    { "Phrygian dominant scale", {0,1,4,5,7,8,10,12,} },
    { "Phrygian mode", {0,1,3,5,7,8,10,12,} },
    { "Prometheus scale", {0,2,4,6,9,10,12,} },
    { "Tritone scale", {0,1,4,6,7,10,12,} },
    { "Ukrainian Dorian scale", {0,2,3,6,7,9,10,12,} },
    { "Whole tone scale", {0,2,4,6,8,10,12,} },
    { "Yo scale", {0,3,5,7,10,12,} },
};

#endif // SCALES_PHIL
