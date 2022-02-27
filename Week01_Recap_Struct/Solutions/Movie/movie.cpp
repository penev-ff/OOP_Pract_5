#include <iostream>
#include <cstring>

#include "movie.hpp"

Movie createMovie(const char *name, Genre genre, unsigned short duration, unsigned short rating)
{
    Movie movie;

    strncpy(movie.name, name, MAX_NAME_SIZE);
    movie.genre = genre;
    movie.duration = duration;
    movie.rating = rating;

    return movie;
}

void printMovieInfo(const Movie &movie)
{
    std::cout << "==============================\n"
              << movie.name << "\n"
              << strGenre(movie.genre) << "\n"
              << movie.duration << " minutes\n"
              << movie.rating << " rating\n"
              << "==============================" << std::endl;
}