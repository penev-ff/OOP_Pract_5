#include <iostream>

const double MEMBERSHIP_FEE = 35;

const double GOLDEN_DISCOUNT = 0.05;

class GymCard
{
private:
    double fee;

public:
    GymCard() : fee(MEMBERSHIP_FEE)
    {
    }

    virtual double getMembershipFee() const
    {
        return this->fee;
    }

    virtual ~GymCard() = default; // Important rule of thumb: polymorphic behaviour => virtual destructor
};

class GoldenGymCard : public GymCard
{
private:
    double discount;

public:
    GoldenGymCard()
        : GymCard(), discount(GOLDEN_DISCOUNT)
    {
    }

    // Overriding only with virtual base
    // the virtual keyword here is optional - it's virtual by default
    double getMembershipFee() const override // override - extremely useful syntax to prevent errors and improve code readability
    {
        // Bottomless recursion - crash
        // return getMembershipFee() - getMembershipFee() * GOLDEN_DISCOUNT;

        // If fee is protected
        // return this->fee - this->fee * GOLDEN_DISCOUNT;

        return GymCard::getMembershipFee() - GymCard::getMembershipFee() * GOLDEN_DISCOUNT;
    }
};

int main()
{
    // Binding

    // Static Binding
    GymCard card;
    GoldenGymCard goldenCard;

    std::cout << card.getMembershipFee() << std::endl;       // 35
    std::cout << goldenCard.getMembershipFee() << std::endl; // 33.50

    // Static vs Dynamic binding - with and without virtual

    GymCard *cardPtr = &goldenCard;                        // We can do this because GoldenGymCard derives from GymCard
    std::cout << cardPtr->getMembershipFee() << std::endl; // 35 - no discount :( - not a polymorphic code

    // Virtual and object destruction
    GymCard **cards = new GymCard *[2];

    cards[0] = new GymCard();
    cards[1] = new GoldenGymCard();

    std::cout << cards[0]->getMembershipFee() << std::endl; // OK
    std::cout << cards[1]->getMembershipFee() << std::endl; // OK

    // If the destructor is not virtual - Memory leak occurs even if we call the delete operator.
    delete cards[0];
    delete cards[1];

    delete[] cards;

    return 0;
}