#include <stdio.h>
#include <stdlib.h>

#include "string.h"

void byte_to_bits(FILE *fp, unsigned char c) {
  int i;
  for(int i = 0; i < 8; i++) {
    fprintf(fp, "%d", (c >> i) & 0x1);
  }
  fprintf(fp, " ");
}

void fprint_bits(FILE *fp, unsigned char *ptr, int num_bytes) {
  int i;
  for(i = 0; i < num_bytes; i++) {
    byte_to_bits(fp, *(ptr + i));
    if((i + 1) % 8 == 0)
      fprintf(fp, "\n");
  }
}

int main (int argc, char **argv)
{
  int key_len, i;
  char c, *output_path, *buf;
  char *err_msg = NULL;
  FILE *f, *output_file;

  if (argc != 3) {
    err_msg = "Usage: ./genkey <key_length> <output_file>";
    goto fin;
  }

  key_len = atoi(argv[1]);
  output_path = argv[2];

  if (key_len == 0 || key_len % 8 != 0) {
    err_msg = "Invalid input for <key_length>.";
    goto fin;
  }

  if (strcmp(output_path + strlen(output_path) - 4, ".key") != 0) {
    err_msg = "Invalid output filepath. Missing a '.key' suffix";
    goto fin;
  }

  f = fopen("/dev/urandom", "r");
  output_file = fopen(output_path, "wb");
  if (output_file == NULL) {
    err_msg = "Unable to create <output_file>";
    goto fin;
  }
  buf = (char *)malloc(sizeof(char) * key_len);
  if (f == NULL || fread(buf, 1, key_len, f) == 0) {
    err_msg = "Error while reading from /dev/urandom";
    goto fin;
  }

  fin:
  if (err_msg != NULL) {
    fprintf(stdout, "Error: %s\n", err_msg);
    return 1;
  } else {

    fprintf(output_file, "----BEGIN KEY----\n");
    fwrite(buf, 1, key_len, output_file);
    fprintf(output_file, "\n----END KEY----");
    fclose(f);
    fclose(output_file);
    free(buf);
  }
  return 0;
}
