#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include "Point2D.h"

using namespace std;

class Shape {
protected:
    string color;

public:
    Shape();  // Constructor por defecto
    Shape(string color);  // Constructor con parámetro
    virtual ~Shape();  

    string get_color() const;
    void set_color(string c);
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void translate(double incX, double incY) = 0;
    virtual void print() const = 0;
};

#endif // SHAPE_H

