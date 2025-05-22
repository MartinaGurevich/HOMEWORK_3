#include "MedicionBase.hpp"
#include "Posicion.hpp"
#include "Presion.hpp"
#include "SaveFlightData.hpp"

int main (){
    //valores de punto b
    Posicion posicion(-34.6f, -58.4f, 950.0f, 5.3);
    Presion presion(101.3f, 5.8f, 6.1f);

    // posicion.imprimir();
    // presion.imprimir();

    SaveFlightData data(posicion,presion);
    
    //serializo 
    ofstream out("datos_totales.dat", ios::binary);
    if(out.is_open()){
        data.serializar(out);
        out.close();
    }
    
    //deserializo
    SaveFlightData copy(posicion, presion);

    ifstream in("datos_totales.dat", ios::binary);
    if (in.is_open()){
        copy.deserializar(in);
        in.close();}

    copy.imprimir();
    return 0;
    
}