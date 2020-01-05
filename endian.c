#include <stdint.h>
#include <stdio.h>

// example from https://en.wikipedia.org/wiki/Endianness

void test_endian()
{
  uint32_t word = 0x0A0B0C0D;    // An unsigned 32-bit integer.
  char *pointer = (char *)&word; // A pointer to the first octet of the word.

  for (int i = 0; i < 4; i++)
  {
    printf("%02x ", (unsigned int)pointer[i]);
  }
  puts("\n");

  printf("Size of char: %d \n", sizeof(char));
}
