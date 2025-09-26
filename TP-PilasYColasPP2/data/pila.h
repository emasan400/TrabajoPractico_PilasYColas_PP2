//
// Created by emasa on 24/9/2025.
//

#ifndef UNTITLED_PILA_H
#define UNTITLED_PILA_H
#include "dominio.h"

struct NodoPila{

    InfoPrestamo info;
    NodoPila* siguiente = nullptr;

};

struct Pila {
    NodoPila* inicio;
};

//Funcion auxiliar para recursividad como solucion investigada
void printPilaRecAux(NodoPila*);

//Push pila
void pushPila(Pila*&, InfoPrestamo);

//Pop pila
InfoPrestamo popPila(Pila*&);

//Muestro Pila
void printPilaRec(Pila*);

//Funcion auxiliar para recursividad por diseño
void clearPilaRecAux(NodoPila*&);

//Libero memoria de Pila
void clearRec(Pila*);

//Funciones auxiliares para busqueda recursiva en pila por tipo de dato a buscar!!!
bool buscarEnPilaPorNro(NodoPila*, int);
bool buscarEnPilaPorPersona(NodoPila*, string);
bool buscarEnPilaPorLibro(NodoPila*, string);
bool buscarEnPilaPorFecha(NodoPila*, string);

//Funcion size recursiva pila
int sizePilaRecursiva(NodoPila*);

#endif //UNTITLED_PILA_H