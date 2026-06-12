/*
 *
 * Proyecto Integrador Sistema de Gestion de Torneos Amateur
 * Georgina Garcia Martinez
 * 11-06-2026
 * version : 5
 * Este archivo define las clases Liga, Equipo, Partido y Torneo.
 * Liga guarda las personas registradas. Equipo, Partido y Torneo guardan
 * la informacion principal del torneo.
 */

#ifndef TORNEO_H_
#define TORNEO_H_

#include <iostream>
#include <string>
#include <vector>

#include "persona.h"

using namespace std;

const int MAX_PERSONAS = 100;

// Declaro clase Liga
class Liga {

private:
    // Variables de instancia del objeto
    string nombre;
    Persona *personas[MAX_PERSONAS];
    int totalPersonas;

public:
    // Declaro constructores
    Liga() {
        nombre = "";
        totalPersonas = 0;
    }

    Liga(string nom) {
        nombre = nom;
        totalPersonas = 0;
    }

    // Declaro metodos publicos
    string getNombre() {
        return nombre;
    }

    void setNombre(string nom) {
        nombre = nom;
    }

    bool existePersona(Persona *persona) {
        for (int i = 0; i < totalPersonas; i++) {
            if (personas[i]->getId() == persona->getId() &&
                personas[i]->getTipo() == persona->getTipo()) {
                return true;
            }
        }

        return false;
    }

    /**
     * registrarPersona agrega una persona a la liga.
     *
     * Guarda jugadores y arbitros en el mismo arreglo de Persona.
     *
     * @param persona apuntador a la persona que se registra.
     * @return
     */
    void registrarPersona(Persona *persona) {
        if (totalPersonas >= MAX_PERSONAS) {
            cout << "No se pudo registrar. Se alcanzo el limite de personas." << endl;
        } else if (existePersona(persona)) {
            cout << "No se pudo registrar. La persona ya existe en la liga." << endl;
        } else {
            personas[totalPersonas] = persona;
            totalPersonas++;
            cout << "Persona registrada correctamente en la liga." << endl;
        }
    }

    /**
     * mostrarPersonas imprime todas las personas registradas.
     *
     * Recorre el arreglo y muestra la informacion de cada persona.
     *
     * @param
     * @return
     */
    void mostrarPersonas() {
        cout << "\nPersonas registradas en la liga: " << nombre << endl;

        if (totalPersonas == 0) {
            cout << "No hay personas registradas." << endl;
        } else {
            for (int i = 0; i < totalPersonas; i++) {
                personas[i]->mostrarInfo();
            }
        }
    }

    /**
     * mostrarPersonas imprime personas por tipo.
     *
     * Sobrecarga del metodo mostrarPersonas.
     *
     * @param tipo tipo de persona que se quiere mostrar.
     * @return
     */
    void mostrarPersonas(string tipo) {
        bool encontrado = false;

        cout << "\nPersonas de tipo " << tipo
             << " registradas en la liga: " << nombre << endl;

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

// Declaro clase Equipo
class Equipo {

private:
    // Variables de instancia del objeto
    string nombre;
    string entrenador;
    vector<Jugador*> listaJugadores;

public:
    // Declaro constructores
    Equipo() {
        nombre = "";
        entrenador = "";
    }

    Equipo(string nom, string ent) {
        nombre = nom;
        entrenador = ent;
    }

    // Declaro metodos publicos
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

    // Sobrecarga del operador ==
    bool operator==(Equipo otro) {
        return nombre == otro.getNombre();
    }

    bool existeJugador(int idJugador) {
        Jugador buscado(idJugador, "", 0, "", 0);

        for (int i = 0; i < listaJugadores.size(); i++) {
            if (*(listaJugadores[i]) == buscado) {
                return true;
            }
        }

        return false;
    }

    void agregarJugador(Jugador *jugador) {
        if (existeJugador(jugador->getId())) {
            cout << "No se pudo agregar al jugador. El ID ya existe en el equipo." << endl;
        } else {
            listaJugadores.push_back(jugador);
            cout << "Jugador agregado correctamente al equipo " << nombre << "." << endl;
        }
    }

    void eliminarJugador(int idJugador) {
        for (int i = 0; i < listaJugadores.size(); i++) {
            if (listaJugadores[i]->getId() == idJugador) {
                listaJugadores.erase(listaJugadores.begin() + i);
                cout << "Jugador eliminado correctamente." << endl;
                return;
            }
        }

        cout << "No se encontro un jugador con ese ID." << endl;
    }

    /**
     * mostrarPlantilla imprime los jugadores del equipo.
     *
     * Muestra la informacion de todos los jugadores registrados.
     *
     * @param
     * @return
     */
    void mostrarPlantilla() {
        cout << "\nEquipo: " << nombre << endl;
        cout << "Entrenador: " << entrenador << endl;
        cout << "Plantilla completa:" << endl;

        if (listaJugadores.size() == 0) {
            cout << "No hay jugadores registrados." << endl;
        } else {
            for (int i = 0; i < listaJugadores.size(); i++) {
                listaJugadores[i]->mostrarInfo();
            }
        }
    }

    /**
     * mostrarPlantilla imprime jugadores por posicion.
     *
     * Sobrecarga del metodo mostrarPlantilla.
     *
     * @param posicion posicion que se desea buscar.
     * @return
     */
    void mostrarPlantilla(string posicion) {
        bool encontrado = false;

        cout << "\nJugadores del equipo " << nombre
             << " en la posicion: " << posicion << endl;

        for (int i = 0; i < listaJugadores.size(); i++) {
            if (listaJugadores[i]->getPosicion() == posicion) {
                listaJugadores[i]->mostrarInfo();
                encontrado = true;
            }
        }

        if (!encontrado) {
            cout << "No hay jugadores registrados en esa posicion." << endl;
        }
    }
};

// Declaro clase Partido
class Partido {

private:
    // Variables de instancia del objeto
    string fecha;
    string hora;
    int golesLocal;
    int golesVisitante;
    Equipo equipoLocal;
    Equipo equipoVisitante;
    Arbitro *arbitro;
    bool jugado;

public:
    // Declaro constructores
    Partido() {
        fecha = "";
        hora = "";
        golesLocal = 0;
        golesVisitante = 0;
        arbitro = 0;
        jugado = false;
    }

    Partido(string fec, string hor, Equipo local, Equipo visitante, Arbitro *arb) {
        fecha = fec;
        hora = hor;
        equipoLocal = local;
        equipoVisitante = visitante;
        arbitro = arb;
        golesLocal = 0;
        golesVisitante = 0;
        jugado = false;
    }

    // Declaro metodos publicos
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

    // Sobrecarga de registrarResultado
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

    /**
     * mostrarResultado imprime la informacion del partido.
     *
     * Muestra equipos, fecha, hora, arbitro y resultado.
     *
     * @param
     * @return
     */
    void mostrarResultado() {
        cout << "\nPartido: " << equipoLocal.getNombre()
             << " vs " << equipoVisitante.getNombre() << endl;

        cout << "Fecha: " << fecha << " | Hora: " << hora << endl;

        cout << "Arbitro asignado: ";
        if (arbitro != 0) {
            arbitro->mostrarInfo();
        } else {
            cout << "Sin arbitro asignado." << endl;
        }

        if (jugado) {
            cout << "Resultado: " << golesLocal
                 << " - " << golesVisitante << endl;
        } else {
            cout << "Resultado pendiente." << endl;
        }
    }
};

// Declaro clase Torneo
class Torneo {

private:
    // Variables de instancia del objeto
    string nombre;
    vector<Equipo> listaEquipos;
    vector<Partido> listaPartidos;

public:
    // Declaro constructores
    Torneo() {
        nombre = "";
    }

    Torneo(string nom) {
        nombre = nom;
    }

    // Declaro metodos publicos
    string getNombre() {
        return nombre;
    }

    void setNombre(string nom) {
        nombre = nom;
    }

    bool existeEquipo(string nombreEquipo) {
        Equipo buscado(nombreEquipo, "");

        for (int i = 0; i < listaEquipos.size(); i++) {
            if (listaEquipos[i] == buscado) {
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

    /**
     * mostrarEquipos imprime los equipos registrados.
     *
     * Muestra el nombre y entrenador de cada equipo.
     *
     * @param
     * @return
     */
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

    /**
     * mostrarEquipos imprime un equipo buscado.
     *
     * Sobrecarga del metodo mostrarEquipos.
     *
     * @param nombreEquipo nombre del equipo que se quiere mostrar.
     * @return
     */
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

    /**
     * mostrarPartidos imprime los partidos registrados.
     *
     * Recorre el vector de partidos registrados en el torneo.
     *
     * @param
     * @return
     */
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
};

#endif // TORNEO_H_