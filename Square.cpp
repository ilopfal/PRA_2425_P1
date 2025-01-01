#include "Square.h"
#include <cmath>

using namespace std;


static double distance(const Point2D& p1, const Point2D& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool Square::check(Point2D* vertices) {
    if (!vertices) return false;
    double side = distance(vertices[0], vertices[1]);
    for (int i = 1; i < 4; i++) {
        int next = (i + 1) % 4;
        if (distance(vertices[i], vertices[next]) != side)
            return false;
    }
    return true;
}

Square::Square() {
    vs = new Point2D[N_VERTICES];
    vs[0] = Point2D(-1, 1);
    vs[1] = Point2D(1, 1);
    vs[2] = Point2D(1, -1);
    vs[3] = Point2D(-1, -1);
    if (!check(vs)) {
        throw invalid_argument("Default vertices do not form a square.");
    }
}

Square::Square(string color, Point2D* vertices) : Rectangle(color, vertices) {
    if (!check(vertices)) {
        throw invalid_argument("Provided vertices do not form a square.");
    }
}

void Square::set_vertices(Point2D* vertices) {
    if (!check(vertices)) {
        throw invalid_argument("Provided vertices do not form a square.");
    }
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = vertices[i];
    }
}

void Square::print() const {
    cout << "Square: Color: " << get_color() << ", Vertices: ";
    for (int i = 0; i < N_VERTICES; i++) {
        cout << "(" << vs[i].x << ", " << vs[i].y << ") ";
    }
    cout << endl;
}

ostream& operator<<(ostream &out, const Square &square) {
    out << "Square: ";
    square.print();
    return out;
}


