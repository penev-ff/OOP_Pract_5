#include "genre.hpp"

// std::string strGenre(Genre genre)
// {
//     return GENRE_STRINGS[genre];
// }

const char *strGenre(Genre genre)
{
    switch (genre)
    {
    case COMEDY:
        return "Comedy";

    case ACTION:
        return "Action";

    case HORROR:
        return "Horror";

    case ROMANTIC:
        return "Romantic";
    }

    return "Unknown";
}