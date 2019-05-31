/* 
 * File:   MaxHeap.hpp
 * Author: dragr
 *
 * Created on 13 de mayo de 2019, 17:26
 */
#include <iostream>
#include <stdexcept>
#include <vector>
#include <iterator>
#include "Knoten.hpp"

#ifndef MAXHEAP_HPP
#define	MAXHEAP_HPP

using namespace std;
template<class X>
class MaxHeap {
    public:
        //Constructores
        MaxHeap();
        MaxHeap(MaxHeap<X> &ursprung);
        virtual ~MaxHeap();

        //Consultores
        int size();
        bool isEmpty();
        int max() const;
        X *maxValues();
        void printHeap();
        X *search(int schlussel);
        X *searchMountain(int schlussel);
        X *mountainAt(int pos);
        void printInorder40(int &n, Knoten<X> *p);
        
        //Modificadores
        void removeMax();
        void insert(const int &schlussel, X *wert);
        void popFront();
    private:
        //Constructores
        vector<Knoten<X>*> *heap;
        
        //Consultores
        int parentPos(int knoten);
        int sonsPos(int vater);
        
        //Modificadores
        
        
};
    
//Constructores

/**
 * Constructor predeterminado.
 */
template<class X>
MaxHeap<X>::MaxHeap(){
    this->heap = new vector<Knoten<X>*>();
    cout << "MaxHeap " << this << " wurde erstellt." << endl;
}

/**
 * Constructor copia.
 * @param key
 * @param wert
 */
template<class X>
MaxHeap<X>::MaxHeap(MaxHeap<X> &ursprung){
    this->heap = new vector<Knoten<X>*>();
    
    Knoten<X> *kn;
    for (auto p = ursprung.heap->begin(); p != ursprung.heap->end(); p++){
        kn = *p;
        this->heap->push_back(new Knoten<X>(*kn));
    }
    cout << "MaxHeap " << &ursprung << " wurde kopiert." << endl;
}

/**
 * Destructor de MaxHeap.
 */
template<class X>
MaxHeap<X>::~MaxHeap(){
    Knoten<X> *kn;
    for (auto p = this->heap->begin(); p != this->heap->end(); p++){
        kn = *p;
        delete kn;
    }
    cout << "Dieses MaxHeap wurde zerstört." << endl;
}

//Consultores
/**
 * Método que devuelve la posición del padre dada la posición del
 * nodo actual.
 * @param knoten
 * @return 
 */
template<class X>

int MaxHeap<X>::parentPos(int knoten){
    int vaterPos;
    if (knoten % 2 == 0){
        return vaterPos = ((knoten - 2) / 2 < 0)? 0 : (knoten - 2)/ 2;
    } else {
        return vaterPos = ((knoten - 1) / 2 < 0)? 0 : (knoten - 1)/ 2;
    }
}

/**
 * Devuelve la posición de los hijos para el método removeMax.
 * @param vater
 * @return 
 */
template<class X>
int MaxHeap<X>::sonsPos(int vater){
    int LSonPos = vater * 2 + 1;
    int RSonPos = vater * 2 + 2;
    int pos = vater;
    
    if (LSonPos < this->heap->size() && this->heap->at(pos)->schlusselHolen() < this->heap->at(LSonPos)->schlusselHolen()){
        pos = LSonPos;
    }
    if (RSonPos < this->heap->size() && this->heap->at(pos)->schlusselHolen() < this->heap->at(RSonPos)->schlusselHolen()){
        pos = RSonPos;
    }
    return pos;
}


/**
 * Devuelve el tamaño del heap.
 * @return 
 */
template<class X>
int MaxHeap<X>::size(){
    return this->heap->size();
}

/**
 * Devuelve si el heap está vacío.
 * @return 
 */
template<class X>
bool MaxHeap<X>::isEmpty(){
    return this->heap->empty();
}

/**
 * Devuelve la key mayor.
 * @return 
 */
template<class X>
int MaxHeap<X>::max() const{
    return this->heap->at(0)->schlusselHolen();
}

/**
 * Devuelve el valor asociado a la key mayor.
 * @return 
 */
template<class X>
X* MaxHeap<X>::maxValues(){
    return this->heap->at(0)->wertHolen();
}

/**
 * Método para imprimir el heap completo.
 */
template<class X>
void MaxHeap<X>::printHeap(){
    Knoten<X> *kn;
    for (auto p = this->heap->begin(); p != this->heap->end(); p++){
        kn = *p;
        cout << kn->wertHolen()->toString() << endl;
    }
}

/**
 * Busca un nodo
 * @param schlussel
 * @return 
 */
template<class X>
X *MaxHeap<X>::search(int schlussel){
    Knoten<X> *kn;
    for (auto p = this->heap->begin(); p != this->heap->end(); p++){
        kn = *p;
        if (kn->schlusselHolen() == schlussel){
            return kn->wertHolen();
        }
    }
}

/**
 * Devuelve la montaña que se encuentra en la posición pasada por parámetro.
 * @param pos
 * @return 
 */
template<class X>
X *MaxHeap<X>::mountainAt(int pos){
    return this->heap->at(pos)->wertHolen();
}

//Modificadores

/**
 * Elimina el vector con key mayor
 */
template<class X>
void MaxHeap<X>::removeMax(){
    if(!isEmpty()){
        swap(this->heap->at(0), this->heap->at(this->heap->size() - 1));
        this->heap->pop_back();
        if(!isEmpty()){
            //DownHeap
            int vaterPos = 0;
            int sonPos = sonsPos(vaterPos);
            while(this->heap->at(vaterPos)->schlusselHolen() < this->heap->at(sonsPos())->schlusselHolen()){
                swap(this->heap->at(vaterPos), this->heap->at(sonPos));
                vaterPos = sonPos;
                sonPos = sonsPos(vaterPos);
            }
        }
    } else {
        throw underflow_error ("MaxHeap leer!");
    }
}

/**
 * Método para insertar nodos en el Heap.
 * Realiza UpHeap para garantizar que prevalece la relación padre > hijos.
 * @param schlussel
 * @param wert
 */
template<class X>
void MaxHeap<X>::insert(const int& schlussel, X* wert){
    this->heap->push_back(new Knoten<X>(schlussel, wert));
    
    int knotenPos = this->heap->size() - 1;
    int vaterPos = parentPos(knotenPos);
    //UpHeap
    while(this->heap->at(vaterPos)->schlusselHolen() < this->heap->at(knotenPos)->schlusselHolen()) {
        swap(this->heap->at(vaterPos), this->heap->at(knotenPos));
        knotenPos = vaterPos;
        vaterPos = parentPos(knotenPos);
    }
}


template<class X>
void MaxHeap<X>::popFront(){
    this->heap->erase(heap->begin());
}
#endif	/* MAXHEAP_HPP */

