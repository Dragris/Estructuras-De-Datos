/* 
 * File:   LinkedQueue.hpp
 * Author: dragr
 *
 * Created on 6 de marzo de 2019, 12:20
 */

#include "Nodo.hpp"
#include "Flight.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

#ifndef LINKEDQUEUE_HPP
#define	LINKEDQUEUE_HPP

using namespace std;

class LinkedQueue{
    public:
        LinkedQueue();
        virtual ~LinkedQueue();
        LinkedQueue(const LinkedQueue& q);
        void insertFront(Flight *element);
        void insertRear(Flight *element);
        void deleteFront();
        void deleteRear();
        Flight* getFront();
        Flight* getRear();
        bool isEmpty();
        void print();
        const int& size() const;
    
    private:
        int nElementos;
        Nodo* front;
        Nodo* rear;
};

/**
 * Constructor
 */
LinkedQueue::LinkedQueue(){
    //Centinelas
    front = new Nodo();
    rear = new Nodo();
    //Centinelas
    
    front->setNext(rear);
    front->setPrevious(nullptr);
    
    rear->setNext(nullptr);
    rear->setPrevious(front);
    
    this->nElementos = 0;
}

/**
 * Destructor
 */
LinkedQueue::~LinkedQueue(){
   std::cout << "Destructor -> LinkedQueue\n"; 
   Nodo* temp = front;
   Nodo* next;
   
   while(temp != nullptr){
       next = temp->getNext();
       delete temp;
       next = temp;
   }
}

/**
 * Constructor copia LinkedQueue
 * @param origenLinked
 */
LinkedQueue::LinkedQueue(const LinkedQueue& origenLinked){
    std::cout << "Contructor copia -> LinkedQueue\n";
    
    this->front = new Nodo(*origenLinked.front);
    
    Nodo* aux;
    Nodo* temp;
    Nodo* next = origenLinked.front->getNext();
    
    while(next->getNext() != nullptr){
        temp = new Nodo (*next);
        
        aux->setNext(temp);
        temp->setPrevious(aux);
        
        aux = aux->getNext();
        temp = next->getNext();
    }
    
    this->rear = new Nodo(*origenLinked.rear);
    this->rear->setPrevious(temp);
    temp->setNext(this->rear);
    
    this->nElementos = origenLinked.nElementos;
}

/**
 * Comprueba si la cola está vacía.
 * También puede implementarse comprobando si rear.getPrevios == front;
 * Y viceversa.
 * @return 
 */
bool LinkedQueue::isEmpty(){
    return this->nElementos == 0;
}



/**
 * Método getFront.
 * @return 
 */
/*
Flight* LinkedQueue::getFront(){
    return this->front->getNext()->printElement();
} 
*/
/**
 * Método getRear
 * @return 
 */
/*
Flight* LinkedQueue::getRear(){
    return this->rear->getPrevious()->printElement();
}
*/


/**
 * Insertar Nodo al principio
 * @param elem
 */
void LinkedQueue::insertFront(Flight* elem) {
    Nodo *elemento = new Nodo (elem);
    
    if (isEmpty()) {
        this->front->setNext(elemento);
        elemento->setPrevious(this->front);
        
        this->rear->setPrevious(elemento);
        elemento->setNext(this->rear);
    } else {
        elemento->setNext(this->front->getNext());
        this->front->getNext()->setPrevious(elemento);
        this->front->setNext(elemento);
        elemento->setPrevious(this->front);
    }
    this->nElementos++;
}
/**
 * Insertar Nodo al final
 * @param elem
 */
void LinkedQueue::insertRear(Flight* elem) {
    Nodo *elemento = new Nodo(elem);
    
    if(isEmpty()){
       this->front->setNext(elemento);
       elemento->setPrevious(this->front);
        
       this->rear->setPrevious(elemento);
       elemento->setNext(this->rear);
    } else{
        elemento->setPrevious(this->rear->getPrevious());
        this->rear->getPrevious()->setNext(elemento);
        this->rear->setPrevious(elemento);
        elemento->setNext(this->rear);
    }
    this->nElementos++;
}
/**
 * Borrar el primer nodo de la Queue
 */
void LinkedQueue::deleteFront(){
    if (isEmpty()){
        throw std::underflow_error("EXCEPCION: No hay elementos en la lista.");
    } else {
    Nodo *delNodo = this->front->getNext();
    delNodo->getNext()->setPrevious(this->front);
    this->front->setNext(delNodo->getNext());
    delete delNodo;
    this->nElementos--;
    }
}

/**
 * Borrar el último nodo de la Queue
 */
void LinkedQueue::deleteRear(){
    if (isEmpty()){
        throw std::underflow_error("EXCEPCION: No hay elementos en la lista.");
    } else {
        Nodo *delNodo = this->rear->getPrevious();
        delNodo->getPrevious()->setNext(this->rear);
        this->rear->setPrevious(delNodo->getPrevious());
        delete delNodo;
        this->nElementos--;
    }
}



void LinkedQueue::print() {
    cout << "[";
    
    Nodo *begin = front->getNext(); //Cogemos el primer nodo, no el centinela
    int cont = 0;
    int elementos = this->nElementos -1;
    while(begin->getNext() != nullptr) {
        begin->printElement();
        if (cont < elementos){
            cout << " ; \n";
        }
        begin = begin->getNext();
        cont++;
    }
    cout << "]" << endl;
}

#endif	/* LINKEDQUEUE_HPP */

