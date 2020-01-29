#pragma once
template<class T>
class Nodo{
private:
    T dato;
    Nodo* siguiente;
public:
    Nodo();
    Nodo(T);
    ~Nodo();
    T getDato();
    void setDato(T newDato);
    Nodo* getSiguiente();
    void setSiguiente(Nodo* newSiguiente);
    void borrarTodo();
    void imprimir();
protected:

};