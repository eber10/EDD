#include <iostream>
using namespace std;

struct Nodo {
    int inf;
    Nodo* siguiente;
    Nodo* anterior;
};

int main() {
    Nodo* p1 = new Nodo{1, NULL, NULL};
    Nodo* nodoA2 = new Nodo{3, NULL, NULL};
    Nodo* nodoA3 = new Nodo{5, NULL, NULL};
    
    p1->siguiente = nodoA2;
    nodoA2->anterior = p1;
    nodoA2->siguiente = nodoA3;
    nodoA3->anterior = nodoA2;
    Nodo* p2= new Nodo{2, NULL, NULL};
    Nodo* nodoB2 = new Nodo{4, NULL, NULL};
    Nodo* nodoB3 = new Nodo{6, NULL, NULL};
    p2->siguiente = nodoB2;
    nodoB2->anterior = p2;
    nodoB2->siguiente = nodoB3;
    nodoB3->anterior = nodoB2;
    Nodo* actualA = p1;
    Nodo* actualB = p2;
    Nodo* lista_mezclada = NULL;
    Nodo* ultimo_mezclado = NULL;
    while (actualA != NULL && actualB != NULL) {
        Nodo* seleccionado;
        
        if (actualA->inf <= actualB->inf) {
            seleccionado = actualA;
            actualA = actualA->siguiente;
        } else {
            seleccionado = actualB;
            actualB = actualB->siguiente;
        }
        seleccionado->anterior = NULL;
        if (lista_mezclada == NULL) {
            lista_mezclada = seleccionado;
            ultimo_mezclado = seleccionado;
        } else {
            ultimo_mezclado->siguiente = seleccionado;
            seleccionado->anterior = ultimo_mezclado;
            ultimo_mezclado = seleccionado;
        }
    }
    if (actualA != NULL) {
        ultimo_mezclado->siguiente = actualA;
        actualA->anterior = ultimo_mezclado;
    } else if (actualB != NULL) {
        ultimo_mezclado->siguiente = actualB;
        actualB->anterior = ultimo_mezclado;
    }
    Nodo* actual = lista_mezclada;
    while (actual != NULL) {
        cout << actual->inf<< " ";
        actual = actual->siguiente;
    }
    cout << endl;
    return 0;
}