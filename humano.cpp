#include "humano.h"
#include <iostream>


Humano::Humano(string nom, int coord_x, int coord_y): Ser(nom, coord_x, coord_y){
}

void Humano::mostrar() {

    cout << "Tipo de ente: " << nombre << endl;
    cout << "Coordenada x: " << coordenada_x << endl;
    cout << "Coordenada y: " << coordenada_y << endl << endl;
}

