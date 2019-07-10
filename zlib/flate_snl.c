// Wasm-specific C version of zlib program

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "zlib_generated.h"

static const int kMaxSize = 4 * 1024 * 1024;

char* my_compress(char* message) {
  char* buffer = calloc(kMaxSize, sizeof(char));
  z_streamp stream = alloc_z_stream();
  deflateInit(stream, Z_DEFAULT_COMPRESSION);
  set_next_in(stream, make_sequence_WByte(message, strlen(message)));
  set_avail_in(stream, strlen(message));
  set_next_out(stream, make_sequence_WByte(buffer, kMaxSize));
  set_avail_out(stream, kMaxSize);
  deflate(stream, Z_FINISH);
  deflateEnd(stream);
  free_z_stream(stream);
  return buffer;
}

char* my_uncompress(char* buffer) {
  char* message = calloc(kMaxSize, sizeof(char));
  z_streamp stream = alloc_z_stream();
  inflateInit(stream);
  set_next_in(stream, make_sequence_WByte(buffer, kMaxSize));
  set_avail_in(stream, strlen(buffer));
  set_next_out(stream, make_sequence_WByte(message, kMaxSize));
  set_avail_out(stream, kMaxSize);
  inflate(stream, Z_FINISH);
  inflateEnd(stream);
  free_z_stream(stream);
  return message;
}

int main(int argc, char** argv) {
  assert(argc == 2);

  char buffer[kMaxSize];
  unsigned int len = read(STDIN_FILENO, buffer, kMaxSize);
  buffer[len] = 0;

  char* str;
  if (strcmp(argv[1], "-c") == 0) {
    str = my_compress(buffer);
  } else {
    assert(strcmp(argv[1], "-u") == 0);
    str = my_uncompress(buffer);
  }
  puts(str);
  free(str);
  return 0;
}
