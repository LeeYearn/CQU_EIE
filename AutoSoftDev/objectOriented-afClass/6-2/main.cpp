#include <iostream>
#include <string>
using namespace std;

class Animal
{
private:
    int m_nWeightBase;

protected:
    int m_nAgeBase;

public:
    void set_weight(int nWeight)
    {
        m_nWeightBase = nWeight;
    }

    int get_weight()
    {
        return m_nWeightBase;
    }

    void set_age(int nAge)
    {
        m_nAgeBase = nAge;
    }
};

class Cat : private Animal
{
private:
    string m_strName;

public:
    Cat(string strName)
    {
        m_strName = strName;
    }

    void set_print_age()
    {
        set_age(5);
        cout << m_strName << ", age = " << m_nAgeBase << endl;
    }

    void set_print_weight()
    {
        set_weight(6);
        cout << m_strName << ", weight = " << get_weight() << endl;
    }
};

int
main()
{
    Cat cat("Persian"); // 定义派生类对象cat
    cat.set_print_age();
    cat.set_print_weight(); // 派生类对象调用自己的公有函数
    return 0;
}