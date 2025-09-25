//
// Created by emasa on 24/9/2025.
//

#include "../data/funcionesCompartidas.h"
#include "../data/cola.h"
#include "../data/pila.h"

//Hago dequeue y guardo dato sacado en Pila
void procesarSiguiente(Cola& evento, Pila& accion) {

     //Consigo último dato de la cola
     InfoReserva datoATrabajar = dequeue(evento);

     //Lo agrego al principio de la pila
     pushPila(accion,datoATrabajar);
}

//Hago busqueda recursiva dentro de Cola y Pila
void buscarRec(Cola evento, Pila accion) {

}

//Vuelta atras del último cambio ("Control+Z")
void deshacer(Pila& accion, Cola& evento) {

}

//Muestra "estadisticas de las listas a mostrar"
void mostrarStats(Cola evento, Pila accion) {

}