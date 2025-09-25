cmake_minimum_required(VERSION 4.0)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled "TP-PilasYColasPP2/src/main.cpp"
        "TP-PilasYColasPP2/src/menu.cpp"
        "TP-PilasYColasPP2/data/menu.h"
        "TP-PilasYColasPP2/src/pila.cpp"
        "TP-PilasYColasPP2/data/pila.h"
        "TP-PilasYColasPP2/src/cola.cpp"
        "TP-PilasYColasPP2/data/cola.h"
        "TP-PilasYColasPP2/src/util.cpp"
        "TP-PilasYColasPP2/data/util.h"
        "TP-PilasYColasPP2/src/dominio.cpp"
        "TP-PilasYColasPP2/data/dominio.h"
        TP-PilasYColasPP2/src/funcionesCompartidas.cpp
        TP-PilasYColasPP2/data/funcionesCompartidas.h
)
