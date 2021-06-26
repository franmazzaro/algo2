#ifndef FUNCIONES_CPP_ESTACA_H
#define FUNCIONES_CPP_ESTACA_H

#include "elemento.h"

class Estaca:public Elemento {

public:

    Estaca(string nom, int coord_x, int coord_y);
    void mostrar();

};


#endif //FUNCIONES_CPP_ESTACA_H
