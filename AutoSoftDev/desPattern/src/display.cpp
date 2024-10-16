#include "../include/display.hpp"

Display::Display()
{
    this->displaySize = "11.6";
    this->displayModel = "super";
}

void Display::set()
{
    cout << "设置显示器型号: " << endl;
    cin >> this->displayModel;
    cout << "设置显示器尺寸: " << endl;
    cin >> this->displaySize;
}

void Display::print()
{
    cout << "\033[1m显示器型号: \033[0m" << this->displayModel << endl;
    cout << "\033[1m显示器尺寸: \033[0m" << this->displaySize << " 英寸" << endl;
}

// Setters
void Display::setDisplayModel(string displayModel) { this->displayModel = displayModel; }
void Display::setDisplaySize(string displaySize) { this->displaySize = displaySize; }

// Getters
string Display::getDisplayModel() { return this->displayModel; }
string Display::getDisplaySize() { return this->displaySize; }
