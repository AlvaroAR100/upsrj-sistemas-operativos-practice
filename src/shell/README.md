# Mini Shell en C – Ejecución Básica de Comandos

Este proyecto implementa un **shell mínimo** en lenguaje C, cuyo objetivo es ilustrar cómo los sistemas operativos **crean y gestionan procesos** para ejecutar comandos introducidos por el usuario.

El shell soporta **un solo comando simple por línea**, sin redirecciones ni tuberías, y sirve como introducción práctica a la programación de procesos en UNIX/Linux.

---

## Objetivo del proyecto

El propósito principal es que el alumno comprenda:

* Cómo un shell interactúa con el sistema operativo.
* Cómo se crean procesos usando `fork()`.
* Cómo se ejecutan programas usando `execvp()`.
* Cómo el proceso padre sincroniza con el hijo usando `wait()` / `waitpid()`.

Este ejercicio **no busca construir un shell completo**, sino entender el **modelo de procesos UNIX**.

---

## Funcionalidades soportadas

* Ejecución de un comando con argumentos.
* Búsqueda automática del ejecutable en el `PATH`.
* Espera bloqueante hasta que el comando termine.
* Comando especial `exit` para salir del shell.

---

## Funcionalidades no soportadas (por diseño)

* Pipes (`|`)
* Redirecciones (`>`, `<`)
* Ejecución en background (`&`)
* Variables de entorno
* Historial de comandos
* Autocompletado

Estas limitaciones permiten enfocarse exclusivamente en **procesos**, no en parsing complejo.

---

## Flujo de ejecución del shell

El funcionamiento del shell sigue siempre el mismo ciclo:

1. Mostrar el prompt
2. Leer una línea desde entrada estándar
3. Separar la línea en comando y argumentos
4. Crear un proceso hijo
5. Ejecutar el comando en el proceso hijo
6. Esperar a que el proceso hijo termine
7. Volver a mostrar el prompt

---

## Diagrama de flujo simplificado

```
Usuario escribe comando
        |
        v
     shell
        |
        +--> fork()
              |
              +--> Hijo: execvp()
              |
              +--> Padre: waitpid()
        |
        v
   Prompt nuevamente
```

---

## Componentes del proyecto

### `shell.c`

* Contiene el **loop principal** del shell.
* Lee la entrada del usuario.
* Divide la línea en tokens (comando y argumentos).
* Detecta el comando `exit`.
* Llama a `execute_command()`.

---

### `shell_exec.c`

* Contiene la lógica de **creación y ejecución de procesos**.
* Implementa:

  * `fork()`
  * `execvp()`
  * `waitpid()`
* Maneja errores básicos del sistema.

---

### `shell_exec.h`

* Define la interfaz entre el shell y la lógica de ejecución.
* Permite separar infraestructura de algoritmo.

---

## Uso del Makefile

El proyecto utiliza un **Makefile** con una estructura de compilación profesional:

```
build/
├── out/   ← archivos objeto (.o)
└── bin/   ← ejecutable final
```

### Compilación

Desde el directorio `shell/`:

```bash
make
```

Esto genera el ejecutable:

```bash
build/bin/shell
```

### Ejecución

```bash
./build/bin/shell
```

---

## Ejemplo de uso

```bash
MiniShell (type 'exit' to quit)
mini-shell> ls
mini-shell> pwd
mini-shell> echo Hello World
mini-shell> exit
```

---

## Relación con Sistemas Operativos

Este ejercicio está directamente relacionado con los temas de:

* Procesos
* Modelo padre–hijo
* Llamadas al sistema
* Espacio de usuario vs kernel
* Reemplazo de imagen de proceso

Es un puente natural entre teoría y práctica.

---

## Objetivo didáctico

Al finalizar este ejercicio, el alumno será capaz de:

* Explicar cómo un shell ejecuta comandos.
* Diferenciar entre `fork()` y `exec()`.
* Entender por qué un shell necesita esperar a sus procesos hijos.
* Reconocer la importancia del modelo de procesos en UNIX.