/* 
 * File:   Circulo.cpp
 * Author: dragr
 * 
 */

#include <iostream>
#include "Circulo.h"

Circulo::Circulo() {
    std::cout << "Constructor de Circulo." << std::endl;
    this->radioA = 0;
    this->radioB = this->radioA;
}

Circulo::Circulo(const Circulo& orig) {
}

Circulo::~Circulo() {
    std::cout << "Destructor de la clase Circulo." << std::endl;
    this->radioA = 0;
    this->radioB = 0;
}

float Circulo::getArea() {
    return (3.14 * (this->radioA * this->radioA));
}

void Circulo::setRadioB(float radio){
    throw std::invalid_argument("Atención, Circulo no puede asignar un valor diferente al radio 2.");
}

void Circulo::setRadioA(float radio){
    if (radio < 0) {
        throw std::invalid_argument("Este valor no es aceptable, r<0");
        throw -1;
    }else {
        this->radioA = radio;
    }
}