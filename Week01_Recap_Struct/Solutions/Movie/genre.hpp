#ifndef GENRE_HPP_GUARD
#define GENRE_HPP_GUARD

// #include <string>

// #define GENRE_SIZE 4

// const std::string GENRE_STRINGS[GENRE_SIZE] = {"Comedy", "Action", "Horror", "Romantic"};

enum Genre
{
    COMEDY,
    ACTION,
    HORROR,
    ROMANTIC
};

// std::string strGenre(Genre genre);

const char *strGenre(Genre genre);

#endif // GENRE_HPP_GUARD