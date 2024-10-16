#include "../include/file.hpp"

void saveAllInfo(SmartCar &car, Student &stu)
{
    string fileName = "../outText/" + car.getID() + ".txt";

    ofstream outFile(fileName);

    if (!outFile)
    {
        cerr << "无法打开文件 " << fileName << " 进行写入。" << endl;
        return;
    }

    // 输出学生信息
    outFile << "学生姓名: " << stu.getName() << endl;
    outFile << "学生学号: " << stu.getId() << endl;

    // 输出小车信息
    outFile << "小车编号: " << car.getID() << endl;
    outFile << "底盘编号: " << car.getChassisId() << endl;
    outFile << "底盘型号: " << car.getChassisModel() << endl;
    outFile << "底盘轴距: " << car.getChassisWheelBase() << " mm" << endl;
    outFile << "底盘轮距: " << car.getChassisWheelTrack() << " mm" << endl;
    outFile << "最小离地间隙: " << car.getChassisMinGap() << " mm" << endl;
    outFile << "最小转弯半径: " << car.getChassisMinTurnRadius() << " m" << endl;
    outFile << "驱动形式: " << car.getChassisDrive() << endl;
    outFile << "最大行程: " << car.getChassisMaxStroke() << " KM" << endl;
    outFile << "轮胎数量: " << car.getTyreNum() << endl;
    outFile << "轮胎型号: " << car.getTyreModel() << endl;
    outFile << "轮胎尺寸: " << car.getTyreSize() << " mm" << endl;

    outFile << "AGX套件型号: " << car.getAGXId() << endl;
    outFile << "AI性能: " << car.getAGXAI() << endl;
    outFile << "CUDA核心数: " << car.getAGXCUDAcore() << endl;
    outFile << "TensorCore数量: " << car.getAGXTensorCore() << endl;
    outFile << "显存容量: " << car.getAGXRDD() << " GB" << endl;
    outFile << "存储容量: " << car.getAGXStore() << " GB" << endl;

    outFile << "摄像头型号: " << car.getCameraModel() << endl;
    outFile << "摄像头模块: " << car.getCameraModule() << endl;
    outFile << "RGB分辨率: " << car.getRGBdpi() << endl;
    outFile << "RGB帧率: " << car.getRGBfps() << " fps" << endl;
    outFile << "FOV: " << car.getFOV() << endl;
    outFile << "深度帧率: " << car.getDeepFps() << " fps" << endl;

    outFile << "激光雷达型号: " << car.getLidarModel() << endl;
    outFile << "通道数: " << car.getLidarChannel() << endl;
    outFile << "测试范围: " << car.getLidarTestRange() << " m" << endl;
    outFile << "功耗: " << car.getLidarPower() << " W" << endl;

    outFile << "陀螺仪型号: " << car.getGyroModel() << endl;
    outFile << "供应商: " << car.getGyroVender() << endl;

    outFile << "显示屏型号: " << car.getDisplayModel() << endl;
    outFile << "显示屏尺寸: " << car.getDisplaySize() << " 英寸" << endl;

    outFile << "电池参数: " << car.getPowerParameter() << endl;
    outFile << "对外供电: " << car.getPowerOutput() << " V" << endl;
    outFile << "充电时长: " << car.getPowerInput() << " H" << endl;

    outFile.close();
}

int loadAllInfo(vector<SmartCar> &carList, vector<Student> &stuList)
{
    string directory = "../outText/";
    bool isText = true;
    for (const auto &entry : filesystem::directory_iterator(directory))
    {
        if (entry.path().extension() == ".txt")
        {
            isText = false;
            break;
        }
    }

    if (isText)
    {
        return 3;
        cout << "没有找到任何txt文件" << endl;
    }

    for (const auto &entry : filesystem::directory_iterator(directory))
    {
        ifstream inFile(entry.path());

        if (entry.path().extension() != ".txt")
        {
            continue;
        }

        SmartCar car;
        Student stu;

        string line;
        while (getline(inFile, line))
        {
            if (line.find("学生姓名: ") != string::npos)
                stu.setName(line.substr(line.find(":") + 2));
            else if (line.find("学生学号: ") != string::npos)
                stu.setId(line.substr(line.find(":") + 2));
            else if (line.find("小车编号: ") != string::npos)
                car.setID(line.substr(line.find(":") + 2));
            else if (line.find("底盘编号: ") != string::npos)
                car.setChassisId(line.substr(line.find(":") + 2));
            else if (line.find("底盘型号: ") != string::npos)
                car.setChassisModel(line.substr(line.find(":") + 2));
            else if (line.find("底盘轴距: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setChassisWheelBase(a.substr(0, a.length() - 3));
            }
            else if (line.find("底盘轮距: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setChassisWheelTrack(a.substr(0, a.length() - 3));
            }
            else if (line.find("最小离地间隙: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setChassisMinGap(a.substr(0, a.length() - 3));
            }
            else if (line.find("最小转弯半径: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setChassisMinTurnRadius(a.substr(0, a.length() - 2));
            }
            else if (line.find("驱动形式: ") != string::npos)
                car.setChassisDrive(line.substr(line.find(":") + 2));
            else if (line.find("最大行程: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setChassisMaxStroke(a.substr(0, a.length() - 3));
            }
            else if (line.find("轮胎数量: ") != string::npos)
                car.setTyreNum(line.substr(line.find(":") + 2));
            else if (line.find("轮胎型号: ") != string::npos)
                car.setTyreModel(line.substr(line.find(":") + 2));
            else if (line.find("轮胎尺寸: ") != string::npos)
                car.setTyreSize(line.substr(line.find(":") + 2));
            else if (line.find("AGX套件型号: ") != string::npos)
                car.setAGXId(line.substr(line.find(":") + 2));
            else if (line.find("AI性能: ") != string::npos)
                car.setAGXAI(line.substr(line.find(":") + 2));
            else if (line.find("CUDA核心数: ") != string::npos)
                car.setAGXCUDAcore(line.substr(line.find(":") + 2));
            else if (line.find("TensorCore数量: ") != string::npos)
                car.setAGXTensorCore(line.substr(line.find(":") + 2));
            else if (line.find("显存容量: ") != string::npos)
                car.setAGXRDD(line.substr(line.find(":") + 2));
            else if (line.find("存储容量: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setAGXStore(a.substr(0, a.length() - 3));
            }
            else if (line.find("摄像头型号: ") != string::npos)
                car.setCameraModel(line.substr(line.find(":") + 2));
            else if (line.find("摄像头模块: ") != string::npos)
                car.setCameraModule(line.substr(line.find(":") + 2));
            else if (line.find("RGB分辨率: ") != string::npos)
                car.setRGBdpi(line.substr(line.find(":") + 2));
            else if (line.find("RGB帧率: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setRGBfps(a.substr(0, a.length() - 4));
            }
            else if (line.find("FOV: ") != string::npos)
                car.setFOV(line.substr(line.find(":") + 2));
            else if (line.find("深度帧率: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setDeepFps(a.substr(0, a.length() - 4));
            }
            else if (line.find("激光雷达型号: ") != string::npos)
                car.setLidarModel(line.substr(line.find(":") + 2));
            else if (line.find("通道数: ") != string::npos)
                car.setLidarChannel(line.substr(line.find(":") + 2));
            else if (line.find("测试范围: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setLidarTestRange(a.substr(0, a.length() - 2));
            }
            else if (line.find("功耗: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setLidarPower(a.substr(0, a.length() - 2));
            }
            else if (line.find("陀螺仪型号: ") != string::npos)
                car.setGyroModel(line.substr(line.find(":") + 2));
            else if (line.find("供应商: ") != string::npos)
                car.setGyroVender(line.substr(line.find(":") + 2));
            else if (line.find("显示屏型号: ") != string::npos)
                car.setDisplayModel(line.substr(line.find(":") + 2));
            else if (line.find("显示屏尺寸: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setDisplaySize(a.substr(0, a.length() - 3));
            }
            else if (line.find("电池参数: ") != string::npos)
                car.setPowerParameter(line.substr(line.find(":") + 2));
            else if (line.find("对外供电: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setPowerOutput(a.substr(0, a.length() - 2));
            }
            else if (line.find("充电时长: ") != string::npos)
            {
                string a = line.substr(line.find(":") + 2);
                car.setPowerInput(a.substr(0, a.length() - 2));
            }
        }

        // 存储学生信息和小车信息
        stuList.push_back(stu);
        carList.push_back(car);
    }

    return 2;
}
