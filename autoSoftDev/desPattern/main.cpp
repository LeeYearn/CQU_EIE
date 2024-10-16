#include "../include/interface.hpp"

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
        if (flag == 3)
        {
            observerOperation();
        }
    }
    system("clear");
    tip(11);
    return 0;
}