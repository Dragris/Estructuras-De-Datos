/* 
 * File:   main.cpp
 * Author: dragr
 *
 * Created on 26 de febrero de 2019, 11:22
 */



#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "LinkedQueue.hpp"

using namespace std;

/**
 * Mensaje de salida
 */
void salida(){
    cout << endl;
    cout << "Bre-bre-bre-bre-bre-break!\n";
}

/**
 * Imprime el primer elemento de la LinkedQueue
 * @param que
 */
template <class X>
void printFront(LinkedQueue<X> *que){
    cout << "\nEl primer elemento es: " << que->getFront();
    cout << endl;
}
/**
 * Insertar elemento al final
 * @param que
 */
template <class X>
void insertarFinal(LinkedQueue<X> *que){
    int elemento;
    cout << "Elemento a insertar al final: ";
    cin >> elemento;
    que->insertRear(elemento);
    cout << endl;
}

/**
 * Elimina el primer elemento de la LinkedQueue  
 * @param que
 */
template <class X>
void borrarInicial(LinkedQueue<X> *que){
    try{
        que->deleteFront();
    } catch(const std:: runtime_error& e){
                    cout << "Se ha producido una excepción:" << endl;
                    cout << e.what() << endl;
    }
    cout << "Se ha eliminado el primer elemento de la linked queue.\n";    
}

/**
 * Imprimir la LinkedQueue
 * @param que
 */
template <class X>
void print(LinkedQueue<X> *que){
    cout << endl;
    que->print();
    cout << endl;
}

/**
 * caso de prueba 1
 */

void caso1(){
    //que->~LinkedQueue();
    LinkedQueue<int> *caso = new LinkedQueue<int>;
                try {
                caso->insertRear(10); caso->insertRear(20);
                caso->insertRear(30); caso->insertRear(40);
            } catch (const std::runtime_error& e){
                cout << "Se ha producido una excepción:" << endl;
                cout << e.what() << endl;
            }
                caso->print();
                try{
                    caso->deleteFront();caso->insertRear(40);
                } catch(const std::runtime_error& e){
                    cout << "Se ha producido una excepción:" << endl;
                    cout << e.what() << endl;
                }
                caso->print();
}

/**
 * Caso de prueba 2
 */

void caso2(){
    //que->~LinkedQueue();
    LinkedQueue<int> *caso = new LinkedQueue<int>;
                try {
                    caso->insertRear(10);
                } catch (const std:: runtime_error& e){
                    cout << "Se ha producido una excepción:" << endl;
                    cout << e.what() << endl;
                }
                caso->getFront();
                try{
                    caso->insertRear(20); caso->insertRear(30);
                } catch(const std:: runtime_error& e){
                    cout << "Se ha producido una excepción:" << endl;
                    cout << e.what() << endl;
                }
                caso->print();caso->deleteFront();
                caso->getFront();
                try{
                    caso->deleteFront();caso->deleteFront();
                    caso->deleteFront();
                } catch(const std:: runtime_error& e){
                    cout << "Se ha producido una excepción:" << endl;
                    cout << e.what() << endl;
                }
                caso->print();
}

/**
 * Menú completo
 * @param Queue
 * @return 
 */
template <class X>
int menu(LinkedQueue<X> *Que){
    string separador (65, '-');
    string cabecera = "Ejercicio 2 | Práctica 2 - Linked Queue - Alberto Barragán";
    vector<string> opciones = {
        "1. Caso prueba 1",
        "2. Caso prueba 2",
        "3. Insertar elemento en la cola",
        "4. Quitar elemento de la cola",
        "5. Consultar el primer elemento de la cola",
        "6. Imprimir toda la cola",
        "7. Salir"
    };
    string pregunta =  "¿Qué quiere hacer? ";
   
    
    int opc = 0;   
    do{
        cout << separador << endl;
        cout << cabecera << endl;
        cout << separador << endl;
        for (string opcion : opciones) {
            cout << opcion << endl;
        }
        cout << separador << endl;
        cout << pregunta;
        
        
        cin >> opc;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
        }
        
        
        
        
        switch(opc){
            case 0:
                break;
                
            case 1:{
                caso1();
                break;
            }
            
            case 2:{
                caso2();
                break;
            }
            case 3:{
                insertarFinal(Que);
                break;
            }
            case 4:{
                borrarInicial(Que);
                break;
            }
            case 5:{
                printFront(Que);
                break;
            }
            case 6:{
                print(Que);
                break;
            }
            case 7:{
                salida();
                break;
            }
            default:
                cout << "Mi programador no ha tenido en cuenta esa respuesta...";
        }
    }while(opc != 7);
}

int main(int argc, char** argv) {
    LinkedQueue<int> *que = new LinkedQueue<int>;
    menu(que);
    return 0;
}

