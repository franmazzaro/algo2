#ifndef FUNCIONES_CPP_BALAS_H
#define FUNCIONES_CPP_BALAS_H

#include "elemento.h"
#include "string"

class Balas: public Elemento{

public:

    Balas(string nom, int coord_x, int coord_y, int cantidad);
    void mostrar();


};


#endif //FUNCIONES_CPP_BALAS_H
