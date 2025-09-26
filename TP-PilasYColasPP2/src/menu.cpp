// menu.cpp
#include <iostream>

#include "../data/cola.h"
#include "../data/pila.h"
#include "../data/util.h"
#include "../data/menu.h"
#include "../data/funcionesCompartidas.h"

using namespace std;

void mostrarMenu() {
    cout << "\n=== TP Pilas y Colas: Biblioteca ===\n"
    << "1) Cargar datos preset\n"
    << "2) Procesar solicitud de prestamo de libro\n"
    << "3) Procesar Entrega de libro(dequeue + push accion)\n"
    << "4) Procesar Devolucion de libro(pop + revertir)\n"
    << "5) Mostrar prestamos de libros (recursivo)\n"
    << "6) Mostrar devoluciones de libros (recursivo)\n"
    << "7) Buscar en prestamos/devoluciones (recursivo)\n"
    << "8) Vaciar prestamos y devoluciones realizadas (recursivo)\n"
    << "9) Estadisticas (size recursivo)\n"
    << "0) Salir\n"
    << "Opcion: ";
}

void loopMenu() {

    Cola* eventos = new Cola;      // tu struct/clase

    //Inicializo estructura cola
    eventos->frente = nullptr;
    eventos->final = nullptr;

    Pila* acciones = new Pila;     // tu struct/clase

    //Inicializo estructura pila
    acciones->inicio = nullptr;

    int op;
    do {
        mostrarMenu();
        cin >> op;
        switch(op){
            case 1:
                //Carga solicitudes de pedido de libros
                cargarPreset(eventos);
                break;
            case 2:
                //Carga nueva solicitud de libro (Create)
                encolarManual(eventos);
                break;
            case 3:
                // Presta libro
                procesarSiguiente(eventos, acciones);
                break;
            case 4:
                //Devuelve libro
                deshacer(acciones, eventos);
                break;
            case 5:
                // Muestra Solicitudes de pedido
                printColaRec(eventos);
                break;
            case 6:
                // Muestra acciones!
                printPilaRec(acciones);
                break;
            case 7:
                // Busco informacion de pedido y acciones
                buscarRec(eventos, acciones);
                break;
            case 8:
                //Limpio pedidos
                clearRec(eventos);
                //Limpio acciones
                clearRec(acciones);
                break;
            case 9:
                // Muestra estadisticas
                mostrarStats(eventos, acciones);
                break;
            case 0:
                cout << "Saliendo...\n";

                // IMPORTANTE, libero la memoria SIEMPRE. Aunque salga del programa
                //Limpio pedidos
                clearRec(eventos);
                //Limpio acciones
                clearRec(acciones);

                break;
            default:
                cout << "Opcion invalida\n";
        }
        // al terminar, el loop vuelve automáticamente al menú

    } while(op != 0);
}