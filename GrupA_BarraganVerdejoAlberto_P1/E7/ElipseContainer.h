/* 
 * File:   ElipseContainer.h
 * Author: dragr
 *
 * Created on 21 de febrero de 2019, 18:04
 */
#include <vector>
#include <iterator>
#include <stdexcept>

#include "Elipse.h"

#ifndef ELIPSECONTAINER_H
#define	ELIPSECONTAINER_H

class ElipseContainer {
public:
    ElipseContainer();
    ElipseContainer(const ElipseContainer& orig);
    virtual ~ElipseContainer();
    void addElipse(Elipse* e);
    float getAreas();
    bool isEmpty() const;
    
private:
    std::vector<Elipse*> container;
    const int MAXCAPACITY = 10;
};

#endif	/* ELIPSECONTAINER_H */

