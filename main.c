#include <stddef.h>

extern void* my_alloc(size_t size);
extern void* my_calloc(size_t size);
extern void my_free(void* ptr);

int main() {
    void* p = my_calloc(123);
    __builtin_printf("p: %p\n", p);
    my_free(p);
    return 0;
}