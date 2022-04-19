#include <iostream>
#include <cstring>
#include <cassert>

#include "shopping_cart.hpp"

#define EPSILON_DELTA 0.000000001

bool runAsserts();

int main()
{
    if (runAsserts())
        std::cout << "OK!" << std::endl;

    return 0;
}

bool runAsserts()
{
    ShoppingCart cart;

    assert(cart.isEmpty());

    cart.addItem(Item("Pen", 1, 1.60));

    assert(cart.exists("Pen"));
    assert(cart.itemsCount() == 1);

    cart.addItem(Item("Pen", 1, 1.60));
    cart.addItem(Item("Marker", 1, 2.20));

    assert(cart.save("cart.csv"));

    assert(cart.exists("Marker"));
    assert(cart.itemsCount() == 2);
    assert(cart.getPriceOf("Marker") - 2.20 < EPSILON_DELTA);

    // Double comparison problems
    assert(cart.totalPrice() - 3.8 < EPSILON_DELTA);

    cart.removeItem("Pen");

    assert(cart.exists("Marker"));
    assert(!cart.exists("Pen"));
    assert(cart.itemsCount() == 1);

    cart.removeItem("Marker");
    assert(cart.isEmpty());

    return true;
}