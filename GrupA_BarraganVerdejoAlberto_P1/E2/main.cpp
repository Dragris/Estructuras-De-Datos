/* 
 * File:   main.cpp
 * Author: dragr
 *
 * Created on 17 de febrero de 2019, 21:07
 */

#include <cstdlib>
#include <iostream>
#include <vector>



using namespace std;

int opc = 0; string nombre; 


int menu(){
    vector<string> arr_options = {"Salir", "Bienvenida", "Redefinir nombre"};
    int opNum = 0;
    cout<<"\nHola "<< nombre << ". ¿Qué quiere hacer?" <<endl;
        
        for (string opcio: arr_options) {
            cout << opNum+1 << ". " << opcio << endl;
            opNum++;
        }
       opNum = 0;
    cin >> opc;
    return opc;
}

void bienvenida(string nombre){
    cout << "Bienvenid@ a la asignatura de Estructura de Datos " << nombre << "." << endl;
}

void setNombre(){
    cout << "Introduzca su nombre: ";
    cin >> nombre;
}


int main(int argc, char** argv) {
    cout << "Introduzca su nombre: ";
    cin >> nombre;
    
    do{
        menu();
        switch(opc){
        
        case 1: 
        break;
            
        case 2:
        bienvenida(nombre);
        break;
            
        case 3: 
        setNombre(); 
        break;
            
        default: cout << "Esa no es una opción válida." << endl;
        break;
        
        }
        
    }while(opc!=1);
    
    cout << "Hasta más ver " << nombre << "." << endl;
    return 0;
}