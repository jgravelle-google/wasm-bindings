// Handwritten wrapper lib approach to bindings generation

__attribute__((wasmidl("z_stream"), struct(
  "Sequence<Integer> next_in",
  "Integer avail_in",
  "Sequence<Integer> next_out",
  "Integer avail_out"
)))
typedef wrap_z_stream z_stream;

__attribute__((wasmidl("z_streamp"), ref(z_stream)))
typedef wrap_z_streamp wrap_z_stream*;

__attribute__((wasmidl("alloc_z_stream"),
  bind_returns(i32-to-ref(z_streamp))
))
wrap_z_streamp alloc_z_stream() {
  return malloc(sizeof(z_stream));
}

__attribute__((wasmidl("deflateInit"),
  bind_returns(i32-to-Integer),
  bind_args(ref-to-i32(z_streamp), Integer-to-i32)
))
int wrap_deflateInit(wrap_z_streamp strm, int level) {
  return deflateInit(stream, level);
}

__attribute__((wasmidl("deflate"),
  bind_returns(i32-to-Integer),
  bind_args(ref-to-i32(z_streamp), Integer-to-i32)
))
int wrap_deflate(wrap_z_streamp strm, int flush) {
  return deflate(stream, flush);
}

__attribute__((wasmidl("deflateEnd"),
  bind_returns(i32-to-Integer),
  bind_args(ref-to-i32(z_streamp), Integer-to-i32)
))
int wrap_deflateEnd(wrap_z_streamp stream) {
  return deflateEnd(stream);
}

__attribute__((wasmidl("inflateInit"),
  bind_returns(i32-to-Integer),
  bind_args(ptr-to-ref(z_streamp))
))
int wrap_inflateInit(wrap_z_streamp strm) {
  return inflateInit(stream);
}

__attribute__((wasmidl("inflate"),
  bind_returns(i32-to-Integer),
  bind_args(ref-to-i32(z_streamp), Integer-to-i32)
))
int wrap_inflate(wrap_z_streamp strm, int flush) {
  return inflate(stream, flush);
}

__attribute__((wasmidl("inflateEnd"),
  bind_returns(i32-to-Integer),
  bind_args(ref-to-i32(z_streamp), Integer-to-i32)
))
int wrap_inflateEnd(wrap_z_streamp stream) {
  return inflateEnd(stream);
}

__attribute__((webidl("Z_NO_FLUSH"), const(Integer)))
const int wrap_Z_NO_FLUSH =      Z_NO_FLUSH;
__attribute__((webidl("Z_PARTIAL_FLUSH"), const(Integer)))
const int wrap_Z_PARTIAL_FLUSH = Z_PARTIAL_FLUSH;
__attribute__((webidl("Z_SYNC_FLUSH"), const(Integer)))
const int wrap_Z_SYNC_FLUSH =    Z_SYNC_FLUSH;
__attribute__((webidl("Z_FULL_FLUSH"), const(Integer)))
const int wrap_Z_FULL_FLUSH =    Z_FULL_FLUSH;
__attribute__((webidl("Z_FINISH"), const(Integer)))
const int wrap_Z_FINISH =        Z_FINISH;
__attribute__((webidl("Z_BLOCK"), const(Integer)))
const int wrap_Z_BLOCK =         Z_BLOCK;
__attribute__((webidl("Z_TREES"), const(Integer)))
const int wrap_Z_TREES =         Z_TREES;

__attribute__((webidl("Z_NO_COMPRESSION"), const(Integer)))
const int wrap_Z_NO_COMPRESSION =      Z_NO_COMPRESSION;
__attribute__((webidl("Z_BEST_SPEED"), const(Integer)))
const int wrap_Z_BEST_SPEED =          Z_BEST_SPEED;
__attribute__((webidl("Z_BEST_COMPRESSION"), const(Integer)))
const int wrap_Z_BEST_COMPRESSION =    Z_BEST_COMPRESSION;
__attribute__((webidl("Z_DEFAULT_COMPRESSION"), const(Integer)))
const int wrap_Z_DEFAULT_COMPRESSION = Z_DEFAULT_COMPRESSION;
