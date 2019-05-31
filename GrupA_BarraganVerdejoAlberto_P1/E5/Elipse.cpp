/* 
 * File:   Elipse.cpp
 * Author: dragr
 * 
 * Created on 21 de febrero de 2019, 11:14
 */

#include <iostream>

#include "Elipse.h"

Elipse::Elipse() {
}

Elipse::Elipse(const Elipse& orig) {
}

Elipse::~Elipse() {
}

float Elipse::getArea() {
    return (3.14 * radioA * radioB);
}

float Elipse::getRadioA() const {
    return radioA;
}

float Elipse::getRadioB() const {
    return radioB;
}

void Elipse::setRadioA(float radio){
    if (radio < 0) {
        std::cout << "Este valor no es aceptable, r<0" << std::endl;
        throw -1;
    }else {
        this->radioA = radio;
    }
}

void Elipse::setRadioB(float radio) {
    if (radio < 0) {
        std::cout << "Este valor no es aceptable, r<0" << std::endl;
        throw -1;
    }else {
        this->radioB = radio;
    }
}