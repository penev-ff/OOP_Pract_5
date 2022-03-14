#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

// Type alias.
// using u_int = unsigned int;
typedef unsigned int u_int;

/**
 * Returns the length of the string determined by '\0'.
 * @param str
 * @return the length of the string
 */
u_int str_len(const char *str);

/**
 * Copies the source string into the destination string array.
 * The terminating null character ('\0') is included after the copy.
 * @note No buffer overflow protection!
 * @param dest The destination array.
 * @param src The source array.
 */
void str_cp(char *dest, const char *src);

/**
 * Two strings are lexicographically equal if they have the same length
 * and contain the same characters in the same positions.
 * Otherwise, the result would be negative if lhs > rhs and positive if lhs < rhs.
 */
int str_cmp(const char *lhs, const char *rhs);

#endif // STRING_UTILS_HPP
