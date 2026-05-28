/*
 * Este archivo prueba el funcionamiento de las clases del proyecto.
 */

#include <iostream>

#include "persona.h"
#include "torneo.h"

using namespace std;

int main() {

    cout << "SISTEMA DE GESTION DE TORNEOS AMATEUR" << endl;

    Torneo torneo("Copa Amateur Queretaro");

    Equipo equipo1("Leonas FC", "Carlos Ramirez");
    Equipo equipo2("Halcones Norte", "Mariana Torres");

    Jugador jugadora1(1, "Ana Lopez", 19, "Portera", 1);
    Jugador jugadora2(2, "Sofia Martinez", 20, "Defensa", 4);
    Jugador jugadora3(3, "Regina Perez", 18, "Delantera", 9);

    Arbitro arbitro1(1, "Jorge Sanchez", 35, 8);
    Arbitro arbitro2(2, "Laura Fernandez", 30, 5);

    cout << "\n--- Prueba de sobreescritura de mostrarInfo() ---" << endl;
    jugadora1.mostrarInfo();
    arbitro1.mostrarInfo();

    cout << "\n--- Registro de jugadores ---" << endl;
    equipo1.agregarJugador(jugadora1);
    equipo1.agregarJugador(jugadora2);
    equipo1.agregarJugador(jugadora3);

    cout << "\n--- Intento de registrar jugador duplicado ---" << endl;
    equipo1.agregarJugador(jugadora1);

    cout << "\n--- Prueba de sobrecarga en mostrarPlantilla() ---" << endl;
    equipo1.mostrarPlantilla();
    equipo1.mostrarPlantilla("Portera");

    cout << "\n--- Registro de equipos en torneo ---" << endl;
    torneo.registrarEquipo(equipo1);
    torneo.registrarEquipo(equipo2);

    cout << "\n--- Intento de registrar equipo duplicado ---" << endl;
    torneo.registrarEquipo(equipo1);

    cout << "\n--- Prueba de sobrecarga en mostrarEquipos() ---" << endl;
    torneo.mostrarEquipos();
    torneo.mostrarEquipos("Leonas FC");

    cout << "\n--- Registro de personas en torneo para polimorfismo ---" << endl;
    torneo.registrarPersona(&jugadora1);
    torneo.registrarPersona(&jugadora2);
    torneo.registrarPersona(&jugadora3);
    torneo.registrarPersona(&arbitro1);
    torneo.registrarPersona(&arbitro2);

    cout << "\n--- Prueba de polimorfismo: mostrar todas las personas ---" << endl;
    torneo.mostrarPersonas();

    cout << "\n--- Prueba de polimorfismo y sobrecarga: mostrar solo jugadores ---" << endl;
    torneo.mostrarPersonas("jugador");

    cout << "\n--- Prueba de polimorfismo y sobrecarga: mostrar solo arbitros ---" << endl;
    torneo.mostrarPersonas("arbitro");

    cout << "\n--- Registro de partidos ---" << endl;
    Partido partido1("20/05/2026", "18:00", equipo1, equipo2, arbitro1);
    partido1.registrarResultado(2, 1);

    Partido partido2("22/05/2026", "20:00", equipo2, equipo1, arbitro2);
    partido2.registrarResultado();

    torneo.registrarPartido(partido1);
    torneo.registrarPartido(partido2);

    cout << "\n--- Intento de registrar partido invalido ---" << endl;
    Partido partidoInvalido("25/05/2026", "19:00", equipo1, equipo1, arbitro1);
    torneo.registrarPartido(partidoInvalido);

    cout << "\n--- Partidos del torneo ---" << endl;
    torneo.mostrarPartidos();

    return 0;
}
