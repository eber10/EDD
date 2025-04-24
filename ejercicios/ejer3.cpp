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
    Nodo* nodo3 = new Nodo{1, NULL, NULL};
    Nodo* nodo4 = new Nodo{7, NULL, NULL};
    
    p->siguiente = nodo2;
    nodo2->anterior = p;
    nodo2->siguiente = nodo3;
    nodo3->anterior = nodo2;
    nodo3->siguiente = nodo4;
    nodo4->anterior = nodo3;
    Nodo* menor = p;
    Nodo* actual = p->siguiente;
    
    while (actual !=NULL) {
        if (actual->inf< menor->inf) {
            menor = actual;
        }
        actual = actual->siguiente;
    }
    if (menor != p) {
        if (menor->anterior !=NULL) {
            menor->anterior->siguiente = menor->siguiente;
        }
        if (menor->siguiente !=NULL) {
            menor->siguiente->anterior = menor->anterior;
        }
        menor->anterior =NULL;
        menor->siguiente =p;
        p->anterior = menor;
        p= menor;
    }
    actual =p;
    while (actual !=NULL) {
        cout << actual->inf<< " ";
        actual = actual->siguiente;
    }
    cout << endl;
    return 0;
}