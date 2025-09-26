# 📚 Trabajo Práctico – Pilas y Colas (Biblioteca)

Este proyecto corresponde al **Trabajo Práctico de la materia Programación II (Ingeniería Informática, FIE – UDE)**.  
El tema elegido es:

**Biblioteca — Solicitudes de préstamo (Cola) y acciones de préstamo/devolución (Pila con undo)**  

---

## 🚀 Descripción

El programa simula la gestión de una **biblioteca** con dos estructuras principales:

- Las **solicitudes de préstamo** se almacenan en una **Cola** (estructura FIFO).
- Las **acciones realizadas** (entregas de libros y devoluciones) se registran en una **Pila** (estructura LIFO), permitiendo aplicar la operación **undo** para revertir la última acción.

Todas las operaciones principales (mostrar, buscar, vaciar, contar) están implementadas de forma **recursiva**.

---

## 📂 Estructura del proyecto

```
TP-PilasYColasPP2/
│── include/        # Archivos .h (definición de estructuras y funciones)
│── src/            # Archivos .cpp (implementación del programa)
│── data/           # Archivo de preset con reservas iniciales
│── Makefile        # Compilación por consola
│── main.cpp        # Punto de entrada del programa
```

---

## ⚙️ Compilación y ejecución

### ▶️ Opción 1: Usar **CLion**
1. Abrir el proyecto en CLion.
2. Ejecutar con el botón de "Run".
3. El menú principal aparecerá en consola.

### ▶️ Opción 2: Compilar por **terminal**
Si tenés `g++` instalado:

```bash
make clean
make
./biblioteca
```

Esto compila todos los archivos de `src/` y genera el ejecutable `biblioteca`.

---

## 📑 Menú principal

El programa ofrece el siguiente menú:

```
=== TP Pilas y Colas: Biblioteca ===
1) Cargar datos preset
2) Realizar reserva de libro
3) Procesar devolución de libro (dequeue + push acción)
4) Deshacer devolución de libro (pop + revertir)
5) Mostrar reservas de libro (recursivo)
6) Mostrar devoluciones de libro (recursivo)
7) Buscar en reservas/devoluciones (recursivo)
8) Vaciar reservas y devoluciones realizadas (recursivo)
9) Estadísticas (size recursivo)
0) Salir
```

---

## 📂 Archivos de datos

El archivo `data/preset_biblioteca.txt` contiene solicitudes iniciales.  
Formato esperado en cada línea:

```
nroReserva nombrePersona nombreLibro fechaDevolucion
```

Ejemplo:
```
1 YugiMuto MagoOscuro 2025-09-10
2 SetoKaiba DragonBlancodeOjosAzules 2025-09-11
```

---

## 🔄 Funcionalidades principales

- **Cola de Solicitudes de Préstamo:**
  - Cargar desde archivo (`cargarPreset`)
  - Mostrar (`printColaRecAux`)
  - Buscar por número, persona, libro o fecha (`buscarEnColaPorX`)
  - Contar elementos (`sizeColaRecursiva`)
  - Vaciar (`clearColaRecursiva`)

- **Pila de Acciones (Entregas y Devoluciones):**
  - Registrar acción (`push`)
  - Deshacer última acción (`pop`)
  - Mostrar (`printPilaRecAux`)
  - Buscar (`buscarEnPilaPorX`)
  - Contar (`sizePilaRecursiva`)
  - Vaciar (`clearPilaRecAux`)

---

## 🧠 Recursividad aplicada

El proyecto incluye múltiples funciones recursivas.  
Ejemplos:
- `printPilaRecAux`
- `clearColaRecursiva`
- `buscarEnColaPorLibro`
- `sizePilaRecursiva`

Todas siguen el esquema:
1. Caso base (`nodo == nullptr`)
2. Acción actual (imprimir, comparar, borrar, contar)
3. Llamada recursiva con `nodo->siguiente`

---

## 👨‍💻 Autores
Atadia Ignacio
Sanchez Emanuel Andres

- **Emanuel Sánchez** – Legajo XXXXXX  
Facultad de Ingeniería del Ejército – Ingeniería Informática
