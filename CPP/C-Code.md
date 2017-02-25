# Excellent C Code
###
```c
// static_assert(x) will generate a compile-time error if 'x' is false;
#define static_assert(x) switch(x) case 0: case (x):
```

# Note
+ With gcc compiler, it's not a big difference. asm or __asm or __asm__ are same, they just use to avoid conflict namespace purpose (there's user defined function that name asm, etc.)