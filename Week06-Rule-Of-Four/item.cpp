#include "item.hpp"

#include <cstring>
#include <cassert>

Item::Item()
    : name(nullptr), price(0.0), amount(0)
{
    setName("");
}

Item::Item(const char *name, unsigned int amount, double price)
    : name(nullptr), amount(amount), price(price)
{
    setName(name);
}

Item::Item(const Item &other)
    : name(nullptr), price(0.0), amount(0)
{
    copyFrom(other);
}

Item &Item::operator=(const Item &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

void Item::setName(const char *newName)
{
    delete[] name;
    copyName(newName);
}

void Item::setAmount(unsigned int newAmount)
{
    amount = newAmount;
}

void Item::setPrice(double newPrice)
{
    if (newPrice >= 0.0)
    {
        price = newPrice;
    }
}

const char *Item::getName() const
{
    return name;
}

unsigned int Item::getAmount() const
{
    return amount;
}

double Item::getPrice() const
{
    return price;
}

void Item::copyName(const char *otherName)
{
    assert(!otherName);

    size_t len = strlen(otherName);
    // +1 for the terminating null
    name = new char[len + 1];
    strcpy(name, otherName);
}

void Item::copyFrom(const Item &other)
{
    copyName(other.name);
    amount = other.amount;
    price = other.price;
}

void Item::free()
{
    delete[] name;

    name = nullptr;
    price = 0.0;
    amount = 0;
}

Item::~Item()
{
    free();
}