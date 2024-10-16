#include <iostream>
using namespace std;

/***
请在这里定义
class A;
和
ostream& operator<<(ostream &os, A &a);
***/

class A
{
protected:
    int x, y;

public:
    A(int _x, int _y) : x(_x), y(_y) {};
    virtual int op() = 0;
    friend ostream &operator<<(ostream &os, A &a)
    {
        os << "(" << a.x << "," << a.y << ")";
        return os;
    }
    virtual ~A() {}
};

class B : public A
{
public:
    B(int _x, int _y) : A(_x, _y) {};
    int op() { return (x + y) * 2; };
};

class C : public A
{
public:
    C(int _x, int _y) : A(_x, _y) {};
    int op() { return x + y + 20; };
};

int main()
{
    int i, j;
    cin >> i >> j;
    A *b, *c;
    b = new B(i, j);
    c = new C(i, j);

    if (b->op() >= c->op())
        cout << "b:" << *b << ":" << b->op();
    else
        cout << "c:" << *c << ":" << c->op();

    free(b);
    free(c);
    return 0;
}