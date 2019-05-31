/* 
 * File:   Elipse.h
 * Author: dragr
 *
 * Created on 21 de febrero de 2019, 11:14
 */

#ifndef ELIPSE_H
#define	ELIPSE_H

class Elipse {
public:
    Elipse();
    Elipse(const Elipse &obj);
    virtual ~Elipse();
    
    virtual float getArea();
    float getRadioA() const;
    float getRadioB() const;
    void setRadioA(float radio); //Circulo cogerá este como radioA y radioB
    void setRadioB(float radio);
    
protected:
    float radioA;
    float radioB;
};

#endif	/* ELIPSE_H */

