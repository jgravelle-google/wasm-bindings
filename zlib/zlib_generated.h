// Generated C header from zlib.widl, for user code

#include "wasm_bindings_shared.h"

struct _z_streamp_obj;
typedef struct _z_streamp_obj* z_streamp;

z_streamp alloc_z_stream(void);
void free_z_stream(z_streamp);

Sequence get_next_in(z_streamp);
Integer get_avail_in(z_streamp);
Sequence get_next_out(z_streamp);
Integer get_avail_out(z_streamp);
void set_next_in(z_streamp, Sequence);
void set_avail_in(z_streamp, Integer);
void set_next_out(z_streamp, Sequence);
void set_avail_out(z_streamp, Integer);

Integer deflateInit(z_streamp, Integer);
Integer deflate(z_streamp, Integer);
Integer deflateEnd(z_streamp);

Integer inflateInit(z_streamp);
Integer inflate(z_streamp, Integer);
Integer inflateEnd(z_streamp);

const Integer Z_NO_FLUSH =      0;
const Integer Z_PARTIAL_FLUSH = 1;
const Integer Z_SYNC_FLUSH =    2;
const Integer Z_FULL_FLUSH =    3;
const Integer Z_FINISH =        4;
const Integer Z_BLOCK =         5;
const Integer Z_TREES =         6;

const Integer Z_NO_COMPRESSION =       0;
const Integer Z_BEST_SPEED =           1;
const Integer Z_BEST_COMPRESSION =     9;
const Integer Z_DEFAULT_COMPRESSION = -1;
