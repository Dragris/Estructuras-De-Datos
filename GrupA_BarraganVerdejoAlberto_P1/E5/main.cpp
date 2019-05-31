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
#include <fstream>

#include "Circulo.h"
#include "Elipse.h"

using namespace std;

int opc, numCirculos = 0;



int menu(){
    vector<string> arr_options = {"Salir", "Introducir figura", "Glosario de figuras","Cargar datos"};
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

void introducirCirculo(int &cont, float radio){
    Circulo* c = new Circulo();
    c->setRadio(radio);
    float area = c->getArea();
    cout << "El área de este círculo es de " << area << "u" << endl;
    cont++;
}

void introducirElipse (int &cont, float radioA, float radioB) {
    Elipse* e = new Elipse();
    e->setRadioA(radioA);
    e->setRadioB(radioB);
    float area = e->getArea();
    cout << "El área de esta elipse es de " << area << "u" << endl;
    cont++;
}

void addFigura(int &contC, int &contE){
    float radioA, radioB;
    char selector;
    cout << "Introduce los datos de tu fgura (tipo [C o E] dato1 dato2 [vacío si el tipo es C]) : ";
    
    cin >> selector;
    //Hacemos la comprobación de tipo:
    if (selector == 'C' || selector == 'c'){
        cin >> radioA;
        //Comprobamos el tipo de dato que se introduce
        if (cin.fail()) {
            cin.clear();
            cout << "Círculo incorrecto" << endl;
            throw -1;
        }
        introducirCirculo(contC,radioA);
        //Repetimos el proceso selector del círculo
    } else if (selector == 'E' || selector == 'e') {
        cin >> radioA >> radioB;
        if (cin.fail()) {
            cin.clear();
            cout << "Elipse incorrecta" << endl;
            throw -1;
        }
        introducirElipse(contE,radioA,radioB);
    } else {
        cout << "Figura incorrecta." << endl;
        throw -1;
    }
}

void glosarioFiguras(int contC, int contE) {
    cout << "Tienes " << contC << " círculos y " << contE << " elipses." << endl;
}

void cargarDatos(int &contC, int &contE){
    char selector;
    float radioA, radioB;
    ifstream file("figures.txt");
    if (file.is_open()) {
        while(!file.eof()){
            file >> selector;
            //Comprobamos tipo de figura
            if (selector == 'C' || selector == 'c'){
                file >> radioA;
                //Comprobamos el tipo de dato que se introduce
                if (file.fail()) {
                    cout << "Datos del círculo incorrectos" << endl;
                    throw -1;
                }
            introducirCirculo(contC,radioA);
            } else if (selector == 'E' || selector == 'e') {
                file >> radioA >> radioB;
                if (file.fail()) {
                    cout << "Datos de la elipse incorrectos" << endl;
                    throw -1;
                }
                introducirElipse(contE,radioA,radioB);
            } else {
                cout << "Figura incorrecta." << endl;
                throw -1;
            }
        }
    } else {
        cout << "Error al leer el archivo.";
        throw -1;
    }
    file.close();
}

int main(int argc, char** argv) {
    int contC = 0, contE = 0;
    
    do{
        menu();
        switch(opc){
        
        case 1: 
            break;
            
        case 2: 
            try {
                addFigura(contC, contE);
            } catch (int ex){
                cout << "Se ha producido una excepción" << endl;
            }
            break;
        case 3:
            glosarioFiguras(contC, contE);
            break;
            
        case 4:
            cargarDatos(contC, contE);
        default: 
            cout << "Esa no es una opción válida." << endl;
            break;
        }
    }while(opc!=1);
    
    cout << "Hasta más ver." << endl;
    return 0;
}

