# LAB 05 – Gestión de usuarios y grupos

## Objetivo

El alumno debe demostrar comprensión de los conceptos básicos de control de acceso multiusuario en Linux, incluyendo la creación y administración de usuarios y grupos, asignación de grupos a usuarios y verificación de identificadores de usuario y grupo mediante comandos de shell.

---

## Entregable

* Un archivo de script llamado:

```
lab05_users.sh
```

El script debe automatizar todas las acciones descritas en esta práctica y ejecutarse sin errores.

---

## Directorio de trabajo

El script debe ejecutarse desde el directorio base del curso:

```
~/unix-labs/
```

No se deben modificar configuraciones críticas del sistema; esta práctica se centra únicamente en **la creación y manejo de usuarios y grupos de forma local y segura**.

---

## Instrucciones

### Paso 1 – Creación de un grupo

El alumno debe crear un grupo nuevo con un nombre representativo, por ejemplo `devgroup`. La salida debe confirmar que el grupo ha sido creado correctamente.

---

### Paso 2 – Creación de un usuario

El alumno debe crear un usuario nuevo con directorio home asignado, por ejemplo `alumno1`. La salida debe confirmar la creación del usuario.

---

### Paso 3 – Asignación de usuario a grupo

El alumno debe agregar el usuario creado al grupo previamente creado, verificando que la asignación se realizó correctamente.

---

### Paso 4 – Verificación de identificadores

El alumno debe mostrar la información de usuario y grupo del usuario creado, incluyendo UID, GID y grupos secundarios a los que pertenece. Esto permite verificar que la configuración es correcta.

---

### Paso 5 – Comprobación de usuario activo

El alumno debe verificar su usuario actual y confirmar su identidad en el sistema mediante comandos de observación como `whoami`.

---

## Consideraciones importantes

* Esta práctica no debe modificar usuarios críticos del sistema ni comprometer la seguridad.
* Todas las acciones deben limitarse a la **creación y verificación de usuarios y grupos locales**.
* Es recomendable ejecutar el script con privilegios administrativos (`sudo`) solo cuando sea necesario.
* Todas las acciones deben estar documentadas dentro de `lab05_users.sh`.

---

## Resultado esperado

Al ejecutar el script entregado:

* Se crea un grupo nuevo y se confirma su existencia.
* Se crea un usuario nuevo con directorio home asignado.
* El usuario se agrega correctamente al grupo.
* Se muestran los identificadores de usuario y grupo de forma clara.
* Se verifica la identidad del usuario actual en el sistema.