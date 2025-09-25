//
// Created by emasa on 24/9/2025.
//

#include "../data/cola.h"

#include <iostream>
#include <ostream>

//Cargo InfoReserva de manera manual en la cola
void encolarManual(Cola& evento) {

    //Info a cargar
    InfoReserva reserva;

    //Preparar info a cargar
    cout << "Ingrese numero de reserva" << endl;
    cin >> reserva.nroReserva;
    bool control = false;

    //Verificacion de dato ingresado!!! Si o si tiene que ser int
    while (!control) {
        cout << "Ingrese numero de reserva: ";
        if (cin >> reserva.nroReserva) {
            // Si llegamos aca es un numero valido
            control = true;
            // Importante! Limpiar buffer porque estoy leyendo un int! Siempre queda un \n al final que despues molesta ingreso de datos
            cin.ignore();
        } else {
            // Si llegamos aca NO es un numero
            cout << "Error: Debe ingresar un numero entero valido" << endl;
            //Cuando cin falla, se bloquea con flag de error. El metodo llamado permite ingresar datos despues del error!
            cin.clear();
            //Permite ignorar lo ingresado por consola. LIMITACION: Si alguien ingresa más de 1000 caracteres erroneos o no pone \n al final el programa falla!
            cin.ignore(1000, '\n');
        }
    }

    //Ingreso demas info
    cout << "Ingrese nombre de la persona que realiza la reserva" << endl;
    cin >> reserva.nombrePersonaReserva;
    cout << endl;

    cout << "Ingrese nombre del libro retirado" << endl;
    cin >> reserva.nombreLibro;
    cout << endl;

    cout << "Ingrese fecha de devolucion en el siguiente formato aaaa-mm-dd" << endl;
    cin >> reserva.fechaDevolucion;
    cout << endl;

    /*
    * Mejora! Plantear parte de abajo del comentario como una funcion queuque
    */

    // Crear NUEVO nodo con la info leida!
    NodoCola* nuevoNodo = new NodoCola;

    nuevoNodo->info = reserva;
    nuevoNodo->siguiente = nullptr;

    // Agregar a la cola sin elementos (Caso 1er entrada)
    if (evento.frente == nullptr) {
        evento.frente = nuevoNodo;
        evento.final = nuevoNodo;
    } else {
        // Agregar a la cola preexistente (Caso agregar al final "FIFO")
        evento.final->siguiente = nuevoNodo;
        evento.final = nuevoNodo;
    }

    cout << "Se ingreso la reserva nro " << reserva.nroReserva << " de " << reserva.nombrePersonaReserva << " para el libro " << reserva.nombreLibro << " hasta el " << reserva.fechaDevolucion << " correctamente!" << endl;

}

//Muestro Cola recursiva
void printColaRec(Cola evento) {

}

//Libero memoria de cola recursiva
void clearRec(Cola& evento) {

}