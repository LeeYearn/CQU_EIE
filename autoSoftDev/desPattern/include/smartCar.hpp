#ifndef SMARTCAR_HPP
#define SMARTCAR_HPP

#include <string>
#include "./agx.hpp"
#include "./camera.hpp"
#include "./chassis.hpp"
#include "./display.hpp"
#include "./gyro.hpp"
#include "./lidar.hpp"
#include "./power.hpp"
#include "./tyre.hpp"
#include "./rand.hpp"
using namespace std;

class SmartCar
{
private:
    string carId;
    Chassis carChassis;
    Tyre carTyre;
    AGX carAGX;
    Camera carCamera;
    Lidar carLidar;
    Gyro carGyro;
    Display carDisplay;
    Power carPower;

public:
    SmartCar();
    void setID();
    void print();
    void setChassis();
    void setTyre();
    void setAGX();
    void setCamera();
    void setLidar();
    void setGyro();
    void setDisplay();
    void setPower();
    void setAll();
    void setID(string id);

    // Setters for individual components
    void setChassisId(string id);
    void setChassisModel(string model);
    void setChassisWheelBase(string wheelBase);
    void setChassisWheelTrack(string wheelTrack);
    void setChassisMinGap(string minGap);
    void setChassisMinTurnRadius(string minTurnRadius);
    void setChassisDrive(string drive);
    void setChassisMaxStroke(string maxStroke);
    void setTyreNum(string num);
    void setTyreModel(string model);
    void setTyreSize(string size);
    void setAGXId(string AGXid);
    void setAGXAI(string AI);
    void setAGXCUDAcore(string CUDAcore);
    void setAGXTensorCore(string TensorCore);
    void setAGXRDD(string RDD);
    void setAGXStore(string store);
    void setCameraModel(string cameraModel);
    void setCameraModule(string cameraModule);
    void setRGBdpi(string RGBdpi);
    void setRGBfps(string RGBfps);
    void setFOV(string FOV);
    void setDeepFps(string deepFps);
    void setLidarModel(string lidarModel);
    void setLidarChannel(string channel);
    void setLidarTestRange(string testRange);
    void setLidarPower(string power);
    void setGyroModel(string gyroModel);
    void setGyroVender(string vender);
    void setDisplayModel(string displayModel);
    void setDisplaySize(string displaySize);
    void setPowerParameter(string power);
    void setPowerInput(string input);
    void setPowerOutput(string output);

    // Getters for the SmartCar
    string getID();
    string getChassisId();
    string getChassisModel();
    string getChassisWheelBase();
    string getChassisWheelTrack();
    string getChassisMinGap();
    string getChassisMinTurnRadius();
    string getChassisDrive();
    string getChassisMaxStroke();
    string getTyreNum();
    string getTyreModel();
    string getTyreSize();
    string getAGXId();
    string getAGXAI();
    string getAGXCUDAcore();
    string getAGXTensorCore();
    string getAGXRDD();
    string getAGXStore();
    string getCameraModel();
    string getCameraModule();
    string getRGBdpi();
    string getRGBfps();
    string getFOV();
    string getDeepFps();
    string getLidarModel();
    string getLidarChannel();
    string getLidarTestRange();
    string getLidarPower();
    string getGyroModel();
    string getGyroVender();
    string getDisplayModel();
    string getDisplaySize();
    string getPowerParameter();
    string getPowerOutput();
    string getPowerInput();
};

#endif // SMARTCAR_HPP
