//
// Created by emasa on 24/9/2025.
//

#ifndef UNTITLED_COLA_H
#define UNTITLED_COLA_H
#include "dominio.h"

//Info de esta estructura en pagina 4, clase 6, UD 4
struct NodoCola{

    InfoReserva info = {};
    NodoCola* siguiente = nullptr;
};

struct Cola {
    //Datos guardados para facilitar "movimientos" en cola
    NodoCola* frente;
    NodoCola* final;
};

//Encolar dato
void enqueue(Cola*&);

//Desencolar dato
InfoReserva dequeue(Cola*&);

//Cargo InfoReserva en la cola
void encolarManual(Cola*&);

//Muestro Cola
void printColaRec(Cola*&);

//Libero memoria de cola
void clearRec(Cola*&);

#endif //UNTITLED_COLA_H