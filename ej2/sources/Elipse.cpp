#include "Elipse.hpp"

Elipse:: Elipse( float x,float y, float a,float b): x(x), y(y), a(a), b(b){};


void Elipse:: SetElip_x(float nuevo_x){
    x=nuevo_x;
}
void Elipse:: SetElip_y(float nuevo_y){
    y=nuevo_y;
}
void Elipse:: SetElip_a(float nuevo_a){
    a=nuevo_a;
}
void Elipse:: SetElip_b(float nuevo_b){
    b=nuevo_b;
}

float Elipse:: Get_Elip_x() const{
    return x;
}
float Elipse:: Get_Elip_y() const{
    return y;
}
float Elipse:: Get_Elip_a()const{
    return a;
}
float Elipse:: Get_Elip_b()const{
    return b;
}