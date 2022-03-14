#include <iostream>

#include "string_utils.hpp"

int main()
{
    char str1[] = "Abc";
    char str2[] = "bbc";

    std::cout << str_len(str1) << std::endl;
    std::cout << str_len(str2) << std::endl;

    std::cout << str_cmp(str1, str2) << std::endl;

    str_cp(str1, str2);

    std::cout << str_cmp(str1, str2) << std::endl;

    std::cout << str_cmp(nullptr, nullptr) << std::endl;
    std::cout << str_cmp(str1, nullptr) << std::endl;
    std::cout << str_cmp(nullptr, str2) << std::endl;

    return 0;
}