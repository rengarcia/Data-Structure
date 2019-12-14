#include <iostream>
#include <string>
#include "Elemento.h"
#include "Cola.h"

using namespace std;

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
