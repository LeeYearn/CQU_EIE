#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <iostream>
#include <string>

using namespace std;

class Display
{
private:
    string displaySize;
    string displayModel;

public:
    Display();
    void set();
    void print();

    void setDisplayModel(string displayModel);
    void setDisplaySize(string displaySize);

    string getDisplayModel();
    string getDisplaySize();
};

#endif // DISPLAY_HPP
