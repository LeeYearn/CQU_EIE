#ifndef CHASSIS_HPP
#define CHASSIS_HPP

#include <iostream>
#include <vector>
#include <string>
#include "./rand.hpp"
#include "observer.hpp"
using namespace std;

class Chassis : public Observer
{
private:
    string id;
    string model;
    string wheelBase;
    string wheelTrack;
    string minGap;
    string minTurnRadius;
    string drive;
    string maxStroke;

public:
    Chassis();
    void set();
    void print();

    void update(const std::string &obstacleStatus) override;

    void setId(string id);
    void setModel(string model);
    void setWheelBase(string wheelBase);
    void setWheelTrack(string wheelTrack);
    void setMinGap(string minGap);
    void setMinTurnRadius(string minTurnRadius);
    void setDrive(string drive);
    void setMaxStroke(string maxStroke);

    string getId();
    string getModel();
    string getWheelBase();
    string getWheelTrack();
    string getMinGap();
    string getMinTurnRadius();
    string getDrive();
    string getMaxStroke();
};

#endif // CHASSIS_HPP