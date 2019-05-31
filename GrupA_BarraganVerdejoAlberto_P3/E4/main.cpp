/*
 * File:   main.cpp
 * Author: dragr
 *
 * Created on 9 de abril de 2019, 11:19
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <time.h>
#include <math.h>

#include "BSTAVL.hpp"

using namespace std;
void mountainSearch(BSTAVL<Mountain> *bst, string filename){
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
                cout << bst->showMountain(id) << endl;
                encontradas++;
            } catch (const invalid_argument &e){
                cout << e.what() << endl;
                noEncontradas++;
            }
        }
    } else {
        throw runtime_error("Error de lectura del archivo.");
    }
    file.close();
    
    cout << "Encontradas:" << encontradas << endl;
    cout << "No encontradas: " << noEncontradas << endl;
    return;
}

void carga(BSTAVL<Mountain> *&bst){
    string opc;
    clock_t t;
    t=clock();  //primera mesura del temps
    bst = new BSTAVL<Mountain>();
    
    cout << "¿Qué fichero quiere (P/G) o E...?" << endl;
    cout << "Disclaimer: ";
    cin >> opc;
    
    if (opc == "p" || opc == "P"){
        bst->appendMountains("mountain_list_small.txt");
    } else if (opc == "g" || opc == "G"){
        bst->appendMountains("mountain_list.txt");
    } else if (opc == "e" || opc == "E"){
        bst->appendMountains("error_list.txt");
    }else {
        cout << "¡Cuidado con las teclas!" << endl;
    }
    
    t=clock()-t; //segona mesura i diferència amb la primera
    cout<<"It took "<<t<<" clicks and "<<(float)t/CLOCKS_PER_SEC<<" seconds "<<endl;
}


void orden(BSTAVL<Mountain> *bst){
    clock_t t;
    t=clock();  //primera mesura del temps
    bst->printInorder40();
    t=clock()-t; //segona mesura i diferència amb la primera
    cout<<"It took "<<t<<" clicks and "<<(float)t/CLOCKS_PER_SEC<<" seconds "<<endl;
}
void buscar(BSTAVL<Mountain> *bst){
    clock_t t;
    t=clock();  //primera mesura del temps
    mountainSearch(bst, "cercaMuntanyes.txt");
    t=clock()-t; //segona mesura i diferència amb la primera
    cout<<"It took "<<t<<" clicks and "<<(float)t/CLOCKS_PER_SEC<<" seconds "<<endl;
}
void profundidad(BSTAVL<Mountain> *bst) {
    cout << "La profundidad del árbol es: " << bst->height() << endl;
}
void salida(){
    cout << endl;
    cout << "Hasta más ver...";
}

int menu() {
    int opc = 0;  
    string separador (60, '-');
    string cabecera = "Ejercicio 2 P3 | BinarySearchTree | Alberto Barragán";
    vector<string> opciones = {
        "1. Cargar desde fichero.",
        "2. Mostrar por ID en orden creciente.",
        "3. Tiempo de búsqueda y número de elementos.",
        "4. Visualizar la profundidad del árbol.",
        "5. Salir."
    };
    string pregunta =  "¿Qué quiere hacer? \n";
    BSTAVL<Mountain> *bst = nullptr;
     
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
                carga(bst);
                break;
            }
            case 2:{
                orden(bst);
                break;
            }
            case 3:{
                buscar(bst);
                break;
            }
            case 4:{
                profundidad(bst);
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
    menu();
    return 0;
}

 /*
|-----------------------------------------------------------------------------------------------------------------------------|
| TIEMPO	|    Inserción SMALL   |       Inseción LARG       |        Busqueda SMALL         |     Busqueda LONG        |
|-----------------------------------------------------------------------------------------------------------------------------|
| BST		| 0 clicks & 0 seconds | 15 clicks & 0.015 seconds |    16 clicks & 0.016 seconds  | 15 clicks & 0.015 seconds|
|-----------------------------------------------------------------------------------------------------------------------------|
| BSTAVL  	|15clicks 0.015seconds|  16 clicks & 0.016 seconds |    15 clicks & 0.015 seconds  | 16 clicks & 0.016 seconds|
|-----------------------------------------------------------------------------------------------------------------------------|
  *  TOO MUCH PC POWER 101
|---------------------------------------------------|
| COSTE         |  Search   |  Insert   | Deletion  |
|---------------------------------------------------|
| BST           |   O(n)    |   O(n)    |   O(n)    |
|---------------------------------------------------|
| BalancedBST   | O(log(n)) | O(log(n)) | O(log(n)) |
|---------------------------------------------------|
  */