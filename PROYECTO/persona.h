/*
 *
 * Proyecto Integrador Sistema de Gestion de Torneos Amateur
 * Georgina Garcia Martinez
 * 11-06-2026
 * version : 5
 * Este archivo define la clase abstracta Persona y las clases heredadas
 * Jugador y Arbitro. Estas clases representan a las personas que participan
 * en la liga.
 */

#ifndef PERSONA_H_
#define PERSONA_H_

#include <iostream>
#include <string>

using namespace std;

// Declaracion de clase Persona que es abstracta
class Persona {

protected:
    // Declaro variables de instancia
    int id;
    string nombre;
    int edad;
    string tipo;

public:
    // Declaro constructores
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

    virtual ~Persona() {}

    // Declaro metodos publicos
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

    virtual void mostrarInfo() = 0; // metodo abstracto que sera sobreescrito
};

// Declaro objeto Jugador que hereda de Persona
class Jugador : public Persona {

private:
    // Variables de instancia del objeto
    string posicion;
    int numero;

public:
    // Declaro constructores
    Jugador() : Persona(0, "", 0, "jugador") {
        posicion = "";
        numero = 0;
    }

    Jugador(int id_num, string nom, int ed, string pos, int num)
        : Persona(id_num, nom, ed, "jugador") {
        posicion = pos;
        numero = num;
    }

    // Declaro metodos publicos
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

    // Sobrecarga del operador ==
    bool operator==(Jugador otro) {
        return id == otro.getId();
    }

    /**
     * mostrarInfo imprime los datos del jugador.
     *
     * Muestra los valores de los atributos en pantalla.
     *
     * @param
     * @return
     */
    void mostrarInfo() {
        cout << "Jugador ID: " << id
             << " | Nombre: " << nombre
             << " | Edad: " << edad
             << " | Posicion: " << posicion
             << " | Numero: " << numero << endl;
    }
};

// Declaro objeto Arbitro que hereda de Persona
class Arbitro : public Persona {

private:
    // Variable de instancia del objeto
    int experiencia;

public:
    // Declaro constructores
    Arbitro() : Persona(0, "", 0, "arbitro") {
        experiencia = 0;
    }

    Arbitro(int id_num, string nom, int ed, int exp)
        : Persona(id_num, nom, ed, "arbitro") {
        experiencia = exp;
    }

    // Declaro metodos publicos
    int getExperiencia() {
        return experiencia;
    }

    void setExperiencia(int exp) {
        experiencia = exp;
    }

    /**
     * mostrarInfo imprime los datos del arbitro.
     *
     * Muestra los valores de los atributos en pantalla.
     *
     * @param
     * @return
     */
    void mostrarInfo() {
        cout << "Arbitro ID: " << id
             << " | Nombre: " << nombre
             << " | Edad: " << edad
             << " | Experiencia: " << experiencia << " anios" << endl;
    }
};

#endif // PERSONA_H_