#include "../include/lidar.hpp"

Lidar::Lidar()
{
    this->lidarModel = "RS-Helios-16p";
    this->channel = "16";
    this->testRange = "100";
    this->power = "8";
}

void Lidar::set()
{
    cout << "设置激光雷达型号: " << endl;
    cin >> this->lidarModel;
    cout << "设置通道数: " << endl;
    cin >> this->channel;
    cout << "设置测试范围: " << endl;
    cin >> this->testRange;
    cout << "设置功率: " << endl;
    cin >> this->power;
}

void Lidar::print()
{
    cout << "\033[1m激光雷达型号: \033[0m" << this->lidarModel << endl;
    cout << "\033[1m通道数: \033[0m" << this->channel << endl;
    cout << "\033[1m测试范围: \033[0m" << this->testRange << " m" << endl;
    cout << "\033[1m功耗: \033[0m" << this->power << " W" << endl;
}

void Lidar::subscribe(Observer *observer)
{
    observers.push_back(observer);
}

void Lidar::unsubscribe(Observer *observer)
{
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Lidar::notify()
{
    for (Observer *observer : observers)
    {
        observer->update(obstacleStatus);
    }
}

void Lidar::setObstacleStatus(const std::string &status)
{
    obstacleStatus = status;
    notify();
}

// Setters
void Lidar::setLidarModel(string lidarModel) { this->lidarModel = lidarModel; }
void Lidar::setChannel(string channel) { this->channel = channel; }
void Lidar::setTestRange(string testRange) { this->testRange = testRange; }
void Lidar::setPower(string power) { this->power = power; }

// Getters
string Lidar::getLidarModel() { return this->lidarModel; }
string Lidar::getChannel() { return this->channel; }
string Lidar::getTestRange() { return this->testRange; }
string Lidar::getPower() { return this->power; }
