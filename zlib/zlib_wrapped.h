// Handwritten wrapper lib approach to bindings generation

#define Z_SOLO
#include "zlib.h"

#include "wasm_bindings_shared.h"

// Declare malloc+free
void *malloc(z_size_t size);
void free(void *ptr);

// Only expose a reference, not struct details
__attribute__((wasm_bindings("z_streamp", "i32-to-ref", "ref-to-i32")))
typedef z_streamp wrap_z_streamp;

// Alloc + Dealloc
WASM_BIND("alloc_z_stream")
wrap_z_streamp alloc_z_stream() {
  return malloc(sizeof(z_stream));
}
WASM_BIND("free_z_stream")
void free_z_stream(wrap_z_streamp stream) {
  free(stream);
}

// Getters and Setters
WASM_BIND("get_next_in")
Sequence_WByte get_next_in(wrap_z_streamp stream) {
  return make_sequence_WByte(stream->next_in, stream->avail_in);
}
WASM_BIND("get_avail_in")
WInteger get_avail_in(wrap_z_streamp stream) {
  return stream->avail_in;
}
WASM_BIND("get_next_out")
Sequence_WByte get_next_out(wrap_z_streamp stream) {
  return make_sequence_WByte(stream->next_out, stream->avail_out);
}
WASM_BIND("get_avail_out")
WInteger get_avail_out(wrap_z_streamp stream) {
  return stream->avail_out;
}

WASM_BIND("set_next_in")
void set_next_in(wrap_z_streamp stream, Sequence_WByte seq) {
  stream->next_in = seq.buffer;
}
WASM_BIND("set_avail_in")
void set_avail_in(wrap_z_streamp stream, WInteger avail) {
  stream->avail_in = avail;
}
WASM_BIND("set_next_out")
void set_next_out(wrap_z_streamp stream, Sequence_WByte seq) {
  stream->next_out = seq.buffer;
}
WASM_BIND("set_avail_out")
void set_avail_out(wrap_z_streamp stream, WInteger avail) {
  stream->avail_out = avail;
}

// Deflate + Inflate
WASM_BIND("deflateInit")
int wrap_deflateInit(wrap_z_streamp stream, int level) {
  return deflateInit(stream, level);
}

WASM_BIND("deflate")
int wrap_deflate(wrap_z_streamp stream, int flush) {
  return deflate(stream, flush);
}

WASM_BIND("deflateEnd")
int wrap_deflateEnd(wrap_z_streamp stream) {
  return deflateEnd(stream);
}

WASM_BIND("inflateInit")
int wrap_inflateInit(wrap_z_streamp stream) {
  return inflateInit(stream);
}

WASM_BIND("inflate")
int wrap_inflate(wrap_z_streamp stream, int flush) {
  return inflate(stream, flush);
}

WASM_BIND("inflateEnd")
int wrap_inflateEnd(wrap_z_streamp stream) {
  return inflateEnd(stream);
}

// Consts
WASM_BIND("Z_NO_FLUSH")
const WInteger wrap_Z_NO_FLUSH =      Z_NO_FLUSH;
WASM_BIND("Z_PARTIAL_FLUSH")
const WInteger wrap_Z_PARTIAL_FLUSH = Z_PARTIAL_FLUSH;
WASM_BIND("Z_SYNC_FLUSH")
const WInteger wrap_Z_SYNC_FLUSH =    Z_SYNC_FLUSH;
WASM_BIND("Z_FULL_FLUSH")
const WInteger wrap_Z_FULL_FLUSH =    Z_FULL_FLUSH;
WASM_BIND("Z_FINISH")
const WInteger wrap_Z_FINISH =        Z_FINISH;
WASM_BIND("Z_BLOCK")
const WInteger wrap_Z_BLOCK =         Z_BLOCK;
WASM_BIND("Z_TREES")
const WInteger wrap_Z_TREES =         Z_TREES;

WASM_BIND("Z_NO_COMPRESSION")
const WInteger wrap_Z_NO_COMPRESSION =      Z_NO_COMPRESSION;
WASM_BIND("Z_BEST_SPEED")
const WInteger wrap_Z_BEST_SPEED =          Z_BEST_SPEED;
WASM_BIND("Z_BEST_COMPRESSION")
const WInteger wrap_Z_BEST_COMPRESSION =    Z_BEST_COMPRESSION;
WASM_BIND("Z_DEFAULT_COMPRESSION")
const WInteger wrap_Z_DEFAULT_COMPRESSION = Z_DEFAULT_COMPRESSION;
