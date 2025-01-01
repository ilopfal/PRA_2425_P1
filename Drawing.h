#ifndef DRAWING_H
#define DRAWING_H

#include "Shape.h"
#include "ListArray.h"  
#include <iostream>

using namespace std;

class Drawing {
private:
    List<Shape*>* shapes;

public:
    Drawing();
    ~Drawing();

    void add_front(Shape* shape);
    void add_back(Shape* shape);
    void print_all() const;
    double get_area_all_circles() const;
    void move_squares(double incX, double incY);
};

#endif

