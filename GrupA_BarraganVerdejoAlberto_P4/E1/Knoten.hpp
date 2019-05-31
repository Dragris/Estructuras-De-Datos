/* 
 * File:   Knoten.hpp
 * Author: dragr
 *
 * Created on 13 de mayo de 2019, 18:26
 */

#ifndef KNOTEN_HPP
#define	KNOTEN_HPP

using namespace std;
template<class X>
class Knoten {
    public:
        //Constructores
        Knoten(const int &schlussel, X *wert);
        Knoten(const Knoten &ursprung);
        virtual ~Knoten();
        //Consultores
        X *wertHolen() const;
        const int &schlusselHolen() const;
        //Modificadores
        void wertEinstellen(X *&wert);
        void schlusselEinstellen(const int schlussel);
        
    private:
        X *wert;
        int schlussel;
         
};

/**
 * Constructor de Nodo.
 * @param schlussel
 * @param wert
 */
template<class X>
Knoten<X>::Knoten(const int &schlussel, X *wert){
    this->wert = wert;
    this->schlussel = schlussel;
}

/**
 * Constructor copia de Nodo.
 * @param ursprung
 */
template<class X>
Knoten<X>::Knoten(const Knoten<X>& ursprung){
    this->wert = new X (*ursprung.wert);
    this->schlussel = ursprung.schlussel;
    cout << "Knoten " << ursprung.wert << " wurde kopiert." << endl;
}

/**
 * Destructor de Nodo.
 */
template<class X>
Knoten<X>::~Knoten(){
    delete this->wert;
    cout << "Knoten " << this->schlussel << " wurde zerstört." << endl;
}

/**
 * Devuelve el value del nodo.
 * @return 
 */
template<class X>
X *Knoten<X>::wertHolen() const{
    return this->wert;
}

/**
 * Devuelve la key del nodo.
 * @return 
 */
template<class X>
const int &Knoten<X>::schlusselHolen() const{
    return this->schlussel;
}

/**
 * Asigna un value al Nodo.
 * @param wert
 */
template<class X>
void Knoten<X>::wertEinstellen(X*& wert){
    this->wert = wert;
}

/**
 * Asigna una key al Nodo.
 * @param schlussel
 */
template<class X>
void Knoten<X>::schlusselEinstellen(const int schlussel){
    this->schlussel = schlussel;
}
#endif	/* KNOTEN_HPP */

