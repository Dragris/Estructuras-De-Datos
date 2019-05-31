/* 
 * File:   Circulo.h
 * Author: dragr
 *
 * Created on 21 de febrero de 2019, 10:56
 */

#ifndef CIRCULO_H
#define	CIRCULO_H

class Circulo {
public:
    Circulo();
    Circulo(const Circulo& orig);
    virtual ~Circulo();
    
    float getArea();
    float getRadio() const;
    void setRadio(float radio);
private:
    float radio;
};

#endif	/* CIRCULO_H */

