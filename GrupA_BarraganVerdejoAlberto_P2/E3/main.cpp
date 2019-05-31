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
#include <fstream>

#include "LinkedQueue.hpp"
#include "Flight.h"

using namespace std;

/**
 * Mensaje de salida
 */
void salida(){
    cout << endl;
    cout << "Bre-bre-bre-bre-bre-break!\n";
}

/**
 * Insertar vuelos por teclado, la fecha no admite espacios
 * @param que
 */
void insertar(LinkedQueue *que){
    string id, orig, dest, fech;
    string separador(65,'-');
    int decis = 1;
    do{
        cout << separador << endl;
        cout << "Identificador : ";
        cin >> id;
        //vuelo.setId(id);
        cout << "Origen : ";
        cin >> orig;
        //vuelo.setOrig(orig);
        cout << "Destino : ";
        cin >> dest;
        //vuelo.setDest(dest);
        cin.ignore(256, '\n'); //Ignoramos todos los caracteres hasta el siguiente input
        cout << "Fecha : ";
        getline(cin, fech);
        //vuelo.setFech(fech);
        Flight* vuelo = new Flight(id, orig, dest, fech);
        que->insertRear(vuelo);
        cout << "¿Seguir introduciendo vuelos? (0 para salir) ";
        cin >> decis;
    }while(decis != 0);
}
/**
 * Elimina el primer elemento de la LinkedQueue  
 * @param que
 */
void borrarInicial(LinkedQueue *que){
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
void print(LinkedQueue *que){
    cout << endl;
    que->print();
    cout << endl;
}

/**
 * Cargar vuelos a través de un fichero
 * @param que
 */
void cargarDatos(LinkedQueue *que){
    ifstream file("flights.csv");
    string id, orig, dest, fech;
    while(file.good()){
        getline(file, id, ',');
        getline(file, orig,',');
        getline(file, dest, ',');
        getline(file, fech, '\n');
        try{
        Flight *vuelo = new Flight(id, orig, dest, fech);
        que->insertRear(vuelo);
        } catch(invalid_argument &e){
            cout << e.what() << endl;
        }
    }
}


/**
 * Menú completo
 * @param Queue
 * @return 
 */
int menu(LinkedQueue *Que){
    string separador (65, '-');
    string cabecera = "Ejercicio 3 | Práctica 2 - Linked Queue - Alberto Barragán";
    vector<string> opciones = {
        "1. Insertar N número de elementos",
        "2. Quitar elemento de la cola",
        "3. Cargar desde fichero",
        "4. Imprimir toda la cola",
        "5. Salir"
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
            case 1:{
                insertar(Que);
                break;
            }
            case 2:{
                borrarInicial(Que);
                break;
            }
            case 3:{
                cargarDatos(Que);
                break;
            }
            case 4:{
                print(Que);
                break;
            }
            case 5:{
                salida();
                break;
            }
            default:
                cout << "Mi programador no ha tenido en cuenta esa respuesta...\n";
        }
    }while(opc != 5);
}

int main(int argc, char** argv) {
    LinkedQueue *que = new LinkedQueue;
    menu(que);
    return 0;
}

