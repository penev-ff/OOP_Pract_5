#include <iostream>
#include <cstring>
#include <cassert>

#include "item.hpp"

bool runAsserts();

int main()
{

    if(runAsserts())
        std::cout << "OK!" << std::endl;

    return 0;
}

bool runAsserts()
{
    Item defaultItem;

    assert(strcmp("", defaultItem.getName()) == 0);
    assert(defaultItem.getAmount() == 0);
    assert(defaultItem.getPrice() == 0.0);

    defaultItem.setName("Pen");
    defaultItem.setAmount(1);
    defaultItem.setPrice(1.60);

    assert(strcmp("Pen", defaultItem.getName()) == 0);
    assert(defaultItem.getAmount() == 1);
    assert(defaultItem.getPrice() == 1.60);

    Item paramItem("Paper", 500, 9.80);

    assert(strcmp("Paper", paramItem.getName()) == 0);
    assert(paramItem.getAmount() == 500);
    assert(paramItem.getPrice() == 9.80);

    // Calls the copy constructor
    Item copyAssign(paramItem);

    assert(strcmp(copyAssign.getName(), paramItem.getName()) == 0);
    assert(copyAssign.getAmount() == paramItem.getAmount());
    assert(copyAssign.getPrice() == paramItem.getPrice());

    // Calls the assignment operator
    copyAssign = paramItem;

    assert(strcmp(copyAssign.getName(), paramItem.getName()) == 0);
    assert(copyAssign.getAmount() == paramItem.getAmount());
    assert(copyAssign.getPrice() == paramItem.getPrice());

    return true;
}