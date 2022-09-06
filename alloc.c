#include <stdlib.h>
#include <string.h>
#include <stddef.h>

static void *(*mallocFunc)(size_t size) = malloc;
static void (*freeFunc)(void *ptr) = free;

void* my_alloc(size_t size) {
    return mallocFunc(size);
}

void* my_calloc(size_t size) {
    void* ptr = my_alloc(size);
    if (ptr) {
        memset(ptr, 0, size);
    }
    return ptr;
}

void my_free(void* ptr) {
    freeFunc(ptr);
}

void set_malloc(void *(*malloc)(size_t size)) {
    mallocFunc = malloc;
}

void set_free(void (*free)(void *ptr)) {
    freeFunc = free;
}
