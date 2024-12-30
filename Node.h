#ifndef NODE_H
#define NODE_H

#include <ostream>
using namespace std;

template <typename T>
class Node {
public:
    T data; // El elemento almacenado de tipo genérico T
    Node<T>* next; // Puntero al siguiente nodo en la lista

    // Constructor
    Node(T data, Node<T>* next = nullptr) : data(data), next(next) {}

    friend ostream& operator<<(ostream &out, const Node<T> &node) {
        out << node.data;
        return out;
    }
};

#endif // NODE_H

