#include "estadistica.h"
#include <iostream>
#include <iomanip>
using namespace std;

Estadistica::Estadistica(Matriz* matriz_) {

    matriz = matriz_;

    porcentaje_humano = 0;
    porcentaje_zombie = 0;
    porcentaje_vampiro = 0;
    porcentaje_agua = 0;
    porcentaje_cruz = 0;
    porcentaje_balas = 0;
    porcentaje_escopeta = 0;
    porcentaje_estaca = 0;

    cantidad_humano = 0;
    cantidad_zombie = 0;
    cantidad_vampiro = 0;
    cantidad_agua = 0;
    cantidad_cruz = 0;
    cantidad_escopeta = 0;
    cantidad_balas = 0;
    cantidad_estaca = 0;
    contador_tabla = 0;

}



void Estadistica::bajar_contador_por_eliminacion(string nombre, int posicion){

    if ((nombre == HUMANOS_STR) ||(nombre == HUMANOS_CV_STR) || (nombre == VANESA_STR)) {
        cantidad_humano--;
    }
    else if ((nombre == VAMPIROS_STR) || (nombre == NOSFERATU_STR)|| (nombre == VAMPIRELLA_STR)) {
        cantidad_vampiro--;
    }
    else if (nombre == ZOMBIES_STR) {
        cantidad_zombie--;
    }
    else if(nombre == AGUA_STR){
        cantidad_agua -= matriz -> devolver_matriz()[posicion] -> obtener_cantidad();
    }
    else if(nombre == CRUCES_STR){
        cantidad_cruz--;
    }
    else if((nombre == ESTACA_STR)){
        cantidad_estaca--;
    }
    else if((nombre == ESCOPETAS_STR)){
        cantidad_escopeta--;
    }
    else if((nombre == BALAS_STR)){
        cantidad_balas -= matriz -> devolver_matriz()[posicion] -> obtener_cantidad();
    }
    contador_tabla--;
}

void Estadistica::calcular_cantidades_objeto(){
    int cantidad_entes = matriz -> devolver_cantidad_entes();

    for (int i = contador_tabla; i < cantidad_entes; i++) {

        string nombre = matriz -> devolver_matriz()[i] -> obtener_nombre();

        if ((nombre == HUMANOS_STR) ||(nombre == HUMANOS_CV_STR) || (nombre == VANESA_STR)) {
            cantidad_humano++;
        }
        else if ((nombre == VAMPIROS_STR) || (nombre == NOSFERATU_STR)|| (nombre == VAMPIRELLA_STR)) {
            cantidad_vampiro++;
        }
        else if (nombre == ZOMBIES_STR) {
            cantidad_zombie++;
        }
        else if(nombre == AGUA_STR){
            int cantidad = matriz -> devolver_matriz()[i] -> obtener_cantidad();
            cantidad_agua += cantidad;
        }
        else if(nombre == CRUCES_STR){
            cantidad_cruz++;
        }
        else if(nombre == ESTACA_STR){
            cantidad_estaca++;
        }
        else if(nombre == ESCOPETAS_STR){
            cantidad_escopeta++;
        }
        else if(nombre == BALAS_STR){
            cantidad_balas += matriz -> devolver_matriz()[i] -> obtener_cantidad();
        }
        contador_tabla++;
    }

}

void Estadistica::calcular_porcentaje(){
    float suma_personajes = cantidad_humano + cantidad_vampiro + cantidad_zombie;
    float suma_objetos = cantidad_agua + cantidad_cruz + cantidad_estaca;
    float escopeta_suma = cantidad_escopeta;
    float balas_suma = cantidad_balas;


    porcentaje_humano = (cantidad_humano/suma_personajes) * 100;
    porcentaje_zombie = (cantidad_zombie/suma_personajes) * 100;
    porcentaje_vampiro = (cantidad_vampiro/suma_personajes) * 100;

    porcentaje_agua = (cantidad_agua/suma_objetos) * 100;
    porcentaje_cruz = (cantidad_cruz/suma_objetos) * 100;
    porcentaje_estaca = (cantidad_estaca/suma_objetos) * 100;

    porcentaje_balas = (balas_suma/escopeta_suma) * 100;
    porcentaje_escopeta = (escopeta_suma/balas_suma) * 100;


}

void Estadistica::imprimir_tabla() {

    cout << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "|ELEMENTO|   " << '\t' << "|CANTIDAD|" << '\t' << "|PORCENTAJE SOBRE EL TOTAL|" << endl;
    cout << "-----------------------------------------------------------" << endl;

    cout << "|" << "Humanos" << "  "  << '\t'<< "|" << cantidad_humano << '\t' << '\t' << fixed << setprecision(1) << "|" << porcentaje_humano << "%" << endl;
    cout << "|" << "Zombis" << "  "  << '\t' << "|" << cantidad_zombie << '\t' << '\t' << fixed << setprecision(1) << "|" << porcentaje_zombie << "%" << endl;
    cout << "|" << "Vampiros" << "  "  << '\t' << "|" << cantidad_vampiro << '\t' << '\t' << fixed << setprecision(1) << "|" << porcentaje_vampiro << "%" << endl;
    cout << "|" << "Agua Bendita" << "  "  << '\t' << "|" << cantidad_agua << '\t' << '\t' << fixed << setprecision(1) << "|" << porcentaje_agua << "%" << endl;
    cout << "|" << "Cruces" << "  "  << '\t' << "|" << cantidad_cruz << '\t' << '\t' << fixed << setprecision(1) << "|" << porcentaje_cruz << "%" << endl;
    cout << "|" << "Estacas" << "  "  << '\t' << "|" << cantidad_estaca << '\t' << '\t' << fixed << setprecision(1) << "|" << porcentaje_estaca << "%" << endl;
    cout << "|" << "Escopetas" << "  "  << '\t' << "|" << cantidad_escopeta << '\t' << '\t' << fixed << setprecision(1) << "|" << porcentaje_escopeta << "%" << endl;
    cout << "|" << "Balas" << " "  << '\t' << '\t' << "|" << cantidad_balas << '\t' << '\t' << fixed << setprecision(1) << "|" << porcentaje_balas << "%" << endl;
    cout << "-----------------------------------------------------------" << endl << endl;

}

