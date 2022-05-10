#include <iostream>

using namespace std;

class Container
{
private:
    int *data;
    size_t capacity, size;

    void free()
    {
        delete[] data;
    }

    void copyFrom(const Container &other)
    {
        // Quite expensive operation

        data = new int[other.capacity];

        for (int i = 0; i < other.size; ++i)
            data[i] = other.data[i];

        size = other.size;
        capacity = other.capacity;
    }

public:
    Container() : size(0), data(nullptr)
    {
        std::cout << "Calling Default Ctor" << this << std::endl;
    }

    Container(size_t capacity)
        : capacity(capacity), size(0)
    {
        std::cout << "Calling Param Ctor " << this << std::endl;

        data = new int[capacity];
    }

    Container(const Container &other)
    {
        std::cout << "Calling Copy Ctor " << this << std::endl;
        copyFrom(other);
    }

    // Steal the resources of a temporary object
    Container(Container &&other) noexcept
    {
        std::cout << "Calling Move Ctor " << this << std::endl;

        this->data = other.data;
        this->capacity = other.capacity;
        this->size = other.size;

        // double free otherwise
        // other won't be used more as it contains a temp value

        other.data = nullptr;
    }

    Container &operator=(const Container &other)
    {
        std::cout << "Calling operator= " << this << std::endl;

        if (this != &other)
        {
            free();
            copyFrom(other);
        }

        return *this;
    }

    Container &operator=(Container &&other) noexcept
    {
        std::cout << "Calling Move operator= " << this << std::endl;

        if (this != &other)
        {
            free();

            this->data = other.data;
            this->capacity = other.capacity;
            this->size = other.size;

            // double free otherwise
            // other won't be used more as it contains a temp value

            other.data = nullptr;
        }

        return *this;
    }

    ~Container()
    {
        std::cout << "Calling Dtor " << this << std::endl;

        free();
    }
};

// RVO (Return Value Optimization) will probably prevent the heavy copy operations
Container createContainer(size_t capacity)
{
    Container container(capacity);

    return container; // Move Ctor called if available and RVO is turned off
}

int main()
{
    Container container = createContainer(50);

    std::cout << &container << std::endl;

    return 0;
}