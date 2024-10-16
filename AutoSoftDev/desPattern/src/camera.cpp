#include "../include/camera.hpp"

Camera::Camera()
{
    this->cameraModel = "RealSense D435i";
    this->cameramodule = "D430";
    this->RGBdpi = "1920 1080";
    this->RGBfps = "30";
    this->FOV = "8758";
    this->deepFps = "90";
}

void Camera::set()
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

void Camera::print()
{
    cout << "\033[1m摄像头型号: \033[0m" << this->cameraModel << endl;
    cout << "\033[1m摄像头模块: \033[0m" << this->cameramodule << endl;
    cout << "\033[1mRGB分辨率: \033[0m" << this->RGBdpi << endl;
    cout << "\033[1mRGB帧率: \033[0m" << this->RGBfps << " fps" << endl;
    cout << "\033[1mFOV: \033[0m" << this->FOV << endl;
    cout << "\033[1m深度帧率: \033[0m" << this->deepFps << " fps" << endl;
}

// Setters and Getters
void Camera::setCameraModel(string cameraModel) { this->cameraModel = cameraModel; }
void Camera::setCameraModule(string cameramodule) { this->cameramodule = cameramodule; }
void Camera::setRGBdpi(string RGBdpi) { this->RGBdpi = RGBdpi; }
void Camera::setRGBfps(string RGBfps) { this->RGBfps = RGBfps; }
void Camera::setFOV(string FOV) { this->FOV = FOV; }
void Camera::setDeepFps(string deepFps) { this->deepFps = deepFps; }

string Camera::getCameraModel() { return this->cameraModel; }
string Camera::getCameraModule() { return this->cameramodule; }
string Camera::getRGBdpi() { return this->RGBdpi; }
string Camera::getRGBfps() { return this->RGBfps; }
string Camera::getFOV() { return this->FOV; }
string Camera::getDeepFps() { return this->deepFps; }
