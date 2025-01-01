#include "Drawing.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"

Drawing::Drawing() {
    shapes = new ListArray<Shape*>();  // Cambia a ListLinked si es necesario
}

Drawing::~Drawing() {
    for (int i = 0; i < shapes->size(); ++i) {
        delete shapes->get(i);  // Liberar cada figura
    }
    delete shapes;  // Liberar la lista
}

void Drawing::add_front(Shape* shape) {
    shapes->prepend(shape);  // Añadir al frente
}

void Drawing::add_back(Shape* shape) {
    shapes->append(shape);  // Añadir al fondo
}

void Drawing::print_all() const {
    for (int i = 0; i < shapes->size(); ++i) {
        if (shapes->get(i)) {
            shapes->get(i)->print();  // Llamar al método print de cada figura
        }
    }
}

double Drawing::get_area_all_circles() const {
    double total_area = 0.0;
    for (int i = 0; i < shapes->size(); ++i) {
        const Circle* circle = dynamic_cast<const Circle*>(shapes->get(i));  // Verificar si es un círculo
        if (circle) {
            total_area += circle->area();  // Sumar el área del círculo
        }
    }
    return total_area;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); ++i) {
        Square* square = dynamic_cast<Square*>(shapes->get(i));  // Verificar si es un cuadrado
        if (square) {
            square->translate(incX, incY);  // Mover el cuadrado
        }
    }
}







