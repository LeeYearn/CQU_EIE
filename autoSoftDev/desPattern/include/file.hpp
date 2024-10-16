#ifndef FILE_HPP
#define FILE_HPP

#include <fstream>
#include <vector>
#include <string>
#include "./student.hpp"
#include "./smartCar.hpp"

using namespace std;
#include <filesystem>

void saveAllInfo(SmartCar &car, Student &stu);
int loadAllInfo(vector<SmartCar> &carList, vector<Student> &stuList);

#endif // FILE_HPP
