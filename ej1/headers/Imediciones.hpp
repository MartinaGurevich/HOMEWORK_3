#pragma once
#include "iostream"
#include "fstream"
#include <memory>

using namespace std; 

class Imediciones
{
public:
    virtual void serializar( ofstream& out)const = 0;
    virtual void deserializar(ifstream& in) =0;
    virtual ~Imediciones()= default;
};
