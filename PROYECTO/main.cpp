/*
 * Este archivo contiene un menu sencillo para probar el uso del sistema.
 */

#include <iostream>
#include <string>

#include "persona.h"
#include "torneo.h"

using namespace std;

const int MAX_EQUIPOS_MAIN = 20;
const int MAX_JUGADORES_MAIN = 100;
const int MAX_ARBITROS_MAIN = 30;

void limpiarBuffer() {
    cin.clear();
    cin.ignore(10000, '\n');
}

int buscarJugadorPorId(Jugador jugadores[], int totalJugadores, int id) {
    for (int i = 0; i < totalJugadores; i++) {
        if (jugadores[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

int buscarArbitroPorId(Arbitro arbitros[], int totalArbitros, int id) {
    for (int i = 0; i < totalArbitros; i++) {
        if (arbitros[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

void mostrarListaEquipos(Equipo equipos[], int totalEquipos) {
    if (totalEquipos == 0) {
        cout << "No hay equipos registrados." << endl;
    } else {
        for (int i = 0; i < totalEquipos; i++) {
            cout << i + 1 << ". " << equipos[i].getNombre()
                 << " | Entrenador: " << equipos[i].getEntrenador() << endl;
        }
    }
}

void cargarDatosPrueba(Torneo &torneo, Equipo equipos[], int &totalEquipos,
                       Jugador jugadores[], int &totalJugadores,
                       Arbitro arbitros[], int &totalArbitros) {

    equipos[totalEquipos] = Equipo("Leonas FC", "Carlos Ramirez");
    torneo.registrarEquipo(equipos[totalEquipos]);
    totalEquipos++;

    equipos[totalEquipos] = Equipo("Halcones Norte", "Mariana Torres");
    torneo.registrarEquipo(equipos[totalEquipos]);
    totalEquipos++;

    jugadores[totalJugadores] = Jugador(1, "Ana Lopez", 19, "Portera", 1);
    equipos[0].agregarJugador(jugadores[totalJugadores]);
    torneo.registrarPersona(&jugadores[totalJugadores]);
    totalJugadores++;

    jugadores[totalJugadores] = Jugador(2, "Sofia Martinez", 20, "Defensa", 4);
    equipos[0].agregarJugador(jugadores[totalJugadores]);
    torneo.registrarPersona(&jugadores[totalJugadores]);
    totalJugadores++;

    jugadores[totalJugadores] = Jugador(3, "Regina Perez", 18, "Delantera", 9);
    equipos[0].agregarJugador(jugadores[totalJugadores]);
    torneo.registrarPersona(&jugadores[totalJugadores]);
    totalJugadores++;

    arbitros[totalArbitros] = Arbitro(1, "Jorge Sanchez", 35, 8);
    torneo.registrarPersona(&arbitros[totalArbitros]);
    totalArbitros++;

    arbitros[totalArbitros] = Arbitro(2, "Laura Fernandez", 30, 5);
    torneo.registrarPersona(&arbitros[totalArbitros]);
    totalArbitros++;

    cout << "Datos de prueba cargados correctamente." << endl;
}

int main() {

    Torneo torneo("Copa Amateur Queretaro");

    Equipo equipos[MAX_EQUIPOS_MAIN];
    Jugador jugadores[MAX_JUGADORES_MAIN];
    Arbitro arbitros[MAX_ARBITROS_MAIN];

    int totalEquipos = 0;
    int totalJugadores = 0;
    int totalArbitros = 0;

    int opcion;
    bool datosCargados = false;

    do {
        cout << "\n=====================================" << endl;
        cout << " SISTEMA DE GESTION DE TORNEOS AMATEUR" << endl;
        cout << "=====================================" << endl;
        cout << "1. Cargar datos de prueba" << endl;
        cout << "2. Registrar equipo" << endl;
        cout << "3. Registrar jugador y asignarlo a equipo" << endl;
        cout << "4. Registrar arbitro" << endl;
        cout << "5. Mostrar equipos" << endl;
        cout << "6. Mostrar plantilla de un equipo" << endl;
        cout << "7. Mostrar personas registradas" << endl;
        cout << "8. Crear partido y registrar resultado" << endl;
        cout << "9. Mostrar partidos" << endl;
        cout << "0. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;
        limpiarBuffer();

        if (opcion == 1) {
            if (!datosCargados) {
                cargarDatosPrueba(torneo, equipos, totalEquipos,
                                  jugadores, totalJugadores,
                                  arbitros, totalArbitros);
                datosCargados = true;
            } else {
                cout << "Los datos de prueba ya fueron cargados." << endl;
            }
        }

        else if (opcion == 2) {
            if (totalEquipos >= MAX_EQUIPOS_MAIN) {
                cout << "No se pueden registrar mas equipos." << endl;
            } else {
                string nombre, entrenador;

                cout << "Nombre del equipo: ";
                getline(cin, nombre);

                cout << "Nombre del entrenador: ";
                getline(cin, entrenador);

                if (torneo.existeEquipo(nombre)) {
                    cout << "No se pudo registrar. Ese equipo ya existe." << endl;
                } else {
                    equipos[totalEquipos] = Equipo(nombre, entrenador);
                    torneo.registrarEquipo(equipos[totalEquipos]);
                    totalEquipos++;
                }
            }
        }

        else if (opcion == 3) {
            if (totalEquipos == 0) {
                cout << "Primero debes registrar al menos un equipo." << endl;
            } else if (totalJugadores >= MAX_JUGADORES_MAIN) {
                cout << "No se pueden registrar mas jugadores." << endl;
            } else {
                int id, edad, numero, equipoElegido;
                string nombre, posicion;

                cout << "ID del jugador: ";
                cin >> id;
                limpiarBuffer();

                if (buscarJugadorPorId(jugadores, totalJugadores, id) != -1) {
                    cout << "No se pudo registrar. Ya existe un jugador con ese ID." << endl;
                } else {
                    cout << "Nombre del jugador: ";
                    getline(cin, nombre);

                    cout << "Edad: ";
                    cin >> edad;
                    limpiarBuffer();

                    cout << "Posicion: ";
                    getline(cin, posicion);

                    cout << "Numero: ";
                    cin >> numero;
                    limpiarBuffer();

                    cout << "\nSelecciona el equipo:" << endl;
                    mostrarListaEquipos(equipos, totalEquipos);
                    cout << "Opcion: ";
                    cin >> equipoElegido;
                    limpiarBuffer();

                    if (equipoElegido < 1 || equipoElegido > totalEquipos) {
                        cout << "Equipo invalido." << endl;
                    } else {
                        jugadores[totalJugadores] = Jugador(id, nombre, edad, posicion, numero);

                        equipos[equipoElegido - 1].agregarJugador(jugadores[totalJugadores]);
                        torneo.registrarPersona(&jugadores[totalJugadores]);

                        totalJugadores++;
                    }
                }
            }
        }

        else if (opcion == 4) {
            if (totalArbitros >= MAX_ARBITROS_MAIN) {
                cout << "No se pueden registrar mas arbitros." << endl;
            } else {
                int id, edad, experiencia;
                string nombre;

                cout << "ID del arbitro: ";
                cin >> id;
                limpiarBuffer();

                if (buscarArbitroPorId(arbitros, totalArbitros, id) != -1) {
                    cout << "No se pudo registrar. Ya existe un arbitro con ese ID." << endl;
                } else {
                    cout << "Nombre del arbitro: ";
                    getline(cin, nombre);

                    cout << "Edad: ";
                    cin >> edad;
                    limpiarBuffer();

                    cout << "Anios de experiencia: ";
                    cin >> experiencia;
                    limpiarBuffer();

                    arbitros[totalArbitros] = Arbitro(id, nombre, edad, experiencia);
                    torneo.registrarPersona(&arbitros[totalArbitros]);

                    totalArbitros++;
                }
            }
        }

        else if (opcion == 5) {
            torneo.mostrarEquipos();
        }

        else if (opcion == 6) {
            if (totalEquipos == 0) {
                cout << "No hay equipos registrados." << endl;
            } else {
                int equipoElegido;

                cout << "\nSelecciona el equipo:" << endl;
                mostrarListaEquipos(equipos, totalEquipos);
                cout << "Opcion: ";
                cin >> equipoElegido;
                limpiarBuffer();

                if (equipoElegido < 1 || equipoElegido > totalEquipos) {
                    cout << "Equipo invalido." << endl;
                } else {
                    equipos[equipoElegido - 1].mostrarPlantilla();
                }
            }
        }

        else if (opcion == 7) {
            int filtro;

            cout << "\n1. Mostrar todas las personas" << endl;
            cout << "2. Mostrar solo jugadores" << endl;
            cout << "3. Mostrar solo arbitros" << endl;
            cout << "Opcion: ";
            cin >> filtro;
            limpiarBuffer();

            if (filtro == 1) {
                torneo.mostrarPersonas();
            } else if (filtro == 2) {
                torneo.mostrarPersonas("jugador");
            } else if (filtro == 3) {
                torneo.mostrarPersonas("arbitro");
            } else {
                cout << "Opcion invalida." << endl;
            }
        }

        else if (opcion == 8) {
            if (totalEquipos < 2) {
                cout << "Se necesitan al menos dos equipos para crear un partido." << endl;
            } else if (totalArbitros == 0) {
                cout << "Se necesita al menos un arbitro para crear un partido." << endl;
            } else {
                int local, visitante, arb;
                int golesLocal, golesVisitante;

                cout << "\nSelecciona equipo local:" << endl;
                mostrarListaEquipos(equipos, totalEquipos);
                cout << "Opcion: ";
                cin >> local;
                limpiarBuffer();

                cout << "\nSelecciona equipo visitante:" << endl;
                mostrarListaEquipos(equipos, totalEquipos);
                cout << "Opcion: ";
                cin >> visitante;
                limpiarBuffer();

                cout << "\nSelecciona arbitro:" << endl;
                for (int i = 0; i < totalArbitros; i++) {
                    cout << i + 1 << ". ";
                    arbitros[i].mostrarInfo();
                }
                cout << "Opcion: ";
                cin >> arb;
                limpiarBuffer();

                if (local < 1 || local > totalEquipos ||
                    visitante < 1 || visitante > totalEquipos ||
                    arb < 1 || arb > totalArbitros) {
                    cout << "Seleccion invalida." << endl;
                } else {
                    string fecha, hora;

                    cout << "Fecha del partido: ";
                    getline(cin, fecha);

                    cout << "Hora del partido: ";
                    getline(cin, hora);

                    Partido partido(fecha, hora,
                                    equipos[local - 1],
                                    equipos[visitante - 1],
                                    arbitros[arb - 1]);

                    cout << "Goles del equipo local: ";
                    cin >> golesLocal;
                    limpiarBuffer();

                    cout << "Goles del equipo visitante: ";
                    cin >> golesVisitante;
                    limpiarBuffer();

                    partido.registrarResultado(golesLocal, golesVisitante);
                    torneo.registrarPartido(partido);
                }
            }
        }

        else if (opcion == 9) {
            torneo.mostrarPartidos();
        }

        else if (opcion == 0) {
            cout << "Saliendo del sistema..." << endl;
        }

        else {
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);

    return 0;
}