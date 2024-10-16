#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    string id;
    string carId;

public:
    void set();
    void print();
    void setName(string name);
    void setId(string id);
    void setCarId(string carId);
    string getName();
    string getId();
};

#endif // STUDENT_HPP
