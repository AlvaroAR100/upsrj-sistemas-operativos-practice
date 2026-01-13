# LAB 04 – Configuración y diagnóstico básico de red

## Objetivo

El alumno debe demostrar que comprende los conceptos básicos de red desde el punto de vista del sistema operativo, identificando interfaces de red, direcciones IP, rutas y conectividad, y documentando estas acciones mediante un script de shell reproducible.

---

## Entregable

* Un archivo de script llamado:

```
lab04_network.sh
```

El script debe automatizar todas las acciones descritas en esta práctica y ejecutarse sin errores.

---

## Directorio de trabajo

El script debe ejecutarse desde el directorio base del curso:

```
~/unix-labs/
```

No se deben crear ni modificar archivos de configuración de red; esta práctica es **solo de observación y diagnóstico**.

---

## Instrucciones

### Paso 1 – Identificación de interfaces de red

El alumno debe obtener y mostrar información sobre todas las interfaces de red disponibles en el sistema, incluyendo interfaces activas e inactivas.

La salida debe permitir identificar el nombre de cada interfaz y su estado.

---

### Paso 2 – Identificación de direcciones IP

Para cada interfaz de red, el alumno debe mostrar la información relacionada con las direcciones IP asignadas, diferenciando entre direcciones IPv4 y, si existen, IPv6.

---

### Paso 3 – Visualización de la tabla de rutas

El alumno debe mostrar la tabla de enrutamiento del sistema, identificando la ruta por defecto y las rutas asociadas a las interfaces de red disponibles.

---

### Paso 4 – Prueba de conectividad de red

El alumno debe realizar una prueba de conectividad hacia un destino externo confiable en Internet, limitando la prueba a un número finito de intentos.

La salida de esta prueba debe permitir verificar si existe conectividad de red.

---

### Paso 5 – Visualización de puertos y conexiones activas

El alumno debe mostrar información sobre los puertos de red abiertos y las conexiones activas en el sistema, diferenciando entre protocolos de transporte cuando sea posible.

---

## Consideraciones importantes

* Esta práctica no debe modificar la configuración de red del sistema.
* Todas las acciones deben limitarse a la observación y diagnóstico.
* El script debe ejecutarse sin requerir privilegios administrativos, siempre que sea posible.
* Todas las acciones deben estar documentadas dentro de `lab04_network.sh`.

---

## Resultado esperado

Al ejecutar el script entregado:

* Se muestra información clara sobre las interfaces de red del sistema.
* Se visualizan las direcciones IP asignadas.
* Se muestra la tabla de rutas del sistema.
* Se confirma o descarta la conectividad de red.
* Se listan puertos y conexiones activas.