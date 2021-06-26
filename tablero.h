#ifndef MATRIZ_CPP_TABLERO_H
#define MATRIZ_CPP_TABLERO_H
#include "matriz.h"

class Tablero {
private:
    Matriz* matriz;

public:

    Tablero(Matriz* matriz_);
    virtual ~Tablero(){};
    void mostrar_tablero();

};


#endif //MATRIZ_CPP_TABLERO_H
