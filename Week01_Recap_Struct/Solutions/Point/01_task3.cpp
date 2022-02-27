#include "point.hpp"

#include <iostream>

int main()
{
    Point A, B;

    read(A);
    read(B);

    print(A);
    print(B);

    std::cout << distanceFromTo(A, B) << std::endl;

    return 0;
}