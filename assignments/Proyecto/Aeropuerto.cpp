
#include <iostream>
#include "Aeropuerto.hpp"

Aeropuerto::Aeropuerto() {}

Aeropuerto::Aeropuerto(std::string clave, std::string nombre, std::string ciudad, std::string pais)
    : clave(clave), nombre(nombre), ciudad(ciudad), pais(pais) {}

std::string Aeropuerto::getClave() const {
    return clave;
}

std::string Aeropuerto::getNombre() const {
    return nombre;
}

std::string Aeropuerto::getCiudad() const {
    return ciudad;
}

std::string Aeropuerto::getPais() const {
    return pais;
}

void Aeropuerto::setClave(std::string c) {
    clave = c;
}

void Aeropuerto::setNombre(std::string n) {
    nombre = n;
}

void Aeropuerto::setCiudad(std::string c) {
    ciudad = c;
}

void Aeropuerto::setPais(std::string p) {
    pais = p;
}

void Aeropuerto::imprime() const {
    std::cout << "Clave: " << clave << ", Nombre: " << nombre << ", Ciudad: " << ciudad << ", Pais: " << pais;
}
