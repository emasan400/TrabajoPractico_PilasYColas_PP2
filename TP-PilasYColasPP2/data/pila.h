//
// Created by emasa on 24/9/2025.
//

#ifndef UNTITLED_PILA_H
#define UNTITLED_PILA_H
#include "dominio.h"

struct Pila{

    InfoReserva info;
    Pila* siguiente;

};

//Muestro Pila
void printPilaRec(Pila);

//Libero memoria de Pila
void clearRec(Pila);

#endif //UNTITLED_PILA_H