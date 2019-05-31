/* 
 * File:   main.cpp
 * Author: dragr
 *
 * Created on 17 de febrero de 2019, 19:57
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;


void bienvenida(string nombre){
    cout << "Bienvenid@ a la asignatura de Estructura de Datos " << nombre << "." << endl;
}


int main(int argc, char** argv) {
    int opc; string nombre;
    string arr_options[] = {"Salir", "Bienvenida"};
    int opNum = 0;
    
    cout << "Introduzca su nombre: ";
    cin >> nombre;
    
    do{
         cout<<"\nHola "<< nombre << ". ¿Qué quiere hacer?" <<endl;
        /* for(int i=0; i<sizeof(arr_options)/sizeof(*arr_options);i++){
             cout<<i+1<<"."<<arr_options[i]<<endl;
         }*/
        
        for (string opcio: arr_options) {
            cout << opNum+1 << ". " << opcio << endl;
            opNum++;
        }
       opNum = 0;
        
        cin>>opc;
        switch(opc){
        
        case 1: break;
            
        case 2: 
        bienvenida(nombre);
        break;
            
        default: cout << "Esa no es una opción válida." << endl;
        break;
        }
        
    }while(opc!=1);
    
    cout << "Hasta más ver " << nombre << "." << endl;
    return 0;
}