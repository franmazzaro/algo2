#include "menu.h"
#include <iostream>
#include <sstream>


using namespace std;

Menu::Menu(){

    eleccion_cuadrantes = 0;
    eleccion_ente = 0;
    ente_elegido = "";
    coord_x_elegida = 0;
    coord_y_elegida = 0;
}



void Menu::menu_mostrar_porcentajes(Estadistica* tabla){
    tabla -> calcular_cantidades_objeto();
    tabla -> calcular_porcentaje();
    tabla -> imprimir_tabla();
}

void Menu::menu_buscar_elemento(Matriz* matriz){

    menu_ente(MENU_BUSCAR);
    bool esta_en_cuadrante = matriz -> revisar_cuadrante(ente_elegido, eleccion_cuadrantes);
    matriz -> imprimir_resultado_cuadrante(esta_en_cuadrante);


}

void Menu::dar_alta(Matriz* matriz){

    bool ocupado = true;

    while(ocupado){
        menu_ente(MENU_ALTA);
        seleccionar_coordenadas(matriz -> devolver_dimension_x(), matriz -> devolver_dimension_y());
        seleccionar_cantidad();
        ocupado = matriz -> verificar_ocupacion(coord_x_elegida, coord_y_elegida);
    }
    matriz -> agregar_ente(ente_elegido, coord_x_elegida, coord_y_elegida, cantidad);
    cout << endl << "Elemento dado de alta coorectamente!" << endl << endl;
}

void Menu::dar_baja(Matriz* matriz, Estadistica* estadistica){

    int posicion = POSICION_INICIAL_INVALIDA;
    while (posicion == POSICION_INICIAL_INVALIDA) {
        menu_ente(MENU_BAJA);
        seleccionar_coordenadas(matriz -> devolver_dimension_x(), matriz -> devolver_dimension_y());
        posicion = matriz -> devolver_posicion_ente(ente_elegido, coord_x_elegida, coord_y_elegida);

        if (posicion != POSICION_INICIAL_INVALIDA) {
            estadistica -> bajar_contador_por_eliminacion(ente_elegido, posicion);
            matriz -> eliminar_ente(posicion);
            cout << endl << "Elemento dado de baja coorectamente!" << endl << endl;
        }
    }
}

void Menu::mostrar_informacion(Matriz* matriz){

    bool encontrado = false;
    while(!encontrado){
        menu_ente(MENU_INFORMACION);
        seleccionar_coordenadas(matriz -> devolver_dimension_x(), matriz -> devolver_dimension_y());
        encontrado = matriz -> verificar_existencia(ente_elegido, coord_x_elegida, coord_y_elegida);
    }
}

void Menu::programa(){

    Matriz* matriz = new Matriz();
    matriz -> cargar_matriz();

    Estadistica* tabla = new Estadistica(matriz);

    Tablero* tablero = new Tablero(matriz);

    bool seguir_en_programa = true;

    while(seguir_en_programa){

        menu_principal();
        if(eleccion_menu == ELECCION_MOSTRAR_PORCENTAJES) {
            menu_mostrar_porcentajes(tabla);
        }
        else if (eleccion_menu == ELECCION_BUSCAR_ELEMENTO){
            menu_buscar_elemento(matriz);
        }
        else if (eleccion_menu == ELECCION_MOSTRAR_TABLERO){
            tablero -> mostrar_tablero();
        }
        else if (eleccion_menu == ELECCION_DAR_ALTA) {
            dar_alta(matriz);
        }
        else if (eleccion_menu == ELECCION_DAR_BAJA) {
            dar_baja(matriz, tabla);
        }
        else if(eleccion_menu == ELECCION_MOSTRAR_INFORMACION){
            mostrar_informacion(matriz);
        }
        else{
            seguir_en_programa = false;
            cout << "Saliendo del programa...";
        }
    }

    delete matriz;
    delete tabla;
    delete tablero;


}


int Menu::eleccion_menus(int valor_max, string mensaje, string mensaje_error){

    bool eleccion_valida = false;
    string eleccion_str;
    int eleccion_int;
    cout << mensaje;

    while(not eleccion_valida){
        cin >> eleccion_str;
        eleccion_valida = isdigit(eleccion_str[PRIMER_POSICION_STR]);

        if(eleccion_valida){
            eleccion_int = stoi(eleccion_str);
        }
        if(eleccion_valida && eleccion_int >= VALOR_MIN && eleccion_int <= valor_max){
            eleccion_valida = true;
        }
        else{
            eleccion_valida = false;
        }
        if(!eleccion_valida)
            cout << mensaje_error;
    }
    return eleccion_int;
}

void Menu::menu_principal() {

    cout << endl << "-------------------- MENU PRINCIPAL --------------------" << endl;
    cout << "ELIJA UNA OPCION:" << endl << endl;
    cout << "1. Mostrar tabla de porcentajes" << endl;
    cout << "2. Buscar elemento en cuadrante" << endl;
    cout << "3. Mostrar tablero" << endl;
    cout << "4. Dar de alta un elemento" << endl;
    cout << "5. Dar de baja un elemento" << endl;
    cout << "6. Mostrar informacion sobre un elemento en una posicion" << endl;
    cout << "7. Salir del programa" << endl << endl;
    eleccion_menu = eleccion_menus(VALOR_MAX_MENU_PRINCIPAL, "Ingrese una opcion del 1 al 7: ", "Tiene que ser un valor del 1 al 7, por favor reintente: ");

}

void Menu::seleccionar_cantidad(){

    if(ente_elegido == AGUA_STR || ente_elegido == BALAS_STR){
        cantidad = eleccion_menus(VALOR_MAX_CANTIDAD, "La maxima cantidad por posicion es 1000:  ", "Ingrese un numero de 1 a 1000: ");
    }
    else{
        cantidad = MINIMO;
    }
}

void Menu::seleccionar_coordenadas(int dimension_x, int dimension_y){

    string dimension_x_str;
    string dimension_y_str;
    string coord_x_str;
    string coord_y_str;

    stringstream cambio_int_str;
    cambio_int_str << dimension_x;
    cambio_int_str >> dimension_x_str;

    stringstream cambio_int_str_2;
    cambio_int_str_2 << dimension_y;
    cambio_int_str_2 >> dimension_y_str;

    cout << "Ingrese la coordenada x del ente: " << endl;
    string mostrar_cantidad_opciones_x = "Ingrese una opcion del 1 al " + dimension_x_str + ": ";
    string mostrar_cantidad_opciones_y = "Ingrese una opcion del 1 al " + dimension_y_str + ": ";
    string mostrar_cantidad_opciones_x_error = "Tiene que ser un valor del 1 al " + dimension_x_str + ", por favor reintente: ";
    string mostrar_cantidad_opciones_y_error = "Tiene que ser un valor del 1 al " + dimension_y_str + ", por favor reintente: ";

    int coord_x = eleccion_menus(dimension_x, mostrar_cantidad_opciones_x, mostrar_cantidad_opciones_x_error);
    int coord_y = eleccion_menus(dimension_y, mostrar_cantidad_opciones_y, mostrar_cantidad_opciones_y_error);

    coord_x_elegida = coord_x;
    coord_y_elegida = coord_y;

}

void Menu::menu_ente(int tipo_de_menu){

    cout << endl;
    if(tipo_de_menu == MENU_ALTA) {
        cout << "-------------------- MENU ALTA DE ENTE --------------------" << endl;
        cout << "Seleccione un ente para dar de alta:" << endl << endl;
    }
    else if(tipo_de_menu == MENU_BAJA){
        cout << "-------------------- MENU BAJA DE ENTE --------------------" << endl;
        cout << "Seleccione un ente para dar de baja:" << endl << endl;
    }
    else if(tipo_de_menu == MENU_INFORMACION){
        cout << "-------------------- MENU INFORMACION SOBRE ENTE --------------------" << endl;
        cout << "Seleccione un ente para ver su informacion:" << endl << endl;
    }
    else if(tipo_de_menu == MENU_BUSCAR){
        cout << "-------------------- MENU BUSCAR EN CUADRANTE --------------------" << endl;
        cout << "Seleccione un ente para ver su informacion:" << endl << endl;
    }
    cout << "1. Humano" << endl;
    cout << "2. Humano caza vampiros" << endl;
    cout << "3. Vanessa" << endl;
    cout << "4. Zombi" << endl;
    cout << "5. Vampiro" << endl;
    cout << "6. Vampirella" << endl;
    cout << "7. Nosferatu" << endl;
    cout << "8. Agua bendita" << endl;
    cout << "9. Cruces" << endl;
    cout << "10. Estacas" << endl;
    cout << "11. Escopetas" << endl;
    cout << "12. Balas" << endl;

    eleccion_ente = eleccion_menus(VALOR_MAX_MENU_DAR_ALTA, "Ingrese una opcion del 1 al 12: ", "Tiene que ser un valor del 1 al 12, por favor reintente: ");

    obtener_nombre_elegido(eleccion_ente);

    if(tipo_de_menu == MENU_BUSCAR) {
        menu_cuadrantes();
    }
}


void Menu::obtener_nombre_elegido(int valor){

    if(valor == 1)
        ente_elegido = HUMANOS_STR;
    else if(valor == 2)
        ente_elegido = HUMANOS_CV_STR;
    else if(valor == 3)
        ente_elegido = VANESA_STR;
    else if(valor == 4)
        ente_elegido = ZOMBIES_STR;
    else if(valor == 5)
        ente_elegido = VAMPIROS_STR;
    else if(valor == 6)
        ente_elegido = VAMPIRELLA_STR;
    else if(valor == 7)
        ente_elegido = NOSFERATU_STR;
    else if(valor == 8)
        ente_elegido = AGUA_STR;
    else if(valor == 9)
        ente_elegido = CRUCES_STR;
    else if(valor == 10)
        ente_elegido = ESTACA_STR;
    else if(valor == 11)
        ente_elegido = ESCOPETAS_STR;
    else if(valor == 12)
        ente_elegido = BALAS_STR;
}

void Menu::menu_cuadrantes(){

    cout << endl << endl << endl;
    cout << "-------------- MENU CUADRANTES --------------" << endl;
    cout << "Seleccione una opcion para buscar:" << endl;
    cout << "1. Cuadrante Noroeste." << endl;
    cout << "2. Cuadrante Noreste." << endl;
    cout << "3. Cuadrante Sudoeste." << endl;
    cout << "4. Cuadrante Sudeste." << endl << endl;
    eleccion_cuadrantes = eleccion_menus(VALOR_MAX_MENU_CUADRANTES, "Ingrese una opcion del 1 al 4: ", "Tiene que ser un valor del 1 al 4, por favor reintente: ");

}
