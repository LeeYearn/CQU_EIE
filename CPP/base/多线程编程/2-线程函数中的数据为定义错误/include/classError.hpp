#pragma once
#include <iostream>
#include <thread>
#include <string>
#include <memory>

class A
{
public:
    A() {};
    ~A() {};
    void foo();
};

void classError();