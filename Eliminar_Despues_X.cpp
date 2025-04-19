#include<iostream>
using namespace std;
struct Nodo{
    int inf;
    Nodo* sig;
};
void Lectura(Nodo* p){
    cout<<"\n------------lista------------\n";
    Nodo* lectura=p;
    while(lectura!=NULL){
        cout<<lectura->inf<<" -> ";
        lectura=lectura->sig;
    }
    cout<<endl;
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
    //eliminar un valor despues de un x.
    int x;
    cout<<"X: "; cin>>x;
    Nodo* q;
    Nodo* t;
    int cen;
    if(p!=NULL){
            q=p;
            t=p;
            cen=0;
            while(q->inf!=x && cen==0){
                if(q->sig!=NULL){
                    q=q->sig;
                    t=q;
                }else{
                    cen=1;
                }
            }
            if(cen==0){
                if(q->sig!=NULL){
                    t=q->sig;
                    q->sig=t->sig;
                    delete(t);
                }else{
                    cout<<"no existe un valor siguiente...\n";
                }
            }else{
                cout<<"no existe x... \n";
            }
    }else{
        cout<<"lista vacia...\n";
    }
    //lectura
    Lectura(p);
    return 0;
}