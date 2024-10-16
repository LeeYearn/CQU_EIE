#include "smartCar.hpp"

SmartCar::SmartCar()
{
    this->carId = generateId("cqusn", 16);
}

void SmartCar::setID()
{
    cout << "设置小车编号" << endl;
    cin >> this->carId;
}

void SmartCar::print()
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

void SmartCar::setChassis() { carChassis.set(); }
void SmartCar::setTyre() { carTyre.set(); }
void SmartCar::setAGX() { carAGX.set(); }
void SmartCar::setCamera() { carCamera.set(); }
void SmartCar::setLidar() { carLidar.set(); }
void SmartCar::setGyro() { carGyro.set(); }
void SmartCar::setDisplay() { carDisplay.set(); }
void SmartCar::setPower() { carPower.set(); }

void SmartCar::setAll()
{
    setID();
    setChassis();
    setTyre();
    setAGX();
    setCamera();
    setLidar();
    setGyro();
    setDisplay();
    setPower();
}

void SmartCar::setID(string id) { this->carId = id; }

// Setters for individual components
void SmartCar::setChassisId(string id) { carChassis.setId(id); }
void SmartCar::setChassisModel(string model) { carChassis.setModel(model); }
void SmartCar::setChassisWheelBase(string wheelBase) { carChassis.setWheelBase(wheelBase); }
void SmartCar::setChassisWheelTrack(string wheelTrack) { carChassis.setWheelTrack(wheelTrack); }
void SmartCar::setChassisMinGap(string minGap) { carChassis.setMinGap(minGap); }
void SmartCar::setChassisMinTurnRadius(string minTurnRadius) { carChassis.setMinTurnRadius(minTurnRadius); }
void SmartCar::setChassisDrive(string drive) { carChassis.setDrive(drive); }
void SmartCar::setChassisMaxStroke(string maxStroke) { carChassis.setMaxStroke(maxStroke); }

void SmartCar::setTyreNum(string num) { carTyre.setNum(num); }
void SmartCar::setTyreModel(string model) { carTyre.setModel(model); }
void SmartCar::setTyreSize(string size) { carTyre.setSize(size); }

void SmartCar::setAGXId(string AGXid) { carAGX.setAGXid(AGXid); }
void SmartCar::setAGXAI(string AI) { carAGX.setAI(AI); }
void SmartCar::setAGXCUDAcore(string CUDAcore) { carAGX.setCUDAcore(CUDAcore); }
void SmartCar::setAGXTensorCore(string TensorCore) { carAGX.setTensorCore(TensorCore); }
void SmartCar::setAGXRDD(string RDD) { carAGX.setRDD(RDD); }
void SmartCar::setAGXStore(string store) { carAGX.setStore(store); }

void SmartCar::setCameraModel(string cameraModel) { carCamera.setCameraModel(cameraModel); }
void SmartCar::setCameraModule(string cameraModule) { carCamera.setCameraModule(cameraModule); }
void SmartCar::setRGBdpi(string RGBdpi) { carCamera.setRGBdpi(RGBdpi); }
void SmartCar::setRGBfps(string RGBfps) { carCamera.setRGBfps(RGBfps); }
void SmartCar::setFOV(string FOV) { carCamera.setFOV(FOV); }
void SmartCar::setDeepFps(string deepFps) { carCamera.setDeepFps(deepFps); }

void SmartCar::setLidarModel(string lidarModel) { carLidar.setLidarModel(lidarModel); }
void SmartCar::setLidarChannel(string channel) { carLidar.setChannel(channel); }
void SmartCar::setLidarTestRange(string testRange) { carLidar.setTestRange(testRange); }
void SmartCar::setLidarPower(string power) { carLidar.setPower(power); }

void SmartCar::setGyroModel(string gyroModel) { carGyro.setGyroModel(gyroModel); }
void SmartCar::setGyroVender(string vender) { carGyro.setVender(vender); }

void SmartCar::setDisplayModel(string displayModel) { carDisplay.setDisplayModel(displayModel); }
void SmartCar::setDisplaySize(string displaySize) { carDisplay.setDisplaySize(displaySize); }

void SmartCar::setPowerParameter(string power) { carPower.setParameter(power); }
void SmartCar::setPowerInput(string input) { carPower.setInput(input); }
void SmartCar::setPowerOutput(string output) { carPower.setOutput(output); }

string SmartCar::getID() { return this->carId; }
string SmartCar::getChassisId() { return carChassis.getId(); }
string SmartCar::getChassisModel() { return carChassis.getModel(); }
string SmartCar::getChassisWheelBase() { return carChassis.getWheelBase(); }
string SmartCar::getChassisWheelTrack() { return carChassis.getWheelTrack(); }
string SmartCar::getChassisMinGap() { return carChassis.getMinGap(); }
string SmartCar::getChassisMinTurnRadius() { return carChassis.getMinTurnRadius(); }
string SmartCar::getChassisDrive() { return carChassis.getDrive(); }
string SmartCar::getChassisMaxStroke() { return carChassis.getMaxStroke(); }

string SmartCar::getTyreNum() { return carTyre.getNum(); }
string SmartCar::getTyreModel() { return carTyre.getModel(); }
string SmartCar::getTyreSize() { return carTyre.getSize(); }

string SmartCar::getAGXId() { return carAGX.getAGXid(); }
string SmartCar::getAGXAI() { return carAGX.getAI(); }
string SmartCar::getAGXCUDAcore() { return carAGX.getCUDAcore(); }
string SmartCar::getAGXTensorCore() { return carAGX.getTensorCore(); }
string SmartCar::getAGXRDD() { return carAGX.getRDD(); }
string SmartCar::getAGXStore() { return carAGX.getStore(); }

string SmartCar::getCameraModel() { return carCamera.getCameraModel(); }
string SmartCar::getCameraModule() { return carCamera.getCameraModule(); }
string SmartCar::getRGBdpi() { return carCamera.getRGBdpi(); }
string SmartCar::getRGBfps() { return carCamera.getRGBfps(); }
string SmartCar::getFOV() { return carCamera.getFOV(); }
string SmartCar::getDeepFps() { return carCamera.getDeepFps(); }

string SmartCar::getLidarModel() { return carLidar.getLidarModel(); }
string SmartCar::getLidarChannel() { return carLidar.getChannel(); }
string SmartCar::getLidarTestRange() { return carLidar.getTestRange(); }
string SmartCar::getLidarPower() { return carLidar.getPower(); }

string SmartCar::getGyroModel() { return carGyro.getGyroModel(); }
string SmartCar::getGyroVender() { return carGyro.getVender(); }

string SmartCar::getDisplayModel() { return carDisplay.getDisplayModel(); }
string SmartCar::getDisplaySize() { return carDisplay.getDisplaySize(); }

string SmartCar::getPowerParameter() { return carPower.getParameter(); }
string SmartCar::getPowerOutput() { return carPower.getOutput(); }
string SmartCar::getPowerInput() { return carPower.getInput(); }
