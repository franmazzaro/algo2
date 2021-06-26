#include "cruz.h"
#include <iostream>

Cruz::Cruz(string nom, int coord_x, int coord_y) : Elemento(nom, coord_x, coord_y){
}

void Cruz::mostrar() {

    cout << "Tipo de ente: " << nombre << endl;
    cout << "Coordenada x: " << coordenada_x << endl;
    cout << "Coordenada y: " << coordenada_y << endl << endl;
}

