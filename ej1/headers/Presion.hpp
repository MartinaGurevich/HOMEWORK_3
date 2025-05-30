#include "MedicionBase.hpp"
#pragma once 

class Presion: public MedicionBase
{
public:
    float presionEstatica; //p
    float presionDinamica; //q

    void imprimir() override;

    void serializar( ofstream& out)const ;
    void deserializar(ifstream& in) ;
    
    Presion(float p, float q, float t);
    ~Presion()= default ;
};


