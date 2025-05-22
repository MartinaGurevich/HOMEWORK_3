#include "Presion.hpp"
#include "Posicion.hpp"

#pragma once

class SaveFlightData
{
public:

    Posicion posicion;
    Presion presion;

    SaveFlightData(const Posicion& p, const Presion& q);
    void serializar(ofstream& out) const;
    void deserializar (ifstream& in);
    void imprimir();

    ~SaveFlightData()=default;
};


