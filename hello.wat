(module "c"
  (memory 8)
  (global $hello_addr i32 (i32.const 16))
  (data (global.get $hello_addr) "Hello \00")
  (func $hello (export "hello") (result i32)
    (global.get $hello_addr)
  )
  (@wit-simple
    (types
      ($String utf8-cstr)
    )
    (funcs
      (export "hello" (result $String))
    )
  )
)

(module "haskell"
  (type $hsText (array i8))
  (func $world (export "world") (result $hsText)
    (local $result $hsText)
    (local.set $result (array.new_default $hsText (i32.const 5)))
    (array.set (local.get $result) (i32.const 0) (i8.const 'w'))
    (array.set (local.get $result) (i32.const 1) (i8.const 'o'))
    (array.set (local.get $result) (i32.const 2) (i8.const 'r'))
    (array.set (local.get $result) (i32.const 3) (i8.const 'l'))
    (array.set (local.get $result) (i32.const 4) (i8.const 'd'))
    (local.get $result)
  )
  (@wit-simple
    (types
      ($String utf8-i8-array)
    )
    (funcs
      (export "world" (result $String))
    )
  )
)

(module "rust"
  (memory 8)
  (import "c" "hello" (func $hello (result i32 i32)))
  (import "haskell" "world" (func $world (result i32 i32)))
  (import "js" "concat" (func $concat (param i32 i32 i32 i32) (result i32 i32)))
  (import "console" "log" (func $log (param i32 i32)))
  (global $allocPtr (mut i32) (i32.const 16))
  (func $main (export "main")
    call $hello
    call $world
    call $concat
    call $log
  )
  (func $alloc (param $size i32)
    ;; bump-allocator
    (global.get $allocPtr)
    (global.set $allocPtr (i32.add (global.get $allocPtr) (local.get $size))
  )
  (@wit-simple
    (types
      ($String utf8-ptr-len)
    )
    (funcs
      (import "c" "hello" (result $String))
      (import "haskell" "world" (result $String))
      (import "js" "concat" (param $String $String) (result $String))
      (import "console" "log" (param $String))
    )
  )
)
