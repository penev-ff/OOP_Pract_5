#include <iostream>
#include <algorithm>

#include "movie.hpp"

const int MAX_MOVIES = 3;

using namespace std;

void printMovies(const Movie *movies)
{
    if (movies == nullptr)
    {
        return;
    }

    for (int i = 0; i < MAX_MOVIES; i++)
    {
        printMovieInfo(movies[i]);
    }
}

void printTopMovie(const Movie *movies)
{
    if (movies == nullptr)
    {
        return;
    }

    int topMovieIndex = -1;
    int topRating = 0;

    for (int i = 0; i < MAX_MOVIES; i++)
    {
        if (movies[i].rating > topRating)
        {
            topMovieIndex = i;
            topRating = movies[i].rating;
        }
    }

    if (topMovieIndex != -1)
    {
        printMovieInfo(movies[topMovieIndex]);
    }
}

// Bonus
void sortMoviesByRating(Movie *movies)
{
    if (movies == nullptr)
    {
        return;
    }
    
    for (int i = 0; i < MAX_MOVIES - 1; i++)
    {
        int min_i = i;

        for (int j = i + 1; j < MAX_MOVIES; j++)
        {
            if (movies[j].rating < movies[min_i].rating)
            {
                min_i = j;
            }
        }

        swap(movies[i], movies[min_i]);
    }
}

int main()
{
    Movie batman = createMovie("Batman", ACTION, 120, 85);
    Movie titanic = createMovie("Titanic", ROMANTIC, 132, 82);
    Movie it = createMovie("It", HORROR, 110, 77);

    Movie movies[MAX_MOVIES] = {batman, titanic, it};

    // printMovies(movies);

    // printTopMovie(movies);

    sortMoviesByRating(movies);

    printMovies(movies);

    return 0;
}