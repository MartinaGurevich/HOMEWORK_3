#include "Rectangulo.hpp"

Rectángulo::Rectángulo(float vertice_posx, float vertice_posy, float ancho, float largo): vertice_posx(vertice_posx), vertice_posy(vertice_posy), ancho(ancho), largo(largo){};

void Rectángulo::SetRect_x(float nuevo_x){
    vertice_posx= nuevo_x;
}

void Rectángulo::SetRect_y(float nuevo_y){
    vertice_posy= nuevo_y;
}
void Rectángulo::SetRect_ancho(float nuevo_ancho){
    ancho= nuevo_ancho;
}
void Rectángulo::SetRect_largo(float nuevo_largo){
    largo= nuevo_largo;
}

float Rectángulo::Get_Rect_x() const{
    return vertice_posx;
}  

float Rectángulo::Get_Rect_y() const{
    return vertice_posy;
}  
float Rectángulo::Get_Rect_ancho() const{
    return ancho;
}  
float Rectángulo::Get_Rect_largo() const{
    return largo;
}  