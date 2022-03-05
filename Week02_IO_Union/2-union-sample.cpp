#include <iostream>
#include <cstring>

const size_t MAX_NAME_SIZE = 256;

// Variant or tagged union
struct Product
{
    char name[MAX_NAME_SIZE];
    bool isPromotional;

    union
    {
        double price;
        int points;
    };
};

void printCost(const Product &product)
{
    std::cout << product.name << std::endl;

    if (product.isPromotional)
    {
        std::cout << "points: " << product.points << std::endl;
    }
    else
    {
        std::cout << "price: " << product.price << std::endl;

        // Garbage value
        // std::cout << "points: " << product.points << std::endl;
    }
}

int main()
{
    Product pan;

    strcpy(pan.name, "Tefal");
    pan.isPromotional = true;
    pan.points = 100;

    Product filter;

    strcpy(filter.name, "Brita");
    filter.isPromotional = false;
    filter.price = 50.65;

    printCost(pan);
    printCost(filter);

    return 0;
}