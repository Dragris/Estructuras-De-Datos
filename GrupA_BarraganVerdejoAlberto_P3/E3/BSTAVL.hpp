/* 
 * File:   BSTAVL.hpp
 * Author: dragr
 *
 * Created on 1 de mayo de 2019, 17:30
 */

#ifndef BSTAVL_HPP
#define	BSTAVL_HPP

#include <iostream>
#include <vector>
#include "Mountain.hpp"
#include "NodeTree.hpp"
#include <string>
#include <vector>
using namespace std;
template<class X>
class BSTAVL {
public:
    //Constructor
    BSTAVL();
    BSTAVL(const BSTAVL &orig);
    virtual ~BSTAVL();
    
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
    X searchMountain(const int &key);
    string nombreMasLargo();
    vector<float> minMaxAltura();
    float minAltura();
    float maxAltura();
    
    //Modificadores
    void insert(const X &element, const int &key);
    void insert(const X &element);
    
private:
    //Constructores
    void copiador(NodeTree<X> *p, const NodeTree<X> *orig);
    void destructor(NodeTree<X> *p); 
    
    //Consultores
    int size (NodeTree<X>* p) const; 
    int height(NodeTree<X> *p);
    void preorder(NodeTree<X> *p) const;
    void postorder(NodeTree<X> *p) const;
    void inorder(NodeTree<X> *p) const; 
    void printInorder40(int &n, NodeTree<X> *p);
    void showLeafNodes(NodeTree<X> *p);
    bool booleanSearch(const X &elemento, NodeTree<X> *p);
    NodeTree<X>* searchMountain(const int &key, NodeTree<X> *p);
    int BalanceFact(NodeTree<X> *p);
    void checkRotation(NodeTree<X> *p);
    void nombreMasLargo(string &max, NodeTree<X> *p);
    void minAltura(float &min, NodeTree<X> *P);
    void maxAltura(float &max, NodeTree<X> *p);
    
    //Modificadores
    void insert(NodeTree<X> *p, NodeTree<X>* element);
    void leftRotation(NodeTree<X> *p);
    void rightRotation(NodeTree<X> *orig);
    void leftRightRotation(NodeTree<X> *orig);
    void rightLeftRotation(NodeTree<X> *orig);
    //Atributos
    NodeTree<X>* pRoot;
};

//Constructores
template<class X>
BSTAVL<X>::BSTAVL(){
    this->pRoot = nullptr;
}

template<class X>
BSTAVL<X>::BSTAVL(const BSTAVL& orig){
    this->pRoot = new NodeTree<X>(*orig.pRoot);
    copiador(this->pRoot, orig.pRoot);
    cout << "Árbol copiado" << endl;
}

template<class X>
void BSTAVL<X>::copiador(NodeTree<X> *p, const NodeTree<X> *orig){
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

template<class X>
BSTAVL<X>::~BSTAVL(){
    destructor(pRoot);
    cout << "Árbol eliminado\n";
}

template<class X>
void BSTAVL<X>::destructor(NodeTree<X> *p){
    if(p != nullptr) {
        destructor(p->right());
        destructor(p->left());
        //Vas visitando los nodos antes de borrarlos, por eso es postorden, bobo, que eres bobo Alberto.
        delete p;
    }
}


//Consultores
/**
 * Devuelve el número de nodos del árbol.
 * @return 
 */
template<class X>
int BSTAVL<X>::size(){
    if (isEmpty()){
        return 0;
    } else {
        return 1 + size(this->pRoot);
    }
}
/**
 * Devuelve el número de nodos del subárbol p.
 * @param p
 * @return 
 */
template <class X>
int BSTAVL<X>::size(NodeTree<X>* p) const{
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


template<class X>
int BSTAVL<X>::height(){
    return this->pRoot->getHeight();
}

template<class X>
int BSTAVL<X>::height(NodeTree<X> *p){
    return p->getHeight();
}

template<class X>
bool BSTAVL<X>::isEmpty(){
    return this->pRoot == nullptr;
}

template<class X>
NodeTree<X>* BSTAVL<X>::root(){
    return this->pRoot;
}

/**
 * Imprime el árbol con Preorder.
 */
template<class X>
void BSTAVL<X>::showPreorder() const{
    cout << "Preorden: {";
    preorder(this->pRoot);
    cout << "}" << endl;
}
/**
 * Método recursivo de soporte para preorder.
 * @param p
 */
template<class X>
void BSTAVL<X>::preorder(NodeTree<X> *p) const{
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
void BSTAVL<X>::showPostorder() const{
    cout << "Postorden: {";
    postorder(this->pRoot);
    cout << "}" << endl;
}
/**Método recursivo de soporte para postorder.
 * 
 * @param p
 */
template<class X>
void BSTAVL<X>::postorder(NodeTree<X>* p) const{
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
void BSTAVL<X>::showInorder() const{
    cout << "Inorden: {";
    inorder(this->pRoot);
    cout << "}" << endl;
}
/**
 * Método recursivo de soporte para inorder.
 * @param p
 */
template<class X>
void BSTAVL<X>::inorder(NodeTree<X> *p) const{
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
void BSTAVL<X>::printInorder40() {
    int n = 0;
    printInorder40(n, pRoot);
}

template<class X>
void BSTAVL<X>::printInorder40(int &n, NodeTree<X> *p){
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
void BSTAVL<X>::showLeafNodes() {
    cout << "Hojas = {";
    showLeafNodes(this->pRoot);
    cout << "\b\b" << "} " << endl;
}

/**
 * Método de soporte para mostrar los nodos externos.
 * @param p
 */
template<class X>
void BSTAVL<X>::showLeafNodes(NodeTree<X> *p){
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
bool BSTAVL<X>::booleanSearch(const X &key){
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
bool BSTAVL<X>::booleanSearch(const X &key, NodeTree<X> *p){
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
X BSTAVL<X>::searchMountain(const int &key) {
    return searchMountain(key, pRoot)->getElement();
}

/**
 * Función de soporte para realizar la búsqueda.
 * @param element
 * @param p
 * @return Type
 */
template <class X>
NodeTree<X> *BSTAVL<X>::searchMountain(const int &key, NodeTree<X> *p) {
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
 * Calcula y devuelve el factor de balance.
 * @param p
 * @return 
 */
template<class X>
int BSTAVL<X>::BalanceFact(NodeTree<X> *orig) {
    int left = 0, right = 0;
    
    if (orig->hasLeft()){
        left = orig->left()->getHeight();
    }
    if (orig->hasRight()){
        right = orig->right()->getHeight();
    }
    return left - right;
}

template<class X>
void BSTAVL<X>::checkRotation(NodeTree<X> *orig) {
    int bf = BalanceFact(orig);
    
    if (bf > 1 && BalanceFact(orig->left()) > 0) {//Rota derecha
        rightRotation(orig);
    } else if (bf < -1 && BalanceFact(orig->right()) <= 0){//Rota izquierda
        leftRotation(orig);
    } else if (bf > 1 && BalanceFact(orig->left()) <= 0){//Rota izq + der
        leftRightRotation(orig);
    } else if (bf < -1 && BalanceFact(orig->right()) > 0){//Rota der + izq
        rightLeftRotation(orig);
    }
}

/**
 * Devuelve la montaña con el nombré más largo del BST.
 * @return 
 */
template<class X>
string BSTAVL<X>::nombreMasLargo(){
    string max = pRoot->getElement().getName();
    nombreMasLargo(max, this->pRoot);
    return max;
}
/**
 * Devuelve la montaña con el nombre más largo desde el nodo dado.
 * @param max
 * @param orig
 */
template<class X>
void BSTAVL<X>::nombreMasLargo(string &max, NodeTree<X> *orig){
    if (orig != nullptr){
        if (max.length() < orig->getElement().getName().lenght()) {
            max = orig->getElement().getName();
        }
        nombreMasLargo(max, orig->left());
        nombreMasLargo(max, orig->right());
    }
}

template<class X>
vector<float> BSTAVL<X>::minMaxAltura() {
    vector<float> minMax = new vector<float>(2);
    minMax[0] = minAltura();
    minMax[1] = maxAltura();
     
    return minMax;
}


/**
 * Devuelve la altura mínima de las montañas del BST.
 * @return 
 */
template<class X>
float BSTAVL<X>::minAltura(){
    float min = pRoot->getElement().getHeight();
    minAltura(min, this->pRoot);
    return min;
}

/**
 * Devuelve la altura mínima de las montañas desde el nodo dado.
 * @param min
 * @param orig
 */
template<class X>
void BSTAVL<X>::minAltura(float& min, NodeTree<X>* orig){
    if (orig != nullptr){
        if(min > orig->getElement().getHeight()){
            min = orig->getElement().getHeight();
        }
        minAltura(min,orig->left());
        minAltura(min,orig->right());
    }
}

/**
 * Devuelve la altura máxima de las montañas del BST.
 * @return 
 */
template<class X>
float BSTAVL<X>::maxAltura(){
    float max = pRoot->getElement().getHeight();
    maxAltura(max, this->pRoot);
    return max;
}

/**
 * Devuelve la altura máxima de las montañas desde el nodo dado.
 * @param max
 * @param orig
 */
template<class X>
void BSTAVL<X>::maxAltura(float& max, NodeTree<X>* orig){
    if (orig != nullptr){
        if (max < orig->getElement().getHeight()){
            max = orig->getElement().getHeight();
        }
        maxAltura(max, orig->left());
        maxAltura(max, orig->right());
    }
}
//Modificadores

/**
 * Método para insertar elementos en el árbol binario.
 * @param element
 */
template <class X>
void BSTAVL<X>::insert(const X &element, const int &key) {
    NodeTree<X> *newNode = new NodeTree<X>(element, key);
    if (isEmpty()) {
        this->pRoot = newNode;
        cout << "Inserta en el árbol el elemento: " << newNode->getElement() << endl;
    } else {
        insert(newNode, pRoot);
    }
}
/**
 * Método para insertar elementos en el árbol binario.
 * @param element
 */
template <class X>
void BSTAVL<X>::insert(const X &element) {
    NodeTree<X> *newNode = new NodeTree<X>(element, element);
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
void BSTAVL<X>::insert(NodeTree<X> *newNodo, NodeTree<X>* orig ){
    if (orig->getKey() < newNodo->getKey()){
        if(!orig->hasRight()){
            newNodo->setParent(orig);
            orig->setRight(newNodo);
            orig->setHeight((orig->getHeight() < newNodo->getHeight() + 1)? newNodo->getHeight() + 1 : orig->getHeight());
            cout << "Inserta en el árbol el elemento: " << newNodo->getElement() << endl;
            checkRotation(orig);
        } else{
            insert(newNodo, orig->right());
            orig->setHeight((orig->getHeight() < orig->right()->getHeight() + 1)? orig->right()->getHeight() + 1 : orig->getHeight());
            checkRotation(orig);
        }
    } else if (orig->getKey() > newNodo->getKey()){
        if (!orig->hasLeft()){
            newNodo->setParent(orig);
            orig->setLeft(newNodo);
            orig->setHeight((orig->getHeight() < newNodo->getHeight() + 1)? newNodo->getHeight() + 1 : orig->getHeight());
            cout << "Inserta en el árbol el elemento: " << newNodo->getElement() << endl;
            checkRotation(orig);
        } else{
            insert(newNodo, orig->left());
            orig->setHeight((orig->getHeight() < orig->left()->getHeight() + 1)? orig->left()->getHeight() + 1 : orig->getHeight());
            checkRotation(orig);
        }
    } else {
        cout <<"Elemento repetido, normalmente se podría insertar pero lo excluimos para no generar errores de búsqueda." << endl;
    }
}
/**
 * Método para rotar a la izquierda el BST.
 * @param orig
 */
template<class X>
void BSTAVL<X>::leftRotation(NodeTree<X> *orig) {
    NodeTree<X> *RSon = orig->right();
    if (orig->isGRoot()){
        pRoot = RSon;
        RSon->setParent(nullptr);
    } else {
        RSon->setParent(orig->parent());
        if (RSon->getKey() < orig->parent()->getKey()){
            orig->parent()->setLeft(RSon);
        } else {
            orig->parent()->setRight(RSon);
        }
    }
    orig->setParent(orig->right());
    if (!RSon->hasLeft()){
        orig->setRight(nullptr);
    } else {
        RSon->left()->setParent(orig);
        orig->setRight(RSon->left());
    }
    RSon->setLeft(orig);
    //Alturas
    int RH, LH;
    
    if (orig->hasLeft()){
        LH = orig->left()->getHeight();
    } else {
        LH = 0;
    }
    if (orig->hasRight()){
        RH = orig->right()->getHeight();
    } else {
        RH = 0;
    }
    if (LH > RH){
        orig->setHeight(LH + 1);
    } else {
        orig->setHeight(RH + 1);
    }
    
    if (RSon->hasLeft()){
        LH = RSon->left()->getHeight();
    } else {
        LH = 0;
    }
    if (RSon->hasRight()){
        RH = RSon->right()->getHeight();
    } else {
        RH = 0;
    }
    if (LH > RH){
        RSon->setHeight(LH + 1);
    } else {
        RSon->setHeight(RH + 1);
    }
}

/**
 * Método para rotar a la derecha el BST.
 * @param orig
 */
template<class X>
void BSTAVL<X>::rightRotation(NodeTree<X> *orig) {
    NodeTree<X> *LSon = orig->left();
    if (orig->isGRoot()){
        pRoot = LSon;
        LSon->setParent(nullptr);
    } else {
        LSon->setParent(orig->parent());
        if (LSon->getKey() < orig->parent()->getKey()){
            orig->parent()->setLeft(LSon);
        } else {
            orig->parent()->setRight(LSon);
        }
    }
    orig->setParent(LSon);
    if (!LSon->hasRight()){
        orig->setLeft(nullptr);
    } else {
        LSon->right()->setParent(orig);
        orig->setLeft(LSon->right());
    }
    LSon->setRight(orig);
    //Alturas
    int RH, LH;
    
    if (orig->hasLeft()){
        LH = orig->left()->getHeight();
    } else {
        LH = 0;
    }
    if (orig->hasRight()){
        RH = orig->right()->getHeight();
    } else {
        RH = 0;
    }
    if (LH > RH){
        orig->setHeight(LH + 1);
    } else {
        orig->setHeight(RH + 1);
    }
    
    if (LSon->hasLeft()){
        LH = LSon->left()->getHeight();
    } else {
        LH = 0;
    }
    if (LSon->hasRight()){
        RH = LSon->right()->getHeight();
    } else {
        RH = 0;
    }
    if (LH > RH){
        LSon->setHeight(LH + 1);
    } else {
        LSon->setHeight(RH + 1);
    }
}

/**
 * Rotación doble izquierda, derecha.
 * @param orig
 */
template<class X>
void BSTAVL<X>::leftRightRotation(NodeTree<X> *orig){
    leftRotation(orig->left());
    rightRotation(orig);
}

/**
 * Rotación doble derecha, izquierda.
 * @param orig
 */
template<class X>
void BSTAVL<X>::rightLeftRotation(NodeTree<X>* orig){
    rightRotation(orig->right());
    leftRotation(orig);
}
#endif	/* BSTAVL_HPP */

