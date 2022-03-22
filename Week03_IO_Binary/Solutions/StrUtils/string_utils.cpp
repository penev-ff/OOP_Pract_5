#include "string_utils.hpp"

u_int str_len(const char *str)
{
    // Same as str == nullptr
    if (!str)
        return 0;

    u_int len = 0;
    // Same as (str + len) != nullptr
    while (str[len])
    {
        ++len;
    }

    return len;
}

void str_cp(char *dest, const char *src)
{
    // The destination or the source should not be nullptr.
    if (!dest || !src)
    {
        return;
    }

    u_int srcLength = str_len(src);

    for (int char_i = 0; char_i < srcLength; ++char_i)
    {
        dest[char_i] = src[char_i];
    }

    dest[srcLength] = '\0';
}

int str_cmp(const char *lhs, const char *rhs)
{
    if (!lhs && !rhs)
    {
        return 0;
    }

    if (!lhs)
    {
        return 1;
    }

    if (!rhs)
    {
        return -1;
    }

    while ((*lhs != '\0' && *rhs != '\0') && (*lhs == *rhs))
    {
        ++lhs;
        ++rhs;
    }

    return *lhs - *rhs;

    //    u_int i = 0;
    //    while (lhs[i] && rhs[i] && lhs[i] == rhs[i]) {
    //        ++i;
    //    }
    //
    //    return lhs[i] - rhs[i];
}
