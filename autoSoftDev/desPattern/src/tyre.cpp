#include "../include/tyre.hpp"

Tyre::Tyre()
{
    this->num = "4";
    this->model = "公路轮 麦克纳姆轮";
    this->size = "175";
}

void Tyre::set()
{
    cout << "设置轮胎数量: " << endl;
    cin >> this->num;
    cout << "设置轮胎型号: " << endl;
    cin >> this->model;
    cout << "设置轮胎尺寸: " << endl;
    cin >> this->size;
}

void Tyre::print()
{
    cout << "\033[1m轮胎数量: \033[0m" << this->num << endl;
    cout << "\033[1m轮胎型号: \033[0m" << this->model << endl;
    cout << "\033[1m轮胎尺寸: \033[0m" << this->size << " mm" << endl;
}

// Setter and Getter implementations
void Tyre::setNum(string num) { this->num = num; }
void Tyre::setModel(string model) { this->model = model; }
void Tyre::setSize(string size) { this->size = size; }

string Tyre::getNum() { return this->num; }
string Tyre::getModel() { return this->model; }
string Tyre::getSize() { return this->size; }
