// Native C version of zlib program, to test usage

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <zlib.h>

static const int kMaxSize = 4 * 1024 * 1024;

char* my_compress(char* message) {
  char* buffer = calloc(kMaxSize, sizeof(char));
  z_stream stream;
  deflateInit(&stream, Z_DEFAULT_COMPRESSION);
  stream.next_in = (unsigned char*)message;
  stream.avail_in = strlen(message);
  stream.next_out = (unsigned char*)buffer;
  stream.avail_out = kMaxSize;
  deflate(&stream, Z_FINISH);
  deflateEnd(&stream);
  return buffer;
}

char* my_uncompress(char* buffer) {
  char* message = calloc(kMaxSize, sizeof(char));
  z_stream stream;
  inflateInit(&stream);
  stream.next_in = (unsigned char*)buffer;
  stream.avail_in = strlen(buffer);
  stream.next_out = (unsigned char*)message;
  stream.avail_out = kMaxSize;
  inflate(&stream, Z_FINISH);
  inflateEnd(&stream);
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
