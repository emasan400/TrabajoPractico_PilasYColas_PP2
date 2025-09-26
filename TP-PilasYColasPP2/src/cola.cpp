//
// Created by emasa on 24/9/2025.
//

#include "../data/cola.h"

#include <iostream>
#include <ostream>

/*
* Mejoras! Se podian hacer funciones aparte con lo hecho en la guia y contenido de pagina 4, Clase 6, UD 4
*/

void enqueue(Cola*& evento, InfoReserva reserva){

    // Crear NUEVO nodo con la info leida!
    NodoCola* nuevoNodo = new NodoCola;

    nuevoNodo->info = reserva;
    nuevoNodo->siguiente = nullptr;

    // Agregar a la cola sin elementos (Caso 1er entrada)
    if (evento->frente == nullptr) {
        evento->frente = nuevoNodo;
        evento->final = nuevoNodo;
    } else {
        // Agregar a la cola preexistente (Caso agregar al final "FIFO")
        evento->final->siguiente = nuevoNodo;
        evento->final = nuevoNodo;
    }
}

InfoReserva dequeue(Cola*& evento) {

    //Dato a retornar, creado por facilidad personal para devolver datos (Posible optimizacion en v2 con #include <queue>) LIMITACION: Si el dato a devolver es null puede generar error
    InfoReserva ret = {};

    //Caso lista vacia. Manejo de error en funcionesCompartidas.cpp
    if (!evento->frente) {
        cout << "No hay reservas!" << endl;
        return ret;
    }

    //Caso "normal"

    //Consigo info a retornar del primer elemento de la cola (FIFO)
    ret = evento->frente->info;

    //Preparo delete del nodo sin desindexar la cola
    NodoCola* aux = evento->frente;
    evento->frente = evento->frente->siguiente;

    //Caso donde evento.frente->siguiente es el final de la cola!
    if (!evento->frente) {
        evento->final = nullptr;
    }

    //Libero memoria
    delete aux;

    return ret;
}

//Cargo InfoReserva de manera manual en la cola
void encolarManual(Cola*& evento) {

    //Info a cargar
    InfoReserva reserva;

    //Preparar info a cargar. LIMITACIONES: No verifico que sea INT realmente
    cout << "Ingrese numero de reserva" << endl;
    cin >> reserva.nroReserva;
    cin.ignore();

    //Ingreso demas info
    cout << "Ingrese nombre de la persona que realiza la reserva" << endl;
    cin >> reserva.nombrePersonaReserva;
    cout << endl;

    cout << "Ingrese nombre del libro retirado" << endl;
    cin >> reserva.nombreLibro;
    cout << endl;

    cout << "Ingrese fecha de devolucion en el siguiente formato aaaa-mm-dd" << endl;
    cin >> reserva.fechaDevolucion;
    cout << endl;

    enqueue(evento, reserva);

    cout << "Se ingreso la reserva nro " << reserva.nroReserva << " de " << reserva.nombrePersonaReserva << " para el libro " << reserva.nombreLibro << " hasta el " << reserva.fechaDevolucion << " correctamente!" << endl;

}

// Modificacion IMPORTANTE! Función auxiliar recursiva que recibe un NodoCola* (Error que persistia en codigo y consultado con DeepSeek)
void printColaRecAux(NodoCola* nodo) {

    // Caso base - Llegar al final de la cola
    if (nodo == nullptr) {
        return;
    }

    // Imprimir el nodo actual
    cout << "Numero Reserva: " << nodo->info.nroReserva << "  Persona: " << nodo->info.nombrePersonaReserva << "  Libro: " << nodo->info.nombreLibro << "  Fecha: " << nodo->info.fechaDevolucion << endl;

    // Llamada recursiva con el siguiente nodo
    printColaRecAux(nodo->siguiente);
}

// Función principal que permite sacar el valor necesario para iterar recursivamente
void printColaRec(Cola* evento) {

    // Verificar si la cola existe y no está vacía
    if (evento == nullptr) {
        cout << "La cola no esta inicializada!!!" << endl;
        return;
    }

    if (evento->frente == nullptr) {
        cout << "La cola esta vacia!" << endl;
        return;
    }

    /*
     *Llamar a la función auxiliar recursiva. Esto fue necesario por la decision de diseño donde se hace un contenedor que
     *tiene el inicio solamente de la cola en evento->frente. Si quiero que sea recursivo lo tengo que hacer para el dato
     *DENTRO del nodo! Super Importante porque no dejaba solucionar error de recursividad
    */

    printColaRecAux(evento->frente);
}

//Libero memoria recursivamente aux
void clearColaRecursiva(NodoCola*& nodo) {

    // Caso base
    if (nodo == nullptr)
    {
        return;
    }

    clearColaRecursiva(nodo->siguiente);
    delete nodo;
    nodo = nullptr;

}

//Libero memoria de cola recursiva
void clearRec(Cola*& evento) {
    clearColaRecursiva(evento->frente);

    cout << "Se limpiaron las reservas!" << endl;
}

// Buscar por número de reserva en Cola (recursiva)
bool buscarEnColaPorNro(NodoCola* nodo, int nroBuscado) {

	// Caso base
	if (nodo == nullptr)
	{
		return false;
	}

    if (nodo->info.nroReserva == nroBuscado) {
        cout << "Encontrado!!! - Reserva " << nodo->info.nroReserva << " - Persona: " << nodo->info.nombrePersonaReserva << " - Libro: " << nodo->info.nombreLibro << " - Fecha: " << nodo->info.fechaDevolucion << endl;
        return true;
    }

    return buscarEnColaPorNro(nodo->siguiente, nroBuscado);
}

// Buscar por persona en Cola (recursiva)
bool buscarEnColaPorPersona(NodoCola* nodo, string personaBuscada) {
    // Caso base
	if (nodo == nullptr)
	{
		return false;
	}

    if (nodo->info.nombrePersonaReserva == personaBuscada) {
        cout << "Encontrado!!! - Reserva " << nodo->info.nroReserva << " - Persona: " << nodo->info.nombrePersonaReserva << " - Libro: " << nodo->info.nombreLibro << " - Fecha: " << nodo->info.fechaDevolucion << endl;
        return true;
    }

    return buscarEnColaPorPersona(nodo->siguiente, personaBuscada);
}

// Buscar por libro en Cola (recursiva)
bool buscarEnColaPorLibro(NodoCola* nodo, string libroBuscado) {
    // Caso base
	if (nodo == nullptr)
	{
		return false;
	}

    if (nodo->info.nombreLibro == libroBuscado) {
        cout << "Encontrado!!! - Reserva " << nodo->info.nroReserva << " - Persona: " << nodo->info.nombrePersonaReserva << " - Libro: " << nodo->info.nombreLibro << " - Fecha: " << nodo->info.fechaDevolucion << endl;
        return true;
    }

    return buscarEnColaPorLibro(nodo->siguiente, libroBuscado);
}

// Buscar por fecha en Cola (recursiva)
bool buscarEnColaPorFecha(NodoCola* nodo, string fechaBuscada) {
    // Caso base
	if (nodo == nullptr)
	{
		return false;
	}

    if (nodo->info.fechaDevolucion == fechaBuscada) {
        cout << "Encontrado!!! - Reserva " << nodo->info.nroReserva << " - Persona: " << nodo->info.nombrePersonaReserva << " - Libro: " << nodo->info.nombreLibro << " - Fecha: " << nodo->info.fechaDevolucion << endl;
        return true;
    }

    return buscarEnColaPorFecha(nodo->siguiente, fechaBuscada);
}

//Funcion size recursiva cola
int sizeColaRecursiva(NodoCola* nodo) {
    // Caso base
    if (nodo == nullptr) {
        return 0;
    }

    return (1 + sizeColaRecursiva(nodo->siguiente));
}