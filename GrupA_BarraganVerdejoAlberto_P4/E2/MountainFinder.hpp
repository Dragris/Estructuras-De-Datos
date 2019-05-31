/* 
 * File:   MountainFinder.hpp
 * Author: dragr
 *
 * Created on 16 de mayo de 2019, 16:45
 */

#ifndef MOUNTAINFINDER_HPP
#define	MOUNTAINFINDER_HPP
#include <stdlib.h>
#include <fstream>
#include <stdexcept>
#include <stdexcept>


#include "MaxHeap.hpp"
#include "Mountain.hpp"

/**
 * Se recicla y adapta de la Práctica 3 Ejercicio 2
 */
using namespace std;
class MountainFinder {
    public:
        //Constructores
        MountainFinder();
        MountainFinder(const MountainFinder &orig);
        virtual ~MountainFinder();
        //Consultores
        Mountain *findMountain(int id);
        string showMountain(int id);
        int size();
        void print();
        void fullPrint();
        int depth();
        //Modificadores
        void appendMountains(string filename);
        void insertMountain(int id, string name, float height);
    private:
        MaxHeap<Mountain> *heap;
        Mountain *divisor(string &str);
};
//Constructores
MountainFinder::MountainFinder(){
    this->heap = new MaxHeap<Mountain>;
}

MountainFinder::MountainFinder(const MountainFinder &orig){
    this->heap = new MaxHeap<Mountain>(*orig.heap);
    cout << "MountainFinder copiado" << endl;
}

MountainFinder::~MountainFinder(){
    delete heap;
    cout << "MountainFinder destruida" << endl;
}

//Consultores
Mountain *MountainFinder::findMountain(int id){
    return heap->search(id);
}

string MountainFinder::showMountain(int id){
    Mountain *mount = heap->search(id);
    if (mount->getKey() != id){
        throw invalid_argument("Montaña: " + std::to_string(id) + " no encontrada.");
    } else {
        return mount->toString();
    }
}

int MountainFinder::size(){
    return this->heap->size();
}


void MountainFinder::print() {
    MaxHeap<Mountain> *kopie = new MaxHeap<Mountain>(*heap);
    int cont = 1;
    while (!kopie->isEmpty()){
        if (cont == 41){
            string opc;
            cout << "Wollen Sie wiedergehen? Y|N" << endl;
            cin >> opc;
            if(opc == "Y" || opc == "y"){
                cont = 0;
            } else {
                break;
            }
        }
        cout << this->heap->maxValues()->toString() << endl;
        heap->popFront();
        cont++;
    }
    delete kopie;
}

void MountainFinder::fullPrint(){
    this->heap->printHeap();
}

int MountainFinder::depth(){
    int vaterPos = 0;
    int LPos = vaterPos * 2 + 1;
    
    int depth = 0;
    while(LPos < heap->size()){
        depth++;
        vaterPos = LPos;
        LPos = vaterPos * 2 + 1;
    }
    return depth;
}

//Modificadores
/**
 * Método para insertar montañas desde un fichero dado su Filename.
 * @param filename
 */
void MountainFinder::appendMountains(string filename){
    ifstream file(filename);
    string line;
    
    if(file.is_open()){
        while (getline(file, line)) {
            Mountain *mount = divisor(line);
            heap->insert(mount->getKey(), mount);
        }
    } else {
        throw runtime_error ("Error al leer el archivo.");
    }
    file.close();
}
/**
 * Método para insertar una montaña en el BST dados sus parámetros.
 * @param id
 * @param name
 * @param height
 */
void MountainFinder::insertMountain(int id, string name, float height){
    heap->insert(id, new Mountain(id, name, height));
}

/**
 * Divide los tres campos para obtener los diferentes parámetros.
 * @param str
 * @return 
 */
Mountain *MountainFinder::divisor(string& str){
    string items[2];
    string temp;
    int pos;
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ':' && str[i+1] == ':') {
            temp = str.substr(0,i);
            items[pos] = temp;
            pos++;
            str = str.substr(i+2);
        }
    }
    int id = stoi(items[0]);
    string nom = items[1];
    float altura = stof(str);
    return new Mountain(id, nom, altura);

}
#endif	/* MOUNTAINFINDER_HPP */

