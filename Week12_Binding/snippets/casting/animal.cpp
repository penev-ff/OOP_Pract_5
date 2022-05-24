#include <iostream>
#include <string>

class Animal
{
private:
    std::string name;
    int age;

public:
    Animal(const std::string &name, int age)
        : name(name), age(age) {}

    virtual void whoAmI() const
    {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Age: " << this->age << std::endl;
    }

    virtual ~Animal() = default;
};

class Dog : public Animal
{
public:
    Dog(const std::string &name, int age) : Animal(name, age) {}

    virtual void whoAmI() const override
    {
        Animal::whoAmI();
        std::cout << "I am a dog" << std::endl;
    }
};

class Pitbull : public Dog
{
public:
    Pitbull(const std::string &name, int age) : Dog(name, age) {}

    virtual void whoAmI() const override final
    {
        Dog::whoAmI();
        std::cout << "Pitbull" << std::endl;
    }
};

class Cat : public Animal
{
    int purrPower;

public:
    Cat(const std::string &name, int age, int purrPower)
        : Animal(name, age), purrPower(purrPower) {}

    virtual void whoAmI() const override
    {
        Animal::whoAmI();
        std::cout << "I am a cat" << std::endl;
    }

    void purr() const
    {
        for (int i = 0; i < purrPower; i++)
        {
            std::cout << "Purrr" << std::endl;
        }
    }
};

int main()
{
    Animal *animals[3];
    animals[0] = new Dog("Sharo", 3);    // Upcasting - From Derived to Base
    animals[1] = new Pitbull("Joro", 4); // Upcasting - From Derived to Base
    animals[2] = new Cat("Bela", 5, 10); // Upcasting - From Derived to Base

    for (int i = 0; i < 3; ++i)
    {
        animals[i]->whoAmI();

        // Casting

        Cat *cat = dynamic_cast<Cat *>(animals[i]);

        if (cat)
        {
            cat->purr();
        }

        std::cout << "-----------" << std::endl;
    }

    for (int i = 0; i < 3; ++i)
    {
        delete animals[i];
    }
    
    Cat *kitty = new Cat("kitty", 1, 3);

    kitty->whoAmI();
    kitty->purr();

    Animal *animal = static_cast<Animal *>(kitty); // OK - C++ Style
    Animal *cStyleAnimal = (Animal *)kitty;

    animal->whoAmI();
    cStyleAnimal->whoAmI();

    // Difference between static_cast and C style cast:

    // 1. static_cast<>() gives you a compile time checking ability, C-Style cast doesn't.
    // 2. static_cast<>() is more readable and can be spotted easily anywhere inside a C++ source code, C_Style cast is'nt.

    return 0;
}
