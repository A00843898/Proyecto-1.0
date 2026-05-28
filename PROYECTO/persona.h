/*
 * Este archivo contiene la clase abstracta Persona
 * y las clases Jugador y Arbitro, que heredan de Persona.
 */

#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>
#include <string>

using namespace std;

// Clase abstracta
class Persona {

protected:
    int id;
    string nombre;
    int edad;
    string tipo;

public:
    Persona() {
        id = 0;
        nombre = "";
        edad = 0;
        tipo = "";
    }

    Persona(int id_num, string nom, int ed, string tip) {
        id = id_num;
        nombre = nom;
        edad = ed;
        tipo = tip;
    }

    int getId() {
        return id;
    }

    string getNombre() {
        return nombre;
    }

    int getEdad() {
        return edad;
    }

    string getTipo() {
        return tipo;
    }

    void setNombre(string nom) {
        nombre = nom;
    }

    void setEdad(int ed) {
        edad = ed;
    }

    // Metodo abstracto que se sobreescribe en las clases hijas
    virtual void mostrarInfo() = 0;
};

// Clase Jugador que hereda de Persona
class Jugador : public Persona {

private:
    string posicion;
    int numero;

public:
    Jugador() : Persona(0, "", 0, "jugador") {
        posicion = "";
        numero = 0;
    }

    Jugador(int id_num, string nom, int ed, string pos, int num)
        : Persona(id_num, nom, ed, "jugador") {
        posicion = pos;
        numero = num;
    }

    string getPosicion() {
        return posicion;
    }

    int getNumero() {
        return numero;
    }

    void setPosicion(string pos) {
        posicion = pos;
    }

    void setNumero(int num) {
        numero = num;
    }

    // Sobreescritura del metodo mostrarInfo()
    void mostrarInfo() {
        cout << "Jugador ID: " << id
             << " | Nombre: " << nombre
             << " | Edad: " << edad
             << " | Posicion: " << posicion
             << " | Numero: " << numero << endl;
    }
};

// Clase Arbitro que hereda de Persona
class Arbitro : public Persona {

private:
    int experiencia;

public:
    Arbitro() : Persona(0, "", 0, "arbitro") {
        experiencia = 0;
    }

    Arbitro(int id_num, string nom, int ed, int exp)
        : Persona(id_num, nom, ed, "arbitro") {
        experiencia = exp;
    }

    int getExperiencia() {
        return experiencia;
    }

    void setExperiencia(int exp) {
        experiencia = exp;
    }

    // Sobreescritura del metodo mostrarInfo()
    void mostrarInfo() {
        cout << "Arbitro ID: " << id
             << " | Nombre: " << nombre
             << " | Edad: " << edad
             << " | Experiencia: " << experiencia << " anios" << endl;
    }
};

#endif
