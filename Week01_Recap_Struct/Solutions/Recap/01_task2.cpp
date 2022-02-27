#include <iostream>

int **allocMatrix(const int ROWS, const int COLS)
{
    int **matrix = new int *[ROWS];

    for (int row = 0; row < ROWS; row++)
    {
        matrix[row] = new int[COLS]{};
    }

    return matrix;
}

void fillMatrix(int **matrix, const int ROWS, const int COLS)
{
    if (matrix == nullptr)
    {
        return;
    }

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            std::cin >> matrix[row][col];
        }
    }
}

void freeMatrix(int **matrix, const int ROWS)
{
    for (int row = 0; row < ROWS; row++)
    {
        delete[] matrix[row];
    }

    delete[] matrix;
}

void printMatrix(int **matrix, const int ROWS, const int COLS)
{
    if (matrix == nullptr)
    {
        return;
    }

    for (int row = 0; row < ROWS; row++)
    {
        for (int col = 0; col < COLS; col++)
        {
            std::cout << matrix[row][col] << ' ';
        }
        std::cout << std::endl;
    }
}

int **transposeMatrix(int **matrix, const int ROWS, const int COLS)
{
    int **transpose = allocMatrix(COLS, ROWS);

    for (int col = 0; col < COLS; col++)
    {
        for (int row = 0; row < ROWS; row++)
        {
            transpose[col][row] = matrix[row][col];
        }
    }

    return transpose;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    int **matrix = allocMatrix(n, m);

    fillMatrix(matrix, n, m);

    printMatrix(matrix, n, m);

    int **transpose = transposeMatrix(matrix, n, m);
    printMatrix(transpose, m, n);

    freeMatrix(matrix, n);
    freeMatrix(transpose, m);

    return 0;
}