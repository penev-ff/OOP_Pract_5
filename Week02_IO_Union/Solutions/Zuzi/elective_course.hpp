#ifndef ELECTIVE_COURSE_HPP_GUARD
#define ELECTIVE_COURSE_HPP_GUARD

#include "category.hpp"
#include "assessment.hpp"

const int MAX_NAME_SIZE = 1 << 10; // 2^10 = 1024

struct ElectiveCourse
{
    unsigned int id;
    char name[MAX_NAME_SIZE];
    Category category;
    unsigned short assessment;
};

#endif // ELECTIVE_COURSE_HPP_GUARD