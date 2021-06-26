#include "agua_bendita.h"
#include <iostream>

using namespace std;

Agua_bendita::Agua_bendita(string nom, int coord_x, int coord_y, int  cantidad) : Elemento(nom, coord_x, coord_y) {

    this -> cantidad = cantidad;

}

void Agua_bendita::mostrar() {

    cout << "Tipo de ente: " << nombre << endl;
    cout << "Coordenada x: " << coordenada_x << endl;
    cout << "Coordenada y: " << coordenada_y << endl;
    cout << "Cantidad en este punto: "<< cantidad << endl << endl;

}
