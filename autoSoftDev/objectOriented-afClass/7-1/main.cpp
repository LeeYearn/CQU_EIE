#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Date
{
private:
    int year, month, day;
    string monthName[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

public:
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }

    void dispalyMDY()
    {
        cout << month << "--"
             << day << "--"
             << year << endl;
    }

    void dispalyMnDY()
    {
        cout << monthName[month - 1] << " "
             << day << ", "
             << year << endl;
    }

    void dispalyDMnY()
    {
        cout << day << " "
             << monthName[month - 1] << " "
             << year << endl;
    }
};

int main()
{
    int year, month, day;
    cin >> year >> month >> day;
    Date date(year, month, day);
    date.dispalyMDY();
    date.dispalyMnDY();
    date.dispalyDMnY();
    return 0;
}