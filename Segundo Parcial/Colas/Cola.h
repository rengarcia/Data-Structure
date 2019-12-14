#include "Elemento.h"
#include <iostream>
using namespace std;
class Cola {
public:
    Elemento* tope;
    Elemento* cola;
    int total;
    int elementos_existentes = 0;
    Cola() : tope(NULL), cola(NULL), total(0) {
    }

    Cola(int n) {
        this->tope = NULL;
        this->cola = NULL;
        this->total = n;
    }

    Elemento* pop() {
        if (this->elementos_existentes > 0) {
            Elemento* sacarme = this->tope;
            this->tope = sacarme->siguiente;
            this->elementos_existentes -= 1;
            return sacarme;
        } else {
            cout << "Nada para sacar" << endl;
            return NULL;
        }
    }

    void push(Elemento* nuevo) {
        if (this->total >= this->elementos_existentes) {
            if (this->elementos_existentes == 0) {
                this->tope = this->cola = nuevo;
            } else {
                this->cola->siguiente = nuevo;
                this->cola = nuevo;
            }

            this->elementos_existentes += 1;
        } else {
            cout << "Error! cola llena" << endl;
        }
    }
};
