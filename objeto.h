#ifndef FUNCIONES_CPP_OBJETO_H
#define FUNCIONES_CPP_OBJETO_H

#include <string>

using namespace std;

class Objeto {

protected:

    string nombre;
    int coordenada_x;
    int coordenada_y;
    int cantidad;

public:
    //PRE:
    //POST: crea el objeto.
    Objeto();

    //PRE: recibe el nombre, y las coordenadas para construir.
    //POST: construye el objeto.
    Objeto(string nombre, int coord_x, int coord_y);

    virtual ~Objeto(){};

    //PRE:
    //POST: muestra la informacion del objeto.
    virtual void mostrar() = 0;


    //PRE:
    //POST: devuelve la cantidad que tiene el objeto.
    int obtener_cantidad();

    //PRE: recibe el nombre del objeto.
    //POST: segun el nombre asigna la letra que va a tener.
    char asignar_letra(string nombre);

    //PRE:
    //POST: devuelve el nombre del objeto.
    string obtener_nombre();

    //PRE:
    //POST: devuelve la coordenada x del objeto.
    int obtener_coordenada_x();

    //PRE:
    //POST: devuelve la coordenada y del objeto.
    int obtener_coordenada_y();

};


#endif //FUNCIONES_CPP_OBJETO_H