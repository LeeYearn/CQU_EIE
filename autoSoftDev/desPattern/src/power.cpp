#include "../include/power.hpp"

Power::Power()
{
    this->parameter = "24V/15Ah";
    this->output = "24";
    this->input = "2";
}

void Power::set()
{
    cout << "设置电池参数: " << endl;
    cin >> this->parameter;
    cout << "设置对外供电: " << endl;
    cin >> this->output;
    cout << "设置充电时长: " << endl;
    cin >> this->input;
}

void Power::print()
{
    cout << "\033[1m电池参数: \033[0m" << this->parameter << endl;
    cout << "\033[1m对外供电: \033[0m" << this->output << " V" << endl;
    cout << "\033[1m充电时长: \033[0m" << this->input << " H" << endl;
}

// Setters
void Power::setParameter(string parameter) { this->parameter = parameter; }
void Power::setOutput(string output) { this->output = output; }
void Power::setInput(string input) { this->input = input; }

// Getters
string Power::getParameter() { return this->parameter; }
string Power::getOutput() { return this->output; }
string Power::getInput() { return this->input; }
