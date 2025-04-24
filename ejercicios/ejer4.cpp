#include <iostream>
using namespace std;

struct Nodo {
    int inf;
    Nodo* siguiente;
    Nodo* anterior;
};

int main() {
    Nodo* p= new Nodo{5, NULL, NULL};
    Nodo* nodo2 = new Nodo{3, NULL, NULL};
    Nodo* nodo3 = new Nodo{9, NULL, NULL};
    Nodo* nodo4 = new Nodo{7, NULL, NULL};
    
    p->siguiente = nodo2;
    nodo2->anterior = p;
    nodo2->siguiente = nodo3;
    nodo3->anterior = nodo2;
    nodo3->siguiente = nodo4;
    nodo4->anterior = nodo3;
    Nodo* mayor = p;
    Nodo* actual = p->siguiente;
    
    while (actual !=NULL) {
        if (actual->inf> mayor->inf) {
            mayor = actual;
        }
        actual = actual->siguiente;
    }
    if (mayor != p) {
        if (mayor->anterior != NULL) {
            mayor->anterior->siguiente = mayor->siguiente;
        }
        if (mayor->siguiente !=NULL) {
            mayor->siguiente->anterior = mayor->anterior;
        }
        mayor->anterior =NULL;
        mayor->siguiente =p;
        p->anterior = mayor;
        p= mayor;
    }
    actual = p;
    while (actual != NULL) {
        cout << actual->inf<< " ";
        actual = actual->siguiente;
    }
    cout<<endl;
    return 0;
}