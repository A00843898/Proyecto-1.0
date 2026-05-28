/*
 * Este archivo contiene las clases Equipo, Partido y Torneo.
 * En la clase Torneo se aplica polimorfismo usando apuntadores a Persona.
 */

#ifndef TORNEO_H_
#define TORNEO_H_

#include <iostream>
#include <string>
#include <vector>

#include "persona.h"

using namespace std;

const int MAX_PERSONAS = 100;

// Clase Equipo
class Equipo {

private:
    string nombre;
    string entrenador;
    vector<Jugador> listaJugadores;

public:
    Equipo() {
        nombre = "";
        entrenador = "";
    }

    Equipo(string nom, string ent) {
        nombre = nom;
        entrenador = ent;
    }

    string getNombre() {
        return nombre;
    }

    string getEntrenador() {
        return entrenador;
    }

    void setNombre(string nom) {
        nombre = nom;
    }

    void setEntrenador(string ent) {
        entrenador = ent;
    }

    bool existeJugador(int idJugador) {
        for (int i = 0; i < listaJugadores.size(); i++) {
            if (listaJugadores[i].getId() == idJugador) {
                return true;
            }
        }
        return false;
    }

    void agregarJugador(Jugador jugador) {
        if (existeJugador(jugador.getId())) {
            cout << "No se pudo agregar al jugador. El ID ya existe en el equipo." << endl;
        } else {
            listaJugadores.push_back(jugador);
            cout << "Jugador agregado correctamente al equipo " << nombre << "." << endl;
        }
    }

    void eliminarJugador(int idJugador) {
        for (int i = 0; i < listaJugadores.size(); i++) {
            if (listaJugadores[i].getId() == idJugador) {
                listaJugadores.erase(listaJugadores.begin() + i);
                cout << "Jugador eliminado correctamente." << endl;
                return;
            }
        }

        cout << "No se encontro un jugador con ese ID." << endl;
    }

    void mostrarPlantilla() {
        cout << "\nEquipo: " << nombre << endl;
        cout << "Entrenador: " << entrenador << endl;
        cout << "Plantilla completa:" << endl;

        if (listaJugadores.size() == 0) {
            cout << "No hay jugadores registrados." << endl;
        } else {
            for (int i = 0; i < listaJugadores.size(); i++) {
                listaJugadores[i].mostrarInfo();
            }
        }
    }

    void mostrarPlantilla(string posicion) {
        bool encontrado = false;

        cout << "\nJugadores del equipo " << nombre
             << " en la posicion: " << posicion << endl;

        for (int i = 0; i < listaJugadores.size(); i++) {
            if (listaJugadores[i].getPosicion() == posicion) {
                listaJugadores[i].mostrarInfo();
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No hay jugadores registrados en esa posicion." << endl;
        }
    }
};

// Clase Partido
class Partido {

private:
    string fecha;
    string hora;
    int golesLocal;
    int golesVisitante;
    Equipo equipoLocal;
    Equipo equipoVisitante;
    Arbitro arbitro;
    bool jugado;

public:
    Partido() {
        fecha = "";
        hora = "";
        golesLocal = 0;
        golesVisitante = 0;
        jugado = false;
    }

    Partido(string fec, string hor, Equipo local, Equipo visitante, Arbitro arb) {
        fecha = fec;
        hora = hor;
        equipoLocal = local;
        equipoVisitante = visitante;
        arbitro = arb;
        golesLocal = 0;
        golesVisitante = 0;
        jugado = false;
    }

    string getFecha() {
        return fecha;
    }

    string getHora() {
        return hora;
    }

    string getNombreLocal() {
        return equipoLocal.getNombre();
    }

    string getNombreVisitante() {
        return equipoVisitante.getNombre();
    }

    bool equiposDiferentes() {
        return equipoLocal.getNombre() != equipoVisitante.getNombre();
    }

    void registrarResultado() {
        golesLocal = 0;
        golesVisitante = 0;
        jugado = true;

        cout << "Resultado registrado como empate 0-0." << endl;
    }

    void registrarResultado(int golesL, int golesV) {
        if (golesL < 0 || golesV < 0) {
            cout << "Error: no se pueden registrar goles negativos." << endl;
        } else {
            golesLocal = golesL;
            golesVisitante = golesV;
            jugado = true;

            cout << "Resultado registrado correctamente." << endl;
        }
    }

    void mostrarResultado() {
        cout << "\nPartido: " << equipoLocal.getNombre()
             << " vs " << equipoVisitante.getNombre() << endl;

        cout << "Fecha: " << fecha << " | Hora: " << hora << endl;

        cout << "Arbitro asignado: ";
        arbitro.mostrarInfo();

        if (jugado) {
            cout << "Resultado: " << golesLocal
                 << " - " << golesVisitante << endl;
        } else {
            cout << "Resultado pendiente." << endl;
        }
    }
};

// Clase Torneo
class Torneo {

private:
    string nombre;
    vector<Equipo> listaEquipos;
    vector<Partido> listaPartidos;

    // Arreglo de apuntadores para aplicar polimorfismo
    Persona *personas[MAX_PERSONAS];
    int totalPersonas;

public:
    Torneo() {
        nombre = "";
        totalPersonas = 0;
    }

    Torneo(string nom) {
        nombre = nom;
        totalPersonas = 0;
    }

    string getNombre() {
        return nombre;
    }

    void setNombre(string nom) {
        nombre = nom;
    }

    bool existeEquipo(string nombreEquipo) {
        for (int i = 0; i < listaEquipos.size(); i++) {
            if (listaEquipos[i].getNombre() == nombreEquipo) {
                return true;
            }
        }
        return false;
    }

    void registrarEquipo(Equipo equipo) {
        if (existeEquipo(equipo.getNombre())) {
            cout << "No se pudo registrar el equipo. El nombre ya existe." << endl;
        } else {
            listaEquipos.push_back(equipo);
            cout << "Equipo registrado correctamente en el torneo." << endl;
        }
    }

    void registrarPartido(Partido partido) {
        if (!partido.equiposDiferentes()) {
            cout << "No se pudo registrar el partido. El equipo local y visitante no pueden ser el mismo." << endl;
        } else {
            listaPartidos.push_back(partido);
            cout << "Partido registrado correctamente en el torneo." << endl;
        }
    }

    void mostrarEquipos() {
        cout << "\nEquipos registrados en el torneo: " << nombre << endl;

        if (listaEquipos.size() == 0) {
            cout << "No hay equipos registrados." << endl;
        } else {
            for (int i = 0; i < listaEquipos.size(); i++) {
                cout << "- " << listaEquipos[i].getNombre()
                     << " | Entrenador: " << listaEquipos[i].getEntrenador() << endl;
            }
        }
    }

    void mostrarEquipos(string nombreEquipo) {
        bool encontrado = false;

        cout << "\nBusqueda de equipo: " << nombreEquipo << endl;

        for (int i = 0; i < listaEquipos.size(); i++) {
            if (listaEquipos[i].getNombre() == nombreEquipo) {
                cout << "Equipo encontrado: " << listaEquipos[i].getNombre()
                     << " | Entrenador: " << listaEquipos[i].getEntrenador() << endl;
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No se encontro un equipo con ese nombre." << endl;
        }
    }

    void mostrarPartidos() {
        cout << "\nPartidos registrados en el torneo: " << nombre << endl;

        if (listaPartidos.size() == 0) {
            cout << "No hay partidos registrados." << endl;
        } else {
            for (int i = 0; i < listaPartidos.size(); i++) {
                listaPartidos[i].mostrarResultado();
            }
        }
    }

    /*
     * Metodo que registra personas en el torneo.
     * Recibe un apuntador a Persona, por lo que puede recibir
     * objetos de tipo Jugador o Arbitro.
     */
    void registrarPersona(Persona *persona) {
        if (totalPersonas < MAX_PERSONAS) {
            personas[totalPersonas] = persona;
            totalPersonas++;
            cout << "Persona registrada correctamente en el torneo." << endl;
        } else {
            cout << "No se pudo registrar. Se alcanzo el limite de personas." << endl;
        }
    }

    /*
     * Metodo que muestra todas las personas registradas.
     * Aqui se aplica polimorfismo porque cada objeto ejecuta
     * su propia version de mostrarInfo().
     */
    void mostrarPersonas() {
        cout << "\nPersonas registradas en el torneo: " << nombre << endl;

        if (totalPersonas == 0) {
            cout << "No hay personas registradas." << endl;
        } else {
            for (int i = 0; i < totalPersonas; i++) {
                personas[i]->mostrarInfo();
            }
        }
    }

    /*
     * Sobrecarga del metodo mostrarPersonas.
     * Permite mostrar solamente jugadores o solamente arbitros.
     */
    void mostrarPersonas(string tipo) {
        bool encontrado = false;

        cout << "\nPersonas de tipo " << tipo
             << " registradas en el torneo: " << nombre << endl;

        for (int i = 0; i < totalPersonas; i++) {
            if (personas[i]->getTipo() == tipo) {
                personas[i]->mostrarInfo();
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No hay personas registradas de ese tipo." << endl;
        }
    }
};

#endif
