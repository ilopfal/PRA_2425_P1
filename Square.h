#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <stdexcept>
#include "Rectangle.h"
#include "Point2D.h"

using namespace std;

class Square : public Rectangle {
private:
    static bool check(Point2D* vertices);

public:
    static const int N_VERTICES = 4;

    Square();
    Square(string color, Point2D* vertices);

    void set_vertices(Point2D* vertices) override;  

    friend ostream& operator<<(ostream &out, const Square &square);

    void print() const override;  // Marcar como const y override

};

#endif // SQUARE_H

