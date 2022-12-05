#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Rectangle;
struct Circle;
struct Triangle;

struct IVisitable
{
    virtual void accept(Rectangle& r) = 0;
    virtual void accept(Circle& c) = 0;
    virtual void accept(Triangle& t) = 0;

    virtual ~IVisitable() {}
};

struct IElenent
{
    virtual void visit(IVisitable& v) = 0;

    virtual ~IElenent() {}
};

struct Rectangle : IElenent
{
    int a;
    int b;

    void visit(IVisitable& v) final
    {
        a = 2;
        b = 3;
        v.accept(*this);
    }
};

struct Circle : IElenent
{
    int r;

    void visit(IVisitable& v) final
    {
        r = 10;
        v.accept(*this);
    }
};


struct Triangle : IElenent
{
    int a;
    int b;
    int c;

    void visit(IVisitable& v) final
    {
        a = 5;
        b = 6;
        c = 7;
        v.accept(*this);
    }
};


struct Printer : IVisitable
{
    void accept(Rectangle& r) final
    {
        cout << "Rectangle" << endl;
    }
    void accept(Circle& c) final
    {
        cout << "Circle" << endl;
    }
    void accept(Triangle& t) final
    {
        cout << "Triangle" << endl;
    }
};


struct Perimeter : IVisitable {
    void accept(Rectangle& r) final
    {
        cout << "Rectangle perimeter: " << (r.a + r.b) << endl;
    }
    void accept(Circle& c) final
    {
        cout << "Circle perimeter: " << (2 * M_PI * c.r) << endl;
    }
    void accept(Triangle& t) final
    {
        cout << "Triangle perimeter: " << (t.a + t.b + t.c) << endl;
    }
};


struct Square : IVisitable {
    void accept(Rectangle& r) final
    {
        cout << "Rectangle square: " << (r.a * r.b) << endl;
    }
    void accept(Circle& c) final
    {
        cout << "Circle square: " << M_PI * (c.r * c.r) << endl;
    }
    void accept(Triangle& t) final
    {
        long double p = (t.a + t.b + t.c) / 2.0;
        double square = sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));

        cout << "Triangle square: " << square << endl;
    }
};


int main()
{
    std::vector<IElenent*> elements;

    elements.push_back(new Circle);
    elements.push_back(new Rectangle);
    elements.push_back(new Triangle);

    Printer p;
    for (auto& el : elements)
    {
        el->visit(p);
    }

    cout << endl;

    Perimeter perimeter;
    for (auto& el : elements)
    {
        el->visit(perimeter);
    }

    cout << endl;

    Square square;
    for (auto& el : elements)
    {
        el->visit(square);
    }
}