/*
 * File:   main.cpp
 * Author: dragr
 *
 * Created on 9 de abril de 2019, 11:19
 */

#include <cstdlib>
#include<iostream>
#include "BSTAVL.hpp"

using namespace std;
void caso1(){
    BSTAVL<int> *bst = new BSTAVL<int>();
    int testArray [] = {7,6,5,4,3 };
    
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
    cout << "Ejercicio 3 P3 | BinarySearchTree | Alberto Barragán";
    caso1();
    return 0;
}

