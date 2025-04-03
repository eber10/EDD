#include<iostream>
using namespace std;
struct Nodo{
    int inf;
    Nodo* sig;
};
void recorrido(Nodo* p){
    if(p!=nullptr){
        cout<<p->inf<<" ";
        recorrido(p->sig);
    }
}

int main(){
    Nodo* p=nullptr;  // Lista vacía

    //primer nodo
    Nodo* q1= new Nodo();
    q1->inf=10;
    q1->sig=p;
    p=q1;
    // segundo nodo
    Nodo* q2= new Nodo();
    q2->inf=20;
    q2->sig=p;
    p=q2;
    // tercer nodo
    Nodo* q3=new Nodo();
    q3->inf=30;
    q3->sig=p;
    p=q3;
    Nodo* q=p;
    recorrido(q);
    return 0;
}