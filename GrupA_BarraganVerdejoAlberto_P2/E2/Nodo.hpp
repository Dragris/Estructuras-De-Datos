/* 
 * File:   Nodo.hpp
 * Author: dragr
 *
 * Created on 6 de marzo de 2019, 12:15
 */

#ifndef NODO_HPP
#define	NODO_HPP

template <class X>
class Nodo {
    public:
        Nodo();
        Nodo(X elemento);
        virtual ~Nodo();
        Nodo(const Nodo& q);
        X& getElement();
        Nodo<X>* getNext();
        void setNext(Nodo<X>* next);
        Nodo<X>* getPrevious();
        void setPrevious(Nodo<X>* previous);
        
    private:
        X element;
        Nodo<X> *next;
        Nodo<X> *previous;
};


/**
 * Constructor por defecto
 */
template <class X>
Nodo<X>::Nodo() {
    this->next = nullptr;
    this->previous = nullptr;    
}

/**
 * Constructor con parámetro.
 * @param 
 */
template <class X>
Nodo<X>::Nodo(X elemento){
    this->next = nullptr;
    this->previous = nullptr;
    this->element = elemento;
}

/**
 * Constructor copia
 * @param q
 * @return 
 */
template <class X>
Nodo<X>::Nodo(const Nodo& NodoOrigen){
    std::cout << "Constructor copia -> Nodo(" << NodoOrigen.element << ")\n";
    this->element = NodoOrigen.element;
    this->next = nullptr;
    this->previous = nullptr;
}

/**
 * Método getNext.
 * @return 
 */
template <class X>
Nodo<X>* Nodo<X>::getNext(){
    return this->next;
}

/**
 * Método setNext, utilizando la dirección del siguiente Nodo.
 * @param next
 * @return 
 */
template <class X>
void Nodo<X>::setNext(Nodo<X>* next){
    this->next = next;
}

/**
 * Método getPrevious, devuelve el nodo anterior.
 * @return 
 */
template <class X>
Nodo<X>* Nodo<X>::getPrevious(){
    return this->previous;
}

/**
 * Método setPrevious, utilizando la dirección del nodo anterior.
 * @param previous
 * @return 
 */
template <class X>
void Nodo<X>::setPrevious(Nodo<X> *previous){
    this->previous = previous;
}
/**
 * Método getElement, te devuelve el elemento almacenado en el nodo.
 */
template <class X>
X& Nodo<X>::getElement(){
    return this->element;
}

/**
 * Método destructor.
 */
template <class X>
Nodo<X>::~Nodo(){
    std::cout << "Destructor -> Nodo(" << this->element << ")\n";
    this->next = nullptr;
    this->previous = nullptr;
}

#endif	/* NODO_HPP */