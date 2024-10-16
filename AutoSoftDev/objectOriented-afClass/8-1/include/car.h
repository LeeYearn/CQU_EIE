#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <vector>
#include <string>
#include "rand.h"
using namespace std;

class Chassis
{
private:
    string id;
    string model = "SCOUT MINI";
    string wheelBase = "451";
    string wheelTrack = "490";
    string minGap = "115";
    string minTurnRadius = "0";
    string drive = "四轮四驱";
    string maxStroke = "10";

public:
    Chassis()
    {
        this->id = generateId("dp", 8);
    }
    void set()
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
    void print()
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
    void setId(string id) { this->id = id; }
    void setModel(string model) { this->model = model; }
    void setWheelBase(string wheelBase) { this->wheelBase = wheelBase; }
    void setWheelTrack(string wheelTrack) { this->wheelTrack = wheelTrack; }
    void setMinGap(string minGap) { this->minGap = minGap; }
    void setMinTurnRadius(string minTurnRadius) { this->minTurnRadius = minTurnRadius; }
    void setDrive(string drive) { this->drive = drive; }
    void setMaxStroke(string maxStroke) { this->maxStroke = maxStroke; }

    string getId() { return this->id; }
    string getModel() { return this->model; }
    string getWheelBase() { return this->wheelBase; }
    string getWheelTrack() { return this->wheelTrack; }
    string getMinGap() { return this->minGap; }
    string getMinTurnRadius() { return this->minTurnRadius; }
    string getDrive() { return this->drive; }
    string getMaxStroke() { return this->maxStroke; }
};

class Tyre
{
private:
    string num = "4";
    string model = "公路轮 麦克纳姆轮";
    string size = "175";

public:
    void set()
    {
        cout << "设置轮胎数量: " << endl;
        cin >> this->num;
        cout << "设置轮胎型号: " << endl;
        cin >> this->model;
        cout << "设置轮胎尺寸: " << endl;
        cin >> this->size;
    }

    void print()
    {
        cout << "\033[1m轮胎数量: \033[0m" << this->num << endl;
        cout << "\033[1m轮胎型号: \033[0m" << this->model << endl;
        cout << "\033[1m轮胎尺寸: \033[0m" << this->size << " mm" << endl;
    }
    void setNum(string num) { this->num = num; }
    void setModel(string model) { this->model = model; }
    void setSize(string size) { this->size = size; }

    string getNum() { return this->num; }
    string getModel() { return this->model; }
    string getSize() { return this->size; }
};

class AGX
{
private:
    string AGXid = "AGX Xavier";
    string AI = "32 TOPS";
    string CUDAcore = "512";
    string TensorCore = "64";
    string RDD = "32";
    string store = "32";

public:
    void set()
    {
        cout << "设置AGX套件型号: " << endl;
        cin >> this->AGXid;
        cout << "设置AI算力: " << endl;
        cin >> this->AI;
        cout << "设置CUDA核心数: " << endl;
        cin >> this->CUDAcore;
        cout << "设置TensorCore数: " << endl;
        cin >> this->TensorCore;
        cout << "设置显存容量: " << endl;
        cin >> this->RDD;
        cout << "设置存储容量: " << endl;
        cin >> this->store;
    }
    void print()
    {
        cout << "\033[1mAGX套件型号: \033[0m" << this->AGXid << endl;
        cout << "\033[1mAI算力: \033[0m" << this->AI << endl;
        cout << "\033[1mCUDA核心数: \033[0m" << this->CUDAcore << endl;
        cout << "\033[1mTensorCore数: \033[0m" << this->TensorCore << endl;
        cout << "\033[1m显存容量: \033[0m" << this->RDD << " GB" << endl;
        cout << "\033[1m存储容量: \033[0m" << this->store << " GB" << endl;
    }
    void setAGXid(string AGXid) { this->AGXid = AGXid; }
    void setAI(string AI) { this->AI = AI; }
    void setCUDAcore(string CUDAcore) { this->CUDAcore = CUDAcore; }
    void setTensorCore(string TensorCore) { this->TensorCore = TensorCore; }
    void setRDD(string RDD) { this->RDD = RDD; }
    void setStore(string store) { this->store = store; }

    string getAGXid() { return this->AGXid; }
    string getAI() { return this->AI; }
    string getCUDAcore() { return this->CUDAcore; }
    string getTensorCore() { return this->TensorCore; }
    string getRDD() { return this->RDD; }
    string getStore() { return this->store; }
};

class Camera
{
private:
    string cameraModel = "RealSense D435i";
    string cameramodule = "D430";
    string RGBdpi = "1920 1080";
    string RGBfps = "30";
    string FOV = "8758";
    string deepFps = "90";

public:
    void set()
    {
        cout << "设置摄像头型号: " << endl;
        cin >> this->cameraModel;
        cout << "设置摄像头模块: " << endl;
        cin >> this->cameramodule;
        cout << "设置RGB分辨率: " << endl;
        cin >> this->RGBdpi;
        cout << "设置RGB帧率: " << endl;
        cin >> this->RGBfps;
        cout << "设置FOV: " << endl;
        cin >> this->FOV;
        cout << "设置深度帧率: " << endl;
        cin >> this->deepFps;
    }
    void print()
    {
        cout << "\033[1m摄像头型号: \033[0m" << this->cameraModel << endl;
        cout << "\033[1m摄像头模块: \033[0m" << this->cameramodule << endl;
        cout << "\033[1mRGB分辨率: \033[0m" << this->RGBdpi << endl;
        cout << "\033[1mRGB帧率: \033[0m" << this->RGBfps << " fps" << endl;
        cout << "\033[1mFOV: \033[0m" << this->FOV << endl;
        cout << "\033[1m深度帧率: \033[0m" << this->deepFps << " fps" << endl;
    }
    void setCameraModel(string cameraModel) { this->cameraModel = cameraModel; }
    void setCameraModule(string cameramodule) { this->cameramodule = cameramodule; }
    void setRGBdpi(string RGBdpi) { this->RGBdpi = RGBdpi; }
    void setRGBfps(string RGBfps) { this->RGBfps = RGBfps; }
    void setFOV(string FOV) { this->FOV = FOV; }
    void setDeepFps(string deepFps) { this->deepFps = deepFps; }

    string getCameraModel() { return this->cameraModel; }
    string getCameraModule() { return this->cameramodule; }
    string getRGBdpi() { return this->RGBdpi; }
    string getRGBfps() { return this->RGBfps; }
    string getFOV() { return this->FOV; }
    string getDeepFps() { return this->deepFps; }
};

class Lidar
{
private:
    string lidarModel = "RS-Helios-16p";
    string channel = "16";
    string testRange = "100";
    string power = "8";

public:
    void set()
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
    void print()
    {
        cout << "\033[1m激光雷达型号: \033[0m" << this->lidarModel << endl;
        cout << "\033[1m通道数: \033[0m" << this->channel << endl;
        cout << "\033[1m测试范围: \033[0m" << this->testRange << " m" << endl;
        cout << "\033[1m功耗: \033[0m" << this->power << " W" << endl;
    }
    void setLidarModel(string lidarModel) { this->lidarModel = lidarModel; }
    void setChannel(string channel) { this->channel = channel; }
    void setTestRange(string testRange) { this->testRange = testRange; }
    void setPower(string power) { this->power = power; }

    string getLidarModel() { return this->lidarModel; }
    string getChannel() { return this->channel; }
    string getTestRange() { return this->testRange; }
    string getPower() { return this->power; }
};

class Gyro
{
private:
    string gyroModel = "CH110";
    string vender = "NXP";

public:
    void set()
    {
        cout << "设置陀螺仪型号: " << endl;
        cin >> this->gyroModel;
        cout << "设置供应商: " << endl;
        cin >> this->vender;
    }
    void print()
    {
        cout << "\033[1m陀螺仪型号: \033[0m" << this->gyroModel << endl;
        cout << "\033[1m供应商: \033[0m" << this->vender << endl;
    }
    void setGyroModel(string gyroModel) { this->gyroModel = gyroModel; }
    void setVender(string vender) { this->vender = vender; }

    string getGyroModel() { return this->gyroModel; }
    string getVender() { return this->vender; }
};

class Display
{
private:
    string displaySize = "11.6";
    string displayModel = "super";

public:
    void set()
    {
        cout << "设置显示器型号: " << endl;
        cin >> this->displayModel;
        cout << "设置显示器尺寸: " << endl;
        cin >> this->displaySize;
    }
    void print()
    {
        cout << "\033[1m显示器型号: \033[0m" << this->displayModel << endl;
        cout << "\033[1m显示器尺寸: \033[0m" << this->displaySize << " 英寸" << endl;
    }
    void setDisplayModel(string displayModel) { this->displayModel = displayModel; }
    void setDisplaySize(string displaySize) { this->displaySize = displaySize; }

    string getDisplayModel() { return this->displayModel; }
    string getDisplaySize() { return this->displaySize; }
};

class Power
{
private:
    string parameter = "24V/15Ah";
    string output = "24";
    string input = "2";

public:
    void set()
    {
        cout << "设置电池参数: " << endl;
        cin >> this->parameter;
        cout << "设置对外供电: " << endl;
        cin >> this->output;
        cout << "设置充电时长: " << endl;
        cin >> this->input;
    }
    void print()
    {
        cout << "\033[1m电池参数: \033[0m" << this->parameter << endl;
        cout << "\033[1m对外供电: \033[0m" << this->output << " V" << endl;
        cout << "\033[1m充电时长: \033[0m" << this->input << " H" << endl;
    }
    void setParameter(string parameter) { this->parameter = parameter; }
    void setOutput(string output) { this->output = output; }
    void setInput(string input) { this->input = input; }

    string getParameter() { return this->parameter; }
    string getOutput() { return this->output; }
    string getInput() { return this->input; }
};

#endif // CAR_H