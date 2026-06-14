#include <iostream>
using namespace std;

class Shape
{
protected:
    int numberOfSides;
    double area;

public:
    Shape(int sides, double area = 0) : numberOfSides(sides), area(area)
    {
    }
    int getNumberOfSides()
    {
        return numberOfSides;
    }
    int getArea()
    {
        return area;
    }

    void setNumberOfSides(int sides)
    {
        numberOfSides = sides;
    }
    void setArea(double a)
    {
        area = a;
    }

    virtual void generateArea() = 0; // Virtual Function so derived classes can override.
                                     // pure virtual --> Shape is abstract.
};

class Rectangle : public Shape
{
protected:
    double length, width;

public:
    Rectangle(double l, double w) : Shape(4), length(l), width(w)
    {
    }

    void generateArea() override
    {
        area = length * width;
    }

    double getLenght()
    {
        return length;
    }
    double getWidth()
    {
        return width;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : Shape(0), radius(r)
    {
    }
    void generateArea() override
    {
        area = 3.142 * radius * radius;
    }
};

class Triangle : public Shape
{
private:
    double height, base;

public:
    Triangle(double h, double b) : Shape(3), height(h), base(b)
    {
    }
    void generateArea() override
    {
        area = (height * base) / 2;
    }
};

class Square : public Rectangle
{
public:
    Square(double side) : Rectangle(side, side)
    {
    }

    void checkIfSquare()
    {
        if (length == width)
        {
            cout << "This is a square." << endl;
        }
        else
        {
            cout << "This is not a square." << endl;
        }
    }

    void generateArea() override
    {
        area = length * width;
    }
};

int main()
{
    Rectangle rect(5, 3);
    rect.generateArea();
    cout << "Area of Rectangle: " << rect.getArea() << endl;

    Circle circ(4);
    circ.generateArea();
    cout << "Area of Circle: " << circ.getArea() << endl;

    Triangle tri(4, 6);
    tri.generateArea();
    cout << "Area of Triangle: " << tri.getArea() << endl;

    Square sq(4);

    sq.generateArea();
    cout << "Area of Square: " << sq.getArea() << endl;
    sq.checkIfSquare();
    return 0;
}