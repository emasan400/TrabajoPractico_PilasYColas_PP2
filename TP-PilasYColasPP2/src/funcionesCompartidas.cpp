//
// Created by emasa on 24/9/2025.
//

#include "../data/funcionesCompartidas.h"

#include <iostream>
#include <ostream>

#include "../data/cola.h"
#include "../data/pila.h"

//Hago dequeue y guardo dato sacado en Pila
void procesarSiguiente(Cola*& evento, Pila*& accion) {

     //Consigo último dato de la cola
     InfoReserva datoATrabajar = dequeue(evento);

     //Lo agrego al principio de la pila
     pushPila(accion,datoATrabajar);
}

//Vuelta atras del último cambio ("Control+Z")
void deshacer(Pila*& accion, Cola*& evento) {

     //Consigo ultimo dato de la pila
     InfoReserva datoATrabajar = popPila(accion);

     //Lo agrego a la cola
     enqueue(evento,datoATrabajar);
}

//Hago busqueda recursiva dentro de Cola y Pila
void buscarRec(Cola* evento, Pila* accion) {
     int op;
     do {
          cout << "Que dato quiere buscar? " << endl;
          cout << "1) Nro Reserva o Devolucion" << endl;
          cout << "2) Persona de la Reserva o Devolucion" << endl;
          cout << "2) Libro de la Reserva o Devolucion" << endl;
          cout << "2) Fecha de la Reserva o Devolucion" << endl;

          cin >> op;
          switch(op) {
               case 1: ;
                    break;
               default: cout << "Opcion invalida\n";
          }
}

//Muestra "estadisticas de las listas a mostrar"
void mostrarStats(Cola* evento, Pila* accion) {

}