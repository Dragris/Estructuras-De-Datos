/* 
 * File:   ArrayQueue.cpp
 * Author: dragr
 * 
 * Created on 26 de febrero de 2019, 11:25
 */

#include "ArrayQueue.h"

#include <vector>
#include <string>
#include <valarray>
#include <iostream>

ArrayQueue::ArrayQueue(){
}

ArrayQueue::ArrayQueue(const int size) {
    this->MAX_Size = size;
}

ArrayQueue::ArrayQueue(const ArrayQueue& orig) {
}

ArrayQueue::~ArrayQueue() {
}

void ArrayQueue::enqueue(int key){
    if (!isFull()){
        this->data.push_back(key);
        std::cout << "Elemento " << key << " agregado.\n";
    } else{
        throw std::runtime_error("Atención, capacidad del contenedor llena.");
    }
}

void ArrayQueue::dequeue(){
    if (!isEmpty()){
        std::cout << "Elemento " << data.at(0) << " eliminado. \n";
        this->data.erase(data.begin());
    } else {
        throw std::runtime_error("Atención, el contenedor está vacío.");
    }
}

bool ArrayQueue::isEmpty(){
    return this->data.size() == 0;
}


bool ArrayQueue::isFull(){
    return this->data.size() >= this->MAX_Size;
}

int ArrayQueue::getFront(){
    return this->data.at(0);
}

void ArrayQueue::print(){
    std::cout << "Los valores son: ";
    int p = this->data.size()-1;
    for (int i = 0; i <= p ; i++){
        //std::cout << "El tamaño es " << p << ", i es " << i << std::endl;
        if (i == p){
            std::cout << this->data.at(i) << ".\n";
        } else {
            std::cout << this->data.at(i) << ", ";
        }
        //std::cout << this->data.at(i) << ", ";
    }
}