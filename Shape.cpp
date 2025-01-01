#include "Shape.h"

// Constructor por defecto, inicia con un color predeterminado
Shape::Shape() : color("default") {}

// Constructor con parámetro que establece el color
Shape::Shape(string color) : color(color) {}

// Destructor virtual
Shape::~Shape() {
    // Limpieza si fuera necesario
}

// Devuelve el color de la forma
string Shape::get_color() const {
    return color;
}

// Establece el color de la forma
void Shape::set_color(string c) {
    color = c;
}



