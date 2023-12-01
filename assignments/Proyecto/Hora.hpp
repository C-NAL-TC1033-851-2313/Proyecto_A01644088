
#ifndef HORA_HPP
#define HORA_HPP

class Hora {
private:
    int hora;
    int minutos;

public:
    Hora();
    Hora(int h, int m);
    int getHora() const;
    int getMin() const;
    void setHora(int h);
    void setMin(int m);
    void imprime() const;
};

#endif 
