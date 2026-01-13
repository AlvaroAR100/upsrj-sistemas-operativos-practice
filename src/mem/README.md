# Simulación de Algoritmos de Reemplazo de Páginas en C

Este proyecto tiene como objetivo implementar y comparar dos algoritmos clásicos de **reemplazo de páginas en memoria virtual**:

1. **First-In, First-Out (FIFO)**
2. **Least Recently Used (LRU)**

Estos algoritmos permiten entender cómo un sistema operativo decide **qué página remover de memoria** cuando ocurre un **page fault** y la memoria física está llena.

---

## Requisitos previos

* Conocimientos básicos de C (arreglos, estructuras, funciones).
* Familiaridad con conceptos de sistemas operativos:

  * Memoria virtual
  * Página
  * Marco (*frame*)
  * Page fault
  * Localidad temporal
* Compilador de C (gcc o equivalente).
* Uso básico de `make` desde línea de comandos.

---

## Infraestructura

El proyecto proporciona una infraestructura común para ambos algoritmos:

* `memory.h` y `memory.c`:

  * Definición de estructuras comunes.
  * Lectura de la secuencia de referencias de páginas.
  * Inicialización de marcos de memoria.
  * Impresión de resultados.

Cada algoritmo se implementa en un archivo independiente:

* `fifo.c`
* `lru.c`

El alumno debe concentrarse únicamente en la **lógica del algoritmo de reemplazo**, no en la entrada/salida ni en la administración de memoria auxiliar.

---

## Organización del proyecto

La compilación se gestiona mediante un **Makefile**, el cual separa claramente los distintos artefactos de construcción:

```
build/
├── out/   ← archivos objeto (.o)
└── bin/   ← ejecutables finales
```

Esta estructura sigue buenas prácticas usadas en proyectos reales de sistemas.

---

## Algoritmos de reemplazo

### 1. First-In, First-Out (FIFO)

* Se reemplaza la página que **lleva más tiempo en memoria**.
* No considera patrones de uso ni localidad.
* Fácil de implementar, pero puede tener resultados pobres.

**Ejemplo:**

Marcos = 3
Referencias: `7 0 1 2 0 3 0 4`

```
Referencia | Marcos       | Page Fault
-----------+--------------+------------
7          | 7 - -        | Sí
0          | 7 0 -        | Sí
1          | 7 0 1        | Sí
2          | 2 0 1        | Sí
0          | 2 0 1        | No
3          | 2 3 1        | Sí
0          | 2 3 0        | Sí
4          | 4 3 0        | Sí
```

---

### 2. Least Recently Used (LRU)

* Se reemplaza la página que **no ha sido usada por más tiempo**.
* Se basa en el principio de **localidad temporal**.
* Mejor desempeño que FIFO, pero mayor complejidad.

**Ejemplo:**

Marcos = 3
Referencias: `7 0 1 2 0 3 0 4`

```
Referencia | Marcos       | Page Fault
-----------+--------------+------------
7          | 7 - -        | Sí
0          | 7 0 -        | Sí
1          | 7 0 1        | Sí
2          | 2 0 1        | Sí
0          | 2 0 1        | No
3          | 2 0 3        | Sí
0          | 2 0 3        | No
4          | 4 0 3        | Sí
```

---

## Pasos sugeridos para la implementación

1. **Definir las estructuras de datos**
   Usar las definiciones en `memory.h`.

2. **Leer la secuencia de referencias**
   Mediante la función proporcionada en la infraestructura.

3. **Inicializar los marcos de memoria**
   Con valores inválidos o vacíos.

4. **Implementar el algoritmo**

   * FIFO: mantener un índice circular o cola.
   * LRU: registrar el último uso de cada página.

5. **Detectar page faults**

   * Verificar si la página ya se encuentra en memoria.

6. **Imprimir resultados**

   * Estado de los marcos tras cada referencia.
   * Número total de page faults.

---

## Compilación y ejecución (Makefile)

Para compilar todos los algoritmos de memoria:

```bash
make
```

Para compilar un algoritmo específico:

```bash
make fifo
make lru
```

Los ejecutables se generan en:

```text
build/bin/
```

Ejecutar:

```bash
./build/bin/fifo
./build/bin/lru
```

Para limpiar los archivos generados:

```bash
make clean
```

---

## Objetivo didáctico

Este proyecto permite comprender:

* Cómo los sistemas operativos manejan memoria limitada.
* El impacto de la localidad temporal en el rendimiento.
* Las diferencias prácticas entre FIFO y LRU.
* La importancia de la modularidad y el uso de Makefiles en proyectos de C.