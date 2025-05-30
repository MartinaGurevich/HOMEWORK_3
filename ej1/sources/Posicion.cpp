#include "Posicion.hpp"

Posicion::Posicion(float latitud, float longitud, float altitud, float t):MedicionBase(t), latitud(latitud), longitud(longitud),altitud(altitud){};

void Posicion:: serializar(ofstream& out) const{
    MedicionBase::serializar(out); //tiempo
    out.write(reinterpret_cast<const char*>(&latitud), sizeof(latitud));
    out.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    out.write(reinterpret_cast<const char*>(&altitud), sizeof(altitud));
}

void Posicion:: deserializar(ifstream& in) {
    MedicionBase::deserializar(in); //tiempo
    in.read(reinterpret_cast<char*>(&latitud), sizeof(latitud));
    in.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    in.read(reinterpret_cast<char*>(&altitud), sizeof(altitud));
}

void Posicion:: imprimir(){
    cout<<"------------------POSICION------------------------\n";
    cout<<"--> LATITUD: "<<latitud<<endl;
    cout<<"--> LONGITUD: "<<longitud<<endl;
    cout<<"--> ALTITUD: "<<altitud<<endl;
    cout<<"--> TIEMPO DE MEDICION: "<<getTiempo()<<endl;
}