#include<iostream>
using namespace std;
struct nodo{
    char nombre[20];
    nodo *sig;
};
nodo *crea_i(nodo *);
nodo *crea_f(nodo *);
void recorre(nodo *);
nodo *inserta_i(nodo *);
nodo *inserta_f(nodo *);
nodo *inserta_ad(nodo *, char *);
nodo *inserta_dd(nodo *, char *);
nodo *eliminar_p(nodo *);
nodo *eliminar_u(nodo *);
nodo *eliminar_x(nodo *, char *);
nodo *eliminar_ad(nodo *, char *);
nodo *eliminar_dd(nodo *, char *);
int main(){
    char codigo[10];
    nodo *p=NULL;
    int op;
    do{
        system("cls");
        cout<<"\nLISTAS ENLAZADAS";
        cout<<"\n================";
        cout<<"\n\n1. CREAR POR EL INICIO";
        cout<<"\n\n2. CREAR POR EL FINAL";
        cout<<"\n\n3. INSERTAR AL INICIO";
        cout<<"\n\n4. INSERTAR AL FINAL";
        cout<<"\n\n5. INSERTAR ANTES DE";
        cout<<"\n\n6. INSERTAR DESPUES DE";
        cout<<"\n\n7. ELIMINAR EL PRIMERR NODO";
        cout<<"\n\n8. ELIMINAR EL ULTIMO NODO";
        cout<<"\n\n9. ELIMINAR UN NODO ESPECIFICO";
        cout<<"\n\n10. ELIMINAR EL NODO ANTERIOR A";
        cout<<"\n\n11. ELIMINAR EL NODO POSTERIOR A";
        cout<<"\n\n12.  M O S T R A R";
        cout<<"\n\n13.  S A L I R";
        cout<<"\n\n\t\t\t. OPCION:";
        cin>>op;
        switch(op){
            case 1:
                system("cls");
                p=NULL;
                p=crea_i(p);
                break;
            case 2:
                system("cls");
                p=NULL;
                p=crea_f(p);
                break;
            case 3:
                system("cls");
                p=inserta_i(p);
                break;
            case 4:
                system("cls");
                p=inserta_f(p);
                break;
            case 5:
                cout<<"Dato de Referencia: "; cin>>co
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                system("cls");
                recorre(p);
                system("pause");
                break;
            case 13:
                break;
        }
    }while(op>0 && op<13);
    return 0;
}
nodo *crea_i(nodo *p){
    nodo *q;
    char op;
    do{
        system("cls");
        q=new(nodo);
        cout<<"\n\nNOMBRE : "; cin>>q->nombre;
        q->sig=p;
        p=q;
        cout<<"\n\n\t\t\tMAS DATOS (S/N)? "; cin>>op;
    }while(op=='s' or op=='S');
    return (p);
}
nodo *crea_f(nodo *p){
    nodo *q, *r;
    char op;
    do{
        system("cls");
        q=new(nodo);
        cout<<"\n\nNOMBRE : "; cin>>q->nombre;
        q->sig=NULL;
        if(p==NULL){
            p=q;
        }else{
            r->sig=q;
        }
        r=q;
        cout<<"\n\n\n\t\tMAS DATOS (S/N)? "; cin>>op;
    }while(op=='s' or op=='S');
    return (p);

}
nodo *inserta_i(nodo *p)
{
    nodo *q;
    system("cls");
    cout << "\n\nINSERTANDO DATO POR EL INICIO ... ";
    q = new(nodo);
    cout << "\n\nNOMBRE     :  ";
    cin >> q->nombre;
    q->sig = p;
    p = q;
    return(p);
}

nodo *inserta_f(nodo *p)
{
    nodo *q, *r;
    system("cls");
    cout << "\n\nINSERTANDO DATO POR EL FINAL ... ";
    q = new(nodo);
    cout << "\n\nNOMBRE     :  ";
    cin >> q->nombre;
    q->sig = NULL;
    r = p;
    if (p == NULL)
        p = q;
    else
    {
        while (r->sig != NULL)
            r = r->sig;
        r->sig = q;
    }
    return(p);
}

void recorre(nodo *p){
    nodo *q;
    system("cls");
    q=p;
    cout<<"\n\n\tLISTA DE DATOS: \n";
    cout<<"\t======================";
    while(q!=NULL){
        cout<<"\n\n\t\t"<<q->nombre;
        q=q->sig;
    }
    cout<<"\n\n\t\t\t";
}

nodo *inserta_ad(nodo *p, char *codigo){
    nodo *r;
    nodo *s;
    int cen;
    if(p!=NULL){
        r=p;
        cen=0;
        while(r->nombre!=codigo and cen==0){
            if(r->sig!=NULL){
                s=r;
                r=r->sig;
            }else{
                cen=1;
            }
        }
        if(cen==0){
            nodo *q;
            cout<<"Ingres un valor: "; cin>>q->nombre;
            if(p==r){
                p=q;
            }else{
                s->sig=q;
            }
            q->sig=r;
        }else{
            cout<<"no existe el dato referencia en la lista...\n";
        }

    }else{
        cout<<"lista vacia...\n";
    }
}
nodo *inserta_dd(nodo *, char *);
nodo *eliminar_p(nodo *);
nodo *eliminar_u(nodo *);
nodo *eliminar_x(nodo *, char *);
nodo *eliminar_ad(nodo *, char *);
nodo *eliminar_dd(nodo *, char *);