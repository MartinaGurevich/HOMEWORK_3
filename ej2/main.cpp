#include "Procesadorfig.hpp"
#include <iostream>
using namespace std;

int main(){
    
    punto P= {2.3f, 5.1f};
    circulo circ= {5.0f,2.1f,6.2f};//primer valor es el radio 
    Elipse eli={4.3f,6.2f,2.5f, 4.1f}; //primeros dos valores x,y, ultimos dos a y b (utiles para area)
    Rectángulo rect={4.3f,6.2f, 5.3f, 10.5f};//ancho y largo , ultimos dos valores

    ProcesadorFigura<punto> areaP(P);
    ProcesadorFigura<circulo> areaC(circ);
    ProcesadorFigura<Elipse> areaE(eli);
    ProcesadorFigura<Rectángulo> areaR(rect);

    cout << "Area de un punto: "<< areaP.calcularArea()<< endl;
    cout << "Area de Circulo: "<< areaC.calcularArea()<< endl;
    cout << "Area de Elipse: "<< areaE.calcularArea()<< endl;
    cout << "Area de Rectángulo: "<< areaR.calcularArea()<< endl;
}


