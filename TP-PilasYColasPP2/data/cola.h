//
// Created by emasa on 24/9/2025.
//

#ifndef UNTITLED_COLA_H
#define UNTITLED_COLA_H
#include "dominio.h"

//Info de esta estructura en pagina 4, clase 6, UD 4
struct NodoCola{

    InfoReserva info = {};
    NodoCola *siguiente = nullptr;
};

struct Cola {
    //Datos guardados para facilitar "movimientos" en cola
    NodoCola* frente;
    NodoCola* final;
};

//Funcion auxiliar para recursividad como solucion investigada
void printColaRecAux(NodoCola*);

//Encolar dato
void enqueue(Cola*&, InfoReserva);

//Desencolar dato
InfoReserva dequeue(Cola*&);

//Cargo InfoReserva en la cola
void encolarManual(Cola*&);

//Muestro Cola
void printColaRec(Cola*);

//Libero memoria recursivamente aux
void clearColaRecursiva(NodoCola*&);

//Libero memoria de cola
void clearRec(Cola*&);

//Funciones auxiliares para busqueda recursiva en cola por tipo de dato a buscar!!!
bool buscarEnColaPorNro(NodoCola*, int);
bool buscarEnColaPorPersona(NodoCola*, string);
bool buscarEnColaPorLibro(NodoCola*, string);
bool buscarEnColaPorFecha(NodoCola*, string);

//Funcion size recursiva cola
int sizeColaRecursiva(NodoCola*);

#endif //UNTITLED_COLA_H