mkdir -p build
$CC main.c alloc.c -o build/bla.js -sMALLOC=emmalloc -O1 -flto 