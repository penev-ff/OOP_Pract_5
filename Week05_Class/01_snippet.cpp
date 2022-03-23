#include <iostream>
#include <cmath> // M_PI

// -----------------------------------------

/*
 * The differences between a class and a struct in C++ is:
 *
 * struct members (fields & methods) are public by default.
 * class members (fields & methods) are private by default.
 */

struct A
{
    // public:
    int publicByDefault;
};

class B
{
    // private:
    int privateByDefault;
};

// -----------------------------------------

struct Node
{
    // https://stackoverflow.com/questions/2706129/can-a-c-class-include-itself-as-an-member
    // Node next; not possible!
    Node *next;
    int val;
} node, *nodePtr;

// -----------------------------------------

// Забележка.
// Когато не дефинираме конструктор в тялото на класа,
// такъв се създава по подразбиране.

// -----------------------------------------

const size_t DEFAULT_RADIUS = 1;

class Circle
{
private:
    int xCentre, yCentre;
    int radius;

public:
    // The Constructor is a special member "function" of a class that is used
    // to initialize objects of its class type.

    // Constructors have no names and cannot be called directly.

    // They are invoked when initialization takes place,
    // and they are selected according to the rules of initialization.

    // Default constructor
    Circle()
    {
        xCentre = 0;
        yCentre = 0;
        radius = DEFAULT_RADIUS;

        // cascade assignment
        // xCentre = yCentre = 0;
    }

    // Circle()
    // {
    //     // this->radius = DEFAULT_RADIUS;
    //     // this->xCentre = 0;
    //     // this->yCentre = 0;

    //     // Constructor Delegation
    //     Circle(DEFAULT_RADIUS, 0, 0);
    // }

    // Parameterized Constructor
    Circle(int radius, int xCentre, int yCentre)
    {
        setRadius(radius);
        setXCentre(xCentre);
        setYCentre(yCentre);
    }

    int getRadius() const
    {
        // Cannot alter data in const member functions
        // radius = 15.4; - Error

        // return this->radius;
        return radius;
    }

    // Getters
    int getXCentre() const
    {
        return xCentre;
    }

    int getYCentre() const
    {
        return yCentre;
    }
    //

    // Setters
    void setRadius(int radius)
    {
        if (radius >= 0)
        {
            this->radius = radius;
        }
    }

    void setXCentre(int xCentre)
    {
        this->xCentre = xCentre;
    }

    void setYCentre(int yCentre)
    {
        this->yCentre = yCentre;
    }
    //

    // We can also declare the methods inside the class/struct
    // and define them afterwards outside using the scope resolution operator.
    // There are also more usage of :: that we will discuss.

    double circumference() const;

    double area() const;

    void printInfo() const;
};

// How we worked with functions & objects before:
// double circumference(const Circle &circle)
// {
//     return 2 * M_PI * circle.radius;
// }

double Circle::circumference() const
{
    return 2 * M_PI * this->radius;
}

double Circle::area() const
{
    return M_PI * this->radius * this->radius;
    // return M_PI * radius * radius;
}

void Circle::printInfo() const
{
    std::cout << "Radius:" << getRadius() << '\n'
              << "xCenter:" << getXCentre() << '\n'
              << "yCenter:" << getYCentre() << '\n'
              << "Circumference: " << circumference() << '\n'
              << "Area: " << area() << std::endl;
}

int main()
{
    Circle defaultCircle;

    // Cannot access radius directly.
    // 'radius' is a private member of 'Circle'.

    // defaultCircle.radius = 123.56;

    std::cout << "Default Circle:" << std::endl;
    defaultCircle.printInfo();

    Circle customCircle(5, 2, 3);

    std::cout << "Custom Circle" << std::endl;
    customCircle.printInfo();

    return 0;
}