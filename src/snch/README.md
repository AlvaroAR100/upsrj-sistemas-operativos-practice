# Sincronización con Mutex y Semáforos

## Problema de los Monos Cruzando un Puente

---

## Objetivo del ejercicio

Este ejercicio tiene como objetivo introducir los conceptos fundamentales de **sincronización en sistemas operativos**, en particular:

* Concurrencia
* Secciones críticas
* Condiciones de carrera
* Exclusión mutua
* Uso de mutex y semáforos

El problema se presenta mediante una situación clásica: **varios monos cruzando un puente angosto**, donde la sincronización incorrecta conduce a comportamientos inválidos aunque el programa *aparente* funcionar.

---

## Descripción del problema

Se tiene un puente angosto con las siguientes restricciones:

* El puente solo puede ser usado por monos que crucen **en la misma dirección**.
* Múltiples monos pueden cruzar simultáneamente **si van en la misma dirección**.
* Nunca debe haber monos cruzando en **direcciones opuestas al mismo tiempo**.

Cada mono es representado por un **hilo de ejecución** (`pthread`).

---

## Escenario sin sincronización

Inicialmente, el programa se ejecuta **sin ninguna lógica de sincronización**.

### Comportamiento observado

* Todos los monos cruzan el puente sin esperar.
* Monos de direcciones opuestas cruzan simultáneamente.
* El programa **no se bloquea** ni produce errores visibles.

Ejemplo de salida:

```text
Monkey 4 is crossing (LEFT -> RIGHT)
Monkey 1 is crossing (RIGHT -> LEFT)
```

### Análisis

Este comportamiento es incorrecto desde el punto de vista lógico, pero:

> **El sistema operativo no detecta ni corrige errores de concurrencia.**

Esto ilustra un concepto clave:

> *Un programa concurrente puede ejecutarse y terminar correctamente,
> aun cuando su lógica sea inválida.*

Este tipo de error se conoce como **condición de carrera** (*race condition*).

---

## Fundamento teórico

### Concurrencia

La concurrencia ocurre cuando múltiples hilos o procesos se ejecutan de manera intercalada o simultánea, compartiendo recursos.

---

### Sección crítica

Una **sección crítica** es una región del código donde se accede a recursos compartidos:

* Estado del puente
* Número de monos cruzando
* Dirección actual del cruce

Si múltiples hilos entran a esta región sin control, se producen inconsistencias.

---

### Condición de carrera

Una condición de carrera ocurre cuando:

* El resultado del programa depende del **orden de ejecución de los hilos**
* Ese orden no está controlado por el programador

En este ejercicio, el acceso sin protección permite que múltiples direcciones usen el puente simultáneamente.

---

### Exclusión mutua

La **exclusión mutua** garantiza que:

* Solo un hilo a la vez puede modificar el estado compartido
* Se protege la sección crítica

Se implementa mediante:

* **Mutex**
* **Semáforos**

---

## Solución: sincronización con mutex y semáforos

La solución correcta implementa:

* **Mutex (`pthread_mutex_t`)**

  * Protege el estado compartido del puente
* **Semáforo (`sem_t`)**

  * Controla el acceso al puente como recurso

### Idea principal

1. El primer mono que entra fija la dirección del puente.
2. Monos en la misma dirección pueden entrar.
3. Monos en dirección opuesta esperan.
4. El último mono libera el puente.

---

## Estructura del proyecto

```
bridge/
├── main.c        ← creación de hilos (monos)
├── bridge.c     ← lógica de sincronización
├── bridge.h     ← interfaz del puente
├── Makefile
└── README.md
```

---

## Compilación y ejecución

### Compilar

```bash
make
```

### Ejecutar

```bash
./build/bin/bridge
```

### Limpiar archivos generados

```bash
make clean
```

---

## Resultados esperados

### Sin sincronización

* El programa termina
* El comportamiento es incorrecto
* Se observan violaciones de las reglas del puente

### Con sincronización

* Nunca hay monos cruzando en direcciones opuestas
* El comportamiento es consistente
* La ejecución sigue siendo concurrente

---

## Objetivo didáctico

Al finalizar este ejercicio, el alumno será capaz de:

* Identificar condiciones de carrera
* Comprender por qué la concurrencia incorrecta no siempre falla visiblemente
* Usar mutex y semáforos para proteger secciones críticas
* Explicar la diferencia entre concurrencia y paralelismo
