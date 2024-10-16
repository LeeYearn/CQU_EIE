#include "../include/quote.hpp"

std::thread t1;

void foo(int &f)
{
    f += 1;
}

void createThread()
{
    int a = 1;
    std::thread t1(foo, std::ref(a));
}

/**
 * @details: 当createThread结束后，a就被释放了，但t1还持有a的引用，所以foo里面的f就会失效而报错。如果要避免这个问题可以将a改为全局变量
 */
void quote()
{
    createThread();
    t1.join();
}