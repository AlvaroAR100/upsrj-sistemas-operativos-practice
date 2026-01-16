

#!/bin/bash

# ============================================================
# Práctica: Exploración del Scheduler Real en Linux (Ubuntu)
# Archivo: scheduler_discovery.sh
# Materia: Sistemas Operativos
# Tema: Scheduler real de Linux (CFS)
# ============================================================

echo "=============================================="
echo " EXPLORACION DEL SCHEDULER REAL DE LINUX (CFS)"
echo "=============================================="
echo

# ------------------------------------------------------------
# CONTEXTO ACADEMICO
# ------------------------------------------------------------
# En clase se estudiaron algoritmos teoricos de planificacion
# como FCFS, SJF y Round Robin.
#
# Estos algoritmos se usan para comprender los conceptos basicos
# de la planificacion de procesos, pero no se aplican directamente
# en sistemas operativos reales como Linux.
#
# Linux utiliza un scheduler moderno llamado:
# Completely Fair Scheduler (CFS)

echo "Contexto:"
echo "En clase se estudiaron algoritmos teoricos como FCFS, SJF y Round Robin."
echo "Linux NO usa estos algoritmos directamente."
echo "En su lugar, utiliza el Completely Fair Scheduler (CFS)."
echo

# ------------------------------------------------------------
# PASO 1: LOCALIZAR EL CODIGO FUENTE DEL KERNEL
# ------------------------------------------------------------
# El codigo fuente del kernel Linux no se encuentra en el
# directorio del usuario (/home).
#
# Normalmente se almacena en /usr/src, que es el directorio
# destinado a codigo fuente del sistema.

echo "Paso 1: Localizando el codigo fuente del kernel..."
cd /usr/src || exit 1
ls
echo

# ------------------------------------------------------------
# PASO 2: DESCOMPRIMIR EL CODIGO FUENTE DEL KERNEL
# ------------------------------------------------------------
# El codigo fuente del kernel suele distribuirse en un
# archivo comprimido (.tar.bz2).
#
# Si el directorio ya existe, no se vuelve a descomprimir.
# Esto permite que el script sea reutilizable.

echo "Paso 2: Descomprimiendo el codigo fuente del kernel..."
if [ ! -d linux-source-5.15.0 ]; then
    tar -xjf linux-source-5.15.0.tar.bz2 || exit 1
fi
echo "Codigo fuente listo."
echo

# ------------------------------------------------------------
# PASO 3: ENTRAR AL DIRECTORIO PRINCIPAL DEL KERNEL
# ------------------------------------------------------------
# El directorio linux-source-5.15.0 contiene todo el codigo
# del kernel Linux.
#
# Dentro de este directorio se encuentran los subsistemas
# principales del sistema operativo.

echo "Paso 3: Entrando al directorio del kernel..."
cd /usr/src/linux-source-5.15.0 || exit 1
ls
echo

# ------------------------------------------------------------
# PASO 4: LOCALIZAR EL SUBSISTEMA DE SCHEDULING
# ------------------------------------------------------------
# El subsistema de planificacion de procesos se encuentra
# dentro del directorio:
#
# kernel/sched
#
# Aqui se implementan las politicas de planificacion del CPU.

echo "Paso 4: Buscando el subsistema de scheduling..."
cd kernel || exit 1

if [ ! -d sched ]; then
    echo "ERROR: No existe el directorio kernel/sched"
    echo "Estructura real del directorio kernel:"
    ls
    exit 1
fi

cd sched || exit 1
ls
echo

# ------------------------------------------------------------
# PASO 5: MOSTRAR EL CODIGO FUENTE DEL CFS
# ------------------------------------------------------------
# El archivo fair.c implementa el Completely Fair Scheduler.
#
# Este scheduler se basa en el concepto de equidad (fairness),
# donde cada proceso recibe tiempo de CPU de forma proporcional
# a su prioridad y al tiempo que ya ha ejecutado.

echo "Paso 5: Mostrando el archivo del CFS (fair.c)"
echo "========================================================"
cat fair.c
echo "========================================================"

# ------------------------------------------------------------
# ANALISIS TEORICO
# ------------------------------------------------------------
#
# A diferencia de FCFS:
# - No ejecuta los procesos solo en orden de llegada.
#
# A diferencia de SJF:
# - No requiere conocer la duracion de los procesos.
#
# A diferencia de Round Robin:
# - No utiliza un quantum fijo para todos los procesos.
#
# El CFS utiliza:
# - virtual runtime (vruntime)
# - estructuras de datos como arboles rojo-negro
# - criterios de equidad para distribuir el CPU
#
# El proceso con menor vruntime es el siguiente en ejecutarse.

# ------------------------------------------------------------
# PREGUNTA DE REFLEXION (OBLIGATORIA)
# ------------------------------------------------------------
#
# ¿Por que Linux no implementa directamente FCFS, SJF o RR
# como se ven en los libros?
#
# Porque estos algoritmos son modelos teoricos simplificados.
# En un sistema operativo real:
# - No se conoce el tiempo exacto de ejecucion de los procesos
# - Existen miles de procesos concurrentes
# - Se requiere baja latencia, equidad y alta escalabilidad
#
# El Completely Fair Scheduler (CFS) es una solucion practica
# y eficiente que se adapta a las necesidades de sistemas
# modernos y multiprocesador.

echo
echo "=============================================="
echo " FIN DE LA PRACTICA"
echo " Scheduler analizado: CFS"
