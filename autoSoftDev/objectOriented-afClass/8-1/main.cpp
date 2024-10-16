#include <iostream>
#include <cstdlib>
#include "smartCar.h"
#include "student.h"
#include "file.h"
using namespace std;
// flag  ==>  0-> 退出界面    1->主界面    2->设置界面
unsigned int flag = 1;
vector<SmartCar> carList;
vector<Student> stuList;
unsigned int idx = 0;

void tip(int count)
{
    switch (count)
    {
    case 0:
        cout << "\033[1;33m无效输入, 请重新输入。\033[0n" << endl;
        break;
    case 1:
        cout << "\033[1;33m[n]显示下一辆学生和小车信息\n[p]显示上一辆学生和小车信息\n[a]新增一辆学生和小车信息\n[s]设置当前学生和小车信息\n[w]保存当前学生和小车信息\n[r]读取本地学生和小车信息\n[e]操作当前小车\n[q]退出程序\033[0m" << endl;
        break;
    case 2:
        cout << "\033[1;33m[0]返回上一层\n[1]设置学生基本信息\n[2]设置小车基本信息\n[3]设置小车底盘信息\n[4]设置小车轮胎信息\n[5]设置小车AGX套件\n[6]设置小车双目摄像头信息\n[7]设置小车九陀螺仪信息\n[8]设置小车多线激光雷达信息\n[9]设置小车液晶显示屏信息\n[10]设置小车电池模块信息\n[11]设置小车所有信息\033[0m" << endl;
        break;
    case 3:
        cout << "\033[1;33m================设置成功================\033[0m" << endl;
        break;
    case 4:
        cout << "\033[1;33m======保存成功, 请在ouTextx目录下查看======\033[0m" << endl;
        break;
    case 5:
        cout << "\033[1;33m[0]随机生成\n[1]手动生成\n[2]读取本地\n[3]取消生成\033[0m" << endl;
        break;
    case 6:
        cout << "\033[1;33m==========当前已经是第一个信息了==========\033[0m" << endl;
        break;
    case 7:
        cout << "\033[1;33m==========当前已经是最后的信息了==========\033[0m" << endl;
        break;
    case 8:
        cout << "\033[1;33m****欢迎使用智能小车管理系统****\033[0m" << endl;
        cout << "当前没有数据，是否新增数据？(y/n)" << endl;
        break;
    case 9:
        cout << "\033[1;33m当前是第 " << idx + 1 << " 个信息，共 " << carList.size() << " 个" << "\033[0m" << endl;
        break;
    case 10:
        cout << "\033[1;33m当前目录中没有txt文件，请重新输入\033[0m" << endl;
        break;
    case 11:
        cout << "\033[1;33m谢谢使用，再见！\033[0m" << endl;
        break;
    case 12:
        cout << "\033[1;33m*道路千万条，安全第一条，行车不规范，亲人两行泪*”\033[0m" << endl;
        break;
    }
}

int createNewInfo(vector<SmartCar> &carList, vector<Student> &stuList, int a = 1)
{
    tip(5);
    string input;
    cin >> input;
    if (input == "0" || input == "1")
    {
        SmartCar car;
        Student stu;
        createStudentInfo(stu, car.getID());
        if (input == "1")
        {
            stu.set();
            car.setAll();
        }
        carList.push_back(car);
        stuList.push_back(stu);
        return 1;
    }
    else if (input == "2")
    {
        int a = loadAllInfo(carList, stuList);
        return a;
    }
    else if (input == "3")
    {
        if (a == 0)
        {
            flag = 0;
            return 0;
        }
        else
        {
            flag = 1;
            return 1;
        }
    }
    return 4;
}

void init(vector<SmartCar> &carList, vector<Student> &stuList, int a = 1, string input = "y")
{
    if (a == 1)
    {
        tip(8);
        cin >> input;
    }
    if (input == "y" || input == "Y")
    {
        int a = createNewInfo(carList, stuList, 0);
        if (a == 0)
        {
            return;
        }
        else if (a == 1)
        {
            idx = 0;
            system("clear");
            tip(9);
            stuList[idx].print();
            carList[idx].print();
            tip(1);
        }
        else if (a == 2)
        {
            system("clear");
            tip(9);
            stuList[idx].print();
            carList[idx].print();
            tip(1);
        }
        else if (a == 3)
        {
            tip(10);
            init(carList, stuList, 0);
            return;
        }
    }
    else
    {
        flag = 0;
    }
}

void interface(vector<SmartCar> &carList, vector<Student> &stuList)
{
    string input;
    cin >> input;
    if (input == "n" || input == "N")
    {
        system("clear");
        if (idx == carList.size() - 1)
            tip(7);
        else
        {
            idx++;
            tip(9);
        }
        stuList[idx].print();
        carList[idx].print();
        tip(1);
    }
    else if (input == "p" || input == "P")
    {
        system("clear");
        if (idx == 0)
            tip(6);
        else
        {
            idx--;
            tip(9);
        }
        stuList[idx].print();
        carList[idx].print();
        tip(1);
    }
    else if (input == "q" || input == "Q")
        flag = 0;
    else if (input == "s" || input == "S")
    {
        system("clear");
        flag = 2;
        tip(2);
    }
    else if (input == "w" || input == "W")
    {
        system("clear");
        saveAllInfo(carList[idx], stuList[idx]);
        tip(4);
        stuList[idx].print();
        carList[idx].print();
        tip(1);
    }
    else if (input == "a" || input == "A")
    {
        int a = createNewInfo(carList, stuList);
        if (a == 0)
            return;
        system("clear");
        idx++;
        tip(9);
        stuList[idx].print();
        carList[idx].print();
        tip(1);
    }
    else if (input == "r" || input == "R")
    {
        system("clear");
        loadAllInfo(carList, stuList);
        tip(9);
        stuList[idx].print();
        carList[idx].print();
        tip(1);
    }
    else if (input == "e" || input == "E")
    {
    }
    else if (input == "clear")
    {
        system("clear");
        tip(1);
    }
    else
        tip(0);
}

void setCartInfo(vector<SmartCar> &carList, vector<Student> &stuList)
{
    int input;
    cin >> input;
    switch (input)
    {
    case 0:
        system("clear");
        flag = 1;
        tip(9);
        stuList[idx].print();
        carList[idx].print();
        tip(1);
        break;
    case 1:
        stuList[idx].set();
        flag = 2;
        system("clear");
        tip(3);
        tip(2);
        break;
    case 2:
        carList[idx].setID();
        flag = 2;
        system("clear");
        tip(3);
        tip(2);
        break;
    case 3:
        carList[idx].setChassis();
        flag = 2;
        system("clear");
        tip(3);
        tip(2);
        break;
    case 4:
        carList[idx].setTyre();
        flag = 1;
        system("clear");
        tip(3);
        tip(2);
        break;
    case 5:
        carList[idx].setAGX();
        flag = 2;
        system("clear");
        tip(3);
        tip(2);
        break;
    case 6:
        carList[idx].setCamera();
        flag = 1;
        system("clear");
        tip(3);
        tip(2);
        break;
    case 7:
        carList[idx].setLidar();
        flag = 2;
        system("clear");
        tip(3);
        tip(2);
        break;
    case 8:
        carList[idx].setGyro();
        flag = 2;
        system("clear");
        tip(3);
        tip(2);
        break;
    case 9:
        carList[idx].setDisplay();
        flag = 2;
        system("clear");
        tip(3);
        tip(2);
        break;
    case 10:
        carList[idx].setPower();
        flag = 2;
        system("clear");
        tip(3);
        tip(2);
        break;
    case 11:
        carList[idx].setAll();
        system("clear");
        tip(3);
        stuList[idx].print();
        carList[idx].print();
        tip(1);
        flag = 1;
        break;
    default:
        system("clear");
        tip(0);
        break;
    }
}

int main()
{
    system("clear");
    init(carList, stuList);
    while (flag)
    {
        if (flag == 1)
        {
            interface(carList, stuList);
        }
        if (flag == 2)
        {
            setCartInfo(carList, stuList);
        }
    }
    system("clear");
    tip(11);
    return 0;
}