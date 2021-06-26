#include "tablero.h"
#include <iostream>

using namespace std;

Tablero::Tablero(Matriz *matriz_) {
    matriz = matriz_;
}


void Tablero::mostrar_tablero(){

    int eje_x = matriz -> devolver_dimension_x() - 1;
    int eje_y = matriz -> devolver_dimension_y() - 1;

    int tope_vector = matriz -> devolver_cantidad_entes();
    char letra;
    int contador;

    cout << endl << endl << "--------------- TABLERO ---------------" << endl;

    cout << "      ";
    for(int j = 0; j <= eje_x; j++){
        cout<< j + 1 << "    ";
    }

    for(int i = 0; i <= eje_y ; i++){
        if(i < 9)
            cout << endl << i + 1 << "   ";
        else
            cout << endl << i + 1 << "  ";
        for(int j = 0; j <= eje_x ; j++){

            bool ocupado = false;
            contador = 0;

            int coord_x;
            int coord_y;
            string nombre;

            while(!ocupado && contador < tope_vector){

                coord_x = matriz -> devolver_matriz()[contador] -> obtener_coordenada_x() - 1;
                coord_y = matriz -> devolver_matriz()[contador] -> obtener_coordenada_y() - 1;
                nombre = matriz -> devolver_matriz()[contador] -> obtener_nombre();

                if((coord_y == i) && (coord_x == j)){
                    ocupado = true;

                    letra = matriz -> devolver_matriz()[contador] -> asignar_letra(nombre);
                    cout << "[ " << letra << " ]";
                }
                contador++;
            }
            if(!ocupado)
                cout << "[ * ]";
        }
    }
    cout << endl << endl;
}

