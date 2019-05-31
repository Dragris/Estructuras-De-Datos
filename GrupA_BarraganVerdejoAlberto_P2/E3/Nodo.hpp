/* 
 * File:   Nodo.hpp
 * Author: dragr
 *
 * Created on 6 de marzo de 2019, 12:15
 */

#include "Flight.h"


#ifndef NODO_HPP
#define	NODO_HPP
#include <string>
using namespace std;

class Nodo {
    public:
        Nodo();
        Nodo(Flight* elemento);
        virtual ~Nodo();
        Nodo(const Nodo& q);
        Flight* getElement();
        Nodo* getNext();
        void setNext(Nodo* next);
        Nodo* getPrevious();
        void setPrevious(Nodo* previous);
        void printElement();
    private:
        Flight* element;
        Nodo *next;
        Nodo *previous;
};


/**
 * Constructor por defecto
 */
Nodo::Nodo() {
    this->next = nullptr;
    this->previous = nullptr;    
}

/**
 * Constructor con parámetro.
 * @param 
 */
Nodo::Nodo(Flight* elemento){
    this->next = nullptr;
    this->previous = nullptr;
    this->element = elemento;
}

/**
 * Constructor copia
 * @param q
 * @return 
 */
Nodo::Nodo(const Nodo& NodoOrigen){
    std::cout << "Constructor copia -> Nodo\n";
    this->element = NodoOrigen.element;
    this->next = nullptr;
    this->previous = nullptr;
}

/**
 * Método getNext.
 * @return 
 */
Nodo* Nodo::getNext(){
    return this->next;
}

/**
 * Método setNext, utilizando la dirección del siguiente Nodo.
 * @param next
 * @return 
 */
void Nodo::setNext(Nodo* next){
    this->next = next;
}

/**
 * Método getPrevious, devuelve el nodo anterior.
 * @return 
 */
Nodo* Nodo::getPrevious(){
    return this->previous;
}

/**
 * Método setPrevious, utilizando la dirección del nodo anterior.
 * @param previous
 * @return 
 */
void Nodo::setPrevious(Nodo *previous){
    this->previous = previous;
}
/**
 * Método getElement, te devuelve el elemento almacenado en el nodo.
 */
Flight* Nodo::getElement(){
    return this->element;
}

/**
 * Método destructor.
 */
Nodo::~Nodo(){
    std::cout << "Destructor -> Nodo\n";
    this->next = nullptr;
    this->previous = nullptr;
}

void Nodo::printElement(){
    cout << this->element->getId() << "," << this->element->getOrig() << "," <<
            this->element->getDest() << "," << this->element->getFech();
}
#endif	/* NODO_HPP */