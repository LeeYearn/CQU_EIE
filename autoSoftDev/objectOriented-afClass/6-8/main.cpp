#include <iostream>
#define PI 3.14159
using namespace std;

class Shape
{
public:
    double getArea() { return 0; }
    double getPerimeter() { return 0; }
};

class Rectangle : public Shape
{
protected:
    double height;
    double width;

public:
    Rectangle() {};
    Rectangle(double _height, double _width)
    {
        height = _height;
        width = _width;
    }
    double getArea()
    {
        return height * width;
    }
    double getPerimeter()
    {
        return 2 * (height + width);
    }
    void Print()
    {
        cout << "Width=" << width << ",Height=" << height << endl;
    }
};

/***
请在这里定义
class Square: public Rectangle;
和
class Circle: public Shape;
***/
class Square : public Rectangle
{

public:
    Square(double _side) : Rectangle(_side, _side) {}

    void Print()
    {
        cout << "Side=" << height << endl;
    }
};

class Circle : public Shape
{
private:
    double PAI = 3.14159;
    double x, y, radius;

public:
    Circle(double _x, double _y, double _radius) : x(_x), y(_y), radius(_radius) {}

    double getArea()
    {
        return PAI * radius * radius;
    }
    double getPerimeter()
    {
        return 2 * PAI * radius;
    }
    void Print()
    {
        cout << "Center=[" << x << "," << y << "],Adius=" << radius << endl;
    }
};

int main()
{
    double ra, rb;
    cin >> ra >> rb;
    Rectangle r1(ra, rb);
    double sa;
    cin >> sa;
    Square s1(sa);
    double ca, cb, cc;
    cin >> ca >> cb >> cc;
    Circle c1(ca, cb, cc);
    cout << "Rectangle" << endl;
    r1.Print();
    cout << "Area=" << r1.getArea() << endl;
    cout << "Perimeter=" << r1.getPerimeter() << endl;
    cout << "Square" << endl;
    s1.Print();
    cout << "Area=" << s1.getArea() << endl;
    cout << "Perimeter=" << s1.getPerimeter() << endl;
    cout << "Circle" << endl;
    c1.Print();
    cout << "Area=" << c1.getArea() << endl;
    cout << "Perimeter=" << c1.getPerimeter() << endl;
    return 0;
}