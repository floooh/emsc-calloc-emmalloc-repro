Run the build script as follows (assuming emcc is in the PATH, otherwise use the path to emcc):

```
CC=emcc ./build.sh
```

This should output something like:

```
error: undefined symbol: calloc (referenced by top-level compiled C/C++ code)
warning: Link with `-sLLD_REPORT_UNDEFINED` to get more information on undefined symbols
warning: To disable errors for undefined symbols use `-sERROR_ON_UNDEFINED_SYMBOLS=0`
warning: _calloc may need to be added to EXPORTED_FUNCTIONS if it arrives from a system library
Error: Aborting compilation due to previous errors
emcc: error: '/Users/floh/projects/fips-sdks/emsdk/node/14.18.2_64bit/bin/node /Users/floh/projects/fips-sdks/emsdk/upstream/emscripten/src/compiler.js /var/folders/dz/g9ydwg8973z9nn5bvffcwf3h0000gn/T/tmpw8xafb_u.json' failed (returned 1)
```

...now remove any of ```-flto```, ```-O1``` or  ```-sMALLOC=emmalloc``` from the build script and run again, this should work.

It also works if malloc is invoked directly instead of through a function pointer in ```alloc.c```:

```c
void* my_alloc(size_t size) {
    return malloc(size);
}
```

Also see: https://groups.google.com/g/emscripten-discuss/c/11fw5kJuq-4