/* 
 * File:   Flight.cpp
 * Author: dragr
 * 
 * Created on 16 de marzo de 2019, 18:17
 */

#include "Flight.h"

Flight::Flight() {
}

Flight::Flight(string id, string orig, string dest, string fech){
    this->id = id;
    this->orig = orig;
    this->dest = dest;
    this->fech = fech;
    //std::cout << id << orig << dest << fech << std::endl;
}
Flight::Flight(const Flight& orig) {
}

Flight::~Flight() {
}

string Flight::to_String(){
    return (getId() + getOrig() + getDest() + getFech());
}

//Getters
string Flight::getId(){
    return this->id;
}
string Flight::getOrig(){
    return this->orig;
}
string Flight::getDest(){
    return this->dest;
}
string Flight::getFech(){
    return this->fech;
}

//Setters
void Flight::setId(string id){
    this->id = id;
}
void Flight::setOrig(string orig){
    this->orig = orig;
}
void Flight::setDest(string dest){
    this->dest = dest;
}
void Flight::setFech(string fech){
    this->fech = fech;
}