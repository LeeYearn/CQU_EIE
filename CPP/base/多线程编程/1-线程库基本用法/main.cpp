#include <iostream>
#include <thread>
#include <string>
void printHello(std::string msg1)
{
    std::cout << msg1 << std::endl;
    return;
}

int main()
{
    // 创建线程，并指定线程函数
    std::thread thread1(printHello, "hello thread 1");
    std::thread thread2(printHello, "hello thread 2");
    std::thread thread3(printHello, "hello thread 3");

    // 等待线程结束
    thread1.join();

    // 判断线程是否可以join
    bool isJoin = thread2.joinable();
    if(isJoin)
        thread2.join();

    // 分离线程，不常用
    thread3.detach();
    return 0;
}

/*
 * 实际上join是等待线程结束后在执行主进程
 * 
 * joinable用于判断线程是否可以join，如果线程已经join或者detach，则返回false。并且会被阻塞，直到被判断的线程结束才会做判断后面的任务
 *
 * 分离线程虽然可以实现主进程结束，子线程继续运行的效果，但是分离线程的结束状态无法获取，也无法进行同步操作，所以分离线程一般不使用
 * 并且线程仍然靠主进程的栈分配空间，detach的分离作用是提前给内核打上标记，让内核知道这个线程已经分离，主进程结束，内核会自动回收这个线程的资源
 */