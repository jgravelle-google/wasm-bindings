// Shared header file for C wasm bindings

#ifndef _WASM_BINDINGS_SHARED_H_
#define _WASM_BINDINGS_SHARED_H_

__attribute__((wasm_bindings("WInteger", "i32-to-Integer", "Integer-to-i32")))
typedef int WInteger;
__attribute__((wasm_bindings("WByte", "i8-to-Integer", "Integer-to-i8")))
typedef char WByte;

// TODO: figure out how to handle generics for C more broadly
__attribute__((wasm_bindings("Sequence<WByte>", "pair-to-seq(WByte)", "seq-to-pair(WByte)")))
typedef struct Sequence_WByte_t {
  WByte* buffer;
  WInteger length;
} Sequence_WByte;

// helper function
Sequence_WByte make_sequence_WByte(WByte* buffer, WInteger length) {
  Sequence_WByte result;
  result.buffer = buffer;
  result.length = length;
  return result;
}

// WASM_BIND used to mark function declarations as bound
#define WASM_BIND(name) __attribute__((wasm_bindings_decl(name)))

#endif // _WASM_BINDINGS_SHARED_H_
