#ifndef INTERFACE_HPP
#define INTERFACE_HPP

#include <iostream>
#include <cstdlib>
#include <vector>

#include "./file.hpp"

#include "./rand.hpp"
#include "./smartCar.hpp"
#include "./student.hpp"

using namespace std;

// Global variables
extern int flag;
extern vector<SmartCar> carList;
extern vector<Student> stuList;
extern unsigned int idx;

// Function declarations
void tip(int count);
int createNewInfo(vector<SmartCar> &carList, vector<Student> &stuList, int a = 1);
void init(vector<SmartCar> &carList, vector<Student> &stuList, int a = 1, string input = "y");
void interface(vector<SmartCar> &carList, vector<Student> &stuList);
void setCartInfo(vector<SmartCar> &carList, vector<Student> &stuList);
void observerOperation();

#endif // INTERFACE_HPP
