# LAB 03 – Empaquetamiento y compresión

## Objetivo

El alumno debe demostrar que comprende cómo agrupar, comprimir y restaurar información en sistemas Linux, utilizando herramientas de empaquetamiento y compresión, y dejando evidencia reproducible de su trabajo mediante un script de shell.

---

## Entregable

* Un archivo de script llamado:

```
lab03_archive.sh
```

Este script debe automatizar todas las acciones descritas en esta práctica y ejecutarse sin errores.

---

## Directorio de trabajo

El script debe ejecutarse desde el directorio base del curso:

```
~/unix-labs/
```

La información a empaquetar corresponderá a resultados generados en prácticas anteriores.

---

## Instrucciones

### Paso 1 – Selección del directorio a respaldar

El alumno debe identificar y utilizar el directorio completo correspondiente a la práctica anterior de gestión de archivos (`lab01`) como fuente del respaldo.

Este directorio debe incluir toda su estructura y contenido.

---

### Paso 2 – Creación de un archivo de respaldo comprimido

A partir del directorio seleccionado, el alumno debe generar un único archivo de respaldo comprimido con las siguientes características:

* Debe contener toda la estructura del directorio original.
* Debe utilizar un formato de compresión común en sistemas Linux.
* El archivo resultante debe llamarse:

```
backup_lab01.tar.gz
```

El archivo debe generarse dentro del directorio `unix-labs`.

---

### Paso 3 – Verificación de la existencia del respaldo

El alumno debe verificar que el archivo de respaldo fue creado correctamente y que se encuentra disponible en el directorio esperado.

Esta verificación debe mostrarse en la salida del script.

---

### Paso 4 – Restauración del respaldo en un nuevo directorio

El alumno debe crear un nuevo directorio llamado:

```
restore_lab01
```

Dentro de este directorio, debe restaurar el contenido del archivo de respaldo creado previamente, preservando la estructura original de archivos y directorios.

---

### Paso 5 – Verificación de la restauración

El alumno debe comprobar que los archivos restaurados existen y que la estructura del directorio restaurado coincide con la del directorio original respaldado.

El resultado de esta verificación debe mostrarse en la salida del script.

---

## Consideraciones importantes

* No se deben modificar los archivos originales durante el proceso.
* El archivo de respaldo debe ser único (no múltiples archivos).
* La restauración debe realizarse en un directorio distinto al original.
* Todas las acciones deben estar contenidas en `lab03_archive.sh`.
* El script debe poder ejecutarse más de una vez sin causar errores graves.

---

## Resultado esperado

Al ejecutar el script entregado:

* Existe un archivo llamado `backup_lab01.tar.gz` en `./unix-labs/`.
* El directorio `restore_lab01` contiene una copia funcional del contenido original de `lab01`.
* La salida del script permite verificar visualmente la existencia del respaldo y su restauración.