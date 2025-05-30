#include "MedicionBase.hpp"
#pragma once 



class Posicion: public MedicionBase
{

public:

    float latitud;
    float longitud;
    float altitud;

    void imprimir() override;

    void serializar( ofstream& out)const ;
    void deserializar(ifstream& in) ;

    Posicion(float lat, float lon, float alt, float t);
    ~Posicion()= default;
};
