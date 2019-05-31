/* 
 * File:   main.cpp
 * Author: dragr
 *
 */

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <fstream>

#include "Circulo.h"
#include "Elipse.h"
#include "ElipseContainer.h"

using namespace std;

int opc, numCirculos = 0;



int menu(){
    vector<string> arr_options = {"Salir", "Introducir figura", "Glosario de figuras","Cargar datos", "Area total"};
    int opNum = 0;
    cout<< "¿Qué quiere hacer?" <<endl;
        
        for (string opcio: arr_options) {
            cout << opNum+1 << ". " << opcio << endl;
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

void introducirCirculo(int &cont, float &radio, ElipseContainer* &container){
    Circulo* c = new Circulo();
    c->setRadioA(radio);
    float area = c->getArea();
    
    container->addElipse(c);
    cout << "El área de este círculo es de " << area << "u" << endl;
    cont++;
}

void introducirElipse (int &cont, float &radioA, float &radioB, ElipseContainer* &container){
    Elipse* e = new Elipse();
    e->setRadioA(radioA);
    e->setRadioB(radioB);
    float area = e->getArea();
    
    container->addElipse(e);
    cout << "El área de esta elipse es de " << area << "u" << endl;
    cont++;
}

void addFigura(int &contC, int &contE, ElipseContainer* &container){
    float radioA, radioB;
    char selector;
    cout << "Introduce los datos de tu fgura (tipo [C o E] dato1 dato2 [vacío si el tipo es C]) : ";
    
    cin >> selector;
    //Hacemos la comprobación de tipo:
    if (selector == 'C' || selector == 'c'){
        cin >> radioA;
        //Comprobamos el dato que se introduce
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Círculo incorrecto" << endl;
            throw -1;
        }
        introducirCirculo(contC,radioA, container);
        //Repetimos el proceso selector del círculo
    } else if (selector == 'E' || selector == 'e') {
        cin >> radioA >> radioB;
        if (cin.fail()) {
            cin.clear();
            cout << "Elipse incorrecta" << endl;
            throw -1;
        }
        introducirElipse(contE,radioA,radioB, container);
    } else {
        cout << "Figura incorrecta." << endl;
        throw -1;
    }
}

void glosarioFiguras(int contC, int contE) {
    cout << "Tienes " << contC << " círculos y " << contE << " elipses." << endl;
}

void cargarDatos(int &contC, int &contE, ElipseContainer* &container){
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
            introducirCirculo(contC,radioA, container);
            } else if (selector == 'E' || selector == 'e') {
                file >> radioA >> radioB;
                if (file.fail()) {
                    cout << "Datos de la elipse incorrectos" << endl;
                    throw -1;
                }
                introducirElipse(contE,radioA,radioB, container);
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

void calcularAreas(ElipseContainer* &container){
    if (container->isEmpty()){
        throw std::runtime_error("Error, el contenedor está vacío, puede probar a introducir alguna figura.");
    } else {
        cout << "El área total de las figuras es de " << container->getAreas() << "u" << endl;
    }
}

int main(int argc, char** argv) {
    int contC = 0, contE = 0;
    ElipseContainer* container = new ElipseContainer();
    do{
        menu();
        switch(opc){
        
        case 1: 
            break;
            
        case 2: 
            try {
                addFigura(contC, contE, container);
            } catch (int ex){
                cout << "Se ha producido una excepción" << endl;
            }
            break;
            
        case 3:
            glosarioFiguras(contC, contE);
            break;
            
        case 4:
            try{
                cargarDatos(contC, contE, container);
            } catch (std::runtime_error& e) {
                cout << "Se ha producido una excepción." << endl;
                cout << e.what() << endl;
            }
            
        case 5:
            try{
                calcularAreas(container);
            } catch (const std::runtime_error& e){
                cout << "Se ha producido una excepción." << endl;
                cout << e.what() << endl;
            }
            break;
        
            
        default: 
            cout << "Esa no es una opción válida." << endl;
            break;
        }
    }while(opc!=1);
    container->~ElipseContainer();
    cout << "Hasta más ver." << endl;
    return 0;
}

