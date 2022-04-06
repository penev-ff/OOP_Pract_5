#ifndef SHOPPING_CART_HPP_GUARD_
#define SHOPPING_CART_HPP_GUARD_

#include <cstddef> // size_t

#include "item.hpp"

const size_t RESIZE_FACTOR = 2;
const size_t INIT_CAPACITY = 16;

class ShoppingCart
{
private:
    size_t capacity;
    size_t count;
    Item *items;

public:
    ShoppingCart();

    ShoppingCart(const ShoppingCart &);

    ShoppingCart &operator=(const ShoppingCart &);

    bool addItem(const Item &item);

    bool removeItem(const char *itemName);

    size_t itemsCount() const;

    bool isEmpty() const;

    bool exists(const char *itemName) const;

    double getPriceOf(const char *itemName) const;

    double totalPrice() const;

    bool save(const char* fileName) const;

    ~ShoppingCart();

    // Helpers
private:
    void free();
    void copyFrom(const ShoppingCart &);

    void resize();

    int find(const char *name) const;
};

#endif // SHOPPING_CART_HPP_GUARD_