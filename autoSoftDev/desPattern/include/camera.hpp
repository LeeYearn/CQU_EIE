#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <string>

using namespace std;

class Camera
{
private:
    string cameraModel;
    string cameramodule;
    string RGBdpi;
    string RGBfps;
    string FOV;
    string deepFps;

public:
    Camera();
    void set();
    void print();

    void setCameraModel(string cameraModel);
    void setCameraModule(string cameramodule);
    void setRGBdpi(string RGBdpi);
    void setRGBfps(string RGBfps);
    void setFOV(string FOV);
    void setDeepFps(string deepFps);

    string getCameraModel();
    string getCameraModule();
    string getRGBdpi();
    string getRGBfps();
    string getFOV();
    string getDeepFps();
};

#endif // CAMERA_HPP
