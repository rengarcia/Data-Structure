#include <iostream>
#include <string>

using namespace std;

class Elemento {
public:
    int dato;
    Elemento* siguiente;
    Elemento() : dato(0), siguiente(NULL) {
    } 
};

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

int main() {
    Cola* stack = new Cola();
    stack->total = 15;
    cout << "Llenando la cola" << endl;
    for (int i = 0; i < 10; i++) {
        Elemento* node = new Elemento();
        node->dato = i + 1;
        cout <<"insertando: " <<i + 1 << endl;
        stack->push(node);
    }
    cout << "Vaciando cola" << endl;
    Elemento * c = stack->pop();
    while (c != NULL) {
        cout << c->dato << endl;
        c = stack->pop();
    }

    return 0;
}
