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
          cout << "Menu busqueda: Que dato quiere buscar? " << endl;
          cout << "1) Nro Reserva o Devolucion" << endl;
          cout << "2) Persona de la Reserva o Devolucion" << endl;
          cout << "3) Libro de la Reserva o Devolucion" << endl;
          cout << "4) Fecha de la Reserva o Devolucion" << endl;
          cout << "100) Volver al menu" << endl;
          cin >> op;

          //Datos a usar para busqueda
          int nroBuscado = 0;
          string textoBuscado = "";
          bool encontrado = false;

          switch(op) {
               case 1:

                    cout << "Ingrese numero de reserva a buscar: ";

                    //LIMITACION: No estamos chequeando que efectivamente sea un entero el dato ingresado
                    cin >> nroBuscado;
                    cin.ignore();

                    //Busco en cola por nro
                    encontrado = buscarEnColaPorNro(evento->frente, nroBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las reservas." << endl;
                    }

                    //Busco en pila por nro
                    encontrado = buscarEnPilaPorNro(accion->inicio, nroBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las devoluciones." << endl;
                    }

                    break;
               case 2:

                    cout << "Ingrese nombre de persona a buscar: ";
                    cin >> textoBuscado;

                    encontrado = buscarEnColaPorPersona(evento->frente, textoBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las reservas." << endl;
                    }

                    encontrado = buscarEnPilaPorPersona(accion->inicio, textoBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las devoluciones." << endl;
                    }
                    break;

               case 3:

                    cout << "Ingrese nombre del libro a buscar: ";
                    cin.ignore();
                    cin >> textoBuscado;

                    encontrado = buscarEnColaPorLibro(evento->frente, textoBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las reservas." << endl;
                    }

                    encontrado = buscarEnPilaPorLibro(accion->inicio, textoBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las devoluciones." << endl;
                    }
                    break;

               case 4:

                    cout << "Ingrese fecha de devolucion a buscar (aaaa-mm-dd): ";
                    cin.ignore();
                    cin >> textoBuscado;

                    encontrado = buscarEnColaPorFecha(evento->frente, textoBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las reservas." << endl;
                    }

                    encontrado = buscarEnPilaPorFecha(accion->inicio, textoBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las devoluciones." << endl;
                    }

                    break;
               case 100:

                    cout << "Volviendo al menu principal" << endl;

                    break;

               default:

                    cout << "Opcion invalida! Ingrese numero de opciones valido" << endl;

                    break;
          }

     }while (op != 100);
}

//Muestra "estadisticas de las listas a mostrar"
void mostrarStats(Cola* evento, Pila* accion) {

     NodoCola* nodoC = evento->frente;
     int contadorC = 0;

     NodoPila* nodoP = accion->inicio;
     int contadorP = 0;


}