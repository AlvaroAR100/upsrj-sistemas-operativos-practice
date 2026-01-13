# LAB 07 – Respaldo de configuraciones

## Objetivo

El alumno debe demostrar prácticas de **administración responsable del sistema**, aprendiendo a realizar respaldos de configuraciones críticas de Linux de manera segura, utilizando herramientas como `cp`, `rsync` y `tar`.

---

## Entregable

* Un archivo de script llamado:

```
lab07_backup.sh
```

El script debe automatizar todas las acciones descritas en esta práctica y ejecutarse sin errores.

---

## Directorio de trabajo

El script debe ejecutarse desde el directorio base del curso:

```
~/unix-labs/
```

No se deben modificar archivos de configuración originales; los respaldos deben realizarse de manera **no destructiva**.

---

## Instrucciones

### Paso 1 – Respaldo del directorio `/etc`

El alumno debe crear un respaldo comprimido de todo el directorio `/etc`, asegurando que la estructura y permisos se conserven. Este respaldo permitirá restaurar configuraciones en caso de necesidad.

---

### Paso 2 – Respaldo de la configuración de red

El alumno debe realizar un respaldo de los archivos de configuración de red específicos del sistema (por ejemplo `/etc/network/` o `/etc/netplan/` dependiendo de la distribución), garantizando que puedan recuperarse en caso de cambios no deseados.

---

### Paso 3 – Uso de herramientas de respaldo

El alumno debe demostrar comprensión del uso de:

* `cp` para copias simples.
* `rsync` para sincronización incremental.
* `tar` para creación de archivos comprimidos y preservación de permisos.

---

## Consideraciones importantes

* Esta práctica no debe alterar la configuración activa del sistema.
* Los respaldos deben almacenarse en un directorio seguro dentro de `~/unix-labs/`.
* Se recomienda usar privilegios administrativos solo cuando sea estrictamente necesario.
* Todas las acciones deben estar documentadas dentro de `lab07_backup.sh`.

---

## Resultado esperado

Al ejecutar el script entregado:

* Se crea un archivo de respaldo comprimido del directorio `/etc`.
* Se realiza un respaldo seguro de la configuración de red.
* Se confirma la integridad de los archivos respaldados y se mantiene la estructura original del sistema.