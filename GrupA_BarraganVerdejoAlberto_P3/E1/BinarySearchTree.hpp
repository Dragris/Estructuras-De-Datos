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
        int size() const;
        int height();
        bool isEmpty();
        NodeTree<X>* root();
        void showPreorder() const;
        void showPostorder() const;
        void showInorder() const;
        void showLeafNodes();
        bool booleanSearch(const X& element);
        int min();
        //Modificadores
        void insert(const X &element);
    private:
        //Constructores y destructores
        void copiador(NodeTree<X> *p, const NodeTree<X> *orig); //Soporte
        void destructor(NodeTree<X> *p); //Soporte
        
        //Consultores
        int size (NodeTree<X>* p) const; //Soporte
        int height(NodeTree<X> *p); //Soporte
        void showLeafNodes(NodeTree<X> *p); //Soporte
        void preorder(NodeTree<X> *p) const; //Soporte
        void postorder(NodeTree<X> *p) const; //Soporte
        void inorder(NodeTree<X> *p) const; //Soporte
        int min(NodeTree<X> *min); //Soporte
        bool booleanSearch(const X &elemento, NodeTree<X> *p); //Soporte
        
        //Modificadores
        void insert(NodeTree<X> *p, NodeTree<X>* element); //Soporte
        
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
    copy(this->pRoot, orig.pRoot);
    std::cout << "Árbol copiado\n";
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
            copy(p.right(), orig->right());
        }
        if(orig->hasLeft()){
            p->setLeft(new NodeTree<X>(*orig->left()));
            p->left()->setParent(p);
            copy(p.left(), orig->left());    
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
int BinarySearchTree<X>::size() const{
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
    if (!isEmpty()){
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
    int left = height(p.left());
    int right = height(p.right());
    
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
    return (this->pRoot == nullptr); 
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
        cout << p->getElement(); //SOLO SIRVE PARA COSAS BÁSICAS
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
        cout << p->getElement(); //SOLO FUNCIONA PARA COSAS BÁSICAS
        if (p->hasRight()){
            cout << ", ";
            inorder(p->right());
        }
    }
}
/**
 * Devuelve todos los nodos externos del árbol.
 */
template<class X>
void BinarySearchTree<X>::showLeafNodes() {
    cout << "Hojas = {";
    showLeafNodes(this->pRoot);
    cout << "\b\b" << "} " << std::endl;
}
/**
 * Método de soporte para mostrar los nodos externos.
 * @param p
 */
template<class X>
void BinarySearchTree<X>::showLeafNodes(NodeTree<X> *p){
    if (p->isExternal()){
        cout << p->getElement() << ", "; //SOLO SIRVE PARA COSAS BÁSICAS
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
bool BinarySearchTree<X>::booleanSearch(const X &elemento){
    if (!isEmpty){
        return booleanSearch(elemento, pRoot);
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
bool BinarySearchTree<X>::booleanSearch(const X &elemento, NodeTree<X> *p){
    if (p == nullptr){
        return false;
    }
    
    if (elemento < p->getElement()){
       return booleanSearch(elemento, p->left());
    } else if (elemento > p->getElement()){
        return booleanSearch(elemento, p->right());
    }
    return true;
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
void BinarySearchTree<X>::insert(const X &element) {
    NodeTree<X> *newNode = new NodeTree<X>(element);
    if (isEmpty()) {
        this->pRoot = newNode;
        std::cout << "Inserta en el árbol el elemento: " << newNode->getElement() << std::endl;
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
    if (orig->getElement() < newNodo->getElement()){
        if(!orig->hasRight()){
            newNodo->setParent(orig);
            orig->setRight(newNodo);
            std::cout << "Inserta en el árbol el elemento: " << newNodo->getElement() << std::endl;
        } else{
            insert(newNodo, orig->right());
        }
    } else if (orig->getElement() > newNodo->getElement()){
        if (!orig->hasLeft()){
            newNodo->setParent(orig);
            orig->setLeft(newNodo);
            std::cout << "Inserta en el árbol el elemento: " << newNodo->getElement() << std::endl;
        } else{
            insert(newNodo, orig->left());
        }
    } else {
        throw ("Elemento repetido, normalmente se podría insertar pero lo excluimos para no generar errores de búsqueda.");
    }
}


#endif	/* BINARYSEARCHTREE_HPP */