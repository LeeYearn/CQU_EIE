#include "../include/gyro.hpp"

Gyro::Gyro()
{
    this->gyroModel = "CH110";
    this->vender = "NXP";
}

void Gyro::set()
{
    std::cout << "设置陀螺仪型号: " << std::endl;
    std::cin >> this->gyroModel;
    std::cout << "设置供应商: " << std::endl;
    std::cin >> this->vender;
}

void Gyro::print()
{
    std::cout << "\033[1m陀螺仪型号: \033[0m" << this->gyroModel << std::endl;
    std::cout << "\033[1m供应商: \033[0m" << this->vender << std::endl;
}

// Setters
void Gyro::setGyroModel(string gyroModel) { this->gyroModel = gyroModel; }
void Gyro::setVender(string vender) { this->vender = vender; }

// Getters
string Gyro::getGyroModel() { return this->gyroModel; }
string Gyro::getVender() { return this->vender; }
