#include <iostream>
using namespace std;

struct Nodo {
    int inf;
    Nodo* siguiente;
    Nodo* anterior;
};

int main() {
    // Crear lista de ejemplo
    Nodo* p = new Nodo{5, NULL, NULL};
    Nodo* nodo2 = new Nodo{3, NULL, NULL};
    Nodo* nodo3 = new Nodo{5, NULL, NULL};
    Nodo* nodo4 = new Nodo{7, NULL, NULL};
    Nodo* nodo5 = new Nodo{5, NULL, NULL};
    
    p->siguiente = nodo2;
    nodo2->anterior = p;
    nodo2->siguiente = nodo3;
    nodo3->anterior = nodo2;
    nodo3->siguiente = nodo4;
    nodo4->anterior = nodo3;
    nodo4->siguiente = nodo5;
    nodo5->anterior = nodo4;
    int dato_buscado = 5;
    int contador = 0;
    bool encontrado = false;
    Nodo* actual = p;
    while (actual !=NULL) {
        if (actual->inf== dato_buscado) {
            contador++;
            encontrado = true;
        }
        actual = actual->siguiente;
    }
    if (encontrado) {
        cout << "El dato " << dato_buscado << " aparece " << contador << " veces." << endl;
    } else {
        cout << "El dato " << dato_buscado << " no fue encontrado." << endl;
    }
    
    return 0;
}