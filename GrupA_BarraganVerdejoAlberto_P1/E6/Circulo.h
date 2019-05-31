/* 
 * File:   Circulo.h
 * Author: dragr
 *
 * Created on 21 de febrero de 2019, 10:56
 */

#ifndef CIRCULO_H
#define	CIRCULO_H
#include "Elipse.h"

class Circulo:public Elipse {
public:
    Circulo();
    Circulo(const Circulo& orig);
    virtual ~Circulo();
    
    float getArea();
    void setRadioA (float radio);
    void setRadioB (float radio); //No lo implementaremos
};

#endif	/* CIRCULO_H */

