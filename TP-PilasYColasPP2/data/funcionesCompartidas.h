//
// Created by emasa on 24/9/2025.
//

#ifndef UNTITLED_FUNCIONESCOMPARTIDAS_H
#define UNTITLED_FUNCIONESCOMPARTIDAS_H
#include "cola.h"
#include "pila.h"

//Funciones compartidas entre estructuras!

//Hago dequeue y guardo dato sacado en Pila
void procesarSiguiente(Cola*&, Pila*&);

//Hago busqueda recursiva dentro de Cola y Pila
void buscarRec(Cola*, Pila*);

//Vuelta atras del último cambio ("Control+Z")
void deshacer(Pila*&,Cola*&);

//Muestra "estadisticas de las listas a mostrar"
void mostrarStats(Cola*, Pila*);

#endif //UNTITLED_FUNCIONESCOMPARTIDAS_H