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

InfoReserva popPila(Pila*& accion) {
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
        cout << "La cola no esta inicializada!!!" << endl;
        return;
    }

    if (evento->inicio == nullptr) {
        cout << "La cola esta vacia!" << endl;
        return;
    }

    /*
     *Llamar a la función auxiliar recursiva. Esto fue necesario por la decision de diseño donde se hace un contenedor que
     *tiene el inicio solamente de la cola en evento->frente. Si quiero que sea recursivo lo tengo que hacer para el dato
     *DENTRO del nodo! Super Importante porque no dejaba solucionar error de recursividad
    */

    printPilaRecAux(evento->inicio);
}

//Funcion aux que libera la memoria para evitar fallas
void clearRecAux(NodoPila*& nodo) {

    //Caso base
    if (nodo == nullptr) {
        return;
    }

    //Llamada recursiva!
    clearRecAux(nodo->siguiente);

    //Libero memoria y limpio basura de nodo
    delete nodo;
    nodo = nullptr;
}

/*
 * Libero memoria de Pila. Necesita una funcion aux por decision de diseño! Tiene una diferencia con clearCola!!!
 * NO es necesario pasar por referencia el objeto Pila. SI es necesario pasar por referencia el objeto NodoPila!
 * Funcionan igual. Pensar en que opcion es más optima
*/
void clearRec(Pila* accion) {
    clearRecAux(accion->inicio);
}

// Buscar por número de reserva en Pila (recursiva)
bool buscarEnPilaPorNro(NodoPila* nodo, int nroBuscado) {

    // Caso base
    if (nodo == nullptr) {
        return false;
    }

    if (nodo->info.nroReserva == nroBuscado) {
        cout << "Encontrado!!! - Devolucion nro " << nodo->info.nroReserva << " - Persona: " << nodo->info.nombrePersonaReserva << " - Libro: " << nodo->info.nombreLibro << " - Fecha: " << nodo->info.fechaDevolucion << endl;
        return true;
    }

    //Llamada recursiva
    return buscarEnPilaPorNro(nodo->siguiente, nroBuscado);
}

// Buscar por persona en Pila (recursiva)
bool buscarEnPilaPorPersona(NodoPila* nodo, string personaBuscada) {

    // Caso base
    if (nodo == nullptr) {
        return false;
    }

    if (nodo->info.nombrePersonaReserva == personaBuscada) {
        cout << "Encontrado!!! - Devolucion nro " << nodo->info.nroReserva << " - Persona: " << nodo->info.nombrePersonaReserva << " - Libro: " << nodo->info.nombreLibro << " - Fecha: " << nodo->info.fechaDevolucion << endl;
        return true;
    }

    return buscarEnPilaPorPersona(nodo->siguiente, personaBuscada); // Recursividad
}

// Buscar por libro en Pila (recursiva)
bool buscarEnPilaPorLibro(NodoPila* nodo, string libroBuscado) {

    // Caso base
    if (nodo == nullptr) {
        return false;
    }


    if (nodo->info.nombreLibro == libroBuscado) {
        cout << "Encontrado!!! - Devolucion nro " << nodo->info.nroReserva << " - Persona: " << nodo->info.nombrePersonaReserva << " - Libro: " << nodo->info.nombreLibro << " - Fecha: " << nodo->info.fechaDevolucion << endl;
        return true;
    }

    return buscarEnPilaPorLibro(nodo->siguiente, libroBuscado); // Recursividad
}

// Buscar por fecha en Pila (recursiva)
bool buscarEnPilaPorFecha(NodoPila* nodo,string fechaBuscada) {

    // Caso base
    if (nodo == nullptr) {
        return false;
    }

    if (nodo->info.fechaDevolucion == fechaBuscada) {
        cout << "Encontrado!!! - Devolucion nro " << nodo->info.nroReserva << " - Persona: " << nodo->info.nombrePersonaReserva << " - Libro: " << nodo->info.nombreLibro << " - Fecha: " << nodo->info.fechaDevolucion << endl;
        return true;
    }

    return buscarEnPilaPorFecha(nodo->siguiente, fechaBuscada); // Recursividad
}

// Tamaño de pila recursiva
int sizePilaRecursiva(NodoPila* nodo) {
    // Caso base
    if (nodo == nullptr) {
        return 0;
    }

    return (1 + sizePilaRecursiva(nodo->siguiente));
}
