/* 
 * File:   main.cpp
 * Author: dragr
 *
 * Created on 26 de febrero de 2019, 11:22
 */

#include "ArrayQueue.h"

#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * 
 */
int opc = 0;
int menu(){
    vector<string> menu = {"Salir","Caso prueba 1","Caso prueba 2","Insertar elemento en la cola",
                           "Quitar elemento de la cola",
                           "Consultar el primer elemento de la cola", "Imprimir toda la cola",
                           "Salir"};
    int opNum = 0;
    cout<< "\n\n¿Qué quiere hacer?" <<endl;
        
        for (string opcio: menu) {
            cout << opNum << ". " << opcio << endl;
            opNum++;
        }
       opNum = 0;
    cin >> opc;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
    }
    return opc;
}

int main(int argc, char** argv) {
    ArrayQueue array1(3);
    do{
        menu();
        switch(opc){
            case 0:
                break;
                
            case 1:{
                ArrayQueue arr(3);
                try {
                arr.enqueue(10);arr.enqueue(20);
                arr.enqueue(30);arr.enqueue(40);
                
            } catch (const std::runtime_error& e){
                cout << "Se ha producido una excepción:" << endl;
                cout << e.what() << endl;
            }
                arr.print();
                try{
                    arr.dequeue();arr.enqueue(40);
                } catch(const std::runtime_error& e){
                    cout << "Se ha producido una excepción:" << endl;
                    cout << e.what() << endl;
                }
                arr.print();
                break;
            }
            
            case 2:{
                ArrayQueue ye(3);
                try {
                    ye.enqueue(10);
                } catch (const std:: runtime_error& e){
                    cout << "Se ha producido una excepción:" << endl;
                    cout << e.what() << endl;
                }
                ye.getFront();
                try{
                    ye.enqueue(20);ye.enqueue(30);
                } catch(const std:: runtime_error& e){
                    cout << "Se ha producido una excepción:" << endl;
                    cout << e.what() << endl;
                }
                ye.print();ye.dequeue();
                ye.getFront();
                try{
                    ye.dequeue();ye.dequeue();
                    ye.dequeue();
                } catch(const std:: runtime_error& e){
                    cout << "Se ha producido una excepción:" << endl;
                    cout << e.what() << endl;
                }
                ye.print();
                break;
            }
            case 3:{
                int n;
                cout << "Introduzca el elemento a insertar: ";
                cin >> n;
                try{
                array1.enqueue(n);
                } catch(const std:: runtime_error& e){
                    cout << "Se ha producido una excepción:" << endl;
                    cout << e.what() << endl;
                }
                break;
            }
            case 4:{
                try{
                    array1.dequeue();
                } catch(const std:: runtime_error& e){
                    cout << "Se ha producido una excepción:" << endl;
                    cout << e.what() << endl;
                }
                break;
            }
            case 5:{
                array1.getFront();
                break;
            }
            case 6:{
                array1.print();
                break;
            }
            case 7:{
                cout << "Bre-bre-bre-bre-bre-break!";
                break;
            }
            default:
                cout << "Im bau, Entschuldigung für die Unannehmichkeiten.";
        }
        
    }while(opc != 0);
}

