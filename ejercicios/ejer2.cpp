#include <iostream>
using namespace std;

struct Nodo {
    int inf;
    Nodo* siguiente;
    Nodo* anterior;
};

int main() {
    Nodo* p = new Nodo{1, NULL, NULL};
    Nodo* nodo2 = new Nodo{2, NULL, NULL};
    Nodo* nodo3 = new Nodo{3, NULL, NULL};
    
    p->siguiente = nodo2;
    nodo2->anterior = p;
    nodo2->siguiente = nodo3;
    nodo3->anterior = nodo2;
    Nodo* actual = p;
    Nodo* temp = NULL;
    while (actual != NULL) {
        temp = actual->anterior;
        actual->anterior = actual->siguiente;
        actual->siguiente = temp;
        actual = actual->anterior;
    }
    if (temp !=NULL) {
        p = temp->anterior;
    }
    actual = p;
    while (actual != nullptr) {
        cout << actual->inf<< " ";
        actual = actual->siguiente;
    }
    cout << endl; 
    return 0;
}