#include <fstream>
#include <iostream>

using namespace std;

#define DEBUG true
#define NO_THROW false

void print(int *array, size_t size)
{
    if (!array)
        return;

    for (size_t i = 0; i < size; i++)
    {
        std::cout << *array + i << " ";
        // std::cout << array[i] << " ";
    }

    std::cout << std::endl;
}

void binaryWriteArray(const char *fPath, int array[], size_t n)
{
    if (!fPath)
        return;

    ofstream fout(fPath, ios_base::binary | ios_base::trunc);

    if (!fout.is_open())
    {
        cerr << "A problem occurred with the file " << fPath << '\n';
        return;
    }

    // It's better to write the size of the array first.
    fout.write((const char *)&n, sizeof(n));
    // Note.
    // The array is pointer by default,
    // there is no need for & to access the address of the variable.
    fout.write((const char *)array, n * sizeof(int));

    fout.close();
}

void binaryReadArray(const char *fPath)
{
    if (!fPath)
        return;

    ifstream fin(fPath, ios_base::binary);

    if (!fin.is_open())
    {
        cerr << "A problem occurred with the file " << fPath << '\n';
        return;
    }

    size_t size = 0;

    // We have stored the size in the first 4 bytes (little-endian format)
    // thus, we can read it and ensure the exact memory allocation.
    // Do not be scared of the syntax.
    fin.read((char *)&size, sizeof(size));

    int *array = new int[size];

    // nothrow Recap
#if NO_THROW
    int *array = new (nothrow) int[size];
    if (!array)
    {
        cerr << "Memory allocation problem.\n";
        fin.close();
        return;
    }
#endif

    fin.read((char *)array, size * sizeof(int));

#if DEBUG
    print(array, size);
#endif

    fin.close();
    delete[] array;
}

void binaryWritePrimitive(const char *fPath, int x)
{
    if (!fPath)
        return;

    ofstream fout(fPath, ios_base::binary | ios_base::trunc);

    if (!fout.is_open())
    {
        cerr << "A problem occurred with the file " << fPath << '\n';
        return;
    }

    fout.write((const char *)&x, sizeof(x));

    fout.close();
}

void binaryReadPrimitive(const char *fPath, int &x)
{
    if (!fPath)
        return;

    ifstream fin(fPath, ios_base::binary);

    if (!fin.is_open())
    {
        cerr << "A problem occurred with the file " << fPath << '\n';
        return;
    }

    fin.read((char *)&x, sizeof(x));

    fin.close();
}

int main()
{
    binaryWritePrimitive("x.dat", 50);

    int y = 0;
    std::cout << "y before: " << y << std::endl;
    binaryReadPrimitive("x.dat", y);
    std::cout << "y after: " << y << std::endl;

    int array[] = {1, 2, 3, 4, 5, 6};
    size_t n = sizeof(array) / sizeof(array[0]);

    // Note.
    // size_t := typedef unsigned long size_t

    binaryWriteArray("arr.dat", array, n);
    binaryReadArray("arr.dat");

    return 0;
}