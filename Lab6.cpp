#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

#define MAX 100 // Capacidad máxima de la pila

class Pila {
private:
    char elementos[MAX];
    int tope;

public:
    Pila();

    bool pilaVacia();
    bool pilaLlena();
    void agregarPila(char dato);
    char sacarPila();
    char cima();
    void mostrarPila();
    int contarElementosPila();
    bool buscarElementoPila(int valor);
    bool compararCon(Pila& otra);
    bool revisarOperacionMatematica(const string& expmatematica);
    bool esPalindrome(const string& palabra);
};

// Constructor
Pila::Pila() {
    tope = -1; // Pila vacía
}

// Método para verificar si la pila está vacía
bool Pila::pilaVacia() {
    if(tope == -1){
        return true;
    }else{
        return false;
    }
}

// Método para verificar si la pila está llena
bool Pila::pilaLlena() {
    if(tope == MAX - 1){
        return true;
    }else{
        return false;
    }
}

// Método para agregar un elemento a la pila (push)
void Pila::agregarPila(char dato) {
    if (pilaLlena()) {
        cout << "Desbordamiento - Pila llena. No se puede agregar más elementos." << endl;
        return;
    }else{
        tope++;
        elementos[tope] = dato;
    }
}

// Método para eliminar el elemento superior de la pila (pop)
char Pila::sacarPila() {
    if (pilaVacia()) {
        cout << "Subdesbordamiento - Pila vacía. No se puede sacar elemento." << endl;
        return (0); // Carácter nulo
    }else{
        char dato = elementos[tope];
        tope--;
        return dato;
    }
}

// Método para ver el elemento en la cima de la pila (peek)
char Pila::cima() {
    if (!pilaVacia()) {
        return elementos[tope];
    } else {
        cout << "Pila vacía." << endl;
        return -1;
    }
}

// Método para mostrar todos los elementos de la pila
void Pila::mostrarPila() {
    if (pilaVacia()) {
        cout << "Pila vacía." << endl;
        return;
    }else{
        cout << "Elementos de la pila (de arriba hacia abajo):" << endl;
        for (int i = tope; i >= 0; i--) {
            cout << elementos[i]<<endl;
        }
        cout << endl;
    }
}

// Método para contar elementos
int Pila::contarElementosPila() {
    return tope+1;
}
// Método para buscar un elemento en la pila
bool Pila::buscarElementoPila(int dato) {
    for (int i =tope; i>=0; i--) {
        if (elementos[i] == dato) {
            return true;
        }
    }
    return false;
}

// Método para comparar con otra pila
bool Pila::compararCon(Pila& pila2) {
    if (tope != pila2.tope) {
        return false;
    }
    for (int i =tope; i>=0; i--) {
        if (elementos[i] != pila2.elementos[i]) {
            return false;
        }
    }
    return true;
}

bool Pila::revisarOperacionMatematica(const string& expmatematica) {
    Pila pilaParentesis;
    for (char c : expmatematica) {
        if (c == '(') {
            pilaParentesis.agregarPila(c);
        } else if (c == ')') {
            if (pilaParentesis.pilaVacia()) {
                return false;
            }
            pilaParentesis.sacarPila();
        }
    }
    return pilaParentesis.pilaVacia();
}
bool Pila::esPalindrome(string& palabra){
    for( char c:palabra){
        pila1.agregarPila(c);
    }
    for(char t:palabra){
        if(t!=pila1.sacarPila()){
            return false;
        }
    }
    return true;
}

// Menú interactivo
void menu() {
    Pila pila1;
    Pila pila2;
    int opcion;
    char dato;
    string palabra;
    do {
        cout <<"------------------------";
        cout <<"\n      MENÚ Pila       ";
        cout <<"\n----------------------";
        cout << "\n1. Apilar en Pila 1";
        cout << "\n2. Desapilar en Pila 1";
        cout << "\n3. Mostrar Pila 1";
        cout << "\n4. Contar elementos de Pila 1";
        cout << "\n5. Buscar un elemento en Pila 1";
        cout << "\n6. Apilar en Pila 2";
        cout << "\n7. Mostrar Pila 2";
        cout << "\n8. Comparar Pila 1 con Pila 2";
        cout << "\n9. Salir";
        cout << "\nOpción: ";
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Ingrese dato a apilar en Pila 1: ";
                cin >> dato;
                pila1.agregarPila(dato);
                break;
            case 2:
                pila1.sacarPila();
                break;
            case 3:
                pila1.mostrarPila();
                break;
            case 4:
                cout << "Cantidad de elementos en Pila 1: " << pila1.contarElementosPila() << endl;
                break;
            case 5:
                cout << "Ingrese el elemento a buscar en Pila 1: ";
                cin >> dato;
                cout << "¿Está el " << dato << "?: " << (pila1.buscarElementoPila(dato) ? "Sí" : "No") << endl;
                break;
            case 6:
                cout << "Ingrese dato a apilar en Pila 2: ";
                cin >> dato;
                pila2.agregarPila(dato);
                break;
            case 7:
                pila2.mostrarPila();
                break;
            case 8:
                cout << "Las pilas son iguales?: " << (pila1.compararCon(pila2) ? "Sí" : "No") << endl;
                break;
            /*case 9:
                cout<<"ingrese una palabra: "; cin>>palabra;
                if(pila1.esPalindrome(palabra)){
                    cout<<"es palindromo";
                }else{
                    cout<<"no es palindromo";
                }
                break;*/
            case 9:
                cout << "Programa finalizado." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 9);
}

// Función principal para probar la clase Pila
int main() {
    SetConsoleOutputCP(CP_UTF8);
    menu();
    /*
    Pila pila;
    cout << "Agregando elementos a, b, c..." << endl;
    pila.agregarPila('a');
    pila.agregarPila('b');
    pila.agregarPila('c');
    pila.mostrarPila();
    cout << "Elemento en la cima: " << pila.cima() << endl;
    cout << "Contiene el a?: " << (pila.buscarElementoPila('a') ? "Sí" : "No") << endl;
    cout << "Contiene el d?: " << (pila.buscarElementoPila('d') ? "Sí" : "No") << endl;
    cout << "Sacando un elemento..." << endl;
    pila.sacarPila();
    pila.mostrarPila();
    cout << "Total de elementos: " << pila.contarElementosPila() << endl;
    
    // Probar comparación
    Pila pila2;
    pila2.agregarPila('a');
    pila2.agregarPila('b');
    pila2.agregarPila('g');
    pila2.mostrarPila();
    cout << "Las pilas son iguales?: " << (pila.compararCon(pila2) ? "Sí" : "No") << endl;
    
    string expresion;
    //cout << "Ingrese la operación matemática: ";
    //cin >> expresion;
    expresion = "((3+4*(8+3**2))";
    //expresion = "(3+4)*(8+3**2))";
    //expresion = "(3+4)*(8+3**2)";
    //expresion = "(3+4)*(8+3**2)(";
    //expresion = "(())(()";
    if (pila.revisarOperacionMatematica(expresion)) {
        cout << "La expresión matemática " << expresion << " es CORRECTA." << endl;
    } else {
        cout << "La expresión matemática " << expresion << " es INCORRECTA." << endl;
    }*/
    return 0;
}