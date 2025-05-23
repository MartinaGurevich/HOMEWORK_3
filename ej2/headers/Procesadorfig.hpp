#pragma once 
#include "iostream"
#include<math.h>
#include "Circulo.hpp"
#include "Elipse.hpp"
#include "Rectangulo.hpp"
#include "Punto.hpp"

using namespace std;

template <typename T> //aca va a entrar circulo 
class ProcesadorFigura{
private:
    T figura; //va a enytrar punto

public:
    ProcesadorFigura(const T& figura): figura(figura){};
    float calcularArea(){
        cout<<"no se puede calcular este area, esta es:";
        return 0.0f; //area nula
    }
};

template<>
class ProcesadorFigura<circulo>{
private: 
    circulo circ;
public:
    ProcesadorFigura(const circulo& circulo): circ (circulo){};
    float calcularArea(){
        return  M_PI * circ.Get_Circle_R();
    }
};

template<>
class ProcesadorFigura<Elipse>{
private: 
    Elipse elip;
public:
    ProcesadorFigura(const Elipse& elipse): elip(elipse);
    float calcularArea(const Elipse& elip){
        return M_PI* elip.Get_Elip_a() * elip.Get_Elip_b();
    }
};

template<>
class ProcesadorFigura<Rectángulo>{
public:
    float calcularArea(const Rectángulo& rect){
        return rect.Get_Rect_ancho()* rect.Get_Rect_largo();
    }
};






