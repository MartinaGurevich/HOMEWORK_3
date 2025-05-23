#include "Procesadorfig.hpp"
#include <iostream>
using namespace std;

int main(){
    
    punto P= {2.3f, 5.1f};
    circulo circ= {5.0f,2.1f,6.2f};
    Elipse eli={4.3f,6.2f,2.5f, 4.1f};
    Rectángulo rect={4.3f,6.2f, 5.3f, 10.5f};

    ProcesadorFigura<punto> areaP(P);
    ProcesadorFigura<circulo> areaC(circ);
    ProcesadorFigura<Elipse> areaE;
    ProcesadorFigura<Rectángulo> areaR;

    cout << "Area de un punto: "<< areaP.calcularArea()<< endl;
    cout << "Area de Circulo: "<< areaC.calcularArea()<< endl;
    cout << "Area de Elipse: "<< areaE.calcularArea(eli)<< endl;
    cout << "Area de Rectángulo: "<< areaR.calcularArea(rect)<< endl;
}


/*preg :  si esta bien en la forma que hago el tenplate , para como se elige cada area ... yo lo pongo " manual " pero no se si esta bien asi */