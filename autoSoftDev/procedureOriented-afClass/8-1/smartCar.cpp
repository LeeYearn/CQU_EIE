#include <iostream>
#include <fstream>
#include "string"
using namespace std;

string generateCarId(string begin)
{
    string chars = "0123456789";
    for (int i = 0; i < 16; ++i)
    {
        begin += chars[rand() % chars.length()];
    }
    return begin;
}