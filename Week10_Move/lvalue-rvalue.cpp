#include <iostream>

int foo(int val)
{
    return 100;
}

// lvalue reference
int &bar(int &val)
{
    // return 100; Error
    return val;
}

const int &baz(const int &val)
{
    return val;
}

// rvalue reference
void rref(int &&val)
{
    std::cout << val << std::endl;
}

// Intro to Value Categories
int main()
{
    // An lvalue has an address that your program can access.
    // An rvalue has not an address and it is temporary.

    // x is lvalue;
    // The numeric literal 50 is rvalue (has no specific address)
    int x = 50;

    // rvalue is not always on the right hand side:
    int y = x; // Both x and y are lvalue.

    foo(50); // OK
    foo(y);  // OK

    // bar(50); // Error: initial value of reference to non-const must be an lvalue
    bar(y); // OK

    baz(50); // OK
    baz(y);  // OK

    // foo(x) = 10;  // Error
    bar(x) = 999; // OK => x will become 999
    // baz(x) = 999; // Error: cannot assign to return value because function 'baz' returns a const value

    // Note
    // The following:
    const int &ref = 50;
    // Would translate to:
    int __internal_unique_name = 10;
    const int &__ref = __internal_unique_name;
    // That's why baz(50) is fine.

    // rvalue reference (&&).
    // && will let us modify the value of a temp object.

    rref(50);
    // rref(x); // Error: an rvalue reference cannot be bound to an lvalue

    return 0;
}