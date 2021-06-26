#ifndef FUNCIONES_CPP_SER_H
#define FUNCIONES_CPP_SER_H

#include "objeto.h"

class Ser: public Objeto {

public:
    Ser(string nom, int coord_x, int coord_y);
    virtual void mostrar() = 0;
    //virtual int obtener_cantidad() = 0;

};


#endif //FUNCIONES_CPP_SER_H
