#ifndef TYRE_HPP
#define TYRE_HPP

#include <iostream>
#include <string>

using namespace std;

class Tyre
{
private:
    string num;
    string model;
    string size;

public:
    Tyre();
    void set();
    void print();

    void setNum(string num);
    void setModel(string model);
    void setSize(string size);

    string getNum();
    string getModel();
    string getSize();
};

#endif // TYRE_HPP
