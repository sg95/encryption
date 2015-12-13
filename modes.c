#include <stdlib.h>
#include <stdio.h>

#include "string.h"

/**
 * Runs the data through a 4-round feistel cipher
 * The key should be twice as long as the data chunk.
 */
void feistel(void *data, int size, int chunk_size, FILE *key) {
  // read key in
  // split data key into chunks
}

/**
 * Perform one round of a feistel cipher.
 * L_i = R_{i-1}
 * R_i = L_{i-1} xor F(K_{i-1}, R_{i-1})
 */
void feistel_round(void *data, void *key, int size) {
  // split into L and R
  //
}

/**
 * Placeholder for a better function. Right now, this function returns chunk
 * xor key.
 *
 * It's the responsibility of the caller to free this function's return.
 */
unsigned char * temp_function(unsigned char *chunk, unsigned char *key, int length) {
  if (length % 8 != 0) {
    fprintf(stderr, "Invalid input to feistel. Length not divisible by 8.");
    exit(1);
  }

  int i;
  unsigned char *buf
  unsigned char chunk_piece, key_piece;

  buf = (unsigned char *)malloc(length);

  for (i = 0; i < length / 8; i++) {
    chunk_piece = *(chunk + 8 * i);
    key_piece = *(key + 8 * i);
    memset(buf + 8 * i, chunk_piece ^ key_piece, 1);
  }

  return buf;
}

/* TODO */
int parity_divide_and_conquer (unsigned char *data, int length) {
  return 0;
}

int parity_naive(unsigned char *data, int length) {
  int i, j, number_of_ones = 0;
  unsigned char current_byte;

  for (i = 0; i < length; i++) {
    current_byte = *(data + i);
    for (j = 0; j < 8; j++) {
      number_of_ones = number_of_ones + ((current_byte >> j) & 0x1);
    }
  }

  return number_of_ones % 2;
}

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
