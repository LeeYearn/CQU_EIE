#include "../include/chassis.hpp"
using namespace std;

Chassis::Chassis()
{
    this->id = generateId("dp", 8);
    this->model = "SCOUT MINI";
    this->wheelBase = "451";
    this->wheelTrack = "490";
    this->minGap = "115";
    this->minTurnRadius = "0";
    this->drive = "四轮四驱";
    this->maxStroke = "10";
}

void Chassis::set()
{
    cout << "设置底盘编号: " << endl;
    cin >> this->id;
    cout << "设置底盘型号: " << endl;
    cin >> this->model;
    cout << "设置底盘轴距: " << endl;
    cin >> this->wheelBase;
    cout << "设置底盘轮距: " << endl;
    cin >> this->wheelTrack;
    cout << "设置最小离地间隙: " << endl;
    cin >> this->minGap;
    cout << "设置最小转弯半径: " << endl;
    cin >> this->minTurnRadius;
    cout << "设置驱动形式: " << endl;
    cin >> this->drive;
    cout << "设置最大行程: " << endl;
    cin >> this->maxStroke;
}

void Chassis::print()
{
    cout << "\033[1m底盘编号: \033[0m" << this->id << endl;
    cout << "\033[1m底盘型号: \033[0m" << this->model << endl;
    cout << "\033[1m底盘轴距: \033[0m" << this->wheelBase << " mm" << endl;
    cout << "\033[1m底盘轮距: \033[0m" << this->wheelTrack << " mm" << endl;
    cout << "\033[1m最小离地间隙: \033[0m" << this->minGap << " mm" << endl;
    cout << "\033[1m最小转弯半径: \033[0m" << this->minTurnRadius << " m" << endl;
    cout << "\033[1m驱动形式: \033[0m" << this->drive << endl;
    cout << "\033[1m最大行程: \033[0m" << this->maxStroke << " KM" << endl;
}

void Chassis::update(const std::string &obstacleStatus)
{
    if (obstacleStatus == "前方")
    {
        std::cout << "后退。。。。" << std::endl;
    }
    else if (obstacleStatus == "左前方")
    {
        std::cout << "右转。。。。" << std::endl;
    }
    else if (obstacleStatus == "右前方")
    {
        std::cout << "左转。。。。" << std::endl;
    }
    else
    {
        std::cout << "未知障碍物状态" << std::endl;
    }
}

void Chassis::setId(string id) { this->id = id; }
void Chassis::setModel(string model) { this->model = model; }
void Chassis::setWheelBase(string wheelBase) { this->wheelBase = wheelBase; }
void Chassis::setWheelTrack(string wheelTrack) { this->wheelTrack = wheelTrack; }
void Chassis::setMinGap(string minGap) { this->minGap = minGap; }
void Chassis::setMinTurnRadius(string minTurnRadius) { this->minTurnRadius = minTurnRadius; }
void Chassis::setDrive(string drive) { this->drive = drive; }
void Chassis::setMaxStroke(string maxStroke) { this->maxStroke = maxStroke; }

string Chassis::getId() { return this->id; }
string Chassis::getModel() { return this->model; }
string Chassis::getWheelBase() { return this->wheelBase; }
string Chassis::getWheelTrack() { return this->wheelTrack; }
string Chassis::getMinGap() { return this->minGap; }
string Chassis::getMinTurnRadius() { return this->minTurnRadius; }
string Chassis::getDrive() { return this->drive; }
string Chassis::getMaxStroke() { return this->maxStroke; }
