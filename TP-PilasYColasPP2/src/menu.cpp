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
    << "2) Realizar reserva de libro\n"
    << "3) Procesar devolucion de libro(dequeue + push accion)\n"
    << "4) Deshacer devolucion de libro(pop + revertir)\n"
    << "5) Mostrar reservas de libro (recursivo)\n"
    << "6) Mostrar devoluciones de libro(recursivo)\n"
    << "7) Buscar en reservas/devoluciones (recursivo)\n"
    << "8) Vaciar reservas y devoluciones realizadas (recursivo)\n"
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
                cargarPreset(eventos);
                break;
            case 2:
                encolarManual(eventos);
                break;
            case 3:
                procesarSiguiente(eventos, acciones);
                break;
            case 4:
                deshacer(acciones, eventos);
                break;
            case 5:
                printColaRec(eventos);
                break;
            case 6:
                printPilaRec(acciones);
                break;
            case 7:
                buscarRec(eventos, acciones);
                break;
            case 8:
                clearRec(eventos);
                clearRec(acciones);
                break;
            case 9:
                mostrarStats(eventos, acciones);
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }
        // al terminar, el loop vuelve automáticamente al menú

    } while(op != 0);
}