/* 
 * File:   main.cpp
 * Author: dragr
 *
 * Created on 18 de febrero de 2019, 19:44
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "Circulo.h"

using namespace std;

int opc;
int menu(){
    vector<string> arr_options = {"Salir", "Introducir círculo"};
    int opNum = 0;
    cout<< "¿Qué quiere hacer?" <<endl;
        
        for (string opcio: arr_options) {
            cout << opNum+1 << ". " << opcio << endl;
            opNum++;
        }
       opNum = 0;
    cin >> opc;
    return opc;
}

void introducirCirculo(int &cont){
    float radio;
    cont++;
    cout << "Círculo nº" << cont << endl;
    cout << "Introduzca el radio: ";
    cin >> radio;
    Circulo* c = new Circulo();
    c->setRadio(radio);
    cout << "El área de este círculo es de " << c->getArea() << "u" << endl;
}


int main(int argc, char** argv) {
    double input;
    int cont = 0;
    
    do{
        menu();
        switch(opc){
        
        case 1: break;
            
        case 2: 
        try {
            introducirCirculo(cont);
        } catch (int ex) {
            cout << "Se ha producido una excepción" << endl;
        }
        break;
            
        default: cout << "Esa no es una opción válida." << endl;
        break;
        
        }
        
    }while(opc!=1);
    
    cout << "Hasta más ver." << endl;
    return 0;
}

