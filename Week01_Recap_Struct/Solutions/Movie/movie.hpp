#ifndef MOVIE_HPP_GUARD
#define MOVIE_HPP_GUARD

#include "genre.hpp"

#define MAX_NAME_SIZE 256

struct Movie
{
    char name[MAX_NAME_SIZE + 1]; // +1 for the '\0'
    Genre genre;
    unsigned short duration;
    unsigned short rating;
};

Movie createMovie(const char *name, Genre genre, unsigned short duration, unsigned short rating);

void printMovieInfo(const Movie &movie);

#endif // MOVIE_HPP_GUARD