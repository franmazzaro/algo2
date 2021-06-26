#ifndef FUNCIONES_CPP_AGUA_BENDITA_H
#define FUNCIONES_CPP_AGUA_BENDITA_H

#include "elemento.h"

class Agua_bendita : public Elemento {


public:

    Agua_bendita(string nom, int coord_x, int coord_y, int cantidad);
    void mostrar();

};


#endif //FUNCIONES_CPP_AGUA_BENDITA_H
