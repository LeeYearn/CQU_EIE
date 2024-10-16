#include "info.h"
#include "student.h"
#include "smartCar.h"
using namespace std;

int main()
{
    srand(time(0));
    smartCar cars[10];
    student students[10];
    for (int i = 0; i < 10; ++i)
    {
        cars[i].carId = generateCarId("cqusn");
        cars[i].carChassis.id = generateCarId("dp");
        createStudentInfo(students[i], cars[i].carId);

        saveAllInfo(cars[i], students[i], "./outText/");
    }

    return 0;
}