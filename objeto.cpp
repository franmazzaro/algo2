#include "objeto.h"
#include <fstream>
#include <iostream>
#include <string>
#include "constantes.h"

Objeto::Objeto(){

    nombre = "";
    coordenada_x = 0;
    coordenada_y = 0;
}



int Objeto::obtener_cantidad() {
    return this -> cantidad;

}

char Objeto::asignar_letra(string nombre){

    char letra;
    if(nombre == HUMANOS_STR)
        letra = 'h';
    else if(nombre == HUMANOS_CV_STR)
        letra = 'H';
    else if(nombre == VANESA_STR)
        letra = 'W';
    else if(nombre == ZOMBIES_STR)
        letra = 'z';
    else if(nombre == VAMPIROS_STR)
        letra = 'v';
    else if(nombre == VAMPIRELLA_STR)
        letra = 'V';
    else if(nombre == NOSFERATU_STR)
        letra = 'N';
    else if(nombre == CRUCES_STR)
        letra = 'c';
    else if(nombre == AGUA_STR)
        letra = 'a';
    else if(nombre == ESTACA_STR)
        letra = 'e';
    else if(nombre == ESCOPETAS_STR)
        letra = 'E';
    else if(nombre == BALAS_STR)
        letra = 'b';

    return letra;
}


Objeto::Objeto(string nom, int coord_x, int coord_y){

    nombre = nom;
    coordenada_x = coord_x;
    coordenada_y = coord_y;

}


string Objeto::obtener_nombre() {
    return nombre;
}

int Objeto::obtener_coordenada_x() {
    return coordenada_x;
}

int Objeto::obtener_coordenada_y() {
    return coordenada_y;
}

