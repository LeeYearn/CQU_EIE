#ifndef RAND_HPP
#define RAND_HPP

#include "./student.hpp"
#include <iostream>
#include <string>

using namespace std;

string generateRandomName();
string generateRandomId(int year, int classNum, int sequenceNum);
void createStudentInfo(Student &stu, string carId);
string generateId(string begin, int length);

#endif // RAND_HPP
