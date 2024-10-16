#include "../include/classError.hpp"

/**
 * @details: 当对象在线程结束前被释放掉时，线程函数就拿不到对象地址了，所以就是可以使用智能指针
 * @description: 这里创建的a就是一个指向class A的指针。当a不再需要的时候，智能指针会自动释放它指向的内存
 */

void A::foo()
{
    std::cout << "foo" << std::endl;
}

void classError()
{
    std::shared_ptr<A> a = std::make_shared<A>();
    std::thread t(&A::foo, a);
    t.join();
}