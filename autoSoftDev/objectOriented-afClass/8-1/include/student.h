#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "student.h"

using namespace std;

class Student
{
private:
    string name;
    string id;
    string carId;


public:
    void set()
    {
        cout << "设置学生姓名:  " << endl;
        cin >> this->name;
        cout << "设置学生学号:  " << endl;
        cin >> this->id;
    }
    void print()
    {
        cout << "\033[1m学生姓名: \033[0m" << this->name << endl;
        cout << "\033[1m学生学号: \033[0m" << this->id << endl;
    }
    void setName(string name) { this->name = name; }
    void setId(string id) { this->id = id; }
    void setCarId(string carId) { this->carId = carId; }
    string getName() { return this->name; }
    string getId() { return this->id; }
};

#endif // STUDENT_H