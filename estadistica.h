#ifndef MATRIZ_CPP_ESTADISTICA_H
#define MATRIZ_CPP_ESTADISTICA_H

#include "matriz.h"

class Estadistica {

private:
    Matriz* matriz;
    float porcentaje_humano;
    float porcentaje_zombie;
    float porcentaje_vampiro;
    float porcentaje_agua;
    float porcentaje_cruz;
    float porcentaje_balas;
    float porcentaje_escopeta;
    float porcentaje_estaca;

    int cantidad_humano;
    int cantidad_zombie;
    int cantidad_vampiro;
    int cantidad_agua;
    int cantidad_cruz;
    int cantidad_balas;
    int cantidad_escopeta;
    int cantidad_estaca;
    int contador_tabla;

public:

    //PRE: recibe un puntero a matriz.
    //POS: Construye el objeto estadistica.
    Estadistica(Matriz* matriz_);

    //PRE:
    //POS: destruye el objeto.
    virtual ~Estadistica(){};

    //PRE:
    //POS: asigna las cantidades del objeto.
    void calcular_cantidades_objeto();

    //PRE:
    //POS: imprime la tabla de estadistica.
    void imprimir_tabla();

    //PRE:
    //POS: calcula los porcentajes de los objetos
    void calcular_porcentaje();

    //PRE: recibe el nombre y la posicion del objeto
    //POS: baja las cantidades de los objetos.
    void bajar_contador_por_eliminacion(string nombre, int posicion);

};


#endif //MATRIZ_CPP_ESTADISTICA_H
