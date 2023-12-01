#include <iostream>
#include <fstream>
#include <iomanip>
#include "Aeropuerto.hpp"
#include "Vuelo.hpp"

const int MAX_AEROPUERTOS = 7; 
const int MAX_VUELOS = 20;    

int main() {
    Aeropuerto aeropuertos[MAX_AEROPUERTOS];
    Vuelo vuelos[MAX_VUELOS];

    std::ifstream file("aeropuertos.txt");
    if (file.is_open()) {
        for (int i = 0; i < MAX_AEROPUERTOS; ++i) {
            std::string clave, nombre, ciudad, pais;
            file >> clave >> nombre >> ciudad >> pais;
            aeropuertos[i] = Aeropuerto(clave, nombre, ciudad, pais);
        }
        file.close();
    } else {
        std::cout << "Error\n";
    }
    std::ifstream file("datosVuelos.txt");
    if (file.is_open()) {
        for (int i = 0; i < MAX_VUELOS; ++i) {
            std::string id, destinoClave, aerolinea;
            int numPasajeros, salidaEstimHora, salidaEstimMin;
            file >> id >> destinoClave >> aerolinea >> numPasajeros >> salidaEstimHora >> salidaEstimMin;

            Aeropuerto destino;
            int pos = buscaAeropuerto(destinoClave, aeropuertos);
            if (pos != -1) {
                destino = aeropuertos[pos];
            } else {
                std::cout << "Error" << id << "\n";
                continue;
            }

            Hora salidaEstim(salidaEstimHora, salidaEstimMin);
            vuelos[i] = Vuelo(id, destino, aerolinea, numPasajeros, salidaEstim);
        }
        file.close();
    } else {
        std::cout << "Error '\n";
    }

    int opcion;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Desplegar la lista de Aeropuertos destino\n";
        std::cout << "2. Desplegar la lista de Vuelos\n";
        std::cout << "3. Desplegar Vuelos que van a un determinado destino\n";
        std::cout << "4. Desplegar Vuelos que salen en un rango de tiempo y 'A tiempo'\n";
        std::cout << "5. Capturar la hora de salida real de un Vuelo\n";
        std::cout << "6. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                desplegarAeropuertos(aeropuertos);
                break;
            case 2:
                desplegarVuelos(vuelos);
                break;
            case 3:
                desplegarVuelosDestino(vuelos, aeropuertos);
                break;
            case 4:
                desplegarVuelosEnRango(vuelos);
                break;
            case 5:
                capturarHoraSalidaReal(vuelos, aeropuertos);
                break;
            case 6:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion invalida. Intente de nuevo.\n";
        }

    } while (opcion != 6);

    return 0;
}


int buscaAeropuerto(const std::string& clave, Aeropuerto aeropuertos[MAX_AEROPUERTOS]) {
    for (int i = 0; i < MAX_AEROPUERTOS; ++i) {
        if (aeropuertos[i].getClave() == clave) {
            return i; 
        }
    }
    return -1; 
}

void desplegarAeropuertos(const Aeropuerto aeropuertos[MAX_AEROPUERTOS]) {
    std::cout << "Aeropuertos:\n";
    for (int i = 0; i < MAX_AEROPUERTOS; ++i) {
        aeropuertos[i].imprime();
    }
}

void desplegarVuelos(const Vuelo vuelos[MAX_VUELOS]) {
    std::cout << "Vuelos:\n";
    for (int i = 0; i < MAX_VUELOS; ++i) {
        vuelos[i].imprime();
    }
}

void desplegarVuelosDestino(const Vuelo vuelos[MAX_VUELOS], const Aeropuerto aeropuertos[MAX_AEROPUERTOS]) {
    std::string clave;
    std::cout << "Ingrese la clave del aeropuerto destino: ";
    std::cin >> clave;

    int pos = buscaAeropuerto(clave, aeropuertos);
    if (pos != -1) {
        std::cout << "Vuelos con destino a " << aeropuertos[pos].getNombre() << ":\n";
        for (int i = 0; i < MAX_VUELOS; ++i) {
            if (vuelos[i].getDestino().getClave() == clave) {
                vuelos[i].imprime();
            }
        }
    } else {
        std::cout << "Error: Aeropuerto con clave " << clave << " no encontrado\n";
    }
}

void desplegarVuelosEnRango(const Vuelo vuelos[MAX_VUELOS]) {
    int horaInicio, minInicio, horaFin, minFin;

    std::cout << "Ingrese la hora de inicio (formato 24 horas - hh:mm): ";
    std::cin >> horaInicio >> minInicio;

    std::cout << "Ingrese la hora de fin (formato 24 horas - hh:mm): ";
    std::cin >> horaFin >> minFin;

    Hora inicio(horaInicio, minInicio);
    Hora fin(horaFin, minFin);

    std::cout << "Vuelos en el rango de tiempo " << inicio.getHora() << ":" << inicio.getMin() << " a " << fin.getHora() << ":" << fin.getMin() << ":\n";

    for (int i = 0; i < MAX_VUELOS; ++i) {
        if (vuelos[i].getSalidaEstim() >= inicio && vuelos[i].getSalidaEstim() <= fin) {
            vuelos[i].imprime();
        }
    }
}

void capturarHoraSalidaReal(Vuelo vuelos[MAX_VUELOS], const Aeropuerto aeropuertos[MAX_AEROPUERTOS]) {
    std::string id;
    std::cout << "Ingrese el ID del vuelo: ";
    std::cin >> id;

    int pos = -1;
    for (int i = 0; i < MAX_VUELOS; ++i) {
        if (vuelos[i].getId() == id) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        int horaReal, minReal;
        std::cout << "Ingrese la hora de salida real (formato 24 horas - hh:mm): ";
        std::cin >> horaReal >> minReal;

        Hora salidaReal(horaReal, minReal);

        vuelos[pos].setSalidaReal(salidaReal);

        if (vuelos[pos].getSalidaReal() > vuelos[pos].getSalidaEstim()) {
            vuelos[pos].setEstatus(0); 
            int minutosRetraso = vuelos[pos].calculaTiempoRetraso();
            std::cout << "El vuelo está demorado " << minutosRetraso << " minutos.\n";
        } else {
            vuelos[pos].setEstatus(1); 
            std::cout << "El vuelo está a tiempo.\n";
        }
    } else {
        std::cout << "Error: Vuelo con ID " << id << " no encontrado\n";
    }
}

