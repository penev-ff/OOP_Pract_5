#include <iostream>

using namespace std;

struct MyStruct
{
    int a;
    int b;
};

union MyUnion
{
    int a;
    int b;
};

union CharUnion
{
    int code;
    char symbol;
} charUnion;

int main()
{
    MyStruct s;
    // Different addresses
    std::cout << &s.a << std::endl;
    std::cout << &s.b << std::endl;

    MyUnion u;
    // Shared address
    std::cout << &u.a << std::endl;
    std::cout << &u.b << std::endl;

    // The biggest of all data types in the union
    cout << sizeof(charUnion) << endl;

    charUnion.code = 97;
    cout << charUnion.code << endl;   // 97
    cout << charUnion.symbol << endl; // 'a' which is with ascii code 97

    charUnion.code = 1000;
    cout << charUnion.code << endl;   // 1000
    cout << charUnion.symbol << endl; // ?????

    return 0;
}