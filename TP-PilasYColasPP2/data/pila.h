//
// Created by emasa on 24/9/2025.
//

#ifndef UNTITLED_PILA_H
#define UNTITLED_PILA_H
#include "dominio.h"

struct NodoPila{

    InfoReserva info;
    NodoPila* siguiente = nullptr;

};

struct Pila {
    NodoPila* inicio;
};

//Funcion auxiliar para recursividad como solucion investigada
void printPilaRecAux(NodoPila*);

//Push pila
void pushPila(Pila*& accion, InfoReserva);

//Pop pila
InfoReserva popPila(Pila*& accion);

//Muestro Pila
void printPilaRec(Pila*);

//Funcion auxiliar para recursividad por diseño
void clearRecAux(NodoPila*&);

//Libero memoria de Pila
void clearRec(Pila*);

//Funciones auxiliares para busqueda recursiva en pila por tipo de dato a buscar!!!
bool buscarEnPilaPorNro(NodoPila*, int);
bool buscarEnPilaPorPersona(NodoPila*, string);
bool buscarEnPilaPorLibro(NodoPila*, string);
bool buscarEnPilaPorFecha(NodoPila*, string);

#endif //UNTITLED_PILA_H