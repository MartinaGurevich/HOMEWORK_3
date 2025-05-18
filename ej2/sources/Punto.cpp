#include "Punto.hpp"

punto:: punto(float x, float y): x(x), y(y){};

void punto::Setpunto_x( float nueva_x){
    x=nueva_x;
}

void punto::Setpunto_y( float nueva_y){
    y=nueva_y;
}

float punto::Get_punto_x()const{
    return x;
}

float punto:: Get_punto_y()const{
    return y;
}