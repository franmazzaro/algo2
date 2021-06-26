//
// Created by franco on 2/6/2021.
//

#ifndef FUNCIONES_CPP_MONSTRUO_H
#define FUNCIONES_CPP_MONSTRUO_H

#include "ser.h"

class Monstruo: public Ser {

public:

    Monstruo(string nom, int coord_x, int coord_y);
    void mostrar();


};


#endif //FUNCIONES_CPP_MONSTRUO_H
