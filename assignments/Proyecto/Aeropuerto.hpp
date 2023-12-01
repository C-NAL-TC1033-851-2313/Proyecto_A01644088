
#ifndef AEROPUERTO_HPP
#define AEROPUERTO_HPP

#include <string>

class Aeropuerto {
private:
    std::string clave;
    std::string nombre;
    std::string ciudad;
    std::string pais;

    static const int MAX_AEROPUERTOS = 10;

public:
    Aeropuerto();
    Aeropuerto(std::string clave, std::string nombre, std::string ciudad, std::string pais);
    std::string getClave() const;
    std::string getNombre() const;
    std::string getCiudad() const;
    std::string getPais() const;
    void setClave(std::string clave);
    void setNombre(std::string nombre);
    void setCiudad(std::string ciudad);
    void setPais(std::string pais);
    void imprime() const;
};

#endif
