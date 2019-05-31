/* 
 * File:   Flight.h
 * Author: dragr
 *
 * Created on 16 de marzo de 2019, 18:17
 */
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#ifndef FLIGHT_H
#define	FLIGHT_H

using namespace std;

class Flight {
public:
    Flight();
    Flight(string id, string orig, string dest, string fech);
    Flight(const Flight& orig);
    virtual ~Flight();
    string getId();
    string getOrig();
    string getDest();
    string getFech();
    void setId(string id);
    void setOrig(string orig);
    void setDest(string dest);
    void setFech(string fech);
    string to_String();
    
private:
    string id;
    string orig;
    string dest;
    string fech;
};

#endif	/* FLIGHT_H */

