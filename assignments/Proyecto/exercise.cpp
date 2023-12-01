#include <iostream>
#include <iomanip>

class Hora {
private:
    int horas;
    int minutos;

public:
    Hora() : horas(0), minutos(0) {}

    Hora(int horas, int minutos) : horas(horas), minutos(minutos) {}

    int getHoras() const {
        return horas;
    }

    int getMinutos() const {
        return minutos;
    }

    void imprime() const {
        std::cout << std::setfill('0') << std::setw(2) << horas << ":" << std::setw(2) << minutos;
    }
};

class Aeropuerto {
private:
    std::string codigo;
    std::string ciudad;
    std::string pais;

public:
    Aeropuerto(const std::string& codigo, const std::string& ciudad, const std::string& pais)
        : codigo(codigo), ciudad(ciudad), pais(pais) {}

    void imprime() const {
        std::cout << "Aeropuerto: " << codigo << " - " << ciudad << ", " << pais;
    }
};

class Vuelo {
private:
    std::string ID;
    Aeropuerto destino;
    std::string aerolinea;
    int numPas;
    Hora salidaEstim;
    Hora salidaReal;
    int estatus;

public:
    Vuelo() : salidaReal(0, 0), estatus(1), destino("", "", "") {}

    Vuelo(const std::string& ID, const Aeropuerto& destino, const std::string& aerolinea, int numPas, const Hora& salidaEstim)
        : ID(ID), destino(destino), aerolinea(aerolinea), numPas(numPas), salidaEstim(salidaEstim), salidaReal(0, 0), estatus(1) {}

    std::string getID() const { return ID; }
    Aeropuerto getDestino() const { return destino; }
    std::string getAerolinea() const { return aerolinea; }
    int getNumPas() const { return numPas; }
    Hora getSalidaEstim() const { return salidaEstim; }
    Hora getSalidaReal() const { return salidaReal; }
    int getEstatus() const { return estatus; }

    void setId(const std::string& newID) { ID = newID; }
    void setDestino(const Aeropuerto& newDestino) { destino = newDestino; }
    void setAerolinea(const std::string& newAerolinea) { aerolinea = newAerolinea; }
    void setNumPas(int newNumPas) { numPas = newNumPas; }
    void setEstatus(int newEstatus) { estatus = newEstatus; }
    void setSalidaEstim(const Hora& newSalidaEstim) { salidaEstim = newSalidaEstim; }
    void setSalidaReal(const Hora& newSalidaReal) { salidaReal = newSalidaReal; }

    int calculaTiempoRetraso() const {
        return (salidaReal.getHoras() * 60 + salidaReal.getMinutos()) - (salidaEstim.getHoras() * 60 + salidaEstim.getMinutos());
    }

    void imprime() const {
        std::cout << "ID: " << ID << std::endl;
        destino.imprime();
        std::cout << "\nAerolínea: " << aerolinea << "\nNúmero de pasajeros: " << numPas
                  << "\nSalida estimada: ";
        salidaEstim.imprime();
        std::cout << "\nSalida real: ";
        salidaReal.imprime();
        std::cout << "\nEstatus: " << (estatus == 1 ? "A tiempo" : "Demorado") << std::endl;
    }
};

int main() {
    // Ejemplo de uso
    Aeropuerto destino("JFK", "Nueva York", "EEUU");
    Hora salidaEstimada(12, 30);

    Vuelo vuelo1("ABC123", destino, "Delta", 150, salidaEstimada);
    vuelo1.setSalidaReal(Hora(13, 0));
    vuelo1.setEstatus(0);

    vuelo1.imprime();

    return 0;
}
