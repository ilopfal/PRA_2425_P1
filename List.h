#ifndef LIST_H//Esto nos evitará los errores de compilación correspondientes a una importación múltiple. 
#define LIST_H

#include <stdexcept> 
using namespace std; 

template <typename T>
class List {
public:
    // Lanza una excepción out_of_range si la posición pos no es válida (fuera del intervalo [0, size()]).
    virtual void insert(int pos, T e) = 0;

    // Inserta el elemento e al final de la lista.
    virtual void append(T e) = 0;

    // Inserta el elemento e al principio de la lista.
    virtual void prepend(T e) = 0;

    // Lanza una excepción out_of_range si la posición no es válida (fuera del intervalo [0, size()-1]).
    virtual T remove(int pos) = 0;

    // Devuelve el elemento situado en la posición pos.
    // Lanza una excepción out_of_range si la posición no es válida (fuera del intervalo [0, size()-1]).
    virtual T get(int pos) const = 0;

    // Devuelve la posición en la que se encuentra la primera ocurrencia del elemento e, o -1 si no se encuentra.
    virtual int search(T e) const = 0;

    // Indica si la lista está vacía.
    virtual bool empty() const = 0;

    // Devuelve el número de elementos de la lista.
    virtual int size() const = 0;

    // Destructor virtual para asegurar una correcta limpieza en clases derivadas.
    virtual ~List() {}
};

#endif // LIST_H

