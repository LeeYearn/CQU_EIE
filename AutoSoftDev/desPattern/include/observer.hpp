#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class Observer
{
public:
    Observer() = default;
    virtual void update(const std::string &msg) = 0;
    virtual ~Observer() = default;
};

#endif // OBSERVER_HPP