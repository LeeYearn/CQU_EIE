#ifndef GYRO_HPP
#define GYRO_HPP

#include <iostream>
#include <string>

using namespace std;

class Gyro
{
private:
    string gyroModel;
    string vender;

public:
    Gyro(); // 构造函数声明
    void set();
    void print();

    void setGyroModel(string gyroModel);
    void setVender(string vender);

    string getGyroModel();
    string getVender();
};

#endif // GYRO_HPP
