#pragma once 
#include "iostream"

class punto
{
private:
    float x;
    float y;
public:
    punto(float x, float y); //posiicon
    //Setter
    void Setpunto_x(float nuevo_x);
    void Setpunto_y(float nuevo_y);
    //Get
    float Get_punto_x() const;
    float Get_punto_y() const;

    ~punto()=default;
};
