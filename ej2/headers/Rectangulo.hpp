#pragma once 
#include "iostream"

class Rectángulo
{
private:
    //pos de su vertice izq inferior
    float vertice_posx;
    float vertice_posy;
    float ancho;
    float largo;
public:
    Rectángulo(float vertice_posx, float vertice_posy, float ancho, float largo);
    
    //Setter
    void SetRect_x(float nuevo_x);
    void SetRect_y(float nuevo_y);
    void SetRect_ancho(float nuevo_ancho);
    void SetRect_largo(float nuevo_largo);
    //Get
    float Get_Rect_x() const;
    float Get_Rect_y() const;
    float Get_Rect_ancho() const;
    float Get_Rect_largo() const;
    
    
    ~Rectángulo()=default;
};