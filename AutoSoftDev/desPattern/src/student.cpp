#include "../include/student.hpp"

void Student::set()
{
    cout << "设置学生姓名:  " << endl;
    cin >> this->name;
    cout << "设置学生学号:  " << endl;
    cin >> this->id;
}

void Student::print()
{
    cout << "\033[1m学生姓名: \033[0m" << this->name << endl;
    cout << "\033[1m学生学号: \033[0m" << this->id << endl;
}

void Student::setName(string name) { this->name = name; }
void Student::setId(string id) { this->id = id; }
void Student::setCarId(string carId) { this->carId = carId; }
string Student::getName() { return this->name; }
string Student::getId() { return this->id; }
