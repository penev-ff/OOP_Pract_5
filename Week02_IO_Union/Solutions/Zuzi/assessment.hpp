#ifndef ASSESSMENT_HPP_GUARD
#define ASSESSMENT_HPP_GUARD

/*
  Exam:           0b000000001
  Course Project: 0b000000010
  Test:           0b000000100
  ---------------------------

  Set Flag => Using the | bitwise operator:
  Exam | CP = 0b000000011 ~ 3
  Exam | CP | Test = 0b000000111 ~ 7

  Test Flag - Using the & bitwise operator:
  int bits = 0b000000101 (Exam + Test):
  
  bool test = bits & Exam; // 1 ~ True
  bool cp = bits & CP;     // 0 ~ False
  bool test = bits & Test; // 4 ~ True  
*/

enum Assessment
{
    EXAM           = 0b000000001, // 1
    COURSE_PROJECT = 0b000000010, // 2
    TEST           = 0b000000100, // 4
};

#endif // ASSESSMENT_HPP_GUARD