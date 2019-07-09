// Shared header file for C wasm bindings

#ifndef _WASM_BINDINGS_SHARED_H_
#define _WASM_BINDINGS_SHARED_H_

typedef struct Sequence_t {
  char* buffer;
  size_t length;
} Sequence;
Sequence make_sequence(char* buffer, size_t length) {
  Sequence result;
  result.buffer = buffer;
  result.length = length;
  return result;
}

typedef int Integer;

#endif // _WASM_BINDINGS_SHARED_H_
