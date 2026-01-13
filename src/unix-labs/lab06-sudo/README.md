# LAB 06 – Sudo y privilegios

## Objetivo

El alumno debe comprender el principio de **mínimo privilegio** en sistemas Linux, aprendiendo a verificar y utilizar privilegios elevados de manera controlada mediante `sudo`, así como revisar la configuración de permisos en `/etc/sudoers`.

---

## Entregable

* Un archivo de script llamado:

```
lab06_sudo.sh
```

El script debe automatizar todas las acciones descritas en esta práctica y ejecutarse sin errores.

---

## Directorio de trabajo

El script debe ejecutarse desde el directorio base del curso:

```
~/unix-labs/
```

No se deben modificar usuarios críticos del sistema ni la configuración de sudoers fuera de un entorno controlado. Esta práctica es **solo de observación y análisis**.

---

## Instrucciones

### Paso 1 – Ver grupos del usuario

El alumno debe mostrar los grupos a los que pertenece el usuario actual, para entender sus permisos y posibles privilegios asociados.

---

### Paso 2 – Verificación de privilegios sudo

El alumno debe comprobar qué comandos puede ejecutar con `sudo` sin necesidad de conocer la contraseña, usando:

```bash
sudo -l
```

La salida debe permitir identificar los permisos otorgados.

---

### Paso 3 – Análisis de `/etc/sudoers`

El alumno debe revisar el archivo `/etc/sudoers` (sin modificarlo) para entender la configuración de privilegios y el alcance de los comandos que cada usuario puede ejecutar.

---

## Consideraciones importantes

* Esta práctica no debe modificar la configuración de `sudoers` ni otorgar privilegios administrativos adicionales.
* Todas las acciones deben centrarse en **observación y análisis** de privilegios.
* Se recomienda utilizar `sudo` solo cuando sea estrictamente necesario.
* Todas las acciones deben estar documentadas dentro de `lab06_sudo.sh`.

---

## Resultado esperado

Al ejecutar el script entregado:

* Se visualizan los grupos a los que pertenece el usuario.
* Se listan los comandos permitidos con `sudo`.
* Se comprende la configuración de privilegios del sistema sin modificarla.