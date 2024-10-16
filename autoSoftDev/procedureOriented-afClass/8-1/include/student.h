#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

typedef struct student
{
    string name;
    string id;
    string carId;
} student;

void createStudentInfo(student &stu, string carId);

#endif // STUDENT_H
