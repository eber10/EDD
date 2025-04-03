#include<iostream>
using namespace std;
struct Nodo{
    int inf;
    Nodo* sig;
};
int main(){
    Nodo* p=nullptr;
    Nodo* r;
    char op;
    do{
        Nodo* q=new Nodo();
        cout<<"Ingrese un valor: "; cin>>q->inf;
        q->sig=nullptr;
        if(p==nullptr){
            p=q;
        }else{
            r->sig=q;
        }
        r=q;
        cout<<"Desea ingresar mas datos? (s:si/n:no):"; cin>>op;
    }while(op=='s');
    Nodo* actual =p;
    while (actual != nullptr) {
        cout << actual->inf<< " ";
        actual = actual->sig;
    }
    return 0;
}