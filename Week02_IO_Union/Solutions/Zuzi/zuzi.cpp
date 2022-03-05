#include "zuzi.hpp"

#include <iostream>
#include <cstring>

using namespace std;

#define MAX_TOKEN_SIZE 128

void parse_by_delimiter(const char *&line, char delimiter, char *token)
{
    while (*line != delimiter && *line)
    {
        *token = *line;
        ++token;
        ++line;
    }

    *token = '\0';
    ++line;
}

void parse_course(ElectiveCourse &course, const char *line)
{
    // Same as != nullptr
    if (!line)
    {
        return;
    }

    char token[MAX_TOKEN_SIZE]{};

    parse_by_delimiter(line, ',', token);
    course.id = std::stoi(token);

    parse_by_delimiter(line, ',', token);
    strncpy(course.name, token, MAX_NAME_SIZE);

    parse_by_delimiter(line, ',', token);
    course.category = (Category)stoi(token);

    parse_by_delimiter(line, ',', token);
    course.assessment = stoi(token);
}

void add_course(Zuzi &zuzi, const ElectiveCourse &course)
{
    if (zuzi.size >= MAX_COURSES)
    {
        return;
    }

    zuzi.courses[zuzi.size] = course;
    ++zuzi.size;
}
