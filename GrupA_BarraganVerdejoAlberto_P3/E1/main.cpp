/*
 * File:   main.cpp
 * Author: dragr
 *
 * Created on 9 de abril de 2019, 11:19
 */

#include <cstdlib>
#include<iostream>
#include "BinarySearchTree.hpp"

using namespace std;
void caso1(){
    BinarySearchTree<int> *bst = new BinarySearchTree<int>();
    int testArray [] = {2, 0, 8, 45, 76, 5, 3, 40 };
    
    cout << "\nInsertando...\n";
    for (int n : testArray){
        bst->insert(n);
    }
    cout << "\nElementos insertados\n";
    
    bst->showPreorder();
    bst->showInorder();
    bst->showPostorder();
    bst->showLeafNodes();
    //bst->~BinarySearchTree();
    delete bst;
}

int main(int argc, char** argv) {
    cout << "Ejercicio 1 P3 | BinarySearchTree | Alberto Barragán";
    caso1();
    return 0;
}

