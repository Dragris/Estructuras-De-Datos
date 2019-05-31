/* 
 * File:   BSTMountainFinder.hpp
 * Author: dragr
 *
 * Created on 12 de abril de 2019, 18:45
 */

#ifndef BSTMOUNTAINFINDER_HPP
#define	BSTMOUNTAINFINDER_HPP
#include <stdlib.h>
#include <fstream>
#include <stdexcept>
#include <stdexcept>


#include "BinarySearchTree.hpp"
#include "Mountain.hpp"
using namespace std;
class BSTMountainFinder {
    public:
        //Constructores
        BSTMountainFinder();
        BSTMountainFinder(const BSTMountainFinder &orig);
        virtual ~BSTMountainFinder();
        //Consultores
        Mountain findMountain(int id);
        string showMountain(int id);
        int size();
        void print();
        int profundidad();
        //Modificadores
        void appendMountains(string filename);
        void insertMountain(int id, string name, float height);
    private:
        BinarySearchTree<Mountain> *bst;
        Mountain divisor(string &str);
};

//Constructores
BSTMountainFinder::BSTMountainFinder(){
    this->bst = new BinarySearchTree<Mountain>;
}

BSTMountainFinder::BSTMountainFinder(const BSTMountainFinder &orig){
    this->bst = new BinarySearchTree<Mountain>(*orig.bst);
    cout << "BSTMountainFinder copiado" << endl;
}

BSTMountainFinder::~BSTMountainFinder(){
    delete bst;
    cout << "BSTMountainFinder destruida" << endl;
}

//Consultores
Mountain BSTMountainFinder::findMountain(int id){
    Mountain mount = bst->searchMountain(id);
    if (mount.getKey() != id){
        throw invalid_argument("Montaña no encontrada.");
    }
    return mount;
}

string BSTMountainFinder::showMountain(int id){
    try{
       Mountain mount = findMountain(id);
       return mount.toString();
    } catch (exception& e){
        cout << e.what() << endl;
    }
}

int BSTMountainFinder::size(){
    return this->bst->size();
}

void BSTMountainFinder::print() {
    bst->printInorder40();
}

int BSTMountainFinder::profundidad(){
    return bst->height();
}

//Modificadores
/**
 * Método para insertar montañas desde un fichero dado su Filename.
 * @param filename
 */
void BSTMountainFinder::appendMountains(string filename){
    ifstream file(filename);
    string line;
    
    if(file.is_open()){
        while (getline(file, line)) {
            Mountain mount = divisor(line);
            bst->insert(mount, mount.getKey());
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
void BSTMountainFinder::insertMountain(int id, string name, float height){
    Mountain mount(id, name, height);
    bst->insert(mount, id);
}

/**
 * Divide los tres campos para obtener los diferentes parámetros.
 * @param str
 * @return 
 */
Mountain BSTMountainFinder::divisor(string& str){
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
    Mountain mount(id, nom, altura);
    return mount;
}

#endif	/* BSTMOUNTAINFINDER_HPP */

