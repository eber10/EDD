#include <iostream>
#include <string>
#include <windows.h>
#define MAX 10 // Tamaño máximo de la cola y pila
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Pila{
    private:
        int elementos[MAX];
        int tope;
    public:
        Pila();
        bool pilaVacia();
        bool pilaLlena();
        void agregarPila(int dato);
        char sacarPila();
        char cima();
        void mostrarPila();
};
// Constructor
Pila::Pila(){
    tope=-1; // Pila vacía
}
// Método para verificar si la pila está vacía
bool Pila::pilaVacia(){
    if(tope==-1){
        return true;
    }else{
        return false;
    }
}
// Método para verificar si la pila está llena
bool Pila::pilaLlena(){
    if(tope==MAX-1){
        return true;
    }else{
        return false;
    }
}
// Método para agregar un elemento a la pila (push)
void Pila::agregarPila(int dato){
    if (pilaLlena()){
        cout<<"Desbordamiento - Pila llena. No se puede agregar más elementos."<<endl;
        return;
    }else{
        tope++;
        elementos[tope]=dato;
    }
}
// Método para eliminar el elemento superior de la pila (pop)
char Pila::sacarPila(){
    if (pilaVacia()){
        cout<<"Subdesbordamiento - Pila vacía. No se puede sacar elemento."<<endl;
        return (0); // Carácter nulo
    }else{
        char dato=elementos[tope];
        tope--;
        return dato;
    }
}

// Método para ver el elemento en la cima de la pila (peek)
char Pila::cima(){
    if (!pilaVacia()){
        return elementos[tope];
    }else{
        cout<<"Pila vacía."<<endl;
        return -1;
    }
}
// Método para mostrar todos los elementos de la pila
void Pila::mostrarPila(){
    if (pilaVacia()){
        cout<<"Pila vacía."<<endl;
        return;
    }else{
        cout<<"Elementos de la pila (de arriba hacia abajo):"<<endl;
        for (int i=tope; i>=0; i--){
            cout<<elementos[i]<<" ";
        }
        cout<<endl;
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class Cola
{
private:
    int elementos[MAX];
    int frente;
    int final;

public:
    Cola();
    bool colaVacia();
    bool colaLlena();
    void insertarCola(int dato);
    int eliminarCola();
    int verFrente();
    void mostrarCola();
    int contarElementos();
    bool buscarElemento(int dato);
    void invertirCola();
    void eliminarColaX();
};

// Constructor: Inicializa la cola vacía
Cola::Cola()
{
    frente = -1;
    final = -1;
}
// Verifica si la cola está vacía
bool Cola::colaVacia()
{
    if (frente == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// Verifica si la cola está llena
bool Cola::colaLlena()
{
    if (final == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Agrega un elemento a la cola
void Cola::insertarCola(int dato)
{
    if (!colaLlena())
    { // Verifica que hay espacio libre
        if (colaVacia())
        { // Se insertará el primer elemento en la cola
            frente = 0;
            final = 0;
        }
        else
        {
            final++;
        }
        elementos[final] = dato;
    }
    else
    {
        cout << "Desbordamiento - La cola está llena.\n";
        return;
    }
}
// Elimina un elemento de la cola
int Cola::eliminarCola()
{
    if (!colaVacia())
    {
        int dato = elementos[frente];
        if (frente == final)
        {
            frente = -1;
            final = -1;
        }
        else
        {
            frente++;
        }
        return dato;
    }
    else
    {
        cout << "Cola vacía.\n";
        return -1;
    }
}
// Muestra el primer elemento de la cola
int Cola::verFrente()
{
    if (!colaVacia())
    {
        return elementos[frente];
    }
    else
    {
        cout << "Cola vacía.\n";
        return -1;
        
    }
}
// Muestra todos los elementos de la cola
void Cola::mostrarCola()
{
    if (!colaVacia())
    {
        cout << "Elementos en la cola: ";
        for (int i = frente; i <= final; i++)
        {
            cout << elementos[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Cola vacía.\n";
    }
}
// Retorna el número de elementos en la cola
int Cola::contarElementos()
{
    if (colaVacia())
    {
        return 0;
    }
    else
    {
        return final - frente + 1;
    }
}
// Busca un elemento en la cola
bool Cola::buscarElemento(int dato)
{
    if (!colaVacia())
    {
        for (int i = frente; i <= final; i++)
        {
            if (elementos[i] == dato)
            {
                return true;
            }
        }
    }
    return false;
}
/*
void simularEvacuacion()
{
    system("cls");
    cout << "\nSIMULACIÓN DE EVACUACIÓN DE PASAJEROS\n";
    Cola pasajeros_prioritarios;
    Cola pasajeros;
    Cola tripulacion;
    pasajeros_prioritarios.insertarCola("Anciano");
    pasajeros_prioritarios.insertarCola("Niño");
    pasajeros_prioritarios.insertarCola("Embarazada");
    pasajeros.insertarCola("Pasajero1");
    pasajeros.insertarCola("Pasajero2");
    pasajeros.insertarCola("Pasajero3");
    tripulacion.insertarCola("Piloto");
    tripulacion.insertarCola("Copiloto");
    tripulacion.insertarCola("Azafata1");
    tripulacion.insertarCola("Azafata2");
    system("PAUSE");
    system("cls");
    cout << "\nINICIANDO PROCESO DE EVACUACIÓN...\n";

    cout << "\nEvacuando pasajeros prioritarios:\n";
    while (!pasajeros_prioritarios.colaVacia())
    {
        string persona = pasajeros_prioritarios.eliminarCola();
        cout << "Evacuando: " << persona << endl;
    }
    cout << "\nEvacuando pasajeros regulares:\n";
    while (!pasajeros.colaVacia())
    {
        string persona = pasajeros.eliminarCola();
        cout << "Evacuando: " << persona << endl;
    }
    cout << "\nEvacuando tripulación:\n";
    while (!tripulacion.colaVacia())
    {
        string persona = tripulacion.eliminarCola();
        cout << "Evacuando: " << persona << endl;
    }
    system("PAUSE");
    system("cls");
    cout << "\n¡EVACUACIÓN COMPLETADA CON ÉXITO!\n";
    system("PAUSE");
}
void juegoDeTurnos()
{
    system("cls");
    cout << "\nJUEGO DE TURNOS\n";
    Cola jugadores;
    jugadores.insertarCola("Sandra");
    jugadores.insertarCola("Felipe");
    jugadores.insertarCola("Miguel");
    jugadores.insertarCola("Julieta");
    cout << "\nINICIANDO JUEGO...\n";
    while (!jugadores.colaVacia())
    {
        string jugador = jugadores.eliminarCola();
        char opcion;
        cout << "\n"
             << jugador << ": quieres retirarte (R) o seguir (S)? ";
        cin >> opcion;
        if (opcion == 'S' || opcion == 's')
        {
            cout << "*** Turno de " << jugador << " ***\n";
            cout << jugador << " ha completado su turno.\n";
            jugadores.insertarCola(jugador);
        }
        else
        {
            cout << jugador << " se ha retirado del juego.\n";
        }
    }
    cout << "\nNo quedan más jugadores en el juego.\n";
    system("PAUSE");
}*/
void Cola::invertirCola(){
    int valor;
    Pila p1;
    if(colaVacia()){
        cout<<"cola vacia..\n";
    }else{
        while(!colaVacia()){
            valor=eliminarCola();
            p1.agregarPila(valor);
        }
        while(!p1.pilaVacia()){
            valor=p1.sacarPila();
            insertarCola(valor);
        }
    }
}
void Cola::eliminarColaX(){
        if(colaVacia()){
            cout<<"cola vacia...\n";
        }else{
            int valor;
            cout<<"ingrese x: "; cin>>valor;
            int j=frente;
            for(int i=frente; i<=final; i++){
                if(elementos[i]!=valor){
                    elementos[j]=elementos[i];
                    j++;
                }
            }
            final=j-1;
            
        }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ColaCircular {
private:
    int elementos[MAX];
    int frente;
    int final;

public:
    ColaCircular() {
        frente = -1;
        final = -1;
    }
    bool estaVacia() {
        return (frente == -1);
    }
    bool estaLlena() {
        return ((final + 1) % MAX == frente);
    }
    void insertarCircular() {
        int dato;
        if (estaLlena()) {
            cout << "Cola Circular llena. No se puede insertar.\n";
        }else{
            cout<<"Ingrese valor: "; cin>>dato;
            if(estaVacia()){
                frente = final = 0;
            }else{
                if(final==MAX){
                    final=0;
                }else{
                    final++;
                }
            }
             elementos[final] = dato;
        }
    }
    int eliminarCircular() {
        int dato;
        if(estaVacia()){
            cout<<"cola vacia...\n";
            return -1;
        }else{
            dato=elementos[frente];
            if(frente==final){
                frente=final=-1;
            }else{
                if(frente==MAX){
                    frente=0;
                }else{
                    frente++;
                }
            }
        }

        return dato;
    }

    void mostrarCircular() {
        if (estaVacia()) {
            cout << "Cola Circular vacía.\n";
            return;
        }
        cout << "Elementos en la cola circular: ";
        int i = frente;
        while (true) {
            cout << elementos[i] << " ";
            if (i == final) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu()
{
    Cola cola1;
    int dato;
    int opcion;
    Pila pila1;
    ColaCircular colaC1;
    do
    {
        system("cls");
        cout << "\n-----------------------------------";
        cout << "\n--        MENÚ DE COLA           --";
        cout << "\n-----------------------------------";
        cout << "\n1. Insertar elemento en la cola   -";
        cout << "\n2. Eliminar elemento de la cola   -";
        cout << "\n3. Ver frente                     -";
        cout << "\n4. Mostrar cola                   -";
        cout << "\n5. Contar elementos               -";
        cout << "\n6. Buscar elemento                -";
        cout << "\n7. Simular evacuación             -";
        cout << "\n8. Juego de turnos                -";
        cout << "\n9. Invertir cola                  -";
        cout << "\n10.Eliminar un valor de cola      -";
        cout << "\n11.Insertar en cola circular      -";
        cout << "\n12.Eliminar en cola circular      -";
        cout << "\n13.Mostrar cola circular          -";
        cout << "\n0. Salir                          -";
        cout << "\n-----------------------------------";
        cout << "\nSeleccione una opción: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            system("cls");
            cout << "Ingrese dato a insertar en la cola: ";
            cin >> dato;
            cola1.insertarCola(dato);
            system("PAUSE");
            break;
        case 2:
            system("cls");
            dato = cola1.eliminarCola();
            if (dato !=-1)
            {
                cout << "Elemento eliminado: " << dato << endl;
            }
            system("PAUSE");
            break;
        case 3:
            system("cls");
            dato = cola1.verFrente();
            if (dato !=-1)
            {
                cout << "Elemento en el frente: " << dato << endl;
            }
            system("PAUSE");
            break;
        case 4:
            system("cls");
            cola1.mostrarCola();
            system("PAUSE");
            break;
        case 5:
            system("cls");
            cout << "Total de elementos en la cola: " << cola1.contarElementos() << endl;
            system("PAUSE");
            break;
        case 6:
            system("cls");
            cout << "Ingrese dato a buscar en la cola: ";
            cin >> dato;
            if (cola1.buscarElemento(dato))
            {
                cout << "Elemento encontrado\n";
            }
            else
            {
                cout << "Elemento no encontrado\n";
            }
            system("PAUSE");
            break;
       /* case 7:
            simularEvacuacion();
            break;
        case 8:
            juegoDeTurnos();
            break;
        */
        case 9:
            system("cls");
        	cola1.invertirCola();
            system("PAUSE");
            break;
        case 10:
             system("cls");
             cola1.eliminarColaX();
             system("PAUSE");
            break;
        case 11:
            system("cls");
            colaC1.insertarCircular();
            system("PAUSE");
            break;
        case 12:
            system("cls");
            dato = colaC1.eliminarCircular();
            if (dato !=-1)
            {
                cout << "Elemento eliminado: " << dato << endl;
            }
            system("PAUSE");
            break;
        case 13:
            system("cls");
            colaC1.mostrarCircular();
            system("PAUSE");
            break;
        case 0:
            cout << "Programa finalizado.\n";
            break;
        default:
            cout << "Opción inválida.\n";
            system("PAUSE");
        }
    } while (opcion != 0);
}
// Función principal para probar la cola
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    menu();
    return 0;
}