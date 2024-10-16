#ifndef INFO_H
#define INFO_H

#include <string>
using namespace std;

string generateCarId(string begin);

typedef struct chassis /*底盘*/
{
    string id;
    string model = "SCOUT MINI";
    double wheelBase = 451;
    double wheelTrack = 490;
    double minGap = 115;
    double minTurnRadius = 0;
    string drive = "四轮四驱";
    double maxStroke = 10;
    int tyre = 4;
    string typeModel = "公路轮 麦克纳姆轮";
    double typeSize = 175;
} chassis;

typedef struct AGX
{
    string AGXid = "AGX Xavier";
    string AI = "32 TOPS";
    int CUDAcore = 512;
    int TensorCore = 64;
    int RDD = 32;
    int store = 32;
} AGX;

typedef struct camera
{
    string cameraModel = "RealSense D435i";
    string cameramodule = "D430";
    string RGBdpi = "1920 1080";
    int RGBfps = 30;
    int FOV = 8758;
    int deepFps = 90;
} camera;

typedef struct LIDAR
{
    string lidarModel = "RS-Helios-16p";
    int channel = 16;
    double testRange = 100;
    int power = 8;
} LIDAR;

typedef struct gyro
{
    string gyroModel = "CH110";
    string vender = "NXP";
} gyro;

typedef struct display
{
    double displaySize = 11.6;
    string displayModel = "super";
} display;

typedef struct power
{
    string parameter = "24V/15Ah";
    double output = 24;
    double input = 2;
} power;

typedef struct smartCar
{
    string carId;
    chassis carChassis;
    AGX carAGX;
    camera carCamera;
    LIDAR carLidar;
    gyro carGyro;
    display carDisplay;
    power carPower;
} smartCar;

#endif // INFO_H
