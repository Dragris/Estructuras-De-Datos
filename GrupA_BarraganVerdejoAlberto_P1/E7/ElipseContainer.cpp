/* 
 * File:   ElipseContainer.cpp
 * Author: dragr
 * 
 * Created on 21 de febrero de 2019, 18:04
 */

#include <iostream>
#include <valarray>
#include <vector>

#include "ElipseContainer.h"
#include "Elipse.h"
#include "Circulo.h"



ElipseContainer::ElipseContainer() {
}

ElipseContainer::ElipseContainer(const ElipseContainer& orig) {
}

void ElipseContainer::addElipse(Elipse* e) {
    if (this->container.size() < MAXCAPACITY) {
        this->container.push_back(e);
    } else {
        throw std::runtime_error("Atención, capacidad del contenedor llena.");
    }
} 

float ElipseContainer::getAreas(){
    float areas = 0;
    
    Elipse* eptr;
    for (std::vector<Elipse*>::iterator p= this->container.begin(); p != this->container.end(); p++) {
        eptr = *p;
        areas = areas + eptr->getArea();
    }
    return areas;
}

bool ElipseContainer::isEmpty() const {
    return this->container.empty();
}


ElipseContainer::~ElipseContainer() {
    Elipse* eptr;
    for (std::vector<Elipse*>::iterator p= this->container.begin(); p != this->container.end(); p++) {
        eptr = *p;
        if (dynamic_cast<Circulo*> (eptr)) {
            delete (Circulo *) (eptr);
        } else {
            delete(eptr);
        }
    } 
}