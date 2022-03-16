#include <iostream>

struct Exact
{
    int x;
    int y;
};

struct Padding
{
    int a;
    char ch;
    int b;
} demo;

struct Arrange1
{
    int x;
    char a;
    int y;
    char b;
};

struct Arrange2
{
    int x, y;
    char a, b;
};

int main()
{
    // We assume that the model we are working with is 32-bit.

    // Recap

    // signed char
    // 1B ~ 8b
    // [-2^7,  2^7 - 1] => [-128, 127] range
    // ones' complement:
    // https://en.wikipedia.org/wiki/Ones%27_complement#Ones.27_complement
    char c;

    // Again 1B, [0, 255] range (Extended ASCII allowed)
    unsigned char u_c;

    // 2B
    // The signed modifier is the default if omitted
    // You should omit it for better legibility.
    signed short s;

    // 4B
    int i;

    // IEEE 754 - FP Arithmetic Standard
    // https://en.wikipedia.org/wiki/IEEE_754

    // 4B - less precision than double
    float f;
    // 8B - greater precision, but still not recommended for strict calculations
    double d;

    // Do not use floating point arithmetics for strict calculations
    // https://itsfoss.com/a-floating-point-error-that-caused-a-damage-worth-half-a-billion/

    std::cout << sizeof(double) << std::endl;

    // Memory allocation

    // Stack-based memory allocation.
    // Reclaimed when the function exits - automatically.
    // Activation Frames
    // You can think of the activation frame as the block
    // of memory that holds the current state of a particular
    // invocation of a function (parameters, variables, etc).
    int x = 10;

    // Dynamic memory allocation (Heap-based)
    // The pointer is living on the stack, but pointing
    // to data living on the heap.
    int *xp = new int(10);
    delete xp;

    // Alignment & Padding
    // The alignment requirement:
    // The valid alignment values are non-negative integral powers of two.

    // !!! Правило за подравняване. Искаме да е изпълнено:
    // Address % Size == 0

    // Пример.
    // sizeof(int) = 4 => ще се разположи на адрес 0 или 4, или 8, ...

    // In order to satisfy alignment requirements of all members of a struct,
    // padding may be inserted after some of its members.
    // https://en.cppreference.com/w/c/language/object

    std::cout << sizeof(Exact) << std::endl; // 8B
    std::cout << sizeof(demo) << std::endl;  // 12B

    //   0  1  2  3  4  5  6  7  8  9  10 11
    //  [ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ][ ]
    //   a  a  a  a  a  c  ^
    //                     не можем тук да сложим int b, защото 6 % 4 != 0

    //   0  1  2  3  4  5  6  7  8  9  10 11
    //  [ ][ ][ ][ ][ ][x][x][x][ ][ ][ ][ ]
    //   a  a  a  a  c  p  p  p  b  b  b  b
    //   a,b(int), p(padding), c(char)

    // The size depends on the order of the variables in the struct.
    // Try to reorder them.
    std::cout << sizeof(Arrange1) << std::endl;
    std::cout << sizeof(Arrange2) << std::endl; 

    return 0;
}