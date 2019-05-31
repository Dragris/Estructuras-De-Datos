/* 
 * File:   Elipse.cpp
 * Author: dragr
 * 
 */

#include <iostream>


#include "Elipse.h"

Elipse::Elipse() {
    std::cout << "Constructor de Elipse" << std::endl;
}

Elipse::Elipse(const Elipse &obj) {
    std::cout << "Constructor copia de Elipse" << std::endl;
    this->radioA = obj.radioA;
    this->radioB = obj.radioB;
}

Elipse::~Elipse() {
    std::cout << "Destructor de la clase Elipse." << std:: endl;
    this->radioA = 0;
    this->radioB = 0;
}

float Elipse::getArea() {
    return (3.14 * radioA * radioB);
}

float Elipse::getRadioA() const {
    return this->radioA;
}

float Elipse::getRadioB() const {
    return this->radioB;
}

void Elipse::setRadioA(float radio){
    if (radio < 0) {
        throw std::invalid_argument("Este valor no es aceptable, r<0");
        
    }else {
        this->radioA = radio;
    }
}

void Elipse::setRadioB(float radio) {
    if (radio < 0) {
        throw std::invalid_argument("Este valor no es aceptable, r<0");
        throw -1;
    }else {
        this->radioB = radio;
    }
}