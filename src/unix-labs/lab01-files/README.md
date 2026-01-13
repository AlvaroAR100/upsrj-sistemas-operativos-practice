# LAB 01 – Gestión de archivos y directorios

## Objetivo

El alumno debe demostrar que comprende el manejo básico del sistema de archivos en Linux, creando una estructura de directorios estandarizada, manipulando archivos y analizando el uso de espacio en disco, dejando evidencia de su trabajo en un script de shell reproducible.

---

## Entregable

* Un archivo de script llamado:

```
lab01_files.sh
```

Este script debe contener todas las acciones descritas en esta práctica y debe poder ejecutarse en cualquier momento para reproducir exactamente el mismo resultado.

---

## Estructura esperada al finalizar la práctica

Al finalizar la práctica, el sistema de archivos del alumno **debe contener exactamente** la siguiente estructura dentro de su directorio personal:

```
~/unix-labs/
└── lab01/
    └── test/
        ├── docs/
        │   └── readme.txt
        ├── bin/
        └── tmp/
            └── readme.txt
```

---

## Instrucciones

### Paso 1 – Creación del directorio base del curso

Dentro del directorio personal del usuario, el alumno debe crear un directorio llamado `unix-labs`, el cual funcionará como contenedor de todas las prácticas del bloque UNIX.

Dentro de `unix-labs`, debe crear un directorio específico para esta práctica llamado `lab01`.

---

### Paso 2 – Creación de la estructura de trabajo de la práctica

Dentro del directorio `lab01`, el alumno debe crear un directorio llamado `test`.

Dentro de `test`, debe crear **tres subdirectorios** con los siguientes nombres y propósitos:

* `docs`: para archivos de documentación
* `bin`: para archivos ejecutables (aunque en esta práctica no se utilizará)
* `tmp`: para archivos temporales

---

### Paso 3 – Creación de un archivo de documentación

Dentro del directorio `docs`, el alumno debe crear un archivo de texto vacío llamado `readme.txt`.

Este archivo representará documentación inicial del proyecto.

---

### Paso 4 – Copia del archivo de documentación

El archivo `readme.txt` creado en el directorio `docs` debe copiarse al directorio `tmp`.

Es importante que, al finalizar este paso, **el archivo exista en ambos directorios** (`docs` y `tmp`), sin eliminar el original.

---

### Paso 5 – Búsqueda de archivos de texto

El alumno debe realizar una búsqueda dentro del directorio `unix-labs` para localizar **todos los archivos con extensión `.txt`**, sin importar en qué subdirectorio se encuentren.

Los resultados de esta búsqueda deben mostrarse en la salida estándar al ejecutar el script.

---

### Paso 6 – Análisis del uso de espacio del directorio de prácticas

El alumno debe obtener y mostrar el espacio total ocupado en disco por el directorio `unix-labs`, utilizando un formato legible para humanos.

---

### Paso 7 – Análisis del uso de espacio del sistema

El alumno debe mostrar información general sobre el uso de espacio en los sistemas de archivos del sistema operativo, incluyendo espacio total, usado y disponible.

---

## Consideraciones importantes

* Todas las acciones deben realizarse exclusivamente desde la línea de comandos.
* Todas las acciones deben estar contenidas dentro del archivo `lab01_files.sh`.
* No se deben ejecutar comandos manualmente fuera del script.
* El script debe poder ejecutarse múltiples veces sin provocar errores graves.
* Los nombres de directorios y archivos deben coincidir exactamente con los especificados.