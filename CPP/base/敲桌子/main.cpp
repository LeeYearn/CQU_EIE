#include <iostream>

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        if (i % 7 == 0 || i / 10 == 7 || i % 10 == 7)
            std::cout << "敲桌子" << std::endl;
        else
            std::cout << i << std::endl;
    }
    return 0;
}