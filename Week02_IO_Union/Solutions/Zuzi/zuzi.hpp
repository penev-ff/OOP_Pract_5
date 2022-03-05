#ifndef ZUZI_HPP_GUARD
#define ZUZI_HPP_GUARD

#include "elective_course.hpp"

const unsigned int MAX_COURSES = 512;

struct Zuzi
{
    unsigned int size = 0;
    ElectiveCourse courses[MAX_COURSES];
};

void parse_course(ElectiveCourse &course, const char *line);

void add_course(Zuzi& zuzi, const ElectiveCourse& course);

#endif // ZUZI_HPP_GUARD
