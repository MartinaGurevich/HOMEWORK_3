#include"Circulo.hpp"

circulo:: circulo(float radio, float x, float y): radio(radio), x(x), y(y){};

void circulo:: SetCircle_x(float nueva_x){
    x=nueva_x;
}

void circulo:: SetCircle_y(float nueva_y){
    y=nueva_y;
}
void circulo:: SetCircle_R(float nuevo_r){
    radio=nuevo_r;
}

float circulo:: Get_Circle_x() const{
    return x;
}
float circulo:: Get_Circle_y() const{
    return y;
}

float circulo:: Get_Circle_R() const{
    return radio* radio;
}
