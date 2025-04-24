#include <iostream>
using namespace std;

struct Nodo {
    int inf;
    Nodo* siguiente;
    Nodo* anterior;
};

int main() {
    Nodo* p= new Nodo{1, NULL,NULL};
    Nodo* nodo2 = new Nodo{2, NULL, NULL};
    Nodo* nodo3 = new Nodo{2, NULL, NULL};
    Nodo* nodo4 = new Nodo{3, NULL, NULL};
    Nodo* nodo5 = new Nodo{3, NULL, NULL};
    
    p->siguiente = nodo2;
    nodo2->anterior = p;
    nodo2->siguiente = nodo3;
    nodo3->anterior = nodo2;
    nodo3->siguiente = nodo4;
    nodo4->anterior = nodo3;
    nodo4->siguiente = nodo5;
    nodo5->anterior = nodo4;
    Nodo* actual = p;
    while (actual !=NULL && actual->siguiente !=NULL) {
        if (actual->inf== actual->siguiente->inf) {
            Nodo* duplicado = actual->siguiente;
            actual->siguiente = duplicado->siguiente;
            if (duplicado->siguiente !=NULL) {
                duplicado->siguiente->anterior = actual;
            }
            delete duplicado;
        } else {
            actual = actual->siguiente;
        }
    }
    actual = p;
    while (actual != NULL) {
        cout << actual->inf<< " ";
        actual = actual->siguiente;
    }
    cout << endl;
    return 0;
}