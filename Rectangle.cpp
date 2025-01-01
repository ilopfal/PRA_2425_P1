#include "Rectangle.h"
#include <cmath>
#include <stdexcept>
#include <iostream>

using namespace std;

static double distance(const Point2D& p1, const Point2D& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool Rectangle::check(Point2D* vertices) {
    if (!vertices) return false;

    double d01 = distance(vertices[0], vertices[1]);
    double d12 = distance(vertices[1], vertices[2]);
    double d23 = distance(vertices[2], vertices[3]);
    double d30 = distance(vertices[3], vertices[0]);
    return (d01 == d23 && d12 == d30);
}

Rectangle::Rectangle() : Shape("red") {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 0.5);
    vs[1] = Point2D(1, 0.5);
    vs[2] = Point2D(1, -0.5);
    vs[3] = Point2D(-1, -0.5);
}

Rectangle::Rectangle(string color, Point2D* vertices) : Shape(color) {
    if (!check(vertices)) {
        throw invalid_argument("Provided vertices do not form a rectangle.");
    }
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

Rectangle::Rectangle(const Rectangle& r) : Shape(r.get_color()) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind < 0 || ind >= N_VERTICES) {
        throw out_of_range("Index out of range");
    }
    return vs[ind];
}

void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw invalid_argument("Provided vertices do not form a rectangle.");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

Point2D Rectangle::operator[](int ind) const {
    return get_vertex(ind);
}

Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        set_color(r.get_color());
        set_vertices(r.vs);
    }
    return *this;
}

ostream& operator<<(ostream& out, const Rectangle& r) {
    r.print();
    return out;
}

void Rectangle::print() const {
    cout << "Rectangle: Color: " << get_color() << ", Vertices: ";
    for (int i = 0; i < N_VERTICES; i++) {
        cout << "(" << vs[i].x << ", " << vs[i].y << ") ";
    }
    cout << endl;
}

double Rectangle::area() const {
    double width = distance(vs[0], vs[1]);
    double height = distance(vs[1], vs[2]);
    return width * height;
}

double Rectangle::perimeter() const {
    double width = distance(vs[0], vs[1]);
    double height = distance(vs[1], vs[2]);
    return 2 * (width + height);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}


