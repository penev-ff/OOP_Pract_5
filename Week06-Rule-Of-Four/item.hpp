#ifndef ITEM_HPP_GUARD_
#define ITEM_HPP_GUARD_

class Item
{
private:
    char *name;
    unsigned int amount;
    double price;

public:
    Item();

    Item(const char *, unsigned int, double);

    Item(const Item &);

    Item &operator=(const Item &);

    const char *getName() const;
    unsigned int getAmount() const;
    double getPrice() const;

    void setName(const char *);
    void setAmount(unsigned int);
    void setPrice(double);

    ~Item();

//
// Helpers
private:
    void free();
    void copyFrom(const Item &);

    void copyName(const char *);
};

#endif // ITEM_HPP_GUARD_