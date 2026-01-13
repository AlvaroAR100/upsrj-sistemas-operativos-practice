# LAB 08 – Políticas de seguridad

## Objetivo

El alumno debe comprender conceptos básicos de **hardening** y gestión de seguridad en Linux, incluyendo control de permisos, propiedad de archivos, visualización de procesos activos y configuración de un firewall local.

---

## Entregable

* Un archivo de script llamado:

```
lab08_security.sh
```

El script debe automatizar todas las acciones descritas en esta práctica y ejecutarse sin errores.

---

## Directorio de trabajo

El script debe ejecutarse desde el directorio base del curso:

```
~/unix-labs/
```

Todas las acciones deben centrarse en **observación, análisis y configuración segura**, sin comprometer la funcionalidad crítica del sistema.

---

## Instrucciones

### Paso 1 – Cambiar permisos de archivos y directorios

El alumno debe ajustar los permisos de su directorio de trabajo `~/unix-labs` para restringir el acceso a otros usuarios, utilizando `chmod` y `chown` según corresponda.

---

### Paso 2 – Visualización de procesos

El alumno debe listar los procesos activos del sistema utilizando comandos como `ps` y `top`, comprendiendo qué servicios están en ejecución y quién los ejecuta.

---

### Paso 3 – Configuración del firewall

El alumno debe verificar el estado del firewall local (`ufw`) y entender cómo las políticas de filtrado de tráfico contribuyen a la seguridad del sistema. No se deben aplicar cambios destructivos.

---

## Consideraciones importantes

* Esta práctica no debe deshabilitar procesos críticos ni bloquear el acceso legítimo al sistema.
* Se recomienda aplicar privilegios administrativos únicamente cuando sea necesario (por ejemplo, al consultar el estado del firewall).
* Todas las acciones deben estar documentadas dentro de `lab08_security.sh`.
* Se deben seguir buenas prácticas de **seguridad mínima** y **principio de menor privilegio**.

---

## Resultado esperado

Al ejecutar el script entregado:

* Se aplican permisos seguros al directorio de trabajo.
* Se muestran los procesos activos del sistema de forma clara.
* Se visualiza el estado del firewall local, confirmando la configuración de políticas de seguridad básicas.