#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <cmath> // Para funciones sqrt() y pow()

using namespace std; // Uso del espacio de nombres estándar de C++

class Point2D {
public:
    double x; // Coordenada x
    double y; // Coordenada y

    // Constructor por defecto y parametrizado
    Point2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Calcula la distancia euclidiana entre dos puntos
    static double distance(const Point2D &a, const Point2D &b) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }

    // Sobrecarga del operador == para comparar dos puntos
    friend bool operator==(const Point2D &a, const Point2D &b) {
        return (a.x == b.x) && (a.y == b.y);
    }

    // Sobrecarga del operador != para comparar si dos puntos son diferentes
    friend bool operator!=(const Point2D &a, const Point2D &b) {
        return !(a == b);
    }

    // Sobrecarga del operador << para imprimir un punto
    friend ostream& operator<<(ostream &out, const Point2D &p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

#endif // POINT2D_H


