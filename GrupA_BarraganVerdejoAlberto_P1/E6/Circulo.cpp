/* 
 * File:   Circulo.cpp
 * Author: dragr
 * 
 * Created on 21 de febrero de 2019, 10:56
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
}

float Circulo::getArea() {
    return (3.14 * (this->radioA * this->radioA));
}

void Circulo::setRadioB(float radio){
    std::cout << "Atención, Círculo no puede asignar un valor diferente al radio 2." << std::endl;
    throw -2;
}

void Circulo::setRadioA(float radio){
    if (radio < 0) {
        std::cout << "Este valor no es aceptable, r<0" << std::endl;
        throw -1;
    }else {
        this->radioA = radio;
    }
}