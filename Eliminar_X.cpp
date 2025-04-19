#include<iostream>
using namespace std;
struct Nodo{
    int inf;
    Nodo* sig;
};
void Lectura(Nodo* p){
    Nodo* lectura=p;
    cout<<"\n--------------------------------\n";
    while(lectura!=NULL){
        cout<<lectura->inf<<" -> ";
        lectura=lectura->sig;
    }
}
int main(){
    Nodo* p=new Nodo{10,NULL};
    Nodo* q1=new Nodo{20,NULL};
    Nodo* q2=new Nodo{30,NULL};
    Nodo* q3=new Nodo{40,NULL};
    Nodo* q4=new Nodo{50,NULL};
    p->sig=q1;
    q1->sig=q2;
    q2->sig=q3;
    q3->sig=q4;
    //lectura
    Lectura(p);
    Nodo* q;
    Nodo* r;
    int cen, x;
    cout<<"\nIngrese x: "; cin>>x;
    if(p!=NULL){
        q=p;
        cen=0;
        while(q->inf!=x and cen==0){
            if(q->sig!=NULL){
                r=q;
                q=q->sig;
            }else{
                cen=1;
            }
        }
        if(cen==0){
            if(p==q){
                p=p->sig;
            }else{
                r->sig=q->sig;
            }
            delete(q);
        }else{
            cout<<"No existe x...\n";
        }
    }else{
        cout<<"lista vacia...\n";
    }
    //Lectura
    Lectura(p);
    return 0;
}