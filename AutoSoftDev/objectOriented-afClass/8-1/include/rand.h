#ifndef RAND_H
#define RAND_H

#include "student.h"
#include "car.h"
#include "smartCar.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
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

void createStudentInfo(Student &stu, string carId)
{
    srand(time(0));
    int year = 2000 + rand() % 25;
    int classNum = 1 + rand() % 9;
    int sequenceNum = rand() % 100;

    stu.setName(generateRandomName());

    stu.setId(generateRandomId(year, classNum, sequenceNum));

    stu.setCarId(carId);
}

string generateId(string begin, int length)
{
    string chars = "0123456789";
    for (int i = 0; i < length; ++i)
    {
        begin += chars[rand() % chars.length()];
    }
    return begin;
}

#endif // RAND_H