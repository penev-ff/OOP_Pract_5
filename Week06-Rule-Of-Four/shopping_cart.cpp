#include "shopping_cart.hpp"

#include <cassert>
#include <cstring>
#include <fstream>

ShoppingCart::ShoppingCart()
    : capacity(INIT_CAPACITY), count(0)
{
    items = new Item[INIT_CAPACITY];
}

ShoppingCart::ShoppingCart(const ShoppingCart &other)
{
    copyFrom(other);
}

int ShoppingCart::find(const char *name) const
{
    if (name && items)
    {
        for (size_t i = 0; i < count; i++)
        {
            if (strcmp(items[i].getName(), name) == 0)
            {
                return i;
            }
        }
    }

    return -1;
}

bool ShoppingCart::addItem(const Item &item)
{
    if (find(item.getName()) != -1)
    {
        // Already added
        return false;
    }

    if (count >= capacity)
    {
        resize();
    }

    // Is the copy constructor or assignment operator called?
    items[count] = item;
    ++count;

    return true;
}

double ShoppingCart::getPriceOf(const char *itemName) const
{
    int index = find(itemName);

    if (index == -1)
    {
        // Not found
        return 0.0;
    }

    return items[index].getPrice();
}

double ShoppingCart::totalPrice() const
{
    double total = 0.0;

    for (size_t i = 0; i < count; i++)
    {
        total += items[i].getPrice() * items[i].getAmount();
    }

    return total;
}

bool ShoppingCart::save(const char *fileName) const
{
    if (!fileName)
    {
        return false;
    }

    std::ofstream file(fileName, std::ios::trunc);

    if (!file.is_open())
    {
        return false;
    }

    file << "name,amount,price" << std::endl;

    for (size_t i = 0; i < count; i++)
    {
        file << items[i].getName() << ','
             << items[i].getAmount() << ','
             << items[i].getPrice() << std::endl;

        if (file.bad())
        {
            file.close();
            return false;
        }
    }

    file.close();

    return file.good();
}

bool ShoppingCart::removeItem(const char *itemName)
{
    int index = find(itemName);
    if (index == -1)
    {
        // No such item or invalid item name
        return false;
    }

    for (size_t i = index; i < count - 1; i++)
    {
        items[i] = items[i + 1];
    }

    --count;
    return true;
}

bool ShoppingCart::exists(const char *itemName) const
{
    return find(itemName) != -1;
}

bool ShoppingCart::isEmpty() const
{
    return count == 0;
}

void ShoppingCart::resize()
{
    // Invariant in our case, but still good to check.
    // If RESIZE_FACTOR == 0, newCapacity = 0 * capacity => newCapacity = 0.
    assert(RESIZE_FACTOR);

    size_t newCapacity = RESIZE_FACTOR * capacity;

    Item *newContainer = new Item[newCapacity];

    for (size_t i = 0; i < count; i++)
    {
        newContainer[i] = items[i];
    }

    delete[] items;
    items = newContainer;

    capacity = newCapacity;
}

ShoppingCart &ShoppingCart::operator=(const ShoppingCart &other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }

    return *this;
}

size_t ShoppingCart::itemsCount() const
{
    return count;
}

ShoppingCart::~ShoppingCart()
{
    free();
}

void ShoppingCart::copyFrom(const ShoppingCart &other)
{
    capacity = other.capacity;
    count = other.count;

    items = new Item[capacity];
    for (size_t i = 0; i < count; i++)
    {
        items[i] = other.items[i];
    }
}

void ShoppingCart::free()
{
    delete[] items;

    items = nullptr;
    capacity = 0;
    count = 0;
}
