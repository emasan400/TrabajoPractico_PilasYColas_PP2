//
// Created by emasa on 24/9/2025.
//

#include "../data/pila.h"

//Push Pila!
void pushPila(Pila*& accion, InfoReserva reserva) {

    //Crear NUEVO nodo con la info leida!
    NodoPila* nuevoNodo = new NodoPila;

    //Asignar los datos al nodo
    nuevoNodo->info = reserva;

    //Siguiente apunta al actual inicio de la pila
    nuevoNodo->siguiente = accion.inicio;

    //El nuevo nodo se convierte en el nuevo inicio
    accion.inicio = nuevoNodo;
}

InfoReserva popPila(Pila*& accion, InfoReserva reserva) {
    InfoReserva ret = {};

    return ret;
}

//Muestro Pila
void printPilaRec(Pila* accion) {

}

//Libero memoria de Pila
void clearRec(Pila* accion) {

}