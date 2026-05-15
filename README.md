# SISTEMA DE GESTIÓN DE TORNEOS AMATEUR

Este proyecto es un programa desarrollado en C++ que permite administrar la información de un torneo deportivo amateur de manera organizada. Su objetivo es facilitar el registro y control de equipos, jugadores, árbitros y partidos utilizando Programación Orientada a Objetos y relaciones UML.

El sistema busca resolver problemas comunes en torneos organizados manualmente, como:

jugadores duplicados,
mala organización de partidos,
pérdida de información,
conflictos en horarios,
errores al registrar resultados.

Este sistema permite:

-Registrar equipos dentro del torneo.
-Registrar jugadores con información básica como ID, nombre, edad, posición y número.
-Asociar jugadores a un equipo específico.
-Registrar árbitros para los partidos.
-Crear partidos entre dos equipos.
-Registrar resultados de los encuentros.
-Consultar información de equipos y partidos.
-Organizar la información del torneo de manera más clara y estructurada.

El sistema utiliza relaciones UML para representar correctamente la interacción entre las clases:

Herencia: Las clases Jugador y Arbitro heredan de la clase abstracta Persona para reutilizar atributos comunes.
Agregación: Un Equipo contiene múltiples Jugadores, pero los jugadores pueden existir independientemente.
Asociación: Un Partido utiliza Equipos y un Árbitro para poder realizarse.
Composición: Un Torneo contiene Partidos, ya que los partidos pertenecen directamente al torneo.

Durante el análisis del problema se identificaron algunos casos que podrían afectar el funcionamiento correcto del sistema, por ejemplo:

-Registrar un jugador repetido en el mismo equipo.
-Programar un partido donde el mismo equipo sea local y visitante.
-Registrar goles negativos.
-Crear partidos sin árbitro.
-Registrar equipos vacíos.
-Programar partidos con horarios repetidos.
-Intentar eliminar jugadores inexistentes.

Este sistema no fue creado para:

Guardar información después de cerrar el programa.
Manejar múltiples torneos al mismo tiempo.
Generar estadísticas avanzadas automáticamente.
Utilizar bases de datos o conexión a internet.
Contar con interfaz gráfica.
Administrar cuentas o usuarios.

El proyecto fue diseñado como una base escalable que podrá ampliarse en futuras versiones agregando nuevas funcionalidades y validaciones.
