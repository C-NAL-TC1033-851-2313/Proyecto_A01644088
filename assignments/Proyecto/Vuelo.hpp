
#ifndef VUELO_HPP
#define VUELO_HPP

#include "Hora.hpp"
#include "Aeropuerto.hpp"
#include <string>

class Vuelo {
private:
    std::string ID;
    Aeropuerto destino;
    std::string aerolinea;
    int numPas;
    Hora salidaEstim;
    Hora salidaReal;
    int estatus;

    static const int MAX_VUELOS = 20;

public:
    Vuelo();
    Vuelo(std::string id, Aeropuerto dest, std::string aerolinea, int numPas, Hora salidaEstim);
    std::string getID() const;
    Aeropuerto getDestino() const;
    std::string getAerolinea() const;
    int getNumPas() const;
    Hora getSalidaEstim() const;
    Hora getSalidaReal() const;
    int getEstatus() const;
    void setId(std::string id);
    void setDestino(Aeropuerto dest);
    void setAerolinea(std::string aerolinea);
    void setNumPas(int numPas);
    void setEstatus(int est);
    void setSalidaEstim(Hora salidaEstim);
    void setSalidaReal(Hora salidaReal);
    int calculaTiempoRetraso() const;
    void imprime() const;
};

#endif
