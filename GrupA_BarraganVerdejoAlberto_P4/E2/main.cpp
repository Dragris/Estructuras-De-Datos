/* 
 * File:   main.cpp
 * Author: dragr
 *
 * Created on 13 de mayo de 2019, 16:45
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <time.h>
#include <math.h>

#include "MountainFinder.hpp"
using namespace std;
void mountainSearch(MountainFinder *heap, string filename){
    ifstream file(filename);
    string line;
    int id;
    
    int encontradas = 0;
    int noEncontradas = 0;
    
    if (file.is_open()) {
        while (!file.eof()){
            file >> id;
            try {
                cout << "Montaña con ID: " << id << endl;
                cout << heap->showMountain(id) << endl;
                encontradas++;
            } catch (const invalid_argument &e){
                cout << e.what() << endl;
                noEncontradas++;
            }
        }
    } else {
        throw runtime_error("Error de lectura del archivo.");
    }
}

void carga(MountainFinder*&heap){
    string opc;
    clock_t t;
    t=clock();  //primera mesura del temps
    heap = new MountainFinder();
    
    cout << "¿Qué fichero quiere (P/G) o E...?" << endl;
    cout << "Disclaimer: ";
    cin >> opc;
    
    if (opc == "p" || opc == "P"){
        heap->appendMountains("mountain_list_small.txt");
    } else if (opc == "g" || opc == "G"){
        heap->appendMountains("mountain_list.txt");
    } else if (opc == "e" || opc == "E"){
        heap->appendMountains("error_list.txt");
    }else {
        cout << "¡Cuidado con las teclas!" << endl;
    }
    
    t=clock()-t; //segona mesura i diferència amb la primera
    cout<<"It took "<<t<<" clicks and "<<(float)t/CLOCKS_PER_SEC<<" seconds "<<endl;
}


void orden(MountainFinder *heap){
    clock_t t;
    t=clock();  //primera mesura del temps
    heap->print();
    t=clock()-t; //segona mesura i diferència amb la primera
    cout<<"It took "<<t<<" clicks and "<<(float)t/CLOCKS_PER_SEC<<" seconds "<<endl;
}
void buscar(MountainFinder *heap){
    clock_t t;
    t=clock();  //primera mesura del temps
    mountainSearch(heap, "cercaMuntanyes.txt");
    t=clock()-t; //segona mesura i diferència amb la primera
    cout<<"It took "<<t<<" clicks and "<<(float)t/CLOCKS_PER_SEC<<" seconds "<<endl;
}
void profundidad(MountainFinder *heap){
    cout << "La profundidad del Heap es de: " << heap->depth() << endl;
}
void fullHeap(MountainFinder *heap){
    heap->fullPrint();
}
void salida(){
    cout << endl;
    cout << "Hasta más ver...";
}

int menu(MountainFinder *heap) {
    string separador (60, '-');
    string cabecera = "Ejercicio 2 P3 | BinarySearchTree | Alberto Barragán";
    vector<string> opciones = {
        "1. Cargar desde fichero.",
        "2. Mostrar heap en grupos de 40.",
        "3. Tiempo de búsqueda y número de elementos.",
        "4. Imprimir todo el Heap.",
        "5. Profundidad del Heap",
        "6. Salir"
    };
    string pregunta =  "¿Qué quiere hacer? \n";
    
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
            cin.ignore(10000, '\n');//Ignora este número de caracteres, en caso de ser más devuelve el error n//10000 veces
        }
        
        switch(opc){
            case 1:{
                carga(heap);
                break;
            }
            case 2:{
                orden(heap);
                break;
            }
            case 3:{
                buscar(heap);
                break;
            }
            case 4:{
                fullHeap(heap);
                break;;
            }
            case 5:{
                profundidad(heap);
                break;
            }
            case 6:{
                salida();
                break;
            }
            default:
                cout << "Mi programador no ha tenido en cuenta esa respuesta...\n";
        }
    }while(opc != 6);
}
int main(int argc, char** argv) {
    MountainFinder *heap = new MountainFinder();
    menu(heap);
    return 0;
}
 
/*
|-----------------------------------------------------------------------------------------------------------------------------|
| TIEMPO	|    Inserción SMALL   |       Inseción LARG       |        Busqueda SMALL         |     Busqueda LONG        |
|-----------------------------------------------------------------------------------------------------------------------------|
| HEAP		| 0 clicks & 0 seconds |    0 clicks & 0 seconds   |    16 clicks & 0.016 seconds  | 31 clicks & 0.031 seconds|
|-----------------------------------------------------------------------------------------------------------------------------|
  *  TOO MUCH PC POWER 101
|---------------------------------------------------|
| COSTE         |  Search   |  Insert   | Deletion  |
|---------------------------------------------------|
| HEAP          |   O(n)    |   O(1)    | O(log(n)) |
|---------------------------------------------------|

  */
