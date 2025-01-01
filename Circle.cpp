#include "Circle.h"
#include <iostream>
#include <cmath>

using namespace std;

Circle::Circle() : Shape("red"), center(Point2D(0, 0)), radius(1) {}

Circle::Circle(string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}

Point2D Circle::get_center() const {
    return center;
}

void Circle::set_center(Point2D p) {
    center = p;
}

double Circle::get_radius() const {
    return radius;
}

void Circle::set_radius(double r) {
    radius = r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c) {
    c.print(); // Aprovechar el método print()
    return out;
}

double Circle::area() const {
    return M_PI * radius * radius;
}

double Circle::perimeter() const {
    return 2 * M_PI * radius;
}

void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

// Aquí está la corrección: el método print() debe ser const
void Circle::print() const {
    cout << "Circle: Color: " << get_color()
         << ", Center = (" << center.x << ", " << center.y << ")"
         << ", Radius = " << radius << endl;
}

