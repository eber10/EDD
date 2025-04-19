#include<iostream>
using namespace std;
struct Nodo{
    int inf;
    Nodo* sig;
};
void Lectura(Nodo* p){
    Nodo* lectura=p;
    cout<<"\n----------------------------\n";
    while(lectura!=NULL){
        cout<<lectura->inf<<" -> ";
        lectura=lectura->sig;
    }
}
int main(){
    Nodo* p=new Nodo{1,NULL};
    Nodo* q1=new Nodo{3,NULL};
    Nodo* q2=new Nodo{1,NULL};
    Nodo* q3=new Nodo{7,NULL};
    Nodo* q4=new Nodo{1,NULL};
    Nodo* q5=new Nodo{1,NULL};
    Nodo* q6=new Nodo{3,NULL};
    Nodo* q7=new Nodo{1,NULL};
    p->sig=q1;
    q1->sig=q2;
    q2->sig=q3;
    q3->sig=q4;
    q4->sig=q5;
    q5->sig=q6;
    q6->sig=q7;
    //lectura
    Lectura(p);
    //eliminar ocurrencia
    Nodo* q;
    Nodo* r;
    Nodo* t;
    int x;
    cout<<"\nX: "; cin>>x;
    if(p!=NULL){
        q=p;
        while(q!=NULL){
            if(q->inf==x){
                t=q;
                if(p==q){
                    p=q->sig;
                    q=p;
                }else{
                    r->sig=q->sig;
                    q=q->sig;
                }
                delete(t);
            }else{
                r=q;
                q=q->sig;
            }
        }
    }else{
        cout<<" lista vacia...\n";
    }
    Lectura(p);
    return 0;
}