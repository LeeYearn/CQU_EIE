#include "info.h"
#include "student.h"
#include "smartCar.h"
#include <vector>
#include <string>
using namespace std;

void displayPrompt()
{
    cout << endl;
    cout << "=====================================================================" << endl;
    cout << "= 按 N 键显示下一辆小车信息，按 P 显示上一辆小车信息，按 Q 退出系统 =" << endl;
    cout << "=====================================================================" << endl;
    cout << endl;
}

int main()
{
    string dir = "./outText";
    vector<string> files = readInfoFromFile(dir);

    if (files.empty())
    {
        cout << "目录中没有txt文件。" << endl;
        return 1;
    }

    int index = 0;
    char input;

    displayInfo(dir + "/" + files[index]);
    displayPrompt();

    while (1)
    {
        cin >> input;
        if (input == 'N' || input == 'n')
        {
            if (index < files.size() - 1)
            {
                index++;
                displayInfo(dir + "/" + files[index]);
            }
            else
            {
                cout << "已经是最后一个文件。" << endl;
            }
        }
        else if (input == 'P' || input == 'p')
        {
            if (index > 0)
            {
                index--;
                displayInfo(dir + "/" + files[index]);
            }
            else
            {
                cout << "已经是第一个文件。" << endl;
            }
        }
        else if (input == 'Q' || input == 'q')
        {
            cout << "退出系统。" << endl;
            break;
        }
        else
        {
            cout << "无效的输入，请按N、P或Q。" << endl;
        }
        displayPrompt();
    }
    return 0;
}