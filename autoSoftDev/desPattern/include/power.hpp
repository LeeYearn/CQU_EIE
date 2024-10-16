#ifndef POWER_HPP
#define POWER_HPP

#include <iostream>
#include <string>

using namespace std;

class Power
{
private:
    string parameter;
    string output;
    string input;

public:
    Power();
    void set();
    void print();

    void setParameter(string parameter);
    void setOutput(string output);
    void setInput(string input);

    string getParameter();
    string getOutput();
    string getInput();
};

#endif // POWER_HPP
