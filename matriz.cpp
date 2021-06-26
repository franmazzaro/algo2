#include "matriz.h"
#include <iostream>
#include <fstream>
#include <string>


Matriz::Matriz() {
    cantidad_entes = 0;
    matriz_ = new Objeto*[cantidad_entes];
    dimension_x = 0;
    dimension_y = 0;
}

Matriz::~Matriz(){

    int cantidad = cantidad_entes;

    for(int i = 0; i < cantidad; i++) {
        delete matriz_[i];
        cantidad_entes--;
    }

    delete[] matriz_;
    matriz_ = nullptr;
}

void Matriz::agregar_ente(string tipo, int coordenada_x_str, int coordenada_y_str, int cantidad){
    llenar_matriz(tipo, coordenada_x_str, coordenada_y_str, cantidad);
}

int Matriz::devolver_dimension_x(){
    return dimension_x;
}

int Matriz::devolver_dimension_y(){
    return dimension_y;
}


int Matriz::devolver_cantidad_entes(){
    return cantidad_entes;
}

Objeto** Matriz::devolver_matriz(){
    return matriz_;
}

bool Matriz::verificar_ocupacion(int coordenada_x, int coordenada_y){

    int contador = 0;
    bool ocupado = false;

    while(!ocupado && contador < devolver_cantidad_entes()){

        int coord_x = devolver_matriz()[contador] -> obtener_coordenada_x();
        int coord_y = devolver_matriz()[contador] -> obtener_coordenada_y();
        if((coord_x == coordenada_x) && (coord_y == coordenada_y)){
            ocupado = true;
        }
        contador++;
    }
    if(ocupado)
        cout << endl << endl << "Este espacio ya esta ocupado por un ente, por favor reintente." << endl << endl;
    return ocupado;

}

void Matriz::mostrar_informacion(int posicion){

    cout << endl << endl;
    cout << "---------------- INFORMACION DEL ENTE -----------------" << endl;
    matriz_[posicion] -> mostrar();
}

bool Matriz::verificar_existencia(string tipo, int coordenada_x, int coordenada_y) {

    int contador = 0;
    bool encontrado = false;
    string nombre;
    int coordenada_x_actual;
    int coordenada_y_actual;
    while (!encontrado && contador < cantidad_entes) {

        nombre = matriz_[contador] -> obtener_nombre();
        coordenada_x_actual = matriz_[contador] -> obtener_coordenada_x();
        coordenada_y_actual = matriz_[contador] -> obtener_coordenada_y();
        if ((nombre == tipo) && (coordenada_x_actual == coordenada_x) && (coordenada_y_actual == coordenada_y)) {
            encontrado = true;
            mostrar_informacion(contador);
        }
        else
            contador++;
    }
    if(!encontrado)
        cout << endl << endl << "No se pudo encontrar el ente con dichas coordenadas, por favor reintente." << endl << endl;
    return encontrado;
}

int Matriz::devolver_posicion_ente(string tipo, int coordenada_x, int coordenada_y){

    int posicion = POSICION_INICIAL_INVALIDA;
    int contador = 0;
    bool encontrado = false;
    string nombre;
    int coordenada_x_actual;
    int coordenada_y_actual;

    while(!encontrado && contador < devolver_cantidad_entes()){

        nombre = matriz_[contador] -> obtener_nombre();
        coordenada_x_actual = matriz_[contador] -> obtener_coordenada_x();
        coordenada_y_actual = matriz_[contador] -> obtener_coordenada_y();
        if((nombre == tipo) && (coordenada_x_actual == coordenada_x) && (coordenada_y_actual == coordenada_y)){
            posicion = contador;
            encontrado = true;
        }
        contador++;
    }
    if (posicion == POSICION_INICIAL_INVALIDA)
        cout << endl << endl << "No se pudo encontrar el ente con dichas coordenadas, por favor reintente." << endl << endl;
    return posicion;
}


void Matriz::eliminar_ente(int posicion_1){

    swap(posicion_1, devolver_cantidad_entes() - 1);
    Objeto** matriz_aux = new Objeto*[cantidad_entes - 1];

    for(int i = 0; i < cantidad_entes - 1; i++){
        matriz_aux[i] = matriz_[i];
    }

    delete matriz_[cantidad_entes - 1];
    delete[] matriz_;

    matriz_ = matriz_aux;
    cantidad_entes--;

}


void Matriz::swap(int posicion_1, int posicion_2){

    Objeto* aux = devolver_matriz()[posicion_2];
    matriz_[posicion_2] = matriz_[posicion_1];
    matriz_[posicion_1] = aux;

}


void Matriz::llenar_matriz(string tipo, int coordenada_x, int coordenada_y, int cantidad){

    Objeto** matriz_aux = new Objeto*[cantidad_entes + 1];

    for(int i = 0; i < cantidad_entes; i++)
        matriz_aux[i] = matriz_[i];

    if(tipo == HUMANOS_STR)
        matriz_aux[cantidad_entes] = new Humano(tipo, coordenada_x, coordenada_y);
    else if(tipo == HUMANOS_CV_STR)
        matriz_aux[cantidad_entes] = new Humano_cv(tipo, coordenada_x, coordenada_y);
    else if(tipo == VANESA_STR)
        matriz_aux[cantidad_entes] = new Vanesa(tipo, coordenada_x, coordenada_y);
    else if(tipo == VAMPIROS_STR)
        matriz_aux[cantidad_entes] = new Vampiro(tipo, coordenada_x, coordenada_y);
    else if(tipo == VAMPIRELLA_STR)
        matriz_aux[cantidad_entes] = new Vampirella(tipo, coordenada_x, coordenada_y);
    else if(tipo == NOSFERATU_STR)
        matriz_aux[cantidad_entes] = new Nosferatu(tipo, coordenada_x, coordenada_y);
    else if(tipo == ZOMBIES_STR)
        matriz_aux[cantidad_entes] = new Zombi(tipo, coordenada_x, coordenada_y);
    else if(tipo == AGUA_STR)
        matriz_aux[cantidad_entes] = new Agua_bendita(tipo, coordenada_x, coordenada_y, cantidad);
    else if(tipo == ESTACA_STR)
        matriz_aux[cantidad_entes] = new Estaca(tipo, coordenada_x, coordenada_y);
    else if(tipo == BALAS_STR)
        matriz_aux[cantidad_entes] = new Balas(tipo, coordenada_x, coordenada_y, cantidad);
    else if(tipo == ESCOPETAS_STR)
        matriz_aux[cantidad_entes] = new Escopeta(tipo, coordenada_x, coordenada_y);
    else if(tipo == CRUCES_STR)
        matriz_aux[cantidad_entes] = new Cruz(tipo, coordenada_x, coordenada_y);

    if(cantidad_entes != SIN_ELEMENTOS){
        delete[] matriz_;
    }

    cantidad_entes++;
    matriz_ = matriz_aux;

}


void Matriz::calcular_coordenadas(string coordenada_x_str, string coordenada_y_str, string& coordenada_x_substr , string& coordenada_y_substr, int& coordenada_x, int& coordenada_y){

    int tamanio_x = coordenada_x_str.size();
    int tamanio_y = coordenada_y_str.size();
    coordenada_x_substr = coordenada_x_str.substr(1, tamanio_x - 2);
    coordenada_y_substr = coordenada_y_str.substr(0, tamanio_y - 1);
    coordenada_x = stoi(coordenada_x_substr);
    coordenada_y = stoi(coordenada_y_substr);

}


void Matriz::cargar_matriz(){

    string tipo;
    string tipo_2;
    ifstream archivo;
    archivo.open("C:/Users/franco/Desktop/algo_2/main/estado.txt");
    if(!archivo){
        cout << "No se pudo abrir el archivo." << endl;
    }
    string dimension_x_str;
    string dimension_y_str;

    archivo >> dimension_x_str >> dimension_y_str;

    dimension_x = stoi(dimension_x_str);
    dimension_y = stoi(dimension_y_str);

    string coordenada_x_substr;
    string coordenada_y_substr;
    string coordenada_x_str;
    string coordenada_y_str;
    int coordenada_x;
    int coordenada_y;
    string cantidad;

    while(!archivo.eof()){

        archivo >> tipo;
        if (tipo == HUMANOS_STR || tipo == ZOMBIES_STR || tipo == VAMPIROS_STR || tipo == VANESA_STR || tipo == NOSFERATU_STR || tipo == VAMPIRELLA_STR) {

            archivo >> tipo_2;
            if (tipo_2 == CV_STR) {
                tipo = HUMANOS_CV_STR;
                archivo >> coordenada_x_str;
                archivo >> coordenada_y_str;
                calcular_coordenadas( coordenada_x_str, coordenada_y_str, coordenada_x_substr , coordenada_y_substr, coordenada_x, coordenada_y);
                llenar_matriz(tipo, coordenada_x, coordenada_y, 1);

            } else{
                archivo >> coordenada_y_str;
                calcular_coordenadas( tipo_2, coordenada_y_str, coordenada_x_substr , coordenada_y_substr, coordenada_x, coordenada_y);
                llenar_matriz(tipo, coordenada_x, coordenada_y, 1);
            }

        } else if (tipo == CRUCES_STR || tipo == ESCOPETAS_STR || tipo == ESTACA_STR) {
            archivo >> coordenada_x_str;
            archivo >> coordenada_y_str;
            calcular_coordenadas( coordenada_x_str, coordenada_y_str, coordenada_x_substr , coordenada_y_substr, coordenada_x, coordenada_y);
            llenar_matriz(tipo, coordenada_x, coordenada_y, 1);

        } else if (tipo == AGUA_STR || tipo == BALAS_STR) {
            archivo >> cantidad;
            archivo >> coordenada_x_str;
            archivo >> coordenada_y_str;
            calcular_coordenadas( coordenada_x_str, coordenada_y_str, coordenada_x_substr , coordenada_y_substr, coordenada_x, coordenada_y);
            llenar_matriz(tipo, coordenada_x, coordenada_y, stoi(cantidad));
        }
    }
    archivo.close();
}


int Matriz::calculo_cota_tablero(int valor){
    return (valor / 2);
}


void Matriz::imprimir_resultado_cuadrante(bool esta_en_cuadrante){

    cout << endl << "--------------- INFORMACION CUADRANTE ---------------" << endl;
    cout << "El objeto buscado ";
    if(esta_en_cuadrante)
        cout << "se encuentra en el cuadrante.";
    else
        cout << "no se encuentra en el cuadrante.";
    cout << endl << "-----------------------------------------------------" << endl;

}


bool Matriz::revisar_cuadrante(string nombre, int cuadrante_elegido) {

    int eje_x = devolver_dimension_x();
    int eje_y = devolver_dimension_y();
    bool esta_en_cuadrante = false;

    int valor_maximo_x_NO = calculo_cota_tablero(eje_x);
    int valor_minimo_x_NO = MINIMO;
    int valor_maximo_y_NO = calculo_cota_tablero(eje_y);
    int valor_minimo_y_NO = MINIMO;

    int valor_maximo_x_NE = eje_x;
    int valor_minimo_x_NE = calculo_cota_tablero(eje_x) + 1;
    int valor_maximo_y_NE = calculo_cota_tablero(eje_y);
    int valor_minimo_y_NE = MINIMO;

    int valor_maximo_x_SO = calculo_cota_tablero(eje_x);
    int valor_minimo_x_SO = MINIMO;
    int valor_maximo_y_SO = eje_y;
    int valor_minimo_y_SO = calculo_cota_tablero(eje_y) + 1;

    int valor_maximo_x_SE = eje_x;
    int valor_minimo_x_SE = calculo_cota_tablero(eje_x) + 1;
    int valor_maximo_y_SE = eje_y;
    int valor_minimo_y_SE = calculo_cota_tablero(eje_y) + 1;

    int contador = 0;
    int tope = devolver_cantidad_entes() - 1;
    string ente;

    while (contador <= tope && !esta_en_cuadrante) {
        ente = devolver_matriz()[contador] -> obtener_nombre();
        if (ente == nombre) {

            if(cuadrante_elegido == 1){

                if ((devolver_matriz()[contador] -> obtener_coordenada_x() >= valor_minimo_x_NO)
                    && (devolver_matriz()[contador] -> obtener_coordenada_x() <= valor_maximo_x_NO)
                    && (devolver_matriz()[contador] -> obtener_coordenada_y() >= valor_minimo_y_NO)
                    && (devolver_matriz()[contador] -> obtener_coordenada_y() <= valor_maximo_y_NO)) {
                    esta_en_cuadrante = true;
                }
            }
            else if(cuadrante_elegido == 2) {

                if ((devolver_matriz()[contador] -> obtener_coordenada_x() >= valor_minimo_x_NE)
                    && (devolver_matriz()[contador] -> obtener_coordenada_x() <= valor_maximo_x_NE)
                    && (devolver_matriz()[contador] -> obtener_coordenada_y() >= valor_minimo_y_NE)
                    && (devolver_matriz()[contador] -> obtener_coordenada_y() <= valor_maximo_y_NE)) {
                    esta_en_cuadrante = true;

                }
            }
            else if(cuadrante_elegido == 3){

                if ((devolver_matriz()[contador] -> obtener_coordenada_x() >= valor_minimo_x_SO)
                    && (devolver_matriz()[contador] -> obtener_coordenada_x() <= valor_maximo_x_SO)
                    && (devolver_matriz()[contador] -> obtener_coordenada_y() >= valor_minimo_y_SO)
                    && (devolver_matriz()[contador] -> obtener_coordenada_y() <= valor_maximo_y_SO)) {
                    esta_en_cuadrante = true;
                }
            }
            else if(cuadrante_elegido == 4){

                if ((devolver_matriz()[contador]->obtener_coordenada_x() >= valor_minimo_x_SE)
                    && (devolver_matriz()[contador] -> obtener_coordenada_x() <= valor_maximo_x_SE)
                    && (devolver_matriz()[contador] -> obtener_coordenada_y() >= valor_minimo_y_SE)
                    && (devolver_matriz()[contador]->obtener_coordenada_y() <= valor_maximo_y_SE)) {
                    esta_en_cuadrante = true;
                }
            }
        }
        contador++;
    }
    return esta_en_cuadrante;
}


