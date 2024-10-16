#ifndef LIDAR_HPP
#define LIDAR_HPP

#include <iostream>
#include <string>
#include "./observer.hpp"

using namespace std;

class Lidar
{
private:
    string lidarModel;
    string channel;
    string testRange;
    string power;

    std::vector<Observer *> observers;
    std::string obstacleStatus;

public:
    Lidar();
    void set();
    void print();

    void subscribe(Observer *observer);
    void unsubscribe(Observer *observer);
    void notify();
    void setObstacleStatus(const std::string &status);

    void setLidarModel(string lidarModel);
    void setChannel(string channel);
    void setTestRange(string testRange);
    void setPower(string power);

    string getLidarModel();
    string getChannel();
    string getTestRange();
    string getPower();
};

#endif // LIDAR_HPP
