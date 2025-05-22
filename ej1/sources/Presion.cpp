#include "Presion.hpp"

Presion:: Presion(float p, float q, float t): MedicionBase(t),presionEstatica(p), presionDinamica(q){};

Presion:: Presion(const Presion& rht):  MedicionBase(rht),presionEstatica(rht.presionEstatica), presionDinamica(rht.presionDinamica){};

void Presion:: serializar(ofstream& out) const{
    MedicionBase::serializar(out); //tiempo
    out.write(reinterpret_cast<const char*>(&presionEstatica), sizeof(presionEstatica));
    out.write(reinterpret_cast<const char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion:: deserializar(ifstream& in) {
    MedicionBase::deserializar(in); //tiempo
    in.read(reinterpret_cast<char*>(&presionEstatica), sizeof(presionEstatica));
    in.read(reinterpret_cast<char*>(&presionDinamica), sizeof(presionDinamica));
}

void Presion:: imprimir(){
    cout<<"--PRESION--"<<endl;
    cout<<"--> PRESIÓN ESTÁTICA: "<<presionEstatica<<endl;
    cout<<"--> PRESIÓN DINÁMICA: "<<presionDinamica<<endl;
    cout<<"--> TIEMPO DE MEDICION: "<<getTiempo()<<endl;
}