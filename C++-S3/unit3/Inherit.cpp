#include <iostream>
using namespace std;

class Shape
{
public:
    Shape() {}
    virtual ~Shape() {}

    virtual float area() const = 0;
};

class Rectangle : public Shape
{
private:
    float width;
    float height;

public:
    Rectangle(float width, float height) : width(width), height(height) {}

    float area() const override
    {
        return width * height;
    }
};

int main()
{
    Rectangle rect(10, 20);
    cout << "The area of the rectangle is: " << rect.area() << std::endl;
    return 0;
}
