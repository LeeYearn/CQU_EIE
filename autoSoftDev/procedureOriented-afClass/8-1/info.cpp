#include "info.h"
#include <fstream>
#include <vector>
#include <filesystem>
#include <string>
#include <sys/types.h>
#include <dirent.h>
using namespace std;

void displayAllInfo(const smartCar &car, const student &stu)
{
    // 输出学生信息
    cout << "姓名: \t\t" << stu.name << endl;
    cout << "学号: \t\t" << stu.id << endl;

    // 输出小车编号
    cout << "小车编号: \t" << car.carId << endl;

    // 输出底盘信息
    cout << "底盘编号: \t" << car.carChassis.id << endl;
    cout << "底盘型号: \t" << car.carChassis.model << endl;
    cout << "底盘轴距: \t" << car.carChassis.wheelBase << " mm" << endl;
    cout << "底盘轮距: \t" << car.carChassis.wheelTrack << " mm" << endl;
    cout << "最小离地间隙: \t" << car.carChassis.minGap << " mm" << endl;
    cout << "最小转弯半径: \t" << car.carChassis.minTurnRadius << " m" << endl;
    cout << "驱动形式: \t" << car.carChassis.drive << endl;
    cout << "最大行程: \t" << car.carChassis.maxStroke << " KM" << endl;
    cout << "轮胎数量: \t" << car.carChassis.tyre << endl;
    cout << "轮胎型号: \t" << car.carChassis.typeModel << endl;
    cout << "轮胎尺寸: \t" << car.carChassis.typeSize << " mm" << endl;

    // 输出AGX套件信息
    cout << "AGX套件型号: \t" << car.carAGX.AGXid << endl;
    cout << "AI性能: \t" << car.carAGX.AI << endl;
    cout << "CUDA核心数: \t" << car.carAGX.CUDAcore << endl;
    cout << "TensorCore数量: " << car.carAGX.TensorCore << endl;
    cout << "显存: \t\t" << car.carAGX.RDD << " GB" << endl;
    cout << "存储: \t\t" << car.carAGX.store << " GB" << endl;

    // 输出摄像头信息
    cout << "摄像头型号:\t " << car.carCamera.cameraModel << endl;
    cout << "摄像头模块:\t " << car.carCamera.cameramodule << endl;
    cout << "RGB分辨率: \t" << car.carCamera.RGBdpi << endl;
    cout << "RGB帧率: \t" << car.carCamera.RGBfps << " fps" << endl;
    cout << "FOV: \t\t" << car.carCamera.FOV << endl;
    cout << "深度帧率: \t" << car.carCamera.deepFps << " fps" << endl;

    // 输出激光雷达信息
    cout << "激光雷达型号: \t" << car.carLidar.lidarModel << endl;
    cout << "通道数: \t" << car.carLidar.channel << endl;
    cout << "测试范围: \t" << car.carLidar.testRange << " m" << endl;
    cout << "功耗: \t\t" << car.carLidar.power << " W" << endl;

    // 输出陀螺仪信息
    cout << "陀螺仪型号: \t" << car.carGyro.gyroModel << endl;
    cout << "厂家: \t\t" << car.carGyro.vender << endl;

    // 输出显示屏信息
    cout << "显示屏尺寸: \t" << car.carDisplay.displaySize << " 英寸" << endl;
    cout << "显示屏型号: \t" << car.carDisplay.displayModel << endl;

    // 输出电池模块信息
    cout << "电池参数: \t" << car.carPower.parameter << endl;
    cout << "对外供电: \t" << car.carPower.output << " V" << endl;
    cout << "充电时长: \t" << car.carPower.input << " H" << endl;
}

void saveAllInfo(const smartCar &car, const student &stu, const string &addr = "./")
{
    string fileName = addr + car.carId + ".txt";

    ofstream outFile(fileName);

    if (!outFile)
    {
        cerr << "无法打开文件 " << fileName << " 进行写入。" << endl;
        return;
    }

    // 输出学生信息
    outFile << "姓名: " << stu.name << endl;
    outFile << "学号: " << stu.id << endl;

    outFile << "小车编号: " << car.carId << endl;
    outFile << "底盘编号: " << car.carChassis.id << endl;
    outFile << "底盘型号: " << car.carChassis.model << endl;
    outFile << "底盘轴距: " << car.carChassis.wheelBase << " mm" << endl;
    outFile << "底盘轮距: " << car.carChassis.wheelTrack << " mm" << endl;
    outFile << "最小离地间隙: " << car.carChassis.minGap << " mm" << endl;
    outFile << "最小转弯半径: " << car.carChassis.minTurnRadius << " m" << endl;
    outFile << "驱动形式: " << car.carChassis.drive << endl;
    outFile << "最大行程: " << car.carChassis.maxStroke << " KM" << endl;
    outFile << "轮胎数量: " << car.carChassis.tyre << endl;
    outFile << "轮胎型号: " << car.carChassis.typeModel << endl;
    outFile << "轮胎尺寸: " << car.carChassis.typeSize << " mm" << endl;

    outFile << "AGX套件型号: " << car.carAGX.AGXid << endl;
    outFile << "AI性能: " << car.carAGX.AI << endl;
    outFile << "CUDA核心数: " << car.carAGX.CUDAcore << endl;
    outFile << "TensorCore数量: " << car.carAGX.TensorCore << endl;
    outFile << "显存: " << car.carAGX.RDD << " GB" << endl;
    outFile << "存储: " << car.carAGX.store << " GB" << endl;

    outFile << "摄像头型号: " << car.carCamera.cameraModel << endl;
    outFile << "摄像头模块: " << car.carCamera.cameramodule << endl;
    outFile << "RGB分辨率: " << car.carCamera.RGBdpi << endl;
    outFile << "RGB帧率: " << car.carCamera.RGBfps << " fps" << endl;
    outFile << "FOV: " << car.carCamera.FOV << endl;
    outFile << "深度帧率: " << car.carCamera.deepFps << " fps" << endl;

    outFile << "激光雷达型号: " << car.carLidar.lidarModel << endl;
    outFile << "通道数: " << car.carLidar.channel << endl;
    outFile << "测试范围: " << car.carLidar.testRange << " m" << endl;
    outFile << "功耗: " << car.carLidar.power << " W" << endl;

    outFile << "陀螺仪型号: " << car.carGyro.gyroModel << endl;
    outFile << "厂家: " << car.carGyro.vender << endl;

    outFile << "显示屏尺寸: " << car.carDisplay.displaySize << " 英寸" << endl;
    outFile << "显示屏型号: " << car.carDisplay.displayModel << endl;

    outFile << "电池参数: " << car.carPower.parameter << endl;
    outFile << "对外供电: " << car.carPower.output << " V" << endl;
    outFile << "充电时长: " << car.carPower.input << " H" << endl;

    outFile.close();
}

vector<string> readInfoFromFile(const string &addr)
{
    vector<string> fileNames;
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(addr.c_str())) != NULL)
    {
        // 遍历目录中的所有文件
        while ((ent = readdir(dir)) != NULL)
        {
            string fileName = ent->d_name;
            // 只处理 .txt 文件
            if (fileName.size() > 4 && fileName.substr(fileName.size() - 4) == ".txt")
            {
                fileNames.push_back(fileName);
            }
        }
        closedir(dir);
    }
    else
    {
        cerr << "无法打开目录: " << addr << endl;
    }

    return fileNames;
}

void displayInfo(const string &filePath)
{
    ifstream file(filePath);
    if (!file.is_open())
    {
        cerr << "无法打开文件: " << filePath << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}