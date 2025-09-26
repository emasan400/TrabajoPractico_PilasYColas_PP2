//
// Created by emasa on 24/9/2025.
//

#include "../data/util.h"

#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

//Cargar informacion del ARCHIVO a la cola. IMPORTANTE!!!
void cargarPreset(Cola*& evento) {

    //Intenta abrir archivo con nombreDefinido
    ifstream archivo("../TP-PilasYColasPP2/data/preset_biblioteca.txt");

    //Manejo de error
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir el archivo data/preset_biblioteca.txt" << endl;
        cout << filesystem::current_path() << endl;
        return;
    }

    //Inicializo infoReserva para sumar al nodo
    InfoReserva reserva;

    //Recorro archivo con datos separados por espacios para cargar registros! (>> mueve entre datos)
    while (archivo >> reserva.nroReserva >> reserva.nombrePersonaReserva >> reserva.nombreLibro >> reserva.fechaDevolucion) {

        /*
         * Mejora! Plantear parte de abajo del comentario como una funcion enqueue
         */

        // Crear NUEVO nodo con la info leida!
        NodoCola* nuevoNodo = new NodoCola;

        nuevoNodo->info = reserva;
        nuevoNodo->siguiente = nullptr;

        // Agregar a la cola sin elementos (Caso 1er entrada)
        if (evento->frente == nullptr) {
            evento->frente = nuevoNodo;
            evento->final = nuevoNodo;
        } else {
            // Agregar a la cola preexistente (Caso agregar al final "FIFO")
            evento->final->siguiente = nuevoNodo;
            evento->final = nuevoNodo;
        }
    }

    //Importante!!! Cierro archivo despues de carga
    archivo.close();

    cout << "Carga completada desde: data/preset_biblioteca.txt " << endl;
}