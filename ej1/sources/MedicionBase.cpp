#include "MedicionBase.hpp"

MedicionBase:: MedicionBase(float tiempoMedicion): tiempoMedicion(make_unique<float> (tiempoMedicion)){};

MedicionBase::MedicionBase(const MedicionBase& rht): tiempoMedicion(make_unique<float> (*rht.tiempoMedicion)){}; //copy constructor

void MedicionBase:: serializar(ofstream& out) const{
    out.write(reinterpret_cast<const char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

void MedicionBase:: deserializar(ifstream& in){
    //asigno memo
    tiempoMedicion= make_unique<float>(0.0f);
    in.read(reinterpret_cast<char*>(tiempoMedicion.get()), sizeof(*tiempoMedicion));
}

float MedicionBase:: getTiempo(){
    return *tiempoMedicion; //dereferenciacion de puntero 
}