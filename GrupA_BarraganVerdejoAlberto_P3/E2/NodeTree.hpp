/* 
 * File:   NodeTree.hpp
 * Author: dragr
 *
 * Created on 9 de abril de 2019, 11:21
 */

#ifndef NODETREE_HPP
#define	NODETREE_HPP
#include <string>
#include<iostream>

using namespace std;
template <class X>
class NodeTree {
    public:
        NodeTree();
        NodeTree(const X& data, const int &key);
        NodeTree(const NodeTree& orig);
        virtual ~NodeTree();
        
        //Consultores
        NodeTree<X>* right() const;
        NodeTree<X>* left() const;
        NodeTree<X>* parent() const;
        bool hasRight() const;
        bool hasLeft() const;
        bool isGRoot() const;
        bool isExternal() const;
        const X& getElement () const;
        const int getKey() const;
        
        //Modificadores
        void setElement(const X& data);
        void setRight(NodeTree<X>* newRight);
        void setLeft(NodeTree<X>* newLeft);
        void setParent(NodeTree<X>* newParent);
        void setKey(const int &key);
    private:
        NodeTree<X>* pParent;
        NodeTree<X>* pLeft;
        NodeTree<X>* pRight;
        X element;
        int id;
};
//Constructores
template<class X>
NodeTree<X>::NodeTree(){
    this->pParent = nullptr;
    this->pLeft = nullptr;
    this->pRight = nullptr;
}

template<class X>
NodeTree<X>::NodeTree(const X& data, const int &key){
    this->element = data;
    this->id = key;
    this->pParent = nullptr;
    this->pLeft = nullptr;
    this->pRight = nullptr;
}

template<class X>
NodeTree<X>::NodeTree(const NodeTree& orig){
    this->element = orig.element;
    this->id = orig.id;
    this->pLeft = nullptr;
    this->pRight = nullptr;
    this->pParent = nullptr;
}

template<class X>
NodeTree<X>::~NodeTree(){
    this->pRight = nullptr;
    this->pLeft = nullptr;
    this->pParent = nullptr;
    cout << "Hulk ha aplastado el nodo " << element << endl;

}

//Consultores

template<class X>
NodeTree<X>* NodeTree<X>::right() const{
    return this->pRight;
}

template<class X>
NodeTree<X>* NodeTree<X>::left() const{
    return this->pLeft;
}

template<class X>
NodeTree<X>* NodeTree<X>::parent() const{
    return this->pParent;
}

template<class X>
bool NodeTree<X>::hasRight() const{
    return (pRight != nullptr);
}

template<class X>
bool NodeTree<X>::hasLeft() const{
    return(pLeft != nullptr);
}

template<class X>
bool NodeTree<X>::isGRoot() const{
    return (pParent != nullptr);
}

template<class X>
bool NodeTree<X>::isExternal() const{
    return (pLeft == pRight && pLeft == nullptr);
}

template<class X>
const X& NodeTree<X>::getElement () const{
    return this->element;
}

template<class X>
const int NodeTree<X>::getKey() const{
    return this->id;
}
//Modificadores
template <class X>
void NodeTree<X>::setElement(const X& data){
    this->element = data;
}

template <class X>
void NodeTree<X>::setRight(NodeTree<X>* newRight){
    this->pRight = newRight;
}

template <class X>
void NodeTree<X>::setLeft(NodeTree<X>* newLeft){
    this->pLeft = newLeft;
}
template <class X>
void NodeTree<X>::setParent(NodeTree<X>* newParent){
    this->pParent = newParent;
}

template<class X>
void NodeTree<X>::setKey(const int &key){
    this->id = key;
}

#endif	/* NODETREE_HPP */

