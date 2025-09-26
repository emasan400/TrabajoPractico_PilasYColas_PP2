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
     InfoPrestamo datoATrabajar = dequeue(evento);
     datoATrabajar.fechaSolicitud = "Entregado";

     //Lo agrego al principio de la pila
     pushPila(accion,datoATrabajar);

     cout << "El nro de prestamo: " << datoATrabajar.nroPrestamo << " - Nombre: " << datoATrabajar.nombrePersonaPrestamo << " - Libro: " << datoATrabajar.nombreLibro << " fue entregado!" << endl;
}

//Vuelta atras del último cambio ("Control+Z")
void deshacer(Pila*& accion, Cola*& evento) {

     //Consigo ultimo dato de la pila
     InfoPrestamo datoATrabajar = popPila(accion);
     datoATrabajar.fechaSolicitud = "Devuelto";

     //Lo agrego a la cola
     enqueue(evento,datoATrabajar);

     cout << "El nro de prestamo: " << datoATrabajar.nroPrestamo << " - Nombre: " << datoATrabajar.nombrePersonaPrestamo << " - Libro: " << datoATrabajar.nombreLibro << " entregado recien se devolvio!" << endl;

}

//Hago busqueda recursiva dentro de Cola y Pila
void buscarRec(Cola* evento, Pila* accion) {
     int op;
     do {
          cout << endl;
          cout << "Menu busqueda: Que dato quiere buscar? " << endl;
          cout << "1) Nro Prestamo o Devolucion" << endl;
          cout << "2) Persona del Prestamo o Devolucion" << endl;
          cout << "3) Libro del Prestamo o Devolucion" << endl;
          cout << "4) Fecha o estado del Prestamo o Devolucion" << endl;
          cout << "100) Volver al menu" << endl;
          cin >> op;

          //Datos a usar para busqueda
          int nroBuscado = 0;
          string textoBuscado;
          bool encontrado = false;

          switch(op) {
               case 1:

                    cout << "Ingrese numero de Prestamo a buscar: ";

                    //LIMITACION: No estamos chequeando que efectivamente sea un entero el dato ingresado
                    cin >> nroBuscado;
                    cin.ignore();

                    //Busco en cola por nro
                    encontrado = buscarEnColaPorNro(evento->frente, nroBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las solicitudes de prestamos." << endl;
                    }

                    //Busco en pila por nro
                    encontrado = buscarEnPilaPorNro(accion->inicio, nroBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las devoluciones o prestamos realizados.." << endl;
                    }

                    break;
               case 2:

                    cout << "Ingrese nombre de persona a buscar: ";
                    cin >> textoBuscado;

                    encontrado = buscarEnColaPorPersona(evento->frente, textoBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las solicitudes de prestamos." << endl;
                    }

                    encontrado = buscarEnPilaPorPersona(accion->inicio, textoBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las devoluciones o prestamos realizados.." << endl;
                    }
                    break;

               case 3:

                    cout << "Ingrese nombre del libro a buscar: ";
                    cin.ignore();
                    cin >> textoBuscado;

                    encontrado = buscarEnColaPorLibro(evento->frente, textoBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las solicitudes de prestamos." << endl;
                    }

                    encontrado = buscarEnPilaPorLibro(accion->inicio, textoBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las devoluciones o prestamos realizados.." << endl;
                    }
                    break;

               case 4:

                    cout << "Ingrese fecha de solicitud a buscar (aaaa-mm-dd) o ultima solicitud con cambio de estado (Puede ser \"Entregado\" o \"Devuelto\"): ";
                    cin.ignore();
                    cin >> textoBuscado;

                    encontrado = buscarEnColaPorFecha(evento->frente, textoBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las solicitudes de prestamos." << endl;
                    }

                    encontrado = buscarEnPilaPorFecha(accion->inicio, textoBuscado);
                    if (!encontrado) {
                         cout << "No se encontro en las devoluciones o prestamos realizados." << endl;
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

     contadorC = sizeColaRecursiva(nodoC);
     cout << "El size de las solicitudes de prestamos es: " << contadorC << endl;

     NodoPila* nodoP = accion->inicio;
     int contadorP = 0;

     contadorP = sizePilaRecursiva(nodoP);
     cout << "El size de los prestamos y devoluciones realizadas es: " << contadorP << endl;
}