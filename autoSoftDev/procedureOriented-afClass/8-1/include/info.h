#include "student.h"
#include "smartCar.h"
#include <iostream>
#include <fstream>
#include <vector>

void displayAllInfo(const smartCar &car, const student &stu);
void saveAllInfo(const smartCar &car, const student &stu, const string &addr);
vector<string> readInfoFromFile(const string &addr);
void displayInfo(const string &filePath);