# Simulación de Planificadores de CPU en C

Este proyecto tiene como objetivo implementar y comparar tres algoritmos básicos de planificación de CPU:

1. **First-Come, First-Served (FCFS)**
2. **Shortest Job First (SJF)**
3. **Round Robin (RR)**

Estos algoritmos son fundamentales para comprender cómo los sistemas operativos asignan la CPU a distintos procesos.

---

## Requisitos previos

* Conocimientos básicos de C (estructuras, arreglos, funciones).
* Familiaridad con conceptos de sistemas operativos:

  * Proceso
  * Tiempo de llegada (*arrival time*)
  * Tiempo de ráfaga (*burst time*)
  * Tiempo de espera (*waiting time*)
  * Tiempo de retorno (*turnaround time*)
* Compilador de C (gcc o equivalente).
* Uso básico de línea de comandos (`make`, `./ejecutable`).

---

## Infraestructura

El proyecto incluye una infraestructura común:

* `process.h` y `process.c`: definición de la estructura `Process` y funciones auxiliares para:

  * Leer procesos desde entrada estándar.
  * Inicializar campos comunes.
  * Imprimir resultados en formato tabular.

Cada algoritmo se implementa en un archivo independiente:

* `fcfs.c`
* `sjf.c`
* `rr.c`

El alumno debe concentrarse únicamente en la **lógica del algoritmo de planificación**, no en la entrada/salida ni en la infraestructura.

---

## Organización del proyecto

La compilación se gestiona mediante un **Makefile**, el cual separa claramente:

* Código fuente
* Archivos objeto
* Ejecutables finales

Estructura generada:

```
build/
├── out/   ← archivos .o
└── bin/   ← ejecutables finales
```

Esta organización refleja prácticas reales usadas en proyectos de sistemas operativos y software de sistemas.

---

## Algoritmos

### 1. First-Come, First-Served (FCFS)

* Los procesos se atienden en el orden en que llegan.
* No hay interrupciones: un proceso se ejecuta hasta terminar.
* Problema clásico: el *efecto convoy* (procesos cortos esperando a uno largo).

**Diagrama de ejemplo:**

Procesos:

* P1 (AT=0, BT=5)
* P2 (AT=1, BT=3)
* P3 (AT=2, BT=2)

```
Tiempo: 0   1   2   3   4   5   6   7   8   9   10
        |---P1---|---P2---|--P3--|
```

---

### 2. Shortest Job First (SJF)

* Se selecciona el proceso con menor tiempo de ráfaga entre los disponibles.
* Minimiza el tiempo promedio de espera.
* Riesgo: *starvation* (procesos largos pueden quedar esperando indefinidamente).

**Diagrama de ejemplo:**

Procesos:

* P1 (AT=0, BT=7)
* P2 (AT=2, BT=4)
* P3 (AT=4, BT=1)

```
Tiempo: 0   1   2   3   4   5   6   7   8   9   10  11  12
        |-------P1-------|----P2----|--P3--|
```

---

### 3. Round Robin (RR)

* Cada proceso recibe un **quantum** fijo de CPU.
* Si no termina en ese quantum, se coloca al final de la cola.
* Garantiza equidad, especialmente en sistemas interactivos.

**Diagrama de ejemplo (quantum = 2):**

Procesos:

* P1 (AT=0, BT=5)
* P2 (AT=1, BT=3)
* P3 (AT=2, BT=4)

```
Tiempo: 0   2   4   6   8   10   12   13
        |P1|P2|P3|P1|P2|P3|P1|
```

---

## Pasos sugeridos para la implementación

1. **Definir la estructura de datos**
   Usar `Process` de `process.h`.

2. **Leer procesos**
   Con `read_processes()`.

3. **Inicializar campos**
   Con `init_processes()`.

4. **Implementar la lógica del scheduler**

   * FCFS: recorrer procesos en orden de llegada.
   * SJF: seleccionar el proceso con menor ráfaga disponible.
   * RR: simular una cola circular con quantum fijo.

5. **Calcular métricas**

   * `waiting_time` = tiempo de inicio − tiempo de llegada
   * `turnaround_time` = `waiting_time + burst_time`

6. **Imprimir resultados**
   Con `print_results()`.

---

## Compilación y ejecución (Makefile)

Para compilar todos los planificadores:

```bash
make
```

Para compilar un planificador específico:

```bash
make fcfs
make sjf
make rr
```

Los ejecutables se generan en:

```text
build/bin/
```

Ejecutar:

```bash
./build/bin/fcfs
./build/bin/sjf
./build/bin/rr
```

Para limpiar los archivos generados:

```bash
make clean
```

---

## Objetivo didáctico

Este proyecto permite comprender cómo distintos algoritmos de planificación afectan:

* El tiempo de espera promedio.
* El tiempo de retorno promedio.
* La equidad entre procesos.
* El diseño modular y la separación entre infraestructura y lógica.

Además, introduce buenas prácticas reales de construcción de software usando **Makefiles** y organización de proyectos en C.