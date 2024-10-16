#ifndef SMARTCAR_H
#define SMARTCAR_H

#include <string>
#include "car.h"
#include "rand.h"
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
    SmartCar()
    {
        this->carId = generateId("cqusn",16);
    }
    void setID()
    {
        cout << "设置小车编号" << endl;
        cin >> this->carId;
    }
    void print()
    {
        cout << "\033[1m小车编号: \033[0m" << this->carId << endl;
        carChassis.print();
        carTyre.print();
        carAGX.print();
        carCamera.print();
        carLidar.print();
        carGyro.print();
        carDisplay.print();
        carPower.print();
    }

    void setChassis() { carChassis.set(); }
    void setTyre() { carTyre.set(); }
    void setAGX() { carAGX.set(); }
    void setCamera() { carCamera.set(); }
    void setLidar() { carLidar.set(); }
    void setGyro() { carGyro.set(); }
    void setDisplay() { carDisplay.set(); }
    void setPower() { carPower.set(); }
    void setAll()
    {
        setID();
        carChassis.set();
        carTyre.set();
        carAGX.set();
        carCamera.set();
        carLidar.set();
        carGyro.set();
        carDisplay.set();
        carPower.set();
    }
    void setID(string id) { this->carId = id; }

    void setChassisId(string id) { carChassis.setId(id); }
    void setChassisModel(string model) { carChassis.setModel(model); }
    void setChassisWheelBase(string wheelBase) { carChassis.setWheelBase(wheelBase); }
    void setChassisWheelTrack(string wheelTrack) { carChassis.setWheelTrack(wheelTrack); }
    void setChassisMinGap(string minGap) { carChassis.setMinGap(minGap); }
    void setChassisMinTurnRadius(string minTurnRadius) { carChassis.setMinTurnRadius(minTurnRadius); }
    void setChassisDrive(string drive) { carChassis.setDrive(drive); }
    void setChassisMaxStroke(string maxStroke) { carChassis.setMaxStroke(maxStroke); }

    void setTyreNum(string num) { carTyre.setNum(num); }
    void setTyreModel(string model) { carTyre.setModel(model); }
    void setTyreSize(string size) { carTyre.setSize(size); }

    void setAGXId(string AGXid) { carAGX.setAGXid(AGXid); }
    void setAGXAI(string AI) { carAGX.setAI(AI); }
    void setAGXCUDAcore(string CUDAcore) { carAGX.setCUDAcore(CUDAcore); }
    void setAGXTensorCore(string TensorCore) { carAGX.setTensorCore(TensorCore); }
    void setAGXRDD(string RDD) { carAGX.setRDD(RDD); }
    void setAGXStore(string store) { carAGX.setStore(store); }

    void setCameraModel(string cameraModel) { carCamera.setCameraModel(cameraModel); }
    void setCameraModule(string cameraModule) { carCamera.setCameraModule(cameraModule); }
    void setRGBdpi(string RGBdpi) { carCamera.setRGBdpi(RGBdpi); }
    void setRGBfps(string RGBfps) { carCamera.setRGBfps(RGBfps); }
    void setFOV(string FOV) { carCamera.setFOV(FOV); }
    void setDeepFps(string deepFps) { carCamera.setDeepFps(deepFps); }

    void setLidarModel(string lidarModel) { carLidar.setLidarModel(lidarModel); }
    void setLidarChannel(string channel) { carLidar.setChannel(channel); }
    void setLidarTestRange(string testRange) { carLidar.setTestRange(testRange); }
    void setLidarPower(string power) { carLidar.setPower(power); }

    void setGyroModel(string gyroModel) { carGyro.setGyroModel(gyroModel); }
    void setGyroVender(string vender) { carGyro.setVender(vender); }

    void setDisplayModel(string displayModel) { carDisplay.setDisplayModel(displayModel); }
    void setDisplaySize(string displaySize) { carDisplay.setDisplaySize(displaySize); }

    void setPowerParameter(string power) { carPower.setParameter(power); }
    void setPowerInput(string input) { carPower.setInput(input); }
    void setPowerOutput(string output) { carPower.setOutput(output); }

    string getID() { return this->carId; }

    string getChassisId() { return carChassis.getId(); }
    string getChassisModel() { return carChassis.getModel(); }
    string getChassisWheelBase() { return carChassis.getWheelBase(); }
    string getChassisWheelTrack() { return carChassis.getWheelTrack(); }
    string getChassisMinGap() { return carChassis.getMinGap(); }
    string getChassisMinTurnRadius() { return carChassis.getMinTurnRadius(); }
    string getChassisDrive() { return carChassis.getDrive(); }
    string getChassisMaxStroke() { return carChassis.getMaxStroke(); }

    string getTyreNum() { return carTyre.getNum(); }
    string getTyreModel() { return carTyre.getModel(); }
    string getTyreSize() { return carTyre.getSize(); }

    string getAGXId() { return carAGX.getAGXid(); }
    string getAGXAI() { return carAGX.getAI(); }
    string getAGXCUDAcore() { return carAGX.getCUDAcore(); }
    string getAGXTensorCore() { return carAGX.getTensorCore(); }
    string getAGXRDD() { return carAGX.getRDD(); }
    string getAGXStore() { return carAGX.getStore(); }

    string getCameraModel() { return carCamera.getCameraModel(); }
    string getCameraModule() { return carCamera.getCameraModule(); }
    string getRGBdpi() { return carCamera.getRGBdpi(); }
    string getRGBfps() { return carCamera.getRGBfps(); }
    string getFOV() { return carCamera.getFOV(); }
    string getDeepFps() { return carCamera.getDeepFps(); }

    string getLidarModel() { return carLidar.getLidarModel(); }
    string getLidarChannel() { return carLidar.getChannel(); }
    string getLidarTestRange() { return carLidar.getTestRange(); }
    string getLidarPower() { return carLidar.getPower(); }

    string getGyroModel() { return carGyro.getGyroModel(); }
    string getGyroVender() { return carGyro.getVender(); }

    string getDisplayModel() { return carDisplay.getDisplayModel(); }
    string getDisplaySize() { return carDisplay.getDisplaySize(); }

    string getPowerParameter() { return carPower.getParameter(); }
    string getPowerOutput() { return carPower.getOutput(); }
    string getPowerInput() { return carPower.getInput(); }
};

#endif // SMARTCAR_H