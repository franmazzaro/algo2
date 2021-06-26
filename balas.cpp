#include "balas.h"
#include <iostream>

Balas::Balas(string nom, int coord_x, int coord_y, int cantidad): Elemento(nom, coord_x, coord_y) {

    this -> cantidad = cantidad;

}

void Balas::mostrar() {

    cout << "Tipo de ente: " << nombre << endl;
    cout << "Coordenada x: " << coordenada_x << endl;
    cout << "Coordenada y: " << coordenada_y << endl;
    cout << "Cantidad en este punto: "<< cantidad << endl << endl;

}

