#pragma once 
#include "iostream"

class circulo
{
private:
    float radio;
    float x;
    float y;
public:
    circulo(float radio, float x, float y);

    //Setter
    void SetCircle_x(float nuevo_x);
    void SetCircle_y(float nuevo_y);
    void SetCircle_R(float nuevo_r);//set radio
    //Get
   float Get_Circle_x() const;
   float Get_Circle_y() const;
   float Get_Circle_R() const; //get radio

    ~circulo()= default;
};
