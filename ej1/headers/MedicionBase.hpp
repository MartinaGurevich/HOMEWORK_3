#include "Imediciones.hpp"
#pragma once 

class MedicionBase: public Imediciones //derivada de la interfaz
{
protected:
    unique_ptr<float> tiempoMedicion;
public:

    MedicionBase(float tiempoMedicion);
    MedicionBase(const MedicionBase& rht); //constructor de deep copy
    
    void serializar( ofstream& out)const override;
    void deserializar(ifstream& in)  override;
    float getTiempo();

    
    virtual void imprimir()= 0 ; 
    virtual ~MedicionBase()= default;
};
