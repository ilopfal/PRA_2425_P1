#ifndef LISTLINKED_H
#define LISTLINKED_H

#include <iostream>
#include <stdexcept>
#include "List.h"
#include "Node.h"

using namespace std;

template <typename T>
class ListLinked : public List<T> {
private:
    Node<T>* first; // Puntero al primer nodo de la lista
    int n; // Número de elementos en la lista

public:
    // Constructor sin argumentos
    ListLinked() : first(nullptr), n(0) {}

    // Destructor
    ~ListLinked() {
        Node<T>* current = first;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    // Sobrecarga del operador []
    T operator[](int pos) override {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Index out of range");
        }
        Node<T>* temp = first;
        for (int i = 0; i < pos; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    // Sobrecarga del operador de salida para imprimir la lista
    friend ostream& operator<<(ostream &out, const ListLinked<T> &list) {
        Node<T>* current = list.first;
        out << "[";
        while (current != nullptr) {
            out << current->data;
            if (current->next != nullptr) {
                out << ", ";
            }
            current = current->next;
        }
        out << "]";
        return out;
    }

};

#endif // LISTLINKED_H


