#include <iostream>
using namespace std;
struct Nodo {
    int inf;
    Nodo* LigDer;
    Nodo* LigaIzq;
};
int main() {
    Nodo* p= new Nodo{10, NULL, NULL};
    Nodo* q1 = new Nodo{20, NULL, NULL};
    Nodo* q2 = new Nodo{30, NULL, NULL};
    Nodo* q3 = new Nodo{40, NULL, NULL};
    Nodo* f=q3;
    p->LigDer=q1;
    q1->LigDer=q2;
    q2->LigDer=q3;
    q1->LigaIzq=p;
    q2->LigaIzq=q1;
    q3->LigaIzq=q2;
    Nodo* q=f;
    while(q!=NULL){
        cout<<q->inf<<" -> ";
        q=q->LigaIzq;
    }
    
    return 0;
}
