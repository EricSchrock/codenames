#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef union {
    uint8_t  u8;  // Basically equivalent to "unsigned char"
    int8_t   i8;  // Basically equivalent to "char"
    uint32_t u32; // Basically equivalent to "unsigned int"
    int32_t  i32; // Basically equivalent to "int"
    float    f32;
    void*    ptr;
} my_union_u;

int main(void) {
    my_union_u my_union;

    printf("\n");
    printf("The size of a union is the size of it's largest element\n");
    printf("\n");
    printf("my_union.u8:  %lu (bytes)\n", sizeof(my_union.u8));
    printf("my_union.i8:  %lu (bytes)\n", sizeof(my_union.i8));
    printf("my_union.u32: %lu (bytes)\n", sizeof(my_union.u32));
    printf("my_union.i32: %lu (bytes)\n", sizeof(my_union.i32));
    printf("my_union.f32: %lu (bytes)\n", sizeof(my_union.f32));
    printf("my_union.ptr: %lu (bytes)\n", sizeof(my_union.ptr));
    printf("\n");
    printf("my_union:     %lu (bytes)\n", sizeof(my_union));
    printf("\n");


    my_union.ptr = (void*)0xFEEDFACEBEEF0055; // Populate my_union with a hexadecimal value (easier to convert to binary than decimal values are)

    printf("Unions are rarely used in practice, but they are helpful for illustrating that memory is always just 1's and 0's.\n");
    printf("We just interpret those 1's and 0's differently, based on the type of the variable (unsigned int, signed int, floating point number, pointer, etc.).\n");

    printf("\n");
    printf("             | raw memory (hex) | interpreted as     |\n");
    printf("-------------+------------------+--------------------+\n");
    printf("my_union.u8  | %16hhx | %18u |\n", my_union.u8, my_union.u8);
    printf("my_union.i8  | %16hhx | %18d |\n", my_union.i8, my_union.i8);
    printf("my_union.u32 | %16x | %18u |\n", my_union.u32, my_union.u32);
    printf("my_union.i32 | %16x | %18d |\n", my_union.i32, my_union.i32);
    printf("my_union.f32 | %16x | %18f |\n", my_union.u32, my_union.f32); // Use my_union.u32 to print raw memory of my_union.f32, since they refer to the same memory
    printf("my_union.ptr | %16lx | %18p |\n", (uint64_t)my_union.ptr, my_union.ptr);
    printf("\n");

    return EXIT_SUCCESS;
}
