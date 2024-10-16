#include <iostream>
using namespace std;
/* 请在这里填写答案 */

class Pig
{
public:
    Pig()
    {
        cout << "Pig 申请了空间..." << endl;
    }

    virtual ~Pig()
    {
        cout << "Pig 释放了空间..." << endl;
    }

    virtual void climb()
    {
        cout << "我只是个平凡的猪猪。" << endl;
    }
};

class MagicPig : public Pig
{
public:
    MagicPig()
    {
        cout << "MagicPig 申请了空间..." << endl;
    }

    ~MagicPig()
    {
        cout << "MagicPig 释放了空间..." << endl;
    }

    void climb() override
    {
        cout << "我能上树了耶！" << endl;
    }
};

int main()
{
    Pig *p1 = new Pig;
    Pig *p2 = new MagicPig;
    cout << endl;

    p1->climb();
    p2->climb();
    cout << endl;

    delete p1;
    delete p2;
    return 0;
}