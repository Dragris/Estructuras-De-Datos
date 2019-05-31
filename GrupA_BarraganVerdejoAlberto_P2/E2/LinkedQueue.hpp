/* 
 * File:   LinkedQueue.hpp
 * Author: dragr
 *
 * Created on 6 de marzo de 2019, 12:20
 */

#include "Nodo.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

#ifndef LINKEDQUEUE_HPP
#define	LINKEDQUEUE_HPP
template <class X>
class LinkedQueue{
    public:
        LinkedQueue();
        virtual ~LinkedQueue();
        LinkedQueue(const LinkedQueue& q);
        void insertFront(const X &element);
        void insertRear(const X &element);
        void deleteFront();
        void deleteRear();
        X& getFront();
        X& getRear();
        bool isEmpty();
        X& goTo(int n);
        void addInList(const X &element, int n);
        void eraseInList(int n);
        void print();
        const int& size() const;
    
    private:
        int nElementos;
        Nodo<X>* front;
        Nodo<X>* rear;
};

/**
 * Constructor
 */
template <class X>
LinkedQueue<X>::LinkedQueue(){
    //Centinelas
    front = new Nodo<X>();
    rear = new Nodo<X>();
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
template <class X>
LinkedQueue<X>::~LinkedQueue(){
   std::cout << "Destructor -> LinkedQueue\n"; 
   Nodo<X>* temp = front;
   Nodo<X>* next;
   
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
template <class X>
LinkedQueue<X>::LinkedQueue(const LinkedQueue<X>& origenLinked){
    std::cout << "Contructor copia -> LinkedQueue\n";
    
    this->front = new Nodo<X>(*origenLinked.front);
    
    Nodo<X>* aux;
    Nodo<X>* temp;
    Nodo<X>* next = origenLinked.front->getNext();
    
    while(next->getNext() != nullptr){
        temp = new Nodo<X> (*next);
        
        aux->setNext(temp);
        temp->setPrevious(aux);
        
        aux = aux->getNext();
        temp = next->getNext();
    }
    
    this->rear = new Nodo<X>(*origenLinked.rear);
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
template <class X>
bool LinkedQueue<X>::isEmpty(){
    return this->nElementos == 0;
}

/**
 * Método getFront.
 * @return 
 */
template <class X>
X& LinkedQueue<X>::getFront(){
    return this->front->getNext()->getElement();
} 

/**
 * Método getRear
 * @return 
 */
template <class X>
X& LinkedQueue<X>::getRear(){
    return this->rear->getPrevious()->getElement();
}

/**
 * Insertar Nodo al principio
 * @param elem
 */
template <class X>
void LinkedQueue<X>::insertFront(const X& elem) {
    Nodo<X> *elemento = new Nodo<X> (elem);
    
    if (isEmpty()) {
        this->front.setNext(elemento);
        elemento.setPrevious(this->front);
        
        this->rear.setPrevious(elemento);
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
template <class X>
void LinkedQueue<X>::insertRear(const X& elem) {
    Nodo<X> *elemento = new Nodo<X> (elem);
    
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
 * Viaja a un punto N en la linked queue.
 * @param n
 */
template <class X>
X& LinkedQueue<X>::goTo(int n){
    Nodo<X> *temp = this->front->getNext();
    for (int i = 0; i<n; i++){
        temp = temp->getNext();
    }
}


template <class X>
void LinkedQueue<X>::addInList(const X &elem, int n){
    if(!isEmpty()){
    Nodo<X> *elemento = new Nodo<X>(elem);
    Nodo<X> *anterior = goTo(int n);
    Nodo<X> *siguiente = anterior->getNext();
    
    anterior->setNext(elemento);
    siguiente->setPrevious(elemento);
    elemento->setPrevious(anterior);
    elemento->setNext(siguiente);
    this->nElementos++;
    } else {
        throw std::underflow_error("EXCEPCION: No hay elementos en la lista.");
    }
}


template <class X>
void LinkedQueue<X>::eraseInList(int n){
    if(!isEmpty()){
        Nodo<X> *borrar = goTo (int n);
        
        borrar->getPrevious()->setNext(borrar->getNext());
        borrar->getNext()->setPrevious(borrar->getPrevious());
        delete borrar;
        this->nElementos--;
    } else {
        throw std::underflow_error("EXCEPCION: No hay elementos en la lista.");
    }
}




/**
 * Borrar el primer nodo de la Queue
 */
template <class X>
void LinkedQueue<X>::deleteFront(){
    if (isEmpty()){
        throw std::underflow_error("EXCEPCION: No hay elementos en la lista.");
    } else {
    Nodo<X> *delNodo = this->front->getNext();
    delNodo->getNext()->setPrevious(this->front);
    this->front->setNext(delNodo->getNext());
    delete delNodo;
    this->nElementos--;
    }
}

/**
 * Borrar el último nodo de la Queue
 */
template <class X>
void LinkedQueue<X>::deleteRear(){
    if (isEmpty()){
        throw std::underflow_error("EXCEPCION: No hay elementos en la lista.");
    } else {
        Nodo<X> *delNodo = this->rear->getPrevious();
        delNodo->getPrevious()->setNext(this->rear);
        this->rear->setPrevious(delNodo->getPrevious());
        delete delNodo;
        this->nElementos--;
    }
}

template <class X>
void LinkedQueue<X>::print() {
    std::stringstream vectorString;
    vectorString << "[";
    
    Nodo<X> *begin = front->getNext(); //Cogemos el primer nodo, no el centinela
    int cont = 0;
    int elementos = this->nElementos -1;
    while(begin->getNext() != nullptr) {
        vectorString << begin->getElement();
        if (cont < elementos){
            vectorString << ",";
        }
        begin = begin->getNext();
        cont++;
    }
    vectorString << "]";
    std::cout << vectorString.str() << std::endl;
}

#endif	/* LINKEDQUEUE_HPP */

