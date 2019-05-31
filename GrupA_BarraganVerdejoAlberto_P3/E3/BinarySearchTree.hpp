/* 
 * File:   BinarySearchTree.hpp
 * Author: dragr
 *
 * Created on 9 de abril de 2019, 11:20
 */


#ifndef BINARYSEARCHTREE_HPP
#define	BINARYSEARCHTREE_HPP
#include "NodeTree.hpp"
#include <string>
#include<iostream>

using namespace std;
template <class X>
class BinarySearchTree {
    public:
        //Constructores y destructores
        BinarySearchTree();
        BinarySearchTree(const BinarySearchTree &orig);
        virtual ~BinarySearchTree();
        
        //Consultores
        int size();
        int height();
        bool isEmpty();
        NodeTree<X>* root();
        void showPreorder() const;
        void showPostorder() const;
        void showInorder() const;
        void printInorder40();
        void showLeafNodes();
        bool booleanSearch(const X& key);
        int min();
        X searchMountain(const int &key);
        
        //Modificadores
        void insert(const X &element, const int &key);
    private:
        //Constructores y destructores
        void copiador(NodeTree<X> *p, const NodeTree<X> *orig); 
        void destructor(NodeTree<X> *p); 
        
        //Consultores
        int size (NodeTree<X>* p) const; 
        int height(NodeTree<X> *p); 
        void showLeafNodes(NodeTree<X> *p);
        void preorder(NodeTree<X> *p) const;
        void postorder(NodeTree<X> *p) const;
        void inorder(NodeTree<X> *p) const; 
        int min(NodeTree<X> *min); 
        bool booleanSearch(const X &elemento, NodeTree<X> *p);
        NodeTree<X>* searchMountain(const int &key, NodeTree<X> *p);
        void printInorder40(int &n, NodeTree<X> *p);
        
        //Modificadores
        void insert(NodeTree<X> *p, NodeTree<X>* element);
        
        //Atributos
        NodeTree<X>* pRoot;
};
//Constructores

//Constructor vacío
template<class X>
BinarySearchTree<X>::BinarySearchTree(){
    this->pRoot = nullptr;
}
//Copia
/**
 * Constructor copia.
 * @param orig
 */
template<class X>
BinarySearchTree<X>::BinarySearchTree(const BinarySearchTree& orig){
    this->pRoot = new NodeTree<X>(*orig.pRoot);
    copiador(this->pRoot, orig.pRoot);
    cout << "Árbol copiado\n";
}
/**
 * Método de soporte para copiar el árbol, usamos recorrido preorden.
 * @param p
 * @param orig
 */
template<class X>
void BinarySearchTree<X>::copiador(NodeTree<X> *p, const NodeTree<X> *orig){
    if (orig != nullptr){
        if(orig->hasRight()){
            p->setRight(new NodeTree<X>(*orig->right()));
            p->right()->setParent(p);
            copiador(p->right(), orig->right());
        }
        if(orig->hasLeft()){
            p->setLeft(new NodeTree<X>(*orig->left()));
            p->left()->setParent(p);
            copiador(p->left(), orig->left());    
        }
    }
}

//Destructor
/**
 * Método destructor.
 */
template<class X>
BinarySearchTree<X>::~BinarySearchTree(){
    destructor(pRoot);
    cout << "Árbol eliminado\n";
}

/**
 * Método de soporte para destruir el árbol, usamos recorrido postorden.
 * @param p
 */
template<class X>
void BinarySearchTree<X>::destructor(NodeTree<X> *p){
    if(p != nullptr) {
        destructor(p->right());
        destructor(p->left());
        //Vas visitando los nodos antes de borrarlos, por eso es postorden, bobo, que eres bobo Alberto.
        delete p;
    }
}
//Consultores

//Size
/**
 * Devuelve el tamaño del árbol.
 * @return 
 */
template<class X>
int BinarySearchTree<X>::size(){
    if (isEmpty()){
        return 0;
    } else {
        return 1 + size(this->pRoot);
    }
}

/**
 * Recorre el árbol desde el nodo dado para calcular su tamaño.
 * Se usa como soporte para calcular el tamaño de un árbol.
 * @param p
 * @return 
 */
template <class X>
int BinarySearchTree<X>::size(NodeTree<X>* p) const{
    int contador = 0;
    if (p != nullptr){
        if (p->hasRight()){
            contador += 1 + size(p->right());
        }
        if (p->hasLeft()){
            contador += 1 + size(p->left());
        }
    }
    return contador;
}
/**
 * Devuelve la altura del árbol binario.
 * @return 
 */
template<class X>
int BinarySearchTree<X>::height(){
    if (isEmpty()){
        return 0;
    } else {
      height(this->pRoot);  
    }
}
/**
 * Devuelve la altura de un nodo concreto.
 * Se usa como soporte para devolver la altura del árbol.
 * @param p
 * @return 
 */
template<class X>
int BinarySearchTree<X>::height(NodeTree<X> *p){
    if (p == nullptr){
        return -1;
    }
    int left = height(p->left());
    int right = height(p->right());
    
    if(left > right){
        return left + 1;
    } else {
        return right + 1;
    }
}
/**
 * Devuvelve true si el árbol está vacío.
 * @return 
 */
template<class X>
bool BinarySearchTree<X>::isEmpty(){
    return (pRoot == nullptr); 
}
/**
 * Devuelve el nodo Raíz.
 * @return 
 */
template<class X>
NodeTree<X>* BinarySearchTree<X>::root(){
    return this->pRoot;
}
/**
 * Imprime el árbol con Preorder.
 */
template<class X>
void BinarySearchTree<X>::showPreorder() const{
    cout << "Preorden: {";
    preorder(this->pRoot);
    cout << "}" << endl;
}
/**
 * Método recursivo de soporte para preorder.
 * @param p
 */
template<class X>
void BinarySearchTree<X>::preorder(NodeTree<X> *p) const{
    if (p != nullptr){
        cout << p->getElement(); //SOLO SIRVE PARA COSAS BÁSICAS, editar print de element
        if (p->hasLeft()){
            cout << ", ";
            preorder(p->left());
        }
        if (p->hasRight()){
            cout << ", ";
            preorder(p->right());
        }
    }
    
}
/**
 * Imprime el árbol con Postorder.
 */
template<class X>
void BinarySearchTree<X>::showPostorder() const{
    cout << "Postorden: {";
    postorder(this->pRoot);
    cout << "}" << endl;
}
/**Método recursivo de soporte para postorder.
 * 
 * @param p
 */
template<class X>
void BinarySearchTree<X>::postorder(NodeTree<X>* p) const{
    if (p != nullptr){
        if (p->hasLeft()){
            postorder(p->left());
            cout << ", ";
        }
        if (p->hasRight()){
            postorder(p->right());
            cout << ", ";
        }
        cout << p->getElement();
    }
}
/**
 * Imprime el árbol con Inorder.
 */
template<class X>
void BinarySearchTree<X>::showInorder() const{
    cout << "Inorden: {";
    inorder(this->pRoot);
    cout << "}" << endl;
}
/**
 * Método recursivo de soporte para inorder.
 * @param p
 */
template<class X>
void BinarySearchTree<X>::inorder(NodeTree<X> *p) const{
    if (p != nullptr){
        if (p->hasLeft()){
            inorder(p->left());
            cout << ", ";
        }
        cout << p->getElement(); //SOLO FUNCIONA PARA COSAS BÁSICAS, editar print de element
        if (p->hasRight()){
            cout << ", ";
            inorder(p->right());
        }
    }
}
/**
 * Llamada al método para imprimir nodos en orden de Key.
 */
template<class X>
void BinarySearchTree<X>::printInorder40() {
    int n = 0;
    printInorder40(n, pRoot);
}

template<class X>
void BinarySearchTree<X>::printInorder40(int &n, NodeTree<X> *p){
    if (p != nullptr){
        return;
    }
    if (n < 41) {
        printInorder40(n, p->left());
        n++;
        
        if (n < 41) {
            cout << p->getElement() << endl;
        }
        
        if (n == 40){
            string opc;
            cout << "¿Quiere seguir? (Y|N)" << endl;
            cin >> opc;
            if (opc == "Y" || opc == "y") {
                n = 0;
            }
        }
        printInorder40(n, p->right());
    }
}
/**
 * Devuelve todos los nodos externos del árbol.
 */
template<class X>
void BinarySearchTree<X>::showLeafNodes() {
    cout << "Hojas = {";
    showLeafNodes(this->pRoot);
    cout << "\b\b" << "} " << endl;
}
/**
 * Método de soporte para mostrar los nodos externos.
 * @param p
 */
template<class X>
void BinarySearchTree<X>::showLeafNodes(NodeTree<X> *p){
    if (p->isExternal()){
        cout << p->getElement() << ", "; //SOLO SIRVE PARA COSAS BÁSICAS, editar print de element
    } else {
        if (p->hasLeft()){
            showLeafNodes(p->left());
        }
        if (p->hasRight()){
            showLeafNodes(p->right());
        }
    }
}
/**
 * Búsqueda de un elemento por ID (montañas).
 * @return 
 */
template<class X>
bool BinarySearchTree<X>::booleanSearch(const X &key){
    if (!isEmpty){
        return booleanSearch(key, pRoot);
    }
    return false;
}
/**
 * Método de soporte para booleanSearch.
 * @param elemento
 * @param p
 * @return 
 */
template<class X>
bool BinarySearchTree<X>::booleanSearch(const X &key, NodeTree<X> *p){
    if (p == nullptr){
        return false;
    }
    
    if (key < p->getKey()){
       return booleanSearch(key, p->left());
    } else if (key > p->getKey()){
        return booleanSearch(key, p->right());
    }
    return true;
}

/**
 * Busca y devuelve el nodo del árbol.
 * @param element
 * @return bool
 */
template <class X>
X BinarySearchTree<X>::searchMountain(const int &key) {
    return searchMountain(key, pRoot)->getElement();
}

/**
 * Función de soporte para realizar la búsqueda.
 * @param element
 * @param p
 * @return Type
 */
template <class X>
NodeTree<X> *BinarySearchTree<X>::searchMountain(const int &key, NodeTree<X> *p) {
    if (p == nullptr) {
        return pRoot;
    }
    if (key < p->getKey()) {
        return searchMountain(key, p->left());
    } else if (key > p->getKey()) {
        return searchMountain(key, p->right());
    }
    return p;
}


/**
 * Función mínimo, clase de problemas.
 * @return 
 */
template<class X>
int BinarySearchTree<X>::min() {
    NodeTree<X> *newNodo = new NodeTree<X>();
    if(!isEmpty()){
    newNodo = this->pRoot;
        if (newNodo.hasLeft()){
            return min(newNodo);
        } else {
            return newNodo->getElement();
        }
    } else {
        throw ("No hay árbol en el que buscar.");
    }
}
/**
 * Método de apoyo para la función mínimo, clase de problemas.
 * @param min
 * @return 
 */
template<class X>
int BinarySearchTree<X>::min(NodeTree<X> *min){
    if (min->hasLeft()){
       return min(min);
    } else {
        return min->getElement();
    }
}

//Modificadores
/**
 * Método para insertar elementos en el árbol binario.
 * @param element
 */
template <class X>
void BinarySearchTree<X>::insert(const X &element, const int &key) {
    NodeTree<X> *newNode = new NodeTree<X>(element, key);
    if (isEmpty()) {
        this->pRoot = newNode;
        cout << "Inserta en el árbol el elemento: " << newNode->getElement() << endl;
    } else {
        insert(newNode, pRoot);
    }
}
/**
 * Método de soporte para insertar elementos en el árbol binario.
 * @param newNodo
 * @param orig
 */
template<class X>
void BinarySearchTree<X>::insert(NodeTree<X> *newNodo, NodeTree<X>* orig ){
    if (orig->getKey() < newNodo->getKey()){
        if(!orig->hasRight()){
            newNodo->setParent(orig);
            orig->setRight(newNodo);
            cout << "Inserta en el árbol el elemento: " << newNodo->getElement() << endl;
        } else{
            insert(newNodo, orig->right());
        }
    } else if (orig->getKey() > newNodo->getKey()){
        if (!orig->hasLeft()){
            newNodo->setParent(orig);
            orig->setLeft(newNodo);
            cout << "Inserta en el árbol el elemento: " << newNodo->getElement() << endl;
        } else{
            insert(newNodo, orig->left());
        }
    } else {
        throw ("Elemento repetido, normalmente se podría insertar pero lo excluimos para no generar errores de búsqueda.");
    }
}

#endif	/* BINARYSEARCHTREE_HPP */