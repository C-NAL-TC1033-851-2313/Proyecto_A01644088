
#include <iostream>
#include <iomanip>
#include "Hora.hpp"

Hora::Hora() : hora(0), minutos(0) {}

Hora::Hora(int h, int m) : hora(0), minutos(0) {
    setHora(h);
    setMin(m);
}

int Hora::getHora() const {
    return hora;
}

int Hora::getMin() const {
    return minutos;
}

void Hora::setHora(int h) {
    if (h >= 0 && h <= 23) {
        hora = h;
    } else {
        std::cerr << "Error: Hora invalida. Puesto como 00:00.\n";
    }
}

void Hora::setMin(int m) {
    if (m >= 0 && m <= 59) {
        minutos = m;
    } else {
        std::cerr << "Error: Hora invalida. Puesto como 00:00.\n";
    }
}

void Hora::imprime() const {
    std::cout << std::setw(2) << std::setfill('0') << hora << ":" << std::setw(2) << std::setfill('0') << minutos;
}
