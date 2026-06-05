# SISTEMA DE GESTIÓN DE TORNEOS AMATEUR

Este proyecto es un programa desarrollado en C++ que permite administrar la información de un torneo deportivo amateur de manera organizada. Su objetivo es facilitar el registro y control de equipos, jugadores, árbitros y partidos utilizando Programación Orientada a Objetos y relaciones UML.

El sistema busca resolver problemas comunes en torneos organizados manualmente, como:

- Jugadores duplicados.
- Mala organización de partidos.
- Pérdida de información.
- Conflictos en horarios.
- Errores al registrar resultados.

## Este sistema permite

- Registrar equipos dentro del torneo.
- Registrar jugadores con información básica como ID, nombre, edad, posición y número.
- Asociar jugadores a un equipo específico.
- Registrar árbitros para los partidos.
- Crear partidos entre dos equipos.
- Registrar resultados de los encuentros.
- Consultar información de equipos y partidos.
- Organizar la información del torneo de manera más clara y estructurada.
- Evitar jugadores duplicados dentro de un mismo equipo.
- Evitar equipos duplicados dentro del torneo.
- Evitar resultados con goles negativos.
- Evitar partidos donde el equipo local y visitante sean el mismo.
- Registrar personas involucradas en el torneo utilizando polimorfismo.
- Mostrar personas registradas por tipo, como jugadores o árbitros.

## Funcionamiento actual del programa
Actualmente, el menú permite:

1. Cargar datos de prueba.
2. Registrar equipo.
3. Registrar jugador y asignarlo a equipo.
4. Registrar árbitro.
5. Mostrar equipos.
6. Mostrar plantilla de un equipo.
7. Mostrar personas registradas.
8. Crear partido y registrar resultado.
9. Mostrar partidos.
0. Salir.


## Relaciones UML utilizadas

El sistema utiliza relaciones UML para representar correctamente la interacción entre las clases:

- **Herencia:** Las clases `Jugador` y `Arbitro` heredan de la clase abstracta `Persona` para reutilizar atributos comunes como ID, nombre y edad.

- **Agregación:** Un `Equipo` contiene múltiples `Jugadores`, pero los jugadores pueden existir como registros independientes.

- **Asociación:** Un `Partido` utiliza `Equipos` y un `Arbitro` para poder realizarse. También se utiliza una asociación entre `Torneo` y `Persona`, ya que el torneo puede registrar personas involucradas mediante apuntadores a la clase base.

- **Composición:** Un `Torneo` contiene `Partidos`, ya que los partidos pertenecen directamente al torneo.


## Avance 4

En este avance se revisó que la clase abstracta `Persona` estuviera declarada correctamente mediante el método virtual puro `mostrarInfo()`.

También se agregó un destructor virtual en la clase base para mantener una estructura más correcta al trabajar con apuntadores a `Persona`.

Además, se implementó sobrecarga del operador `==` en clases como `Jugador` y `Equipo`. Esta sobrecarga permite comparar objetos de manera más clara, por ejemplo, para identificar jugadores repetidos por ID o equipos repetidos por nombre.

También se mejoró el archivo `main.cpp` para que el sistema funcione mediante un menú básico en consola, en lugar de ejecutar únicamente pruebas fijas.

## Clases principales

El proyecto trabaja con las siguientes clases:

- `Persona`: clase abstracta que contiene datos generales.
- `Jugador`: representa a los jugadores registrados en el torneo.
- `Arbitro`: representa al árbitro asignado a los partidos.
- `Equipo`: administra la información del equipo y sus jugadores.
- `Partido`: representa un encuentro entre dos equipos.
- `Torneo`: administra los equipos, partidos y personas involucradas en el torneo.

## Archivos del proyecto

- `persona.h`: contiene las clases `Persona`, `Jugador` y `Arbitro`.
- `torneo.h`: contiene las clases `Equipo`, `Partido` y `Torneo`.
- `main.cpp`: contiene el menú principal y las pruebas funcionales del sistema.

## Casos que podrían afectar el funcionamiento del sistema

Durante el análisis del problema se identificaron algunos casos que podrían afectar el funcionamiento correcto del sistema, por ejemplo:

- Registrar un jugador repetido en el mismo equipo.
- Programar un partido donde el mismo equipo sea local y visitante.
- Registrar goles negativos.
- Crear partidos sin árbitro.
- Registrar equipos vacíos.
- Programar partidos con horarios repetidos.
- Intentar eliminar jugadores inexistentes.

## Cómo compilar y ejecutar desde consola

Para compilar el programa desde consola, primero asegúrate de tener los archivos main.cpp, persona.h y torneo.h en la misma carpeta.

COMO SE USA: Presiona: Win + R → escribe "cmd" → Enter

En la consola escribes: cd /d "C:(la carpeta donde están tus archivos)" y presionas Enter.

Ya en la carpeta del proyecto, escribe: g++ main.cpp -o torneo

Para ejecutar el programa en Windows escribe: torneo En Mac o Linux, después de compilarlo, se ejecuta con: ./torneo
