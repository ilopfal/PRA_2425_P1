#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <stdexcept>
#include "Point2D.h"

using namespace std;  // Usando el espacio de nombres estándar

class Shape {
protected:
    string color;  // Color de la figura

public:
    // Constructor por defecto, establece el color inicial como rojo
    Shape() : color("red") {}

    // Constructor con especificación de color
    Shape(string color) {
        set_color(color);  // Utiliza el método set_color para establecer el color y validar
    }

    // Devuelve el color actual de la figura
    string get_color() const {
        return color;
    }

    // Establece el color de la figura; lanza excepción si el color no es válido
    void set_color(string c) {
        if (c == "red" || c == "green" || c == "blue") {
            color = c;
        } else {
            throw invalid_argument("Invalid color. Color must be one of: 'red', 'green', 'blue'.");
        }
    }

    // Método virtual puro para calcular el área de la figura
    virtual double area() const = 0;

    // Método virtual puro para calcular el perímetro de la figura
    virtual double perimeter() const = 0;

    // Método virtual puro para trasladar la figura
    virtual void translate(double incX, double incY) = 0;

    // Método virtual puro para imprimir información de la figura
    virtual void print() = 0;
};

#endif // SHAPE_H

