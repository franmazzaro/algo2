#include "monstruo.h"
#include <iostream>

Monstruo::Monstruo(string nom, int coord_x, int coord_y): Ser(nom, coord_x, coord_y){
}

void Monstruo::mostrar() {

    cout << "Tipo de ente: " << nombre << endl;
    cout << "Coordenada x: " << coordenada_x << endl;
    cout << "Coordenada y: " << coordenada_y << endl << endl;
}
