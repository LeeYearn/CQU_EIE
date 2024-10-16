#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "student.h"
using namespace std;

string generateRandomName()
{
    const string surnames[] = {"张", "李", "王", "赵", "刘", "陈"};
    const string givenNames[] = {"伟", "芳", "娜", "静", "强", "磊", "洋", "梅", "丽", "俊"};

    string surname = surnames[rand() % (sizeof(surnames) / sizeof(surnames[0]))];
    string givenName = givenNames[rand() % (sizeof(givenNames) / sizeof(givenNames[0]))] +
                       givenNames[rand() % (sizeof(givenNames) / sizeof(givenNames[0]))];

    return surname + givenName;
}

string generateRandomId(int year, int classNum, int sequenceNum)
{
    char id[10];
    snprintf(id, sizeof(id), "E%04d%01d%02d", year, classNum, sequenceNum);
    return string(id);
}

void createStudentInfo(student &stu, string carId)
{
    //srand(static_cast<unsigned>(time(0)));
    int year = 2000 + rand() % 25;
    int classNum = 1 + rand() % 9;
    int sequenceNum = rand() % 100;

    stu.name = generateRandomName();

    stu.id = generateRandomId(year, classNum, sequenceNum);

    stu.carId = carId;
}
