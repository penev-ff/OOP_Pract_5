#include <fstream>

#include <iostream>

#include "pizza_delivery.hpp"
#include "../StrUtils/string_utils.hpp"

using namespace std;

void saveDeliveryList(const PizzaDelivery *deliveryList,
                      const size_t ORDERS,
                      const char *fileName)
{
    if (!deliveryList || !fileName)
        return;

    ofstream file(fileName, ios_base::binary | ios_base::trunc);

    if (!file.is_open())
        return;

    file.write((const char *)deliveryList, ORDERS * sizeof(PizzaDelivery));

    file.close();
}

void loadDeliveryList(PizzaDelivery *deliveryList,
                      const size_t ORDERS,
                      const char *fileName)
{
    if (!deliveryList || !fileName)
        return;

    ifstream file(fileName, ios_base::binary);

    if (!file.is_open())
        return;

    file.read((char *)deliveryList, ORDERS * sizeof(PizzaDelivery));

    file.close();
}

void sortByAddress(PizzaDelivery *deliveryList, const size_t ORDERS)
{
    if (!deliveryList)
        return;

    for (int i = 0; i < ORDERS; i++)
    {
        int min_i = i;

        for (int j = i + 1; j < ORDERS; j++)
        {
            if (str_cmp(deliveryList[min_i].address, deliveryList[j].address) < 0)
            {
                std::cout << "true" << std::endl;
                min_i = j;
            }
        }

        // if (min_i != i) {
        swap(deliveryList[min_i], deliveryList[i]);
        // }
    }
}

int main()
{
    const size_t ORDERS = 2;

    PizzaDelivery deliveryList[] =
        {
            {"Umbria", "Malinova 12", 12.60, 2},
            {"Tuscany", "Studentski Grad 123", 8.40, 1}};

    saveDeliveryList(deliveryList, ORDERS, "delivery.bin");

    loadDeliveryList(deliveryList, ORDERS, "delivery.bin");
    sortByAddress(deliveryList, ORDERS);
    saveDeliveryList(deliveryList, ORDERS, "delivery-sorted.bin");
    
    return 0;
}