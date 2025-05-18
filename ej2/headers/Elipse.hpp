#pragma once 
#include "iostream"

class Elipse
{
private:
    float x;
    float y;
    float a;//semieje mayor
    float b; //semieje menor 
public:
    Elipse(  float x,float y, float a,float b);

    //Setter
    void SetElip_x(float nuevo_x);
    void SetElip_y(float nuevo_y);
    void SetElip_a(float nuevo_a);
    void SetElip_b(float nuevo_b);
    //Get
  float Get_Elip_x()const;
  float Get_Elip_y()const;
  float Get_Elip_a()const;
  float Get_Elip_b()const;

    Elipse() = default;
};