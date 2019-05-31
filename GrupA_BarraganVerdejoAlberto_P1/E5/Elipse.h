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
    Elipse(const Elipse& orig);
    virtual ~Elipse();
    
    float getArea();
    float getRadioA() const;
    float getRadioB() const;
    void setRadioA(float radio);
    void setRadioB(float radio);
    
private:
    float radioA;
    float radioB;
};

#endif	/* ELIPSE_H */

