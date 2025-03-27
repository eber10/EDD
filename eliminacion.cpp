#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
void Insertar(string x[], int &n, int Max, string dato){
    if(n<Max){
        x[n]=dato;
        n++;
    }else{
        cout<<"Array lleno"<<endl;
    }
}
void Eliminar(string x[], int &n, string dato){
    if(n!=0){
        int cen=0;
        int i=0;
        while((i<=n) && (cen==0)){
            if(dato==x[i]){
                n--;
                for(int j=i; j<n; j++){
                    x[j]=x[j+1];
                }
                cen=1;
            }else{
                i++;
            }
        }
        if(cen==0){
            cout<<"Dato no encontrado"<<endl;
        }
    }else{
        cout<<"Array vacio"<<endl;
    }
}
void Modificar(string x[], int &n, string dato, string dato2){
    if(n!=0){
        int cen=0;
        int i=0;
        while((i<=n)&&(cen==0)){
            if(dato==x[i]){
                x[i]=dato2;
                cen=1;
            }else{
                i++;
            }
        }
        if(cen==0){
            cout<<"Dato no encontrado para modificar"<<endl;
        }
    }else{
        cout<<"Array vacio"<<endl;
    }

}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    const int Max=10;
    string x[Max]={"sheyla","david","angel","jose"}, dato, dato2;
    int n=4, op;
    bool salir=false;
    do{
        cout<<"ARREGLOS DESORDENADOS"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"1. Inserción         "<<endl;
        cout<<"2. Eliminación       "<<endl;
        cout<<"3. Modificación      "<<endl;
        cout<<"4. salir             "<<endl;
        cin>>op;
        switch(op){
            case 1:
                cout<<"Ingrese el dato a insertar:"; cin>>dato;
                Insertar(x,n,Max,dato);
                for(int i=0; i<n; i++){
                    cout<<x[i]<<" ";
                }
                cout<<endl;
                break;
            case 2:
                cout<<"Ingrese el dato a eliminar:"; cin>>dato;
                Eliminar(x,n,dato);
                for(int i=0; i<n; i++){
                    cout<<x[i]<<" ";
                }
                cout<<endl;
                break;
            case 3:
            cout<<"Ingrese el dato a modificar:"; cin>>dato;
            cout<<"Ingresae el nuevo dato:"; cin>>dato2;
            Modificar(x,n,dato,dato2);
            for(int i=0; i<n; i++){
                cout<<x[i]<<" ";
            }
            cout<<endl;
                break;
            case 4:
                salir=true;
        }
    }while(!salir);
    
    return 0; 
}