#include "Posicion.hpp"

Posicion::Posicion(float lat, float lon, float alt, float t):latitud(lat), longitud(lon),altitud(alt),
MedicionBase(t){};

Posicion::Posicion( const Posicion& rht):latitud(rht.latitud), longitud(rht.longitud),altitud(rht.altitud),
MedicionBase(rht){}; //copio constr

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
    cout<<"--> LATITUD: "<<latitud<<endl;
    cout<<"--> LONGITUD: "<<longitud<<endl;
    cout<<"--> ALTITUD: "<<altitud<<endl;
    cout<<"--> TIEMPO DE MEDICION: "<<getTiempo()<<endl;
}