#ifndef FUNCIONES_CPP_MATRIZ_H
#define FUNCIONES_CPP_MATRIZ_H

#include "include.h"



class Matriz {

private:

    Objeto** matriz_;
    int cantidad_entes;
    int dimension_x;
    int dimension_y;

public:

    //PRE:
    //POST: Crea el objeto matriz.
    Matriz();

    //PRE:
    //POST: Destruye el objeto.
    ~Matriz();

    //PRE: Recibe las coordenadas con parentesis y coma.
    //POST: Devuelve las coordenadas sin simbolos para poder transformar a int.
    void calcular_coordenadas(string coordenada_x_str, string coordenada_y_str, string& coordenada_x_substr , string& coordenada_y_substr, int& coordenada_x, int& coordenada_y);

    //PRE:
    //POST: lee el archivo y carga los objetos en la matriz.
    void cargar_matriz();

    //PRE: recibe las coordenadas.
    //POST: revisa si ya esta ocupada la posision elegida.
    bool verificar_ocupacion(int coordenada_x, int coordenada_y);

    //PRE: recibe el tipo de ente, sus corrdenadas y la cantidad.
    //POST: crea los objetos y los guarda en la matriz.
    void llenar_matriz(string tipo, int coordenada_x_str, int coordenada_y_str, int cantidad);

    //PRE: recibe el tipo de ente, sus corrdenadas y la cantidad.
    //POST: agrega un objeto en la matriz.
    void agregar_ente(string tipo, int coordenada_x_str, int coordenada_y_str, int cantidad);

    //PRE: recibe el tipo de ente, sus corrdenadas y la posicion.
    //POST: elimina de la matriz al objeto.
    void eliminar_ente(int posicion);

    //PRE: recibe 2 posiciones.
    //POST: intercambia al objeto entre la posicion en la que se encuentra y la posicion final.
    void swap(int posicion_1, int posicion_2);

    //PRE: recibe la posicion del objeto en la matriz.
    //POST: muestra la informacion del objeto.
    void mostrar_informacion(int posicion);


    //PRE: recibe el tipo y sus coordenadas.
    //POST: revisa si lo ingresado existe en la matriz.
    bool verificar_existencia(string tipo, int coordenada_x_str, int coordenada_y_str);

    //PRE: recibe el tipo y sus coordenadas.
    //POST: devuelve donde se encuentra el ente en la matriz.
    int devolver_posicion_ente(string tipo, int coordenada_x_str, int coordenada_y_str);

    //PRE:
    //POST: devuelve la cantidad de entes que hay en la matriz.
    int devolver_cantidad_entes();

    //PRE:
    //POST: devuelve la matriz.
    Objeto** devolver_matriz();

    //PRE:
    //POST: devuelve el tamanio que tendra el eje x del tablero.
    int devolver_dimension_x();

    //PRE:
    //POST: devuelve el tamanio que tendra el eje y del tablero.
    int devolver_dimension_y();

    //PRE:
    //POST: devuelve el maximo de un cuadrante.
    int calculo_cota_tablero(int valor);

    //PRE: recive el nombre a buscar y el cuadrante elegido.
    //POST: verifica si el objeto se encuentra en el cuadrante.
    bool revisar_cuadrante(string nombre, int cuadrante_elegido);

    //PRE: recibe una variable booleana.
    //POST: devuelve un mensaje de si existe en el cuadrante o no.
    void imprimir_resultado_cuadrante(bool esta_en_cuadrante);

};


#endif //FUNCIONES_CPP_MATRIZ_H
