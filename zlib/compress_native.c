#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <zlib.h>

static const int kMaxSize = 4 * 1024 * 1024;

char* my_compress(char* message) {
  char* buffer = malloc(sizeof(char) * kMaxSize);
  z_stream stream;
  deflateInit(&stream, Z_DEFAULT_COMPRESSION);
  stream.next_in = (unsigned char*)message;
  stream.avail_in = strlen(message);
  stream.avail_out = kMaxSize;
  stream.next_out = (unsigned char*)buffer;
  deflate(&stream, Z_FINISH);
  deflateEnd(&stream);
  return buffer;
}

// char* my_uncompress(char* buffer) {
// }

int main(int argc, char** argv) {
  assert(argc == 2);
  assert(strcmp(argv[1], "-c") == 0);

  char buffer[kMaxSize];
  unsigned int len = read(STDIN_FILENO, buffer, kMaxSize);
  buffer[len] = 0;

  char* str = my_compress(buffer);
  puts(str);
  free(str);
  return 0;
}
