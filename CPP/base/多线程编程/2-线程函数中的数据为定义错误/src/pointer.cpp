#include "../include/pointer.hpp"

void foo(int *p)
{
    std::cout << *p << std::endl;
}

/**
 * @details: 在进程结束前提前释放指针p，线程访问的指针p就是一个野指针，虽然一般情况下不会报错，但是数据不对
 */
void pointer()
{
    int *p = new int(1);
    std::thread t1(foo, p);
    delete p;
    t1.join();
}
