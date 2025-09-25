//
// Created by emasa on 24/9/2025.
//

#include "../data/pila.h"

#include <iostream>
#include <ostream>

//Push Pila!
void pushPila(Pila*& accion, InfoReserva reserva) {

    //Crear NUEVO nodo con la info leida!
    NodoPila* nuevoNodo = new NodoPila;

    //Asignar los datos al nodo
    nuevoNodo->info = reserva;

    //Siguiente apunta al actual inicio de la pila
    nuevoNodo->siguiente = accion->inicio;

    //El nuevo nodo se convierte en el nuevo inicio
    accion->inicio = nuevoNodo;
}

InfoReserva popPila(Pila*& accion, InfoReserva reserva) {
    //Dato a retornar
    InfoReserva ret = {};

    //Caso donde la pila este vacia. LIMITACION: Si el dato a devolver es null puede generar error. No encontre manejo de error que se haya enseñado en clase. Se puede manejar con throw runtime_error("Error: Pila vacía. No se puede hacer pop a la lista."); segun chatGPT y DeepSeek
    if(!accion->inicio) {
        cout << "La pila esta vacia!" << endl;
        return ret;
    }

    //Preparo dato a retornar
    ret = accion->inicio->info;

    //Manejo memoria de lista
    NodoPila* aux = new NodoPila;
    aux = accion->inicio;
    accion->inicio = accion->inicio->siguiente;

    //Libero Memoria!
    delete aux;

    return ret;
}

// Modificacion IMPORTANTE! Función auxiliar recursiva que recibe un NodoCola* (Error que persistia en codigo y consultado con DeepSeek)
void printPilaRecAux(NodoPila* nodo){

    // Caso base - Llegar al final de la cola
    if (nodo == nullptr) {
        return;
    }

    // Imprimir el nodo actual
    cout << "Numero Devolucion: " << nodo->info.nroReserva << "  Persona: " << nodo->info.nombrePersonaReserva << "  Libro: " << nodo->info.nombreLibro << "  Fecha: " << nodo->info.fechaDevolucion << endl;

    // Llamada recursiva con el siguiente nodo
    printPilaRecAux(nodo->siguiente);

}

// Función principal que permite sacar el valor necesario para iterar recursivamente
void printPilaRec(Pila* evento) {

    // Verificar si la cola existe y no está vacía
    if (evento == nullptr) {
        cout << "La cola no está inicializada!!!" << endl;
        return;
    }

    if (evento->inicio == nullptr) {
        cout << "La cola está vacía!" << endl;
        return;
    }

    /*
     *Llamar a la función auxiliar recursiva. Esto fue necesario por la decision de diseño donde se hace un contenedor que
     *tiene el inicio solamente de la cola en evento->frente. Si quiero que sea recursivo lo tengo que hacer para el dato
     *DENTRO del nodo! Super Importante porque no dejaba solucionar error de recursividad
    */

    printPilaRecAux(evento->inicio);
}

//Libero memoria de Pila
void clearRec(Pila* accion) {

}