#ifndef FUNCIONES_CPP_ELEMENTO_H
#define FUNCIONES_CPP_ELEMENTO_H

#include "objeto.h"

class Elemento : public Objeto {

public:
    //PRE:
    //POST:
    Elemento(string nom, int coord_x, int coord_y);

    //PRE:
    //POST:
    virtual void mostrar() = 0;

    //PRE:
    //POST:
    //virtual int obtener_cantidad() = 0;

};


#endif //FUNCIONES_CPP_ELEMENTO_H
