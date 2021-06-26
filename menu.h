#ifndef MAIN_CPP_MENU_H
#define MAIN_CPP_MENU_H

#include <string>
#include "estadistica.h"
#include "matriz.h"
#include "tablero.h"

using namespace std;

class Menu {
private:

    int eleccion_menu;
    int eleccion_cuadrantes;
    int eleccion_ente;
    string ente_elegido;
    int coord_x_elegida;
    int coord_y_elegida;
    int cantidad;


public:

    //PRE:
    //POST: construye el menu
    Menu();

    //PRE:
    //POST: muestra el menu principal.
    void menu_principal();

    //PRE: recibe el menu para mostrar.
    //POST: muestra el menu.
    void menu_ente(int tipo_de_menu);

    //PRE:
    //POST: muestra el menu de cuadrantes
    void menu_cuadrantes();

    //PRE: recibe el valor maximo para ingresar, y los mensajes para mostrar.
    //POST: verifiva si el valor ingresado es correcto.
    int eleccion_menus(int valor_max, string mensaje, string mensaje_error);

    //PRE:
    //POST: algoritmo principal para correr el programa.
    void programa();

    //PRE: recive el valor elegido.
    //POST: devuelve el nombre elegido.
    void obtener_nombre_elegido(int valor);

    //PRE: recibe las coordenadas.
    //POST: asigna las coordenadas elegidas.
    void seleccionar_coordenadas(int dimension_x, int dimension_y);

    //PRE:
    //POST: asigna la cantidad del objeto.
    void seleccionar_cantidad();

    //PRE: recibe un puntero del objeto estadistica.
    //POST: utiliza los metodos del objeto estadistica para hacer la tabla.
    void menu_mostrar_porcentajes(Estadistica* tabla);

    //PRE: recibe un puntero del objeto matriz.
    //POST: utiliza los metodos del objeto matriz y revisa el cuadrante.
    void menu_buscar_elemento(Matriz* matriz);

    //PRE: recibe el objeto matriz.
    //POST: utiliza metodos del objeto matriz para dar de alta un objeto.
    void dar_alta(Matriz* matriz);

    //PRE: recibe el objeto matriz.
    //POST: utiliza metodos del objeto matriz para dar de baja un objeto.
    void dar_baja(Matriz* matriz, Estadistica* estadistica);

    //PRE: recibe el objeto matriz.
    //POST: utiliza metodos del objeto matriz para mostrar la informacion de un objeto.
    void mostrar_informacion(Matriz* matriz);

};


#endif //MAIN_CPP_MENU_H
