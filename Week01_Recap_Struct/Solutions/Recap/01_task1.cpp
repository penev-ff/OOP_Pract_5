#include <iostream>

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int *allocArray(const int N)
{
    // Prevent bad_alloc exception.
    // https://www.cplusplus.com/reference/new/nothrow/
    // int *arr = new (std::nothrow) int[N];

    return new int[N];
}

void free(int *arr)
{
    // Delete of nullptr is properly defined - won't crash.
    delete[] arr;
}

void readArray(int *arr, const int N)
{
    if (arr == nullptr)
    {
        return;
    }

    for (int i = 0; i < N; i++)
    {
        std::cin >> arr[i];
    }
}

void printArray(const int *arr, const int N)
{
    if (arr == nullptr)
    {
        return;
    }

    for (int i = 0; i < N - 1; i++)
    {
        std::cout << arr[i] << ", ";
    }

    std::cout << arr[N - 1] << std::endl;
}

// Selection sort
void sortArray(int *arr, const int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        int min_i = i;

        for (int j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[min_i])
            {
                min_i = j;
            }
        }

        swap(arr[i], arr[min_i]);
    }
}

int main()
{
    int n;
    std::cin >> n;

    int *arr = allocArray(n);
    readArray(arr, n);

    printArray(arr, n);

    sortArray(arr, n);

    printArray(arr, n);

    free(arr);

    return 0;
}