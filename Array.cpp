#include<iostream>
#include<string>
#include<windows.h>
using namespace std;
//datos desordenados
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

// arreglos ordenados 
int Buscar_Datos_Ord(int y[], int &m, int dat){
    int i=0, pos;
    while(i<m && y[i]<dat){
        i++;
    }
    if(i>=m || y[i]>dat){
            pos=-i;
    }else{
        pos=i;
    }
    return pos;
}
void Insercion_Datos_Ord(int y[], int &m, int Max, int dat){
    int pos;
    if(m<Max){
        pos=Buscar_Datos_Ord(y,m,dat);
        if(pos<=0){
            m++;
            pos*=-1;
            for(int i=m; i>=pos+1; i--){
                y[i]=y[i-1];
            }
            y[pos]=dat;
        }else{
            cout<<"Dato existente.."<<endl;
        }
    }else{
        cout<<"Arreglo lleno.."<<endl;
    }
}
void Eliminar_Datos_Ord(int y[], int &m, int dat){
    int pos;
    if(m>0){
        pos=Buscar_Datos_Ord(y,m,dat);
        if(pos>=0){
            m--;
            for(int i=pos; i<m; i++){
                y[i]=y[i+1];
            }
        }else{
            cout<<"Dato no existente.."<<endl;
        }
    }else{
        cout<<"Arreglo vacio.."<<endl;
    }
}
//ordenar array
void Ordenar_array(int y[], int m){
    for(int i=0; i<m-1; i++){
        for(int j=i+1; j<m; j++){
            if(y[i]>y[j]){
                int aux=y[i];
                y[i]=y[j];
                y[j]=aux;
            }
        }
    }
}
void Modificar_Datos_Ord(int y[], int &m, int dat, int dat2){
    int pos;
    if(m>0){
        pos=Buscar_Datos_Ord(y,m,dat);
        if(pos>=0){
            y[pos]=dat2;
            Ordenar_array(y,m);
        }else{
            cout<<"Dato no existente.."<<endl;
        }
    }else{
        cout<<"Arreglo vacio.."<<endl;
    }
}
int main(){
    SetConsoleOutputCP(CP_UTF8);
    const int Max=10;
    string x[Max]={"sheyla","david","angel","jose"}, dato, dato2;
    int y[Max]={10,20,30,40,50};
    int n=4, m=5, op1, op2, op3, dat, dat2, resultado;
    bool salir1=false, salir2=false, salir3=false;
    do{
        cout<<"----OPERACIONES CON ARREGLOS----"<<endl;
        cout<<"1. Arreglos desordenados        "<<endl;
        cout<<"2. Arreglos ordenados           "<<endl;
        cout<<"3. Salir                        "<<endl;
        cin>>op1;
        switch(op1){
            case 1:
                do{
                    cout<<"ARREGLOS DESORDENADOS"<<endl;
                    cout<<"---------------------"<<endl;
                    cout<<"1. Inserción         "<<endl;
                    cout<<"2. Eliminación       "<<endl;
                    cout<<"3. Modificación      "<<endl;
                    cout<<"4. salir             "<<endl;
                    cin>>op2;
                    switch(op2){
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
                            salir2=true;
                        default:
                            break;
                    }
                }while(!salir2);
                break;
            case 2:
                do{
                    cout<<"ARREGLOS ORDENADOS"<<endl;
                    cout<<"------------------"<<endl;
                    cout<<"1. Buscar         "<<endl;
                    cout<<"2. Inserción      "<<endl;
                    cout<<"3. Eliminación    "<<endl;
                    cout<<"4. Modificación   "<<endl;
                    cout<<"5. Salir          "<<endl;
                    cin>>op3;
                    switch(op3){
                        case 1:
                            cout<<"Ingrese el dato a buscar:"; cin>>dat;
                            resultado=Buscar_Datos_Ord(y,m,dat);
                            if(resultado<0){
                                resultado*=-1;
                                cout<<"Dato no existente.."<<endl;
                                cout<<"Posición esperado: "<<resultado<<endl;
                            }else{
                                cout<<"Dato existente.."<<endl;
                                cout<<"Posición: "<<resultado<<endl;
                            }
                            break;
                        case 2:
                            cout<<"Ingrese el dato a insertar: "; cin>>dat;
                            Insercion_Datos_Ord(y,m,Max,dat);
                            for(int i=0; i<m; i++){
                                cout<<y[i]<<" ";
                            }
                            cout<<endl;
                            break;
                        case 3:
                            cout<<"Ingrese el dato a eliminar:"; cin>>dat;
                            Eliminar_Datos_Ord(y,m,dat);
                            for(int i=0; i<m; i++){
                                cout<<y[i]<<" ";
                             }
                             cout<<endl;
                            break;
                        case 4:
                             cout<<"Ingrese el dato a modificar: "; cin>>dat;
                             cout<<"Ingrese el nuevo dato: "; cin>>dat2;
                             Modificar_Datos_Ord(y,m,dat,dat2);
                             for(int i=0; i<m; i++){
                                cout<<y[i]<<" ";
                            }
                            cout<<endl;

                            break;
                        case 5:
                            salir3=true;
                            break;
                        default:
                            break;
                    }
                }while(!salir3);
                break;
            case 3:
                salir1=true;
                break;
            default:
                break;
        }
    }while(!salir1);
    
    return 0; 
}