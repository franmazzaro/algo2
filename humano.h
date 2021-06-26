#ifndef FUNCIONES_CPP_HUMANO_H
#define FUNCIONES_CPP_HUMANO_H

#include "ser.h"

class Humano: public Ser {

public:

    Humano(string nom, int coord_x, int coord_y);
    void mostrar();


};


#endif //FUNCIONES_CPP_HUMANO_H
