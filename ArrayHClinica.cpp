#include<iostream>
#include<string.h>
#include<windows.h>
#define Max 5
char hclinica[10];
using namespace std;
struct Paciente{
    char hc[15], nomb[20];
    float peso, talla,imc;
};
void inserta_d(Paciente [],int &);
void eliminar_d(Paciente [],int &);
void modifica_d(Paciente [],int &);
int  buscar_o(Paciente [],int);
void inserta_o(Paciente [],int &);
void elimina_o(Paciente [],int &);
void modifica_o(Paciente [],int &);
void mostrar(Paciente [],int);

int main(){
    SetConsoleOutputCP(CP_UTF8);
    Paciente x[Max]={{"HC12", "Ana", 55, 1.60, 28.3},
                    {"HC14", "Luis", 70, 1.75, 29.5},
                    {"HC16", "María", 62, 1.68, 27.5},
                    {"HC18", "Carlos", 80, 1.82, 30.1}
                    };
    int op, opc,n=3,i;
    int pos;
    do{
        system("cls");
        cout<<"\nM  E  N  U";
        cout<<"\n==========";
        cout<<"\n\n1. ARRAY DESORDENADOS....";
        cout<<"\n\n2. ARRAY ORDENADOS....";
        cout<<"\n\n3. S A L I R";
        cout<<"\n\n\t\tOPCIÓN:"; cin>>op;
        switch(op){
            case 1:
                do{
                    system("cls");
                    cout<<"\n\n\nARREGLOS DESORDENADOS";
                    cout<<"\n=========================";
                    cout<<"\n\n1. INSERTAR";
                    cout<<"\n\n2. ELIMINAR";
                    cout<<"\n\n3. MODIFICAR";
                    cout<<"\n\n4. MOSTRAR";
                    cout<<"\n\n5. S A L I R";
                    cout<<"\n\n\t\t\t OPCIÓN:"; cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1:
                            inserta_d(x,n);
                            mostrar(x,n);
                            break;
                        case 2:
                            eliminar_d(x,n);
                            mostrar(x,n);
                            break;
                        case 3:
                            modifica_d(x,n);
                            mostrar(x,n);
                            break;
                        case 4:
                            mostrar(x,n);
                            break;
                        case 5:
                            break;
                    }
                }while(opc>0&&opc<5);
                break;
            case 2:
                do{
                    system("cls");
                    cout<<"\n\n\nARREGLOS ORDENADOS";
                    cout<<"\n=========================";
                    cout<<"\n\n1. BUSCAR";
                    cout<<"\n\n2. INSERTAR";
                    cout<<"\n\n3. ELIMINAR";
                    cout<<"\n\n4. MODIFICAR";
                    cout<<"\n\n5. S A L I R";
                    cout<<"\n\n\t\t\t OPCIÓN:"; cin>>opc;
                    system("cls");
                    switch(opc){
                        case 1:
                            pos = buscar_o(x, n);
                            if(pos<0){
                                pos=-pos-1;
                                cout << "\n\nPaciente NO encontrado. Posición destinada en la lista: " <<pos+1 << "\n";
                            }else{
                                cout << "\n\n\t\tPACIENTE ENCONTRADO: \n\n";
                                cout<<"\t\t===========================\n\n";
                                cout<<"\nx["<<pos+1<<"]:\n\n";
                                cout<<"\n\n\t\tHISTORIA CLINICA : "<<x[pos].hc;
                                cout<<"\n\n\t\tNOMBRE   : "<<x[pos].nomb;
                                cout<<"\n\n\t\tPESO     : "<<x[pos].peso;
                                cout<<"\n\n\t\tTALLA    : "<<x[pos].talla;
                                cout<<"\n\n\t\tPROMEDIO : "<<x[pos].imc<<endl;
                            }
                            system("pause");
                            break;
                        case 2:
                            inserta_o(x,n);
                            break;
                        case 3:     
                            elimina_o(x,n);
                            mostrar(x,n);
                            break;
                        case 4:
                            modifica_o(x,n);
                            break;
                        case 5:
                            break;
                    }
                }while(opc>0&&opc<5);
                break;
            case 3:
                break;
        }
    }while(op>0&&op<3);
    return 0;
}
void inserta_d(Paciente x[],int &n){
    int i,j,cen;
    if(n<Max-1){
        cen=0;
        i=0;
        cout<<"\n\n\nDATOS DEL REGISTRO A INSERTAR:"; cout<<"\n\n\t\tHISTORIA CLÍNICA:"; cin>>hclinica;
        if(n>-1){
            while((i<=n)&&(cen==0)){
                if(strcmp(x[i].hc,hclinica)==0){
                    cen=1;
                }else{
                    i++;
                }
            }
        }
        if(cen==0){
            n=n+1;
            strcpy(x[i].hc,hclinica);
            cout<<"\n\n\t\tNOMBRE: ";cin>>x[i].nomb;
            cout<<"\n\n\t\tPESO: ";cin>>x[i].peso;
            cout<<"\n\n\t\tTALLA: ";cin>>x[i].talla;
            x[i].imc=(x[i].peso+x[i].talla)/2;
            cout<<"\n\n\t\tINDICE MASA CORPORAL:"<<x[i].imc;
        }else{
            cout<<"\n\n\n\nEL DATO YA ESTA REGISTRADO EN LA BASE DE DATOS. No se realizo la inserción......";
        }   
    }else{
        cout<<"\n\n\t\tEL ARREGLO ESTA LLENO. PELIGRO DE DESBORDAMIENTO. No se inserto nigún dato.....";
    }
}
void eliminar_d(Paciente x[],int &n){
    int i,j,cen;
    cout<<"\n\n\tDATO A ELIMINAR: \n\n";
    cout<<"\tHISTORIA CLINICA: ";cin>>hclinica;
    if(n>-1){
        i=0;
        cen=0;
        while((i<=n)&&(cen==0)){
            if(strcmp(x[i].hc,hclinica)==0){
                cen=1;
                n--;
                for(j=i; j<=n; j++){
                    x[j]=x[j+1];
                }
            }else{
                i++;
            }
        }
        if(cen==0){
            cout<<"\n\n\t\t"<<hclinica<<" NO ESTA EN EL ARREGLO\n\n";
        }
    }else{
        cout<<"\n\n\nEL ARREGLO ESTA VACIO....\n\n\n";
        system("cls");
    }
}
void modifica_d(Paciente x[],int &n){
    int i,cen,op;
    char hc1[10];
    cout<<"\n\t\tCODIGO DEL REGISTRO A MODIFICAR: \n\n";
    cout<<"\tHISTORIA CLINICA :";cin>>hc1;
    if(n>-1){
        i=0;
        cen=0;
        while((i<=n)&&(cen==0)){
            if(strcmp(x[i].hc,hc1)==0){
                cen=1;
                cout<<"\n\n\tQUE CAMPO DESEA MODIFICAR? \n\n";
                cout<<"1. HISTORIA CLINICA  2. NOMBRE   3. PESO 4.TALLA \n\n";
                cout<<"OPCIÓN:";cin>>op;
                switch(op){
                    case 1:
                        cout<<"\nINGRESA LA HISTORIA CLINICA CORRECTA:  ";cin>>x[i].hc;
                        break;
                    case 2:
                        cout<<"\nINGRESA EL NOMBRE CORRECTO: ";cin>>x[i].nomb;
                        break;
                    case 3:
                        cout<<"\nINGRESA EL PESO CORRECTO: "; cin>>x[i].peso;
                        x[i].imc=x[i].peso/(x[i].talla*x[i].talla);
                        break;
                    case 4:
                        cout<<"\nINGRESA LA TALLA CORRECTA: ";cin>>x[i].talla;
                        x[i].imc=x[i].peso/(x[i].talla*x[i].talla);
                        break;
                }
            }else{
                i++;
            }
        }
        if(cen==0){
            cout<<"\n\n\t\tLA HISTORIA CLINICA"<<hc1<<" NO ESTA EN EL ARREGLO \n\n";
            system("pause");
        }
    }else{
        cout<<"\n\n\nEL ARREGLO ESTA VACIO...\n\n\n";
        system("pause");
    }
}
int buscar_o(Paciente x[], int n) {
   int i,pos;
    if(n>-1){
        i=0;
        cout<<"\n\n\nDATOS DEL REGISTRO:"; cout<<"\n\nHISTORIA CLÍNICA:"; cin>>hclinica;
        while((i<=n)&&(strcmp(x[i].hc, hclinica) < 0)){
                i++;
        }
        if((i>n)or(strcmp(x[i].hc, hclinica) > 0)){
            pos=-(i+1);
        }else{
            pos=i;
        }
        return pos;
    }else{
        system("pause");
        cout<<"ARREGLO VACIO....."<<endl;
    }
}
/*
void inserta_o(Paciente x[],int &n){
    int pos;
    if(n<Max-1){
        pos=buscar_o(x,n);
        pos=-pos-1;
        if(pos<=0){
            n++;
            pos*=-1;
            for(int i=n; i>=pos+1; i--){
                x[i]=x[i-1];
            }
            strcpy(x[pos].hc,hclinica);
            cout<<"\n\n\t\tNOMBRE: ";cin>>x[pos].nomb;
            cout<<"\n\n\t\tPESO: ";cin>>x[pos].peso;
            cout<<"\n\n\t\tTALLA: ";cin>>x[pos].talla;
            x[pos].imc=(x[pos].peso+x[pos].talla)/2;
            cout<<"\n\n\t\tINDICE MASA CORPORAL:"<<x[pos].imc;
            mostrar(x,n);
        }else{
            cout<<"HISTORIA CLINICA EXISTENTE....\n\n";
        }
    }else{
        cout<<"ARREGLO LLENO, LIBERE ESPACIO....\n";
        cout<<"-------------------------------\n\n";
        system("pause");
    }
}*/
void inserta_o(Paciente x[], int &n){
    int pos;
    if(n < Max - 1){
        if(n!=-1){
            pos = buscar_o(x, n);
             if(pos >= 0){
                cout << "\n\n\t\tHISTORIA CLÍNICA YA EXISTE. NO SE REALIZÓ LA INSERCIÓN.\n";
                system("pause");
                return;
            }
            pos = -pos - 1; // Convertimos posición de inserción
            n++;
            for(int i = n; i > pos; i--){
                x[i] = x[i - 1];
            }
            strcpy(x[pos].hc, hclinica);
            cout << "\n\n\t\tNOMBRE: "; cin >> x[pos].nomb;
            cout << "\n\n\t\tPESO: "; cin >> x[pos].peso;
            cout << "\n\n\t\tTALLA: "; cin >> x[pos].talla;
            x[pos].imc = (x[pos].peso + x[pos].talla) / 2;
            cout << "\n\n\t\tINDICE MASA CORPORAL:" << x[pos].imc;
            mostrar(x, n);
        }else{
            cout << "\n\n\t\tHISTORIA CLINICA: "; cin >> x[0].hc;
            cout << "\n\n\t\tNOMBRE: "; cin >> x[0].nomb;
            cout << "\n\n\t\tPESO: "; cin >> x[0].peso;
            cout << "\n\n\t\tTALLA: "; cin >> x[0].talla;
            x[0].imc = (x[0].peso + x[0].talla) / 2;
            cout << "\n\n\t\tINDICE MASA CORPORAL:" << x[0].imc;
            n++;
        }
    } else {
        cout << "ARREGLO LLENO, LIBERE ESPACIO....\n";
        system("pause");
    }
}

void elimina_o(Paciente x[],int &n){
    int pos;
    if(n>-1){
        pos=buscar_o(x,n);
        if(pos>=0){
            n--;
            for(int i=pos; i<=n; i++){
                x[i]=x[i+1];
            }
        }else{
            cout<<"HISTORIA CLINICA NO EXISTENTE...\n\n";
        }
    }else{
        cout<<"ARREGLO VACIO...\n\n";
    }
}
void ordenar(Paciente x[],int n){
    for(int i=0; i<=n-1; i++){
        for(int j=i+1; j<=n; j++){
            if(strcmp(x[i].hc, x[j].hc) > 0){
                Paciente aux=x[i];
                x[i]=x[j];
                x[j]=aux;
            }
        }
    }
}
void modifica_o(Paciente x[], int &n){
    int pos, op;
    if(n>-1){
        pos=buscar_o(x,n);
        if(pos>0){
            /*
            strcpy(x[pos].hc, hclinica);
            cout << "\n\n\t\tNOMBRE: "; cin >> x[pos].nomb;
            cout << "\n\n\t\tPESO: "; cin >> x[pos].peso;
            cout << "\n\n\t\tTALLA: "; cin >> x[pos].talla;
            x[pos].imc = (x[pos].peso + x[pos].talla) / 2;
            cout << "\n\n\t\tINDICE MASA CORPORAL:" << x[pos].imc;*/
            
            cout<<"\n\n\tQUE CAMPO DESEA MODIFICAR? \n\n";
            cout<<"1. HISTORIA CLINICA  2. NOMBRE   3. PESO 4.TALLA \n\n";
            cout<<"OPCIÓN:";cin>>op;
            switch(op){
                case 1:
                    cout<<"\nINGRESA LA HISTORIA CLINICA CORRECTA:  ";cin>>x[pos].hc;
                    break;
                case 2:
                    cout<<"\nINGRESA EL NOMBRE CORRECTO: ";cin>>x[pos].nomb;
                    break;
                case 3:
                    cout<<"\nINGRESA EL PESO CORRECTO: "; cin>>x[pos].peso;
                    x[pos].imc=x[pos].peso/(x[pos].talla*x[pos].talla);
                    break;
                case 4:
                    cout<<"\nINGRESA LA TALLA CORRECTA: ";cin>>x[pos].talla;
                    x[pos].imc=x[pos].peso/(x[pos].talla*x[pos].talla);
                    break;
            }
            ordenar(x,n);
            mostrar(x, n); 
        }else{
            cout<<"HISTORIA CLINICA NO EXISTENTE...\n\n";
        }
    }else{
        cout<<"ARREGLO VACIO...\n\n";
    }
}
void mostrar(Paciente x[],int n){
    int i;
    if(n>-1){
        cout<<"\n\n\t\t-----------ARREGLO DE PACIENTES----------\n\n\t\t";
        for(i=0; i<=n; i++){
            cout<<"\nx["<<i+1<<"]:\n\n";
            cout<<"\n\n\t\tHISTORIA CLINICA : "<<x[i].hc;
            cout<<"\n\n\t\tNOMBRE   : "<<x[i].nomb;
            cout<<"\n\n\t\tPESO     : "<<x[i].peso;
            cout<<"\n\n\t\tTALLA    : "<<x[i].talla;
            cout<<"\n\n\t\tPROMEDIO : "<<x[i].imc;
        }
        cout<<"\n\n";
        system("pause");
    }else{
        cout<<"HISTORIA CLINICA VACIA...\n\n";
        system("pause");
    }
    
}


