
#include <iostream>
#include "Vuelo.hpp"

Vuelo::Vuelo() : salidaReal(), estatus(1) {}

Vuelo::Vuelo(std::string id, Aeropuerto dest, std::string aerolinea, int numPas, Hora salidaEstim)
    : ID(id), destino(dest), aerolinea(aerolinea), numPas(numPas), salidaEstim(salidaEstim), salidaReal(), estatus(1) {}

std::string Vuelo::getID() const {
    return ID;
}

Aeropuerto Vuelo::getDestino() const {
    return destino;
}

std::string Vuelo::getAerolinea() const {
    return aerolinea;
}

int Vuelo::getNumPas() const {
    return numPas;
}

Hora Vuelo::getSalidaEstim() const {
    return salidaEstim;
}

Hora Vuelo::getSalidaReal() const {
    return salidaReal;
}

int Vuelo::getEstatus() const {
    return estatus;
}

void Vuelo::setId(std::string id) {
    ID = id;
}

void Vuelo::setDestino(Aeropuerto dest) {
    destino = dest;
}

void Vuelo::setAerolinea(std::string aero) {
    aerolinea = aero;
}

void Vuelo::setNumPas(int num) {
    numPas = num;
}

void Vuelo::setEstatus(int est) {
    estatus = est;
}

void Vuelo::setSalidaEstim(Hora salidaEstim) {
    this->salidaEstim = salidaEstim;
}

void Vuelo::setSalidaReal(Hora salidaReal) {
    this->salidaReal = salidaReal;
}

int Vuelo::calculaTiempoRetraso() const {
    int MinRet = 0;

    
    if (estatus == 0) {
        if (salidaReal.getHora() > salidaEstim.getHora() || (salidaReal.getHora() == salidaEstim.getHora() && salidaReal.getMin() > salidaEstim.getMin())) {
            MinRet = (salidaReal.getHora() - salidaEstim.getHora()) * 60 + (salidaReal.getMin() - salidaEstim.getMin());
        }
    }

    return MinRet;
}

void Vuelo::imprime() const {
    std::cout << "ID: " << ID << ", Destino: ";
    destino.imprime();
    std::cout << ", Aerolínea: " << aerolinea << ", NumPas: " << numPas << ", Salida Estimada: ";
    salidaEstim.imprime();
    std::cout << ", Salida Real: ";
    salidaReal.imprime();
    std::cout << ", Estatus: " << (estatus == 1 ? "A tiempo" : "Demorado") << std::endl;
}
