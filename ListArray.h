#ifndef LISTARRAY_H
#define LISTARRAY_H

#include <stdexcept>
#include <ostream>
#include "List.h"

using namespace std;

template <typename T>
class ListArray : public List<T> {
private:
    T* arr;  // Puntero al inicio del array que almacenará los elementos de la lista.
    int max; // Tamaño actual del array.
    int n;   // Número de elementos que contiene la lista.
    static const int MINSIZE = 2; // Tamaño mínimo del array.

    // Método privado que redimensiona el array al tamaño especificado.
    void resize(int new_size) {
        if (new_size < MINSIZE) {
            new_size = MINSIZE;
        }
        T* new_arr = new T[new_size];
        int copySize = (new_size < n) ? new_size : n;
        for (int i = 0; i < copySize; i++) {
            new_arr[i] = arr[i];
        }
        delete[] arr;
        arr = new_arr;
        max = new_size;
    }

public:
    // Constructor
    ListArray() : arr(new T[MINSIZE]), max(MINSIZE), n(0) {}

    // Destructor
    virtual ~ListArray() {
        delete[] arr;
    }

    // Inserta el elemento e en la posición pos.
    virtual void insert(int pos, T e) override {
        if (pos < 0 || pos > n) {
            throw out_of_range("Indice fuera de rango");
        }
        if (n == max) {
            resize(max * 2);
        }
        for (int i = n; i > pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos] = e;
        n++;
    }

    // Inserta el elemento e al final de la lista.
    virtual void append(T e) override {
        insert(n, e);
    }

    // Inserta el elemento e al principio de la lista.
    virtual void prepend(T e) override {
        insert(0, e);
    }

    // Elimina y devuelve el elemento situado en la posición pos.
    virtual T remove(int pos) override {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Indice fuera de rango");
        }
        T removedItem = arr[pos];
        for (int i = pos; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        if (max > MINSIZE && n < max / 4) {
            resize(max / 2);
        }
        return removedItem;
    }

    // Devuelve el elemento situado en la posición pos.
    virtual T get(int pos) const override {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Indice fuera de rango");
        }
        return arr[pos];
    }

    // Devuelve la posición en la que se encuentra la primera ocurrencia del elemento e.
    virtual int search(T e) const override {
        for (int i = 0; i < n; i++) {
            if (arr[i] == e) {
                return i;
            }
        }
        return -1;
    }

    // Indica si la lista está vacía.
    virtual bool empty() const override {
        return n == 0;
    }

    // Devuelve el número de elementos de la lista.
    virtual int size() const override {
        return n;
    }

    // Sobrecarga del operador de índice.
    T operator[](int pos) {
        if (pos < 0 || pos >= n) {
            throw out_of_range("Indice fuera de rango");
        }
        return arr[pos];
    }

    // Sobrecarga del operador de salida para imprimir la lista.
    friend ostream& operator<<(ostream &out, const ListArray<T> &list) {
        out << "[";
        for (int i = 0; i < list.n; i++) {
            out << list.arr[i];
            if (i < list.n - 1) out << ", ";
        }
        out << "]";
        return out;
    }
};

#endif // LISTARRAY_H

