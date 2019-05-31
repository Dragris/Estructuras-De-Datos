/* 
 * File:   Mountain.hpp
 * Author: dragr
 *
 * Created on 12 de abril de 2019, 18:43
 */

#ifndef MOUNTAIN_HPP
#define	MOUNTAIN_HPP
#include <iostream>
#include <string>
/**
 * Clase reusada de la práctica 3.
 */
using namespace std;
class Mountain {
    public:
        //Constructor
        Mountain();
        Mountain(int key, string name, float height);
        Mountain(const Mountain &orig);
        virtual ~Mountain();
        //Consultores
        int getKey();
        string getName();
        float getHeight();
        const string toString() const;
        //Modificadores
        void setKey(int id);
        void setName(string nombre);
        void setHeight(float altura);
    private:
        int id;
        string nombre;
        float altura;
};
//Constructor
Mountain::Mountain(){
}
Mountain::Mountain(int key, string name, float height){
    this->id = key;
    this->nombre = name;
    this->altura = height;
}
Mountain::Mountain(const Mountain &orig){
    this->id = orig.id;
    this->nombre = orig.nombre;
    this->altura = orig.altura;
}
Mountain::~Mountain(){
}
//Getters
int Mountain::getKey(){
    return this->id;
}

string Mountain::getName(){
    return this->nombre;
}

float Mountain::getHeight(){
    return this->altura;
}
//Setters
void Mountain::setKey(int id){
    this->id = id;
}

void Mountain::setName(string nombre){
    this->nombre = nombre;
}

void Mountain::setHeight(float altura){
    this->altura = altura;
}


const string Mountain::toString() const {
    return "Mountain {ID=" + std::to_string(this->id) + ", Nombre: " + this->nombre + ", Altura= " + std::to_string(this->altura) +"}";
}

/**
 * Método para editar la salida por pantalla de Mountain cuando se le llama.
 * @param strm
 * @param m
 * @return 
 */
std::ostream &operator<<(std::ostream &strm, const Mountain &m) {
	return strm << m.toString(); // Uso el string devuelto en toString()
}

#endif	/* MOUNTAIN_HPP */

