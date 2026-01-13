# LAB 02 – Gestión de repositorios y paquetes

## Objetivo

El alumno debe demostrar que comprende cómo Linux obtiene, instala, consulta y elimina software mediante su sistema de gestión de paquetes, utilizando repositorios oficiales y documentando todas sus acciones en un script reproducible.

---

## Entregable

* Un archivo de script llamado:

```
lab02_repos.sh
```

El script debe ejecutar todas las acciones descritas en esta práctica de forma automática y sin errores.

---

## Directorio de trabajo

El script debe ejecutarse desde el directorio base del curso:

```
~/unix-labs/
```

No se deben crear nuevos directorios para esta práctica; el foco está en la **gestión del sistema**, no en archivos locales.

---

## Instrucciones

### Paso 1 – Actualización de la información de los repositorios

El alumno debe actualizar la información local del sistema sobre los repositorios de software configurados, asegurándose de que el sistema tenga conocimiento de las versiones más recientes de los paquetes disponibles.

Este paso no debe instalar ni eliminar software, únicamente actualizar la información.

---

### Paso 2 – Instalación de un paquete de monitoreo del sistema

El alumno debe instalar un paquete que permita visualizar procesos y uso de recursos del sistema desde la terminal.

El paquete seleccionado debe cumplir las siguientes condiciones:

* Estar disponible en los repositorios oficiales de Ubuntu 22.04
* Ser una herramienta interactiva de monitoreo
* No requerir configuración adicional tras la instalación

---

### Paso 3 – Consulta de información del paquete instalado

Una vez instalado el paquete, el alumno debe consultar y mostrar información detallada sobre dicho paquete, incluyendo al menos:

* Descripción
* Versión
* Origen del repositorio

La información debe mostrarse en la salida estándar al ejecutar el script.

---

### Paso 4 – Verificación de la instalación

El alumno debe demostrar que el paquete instalado existe en el sistema y que fue correctamente registrado por el gestor de paquetes.

Este paso debe realizarse mediante una consulta al sistema de paquetes, no ejecutando directamente el programa.

---

### Paso 5 – Eliminación del paquete instalado

El alumno debe eliminar completamente el paquete instalado en el paso 2, asegurándose de que ya no forme parte del sistema.

No es necesario eliminar archivos de configuración residuales, solo el paquete principal.

---

### Paso 6 – Limpieza opcional del sistema de paquetes

Como paso final, el alumno debe realizar una limpieza del sistema de paquetes, eliminando dependencias que ya no sean necesarias como consecuencia de la desinstalación.

Este paso es opcional, pero recomendado.

---

## Consideraciones importantes

* Todas las acciones deben realizarse mediante el gestor de paquetes del sistema.
* El script puede requerir privilegios administrativos; el alumno debe ser consciente de cuándo y por qué se requieren.
* No se deben instalar paquetes fuera de los repositorios oficiales.
* Todas las acciones deben estar documentadas y automatizadas dentro de `lab02_repos.sh`.
* El script debe poder ejecutarse nuevamente sin provocar fallos críticos.

---

## Resultado esperado

Al ejecutar el script entregado:

* El sistema actualiza correctamente la información de repositorios.
* El paquete es instalado, consultado y eliminado sin errores.
* La salida del script muestra información clara sobre el paquete.
* El sistema queda en un estado consistente tras la ejecución.