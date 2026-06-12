# SISTEMA DE GESTIÓN DE TORNEOS AMATEUR

Este proyecto es un programa desarrollado en C++ que permite administrar la información de un torneo deportivo amateur de manera organizada. Su objetivo es facilitar el registro y control de equipos, jugadores, árbitros y partidos utilizando Programación Orientada a Objetos y relaciones UML.

El sistema busca resolver problemas comunes en torneos organizados manualmente, como:

- Jugadores duplicados.
- Mala organización de partidos.
- Pérdida de información.
- Conflictos en horarios.
- Errores al registrar resultados.
- Falta de control sobre las personas involucradas en el torneo.

## Este sistema permite

- Registrar equipos dentro del torneo.
- Registrar jugadores con información básica como ID, nombre, edad, posición y número.
- Asociar jugadores a un equipo específico.
- Registrar árbitros para los partidos.
- Registrar personas dentro de una liga utilizando polimorfismo.
- Mostrar personas registradas por tipo, como jugadores o árbitros.
- Crear partidos entre dos equipos.
- Asignar un árbitro a un partido.
- Registrar resultados de los encuentros.
- Consultar información de equipos, plantillas, personas y partidos.
- Evitar jugadores duplicados dentro de un mismo equipo.
- Evitar equipos duplicados dentro del torneo.
- Evitar resultados con goles negativos.
- Evitar partidos donde el equipo local y visitante sean el mismo.

## Funcionamiento actual del programa

Actualmente, el menú permite:

1. Cargar datos de prueba.
2. Registrar equipo.
3. Registrar jugador y asignarlo a equipo.
4. Registrar árbitro.
5. Mostrar equipos.
6. Mostrar plantilla de un equipo.
7. Mostrar personas registradas en la liga.
8. Crear partido y registrar resultado.
9. Mostrar partidos.
0. Salir.

## Clases del proyecto

### Persona

Es una clase abstracta que contiene la información general de una persona dentro del sistema, como ID, nombre, edad y tipo. Tiene el método abstracto `mostrarInfo()`, el cual es sobreescrito por las clases hijas.

### Jugador

La clase `Jugador` hereda de `Persona`. Representa a un jugador registrado en el sistema. Además de los atributos heredados, contiene posición y número.

### Arbitro

La clase `Arbitro` hereda de `Persona`. Representa a un árbitro registrado en la liga. Además de los atributos heredados, contiene los años de experiencia.

### Liga

La clase `Liga` se encarga de registrar a las personas involucradas en el sistema. Utiliza un arreglo de apuntadores a `Persona`, lo que permite guardar tanto jugadores como árbitros en el mismo arreglo. En esta clase se aplica el polimorfismo.

### Equipo

La clase `Equipo` representa a un equipo dentro del torneo. Contiene nombre, entrenador y una lista de jugadores. También permite agregar jugadores, eliminar jugadores y mostrar la plantilla completa o filtrada por posición.

### Partido

La clase `Partido` representa un encuentro entre dos equipos. Contiene fecha, hora, goles del equipo local, goles del equipo visitante, equipo local, equipo visitante, árbitro asignado y si el partido ya fue jugado.

### Torneo

La clase `Torneo` administra los equipos y partidos registrados. Contiene una lista de equipos y una lista de partidos. En esta versión, `Torneo` se enfoca en la organización de equipos y partidos, mientras que `Liga` se encarga de las personas.

## Relaciones UML utilizadas

El sistema utiliza relaciones UML para representar la interacción entre las clases:

- **Herencia:** `Jugador` y `Arbitro` heredan de la clase abstracta `Persona`.
- **Agregación:** `Liga` registra objetos de tipo `Persona`, `Equipo` contiene jugadores y `Torneo` registra equipos.
- **Asociación:** `Partido` utiliza dos equipos, uno como local y otro como visitante. También se asocia con un `Arbitro`.
- **Composición:** `Torneo` contiene partidos, ya que los partidos pertenecen directamente al torneo.

## Archivos del proyecto

### persona.h
Contiene las clases:
- `Persona`
- `Jugador`
- `Arbitro`

### torneo.h
Contiene las clases:
- `Liga`
- `Equipo`
- `Partido`
- `Torneo`

### main.cpp
Contiene el menú principal del programa y permite probar las funcionalidades del sistema.


## Validaciones del programa
El programa incluye algunas validaciones para evitar errores básicos:

- No permite registrar equipos repetidos.
- No permite registrar jugadores repetidos por ID.
- No permite registrar árbitros repetidos por ID.
- No permite agregar al mismo jugador dos veces al mismo equipo.
- No permite crear partidos si no hay al menos dos equipos registrados.
- No permite crear partidos si no hay árbitros registrados.
- No permite crear un partido donde el equipo local y visitante sean el mismo.
- No permite registrar resultados con goles negativos.
- No permite cargar los datos de prueba más de una vez.
  
## Cómo compilar y ejecutar desde consola

Para compilar el programa desde consola, primero asegúrate de tener los archivos main.cpp, persona.h y torneo.h en la misma carpeta.

COMO SE USA: Presiona: Win + R → escribe "cmd" → Enter

En la consola escribes: cd /d "C:(la carpeta donde están tus archivos)" y presionas Enter.

Ya en la carpeta del proyecto, escribe: g++ main.cpp -o torneo

Para ejecutar el programa en Windows escribe: torneo En Mac o Linux, después de compilarlo, se ejecuta con: ./torneo
