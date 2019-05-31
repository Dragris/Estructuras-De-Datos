/* 
 * File:   Circulo.cpp
 * Author: dragr
 * 
 * Created on 21 de febrero de 2019, 10:56
 */

#include <iostream>

#include "Circulo.h"

Circulo::Circulo() {
}

Circulo::Circulo(const Circulo& orig) {
}

Circulo::~Circulo() {
}

float Circulo::getArea() {
    return (3.14 * (this->radio * this->radio));
}

float Circulo::getRadio() const {
    return this->radio;
}

void Circulo::setRadio(float radio) {
    if (radio < 0) {
        std::cout << "Este valor no es aceptable, r<0" << std::endl;
        throw -1;
    }else {
        this->radio = radio;
    }
}