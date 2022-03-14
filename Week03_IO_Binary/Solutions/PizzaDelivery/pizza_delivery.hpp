#ifndef PIZZA_HPP_
#define PIZZA_HPP_

#define MAX_NAME_SIZE 128
#define MAX_ADDRESS_SIZE 256

typedef unsigned short u_short;

struct PizzaDelivery
{
    char name[MAX_NAME_SIZE];
    char address[MAX_ADDRESS_SIZE];
    double price;
    u_short count;
};

#endif // PIZZA_HPP_