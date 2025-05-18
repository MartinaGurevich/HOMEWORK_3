#include <iostream>
#include <string>
#include <vector>
using namespace std;

//defino tipos de datos 
using vecDT= vector<double>;
using PalabrasDT= vector<string>;
using listasDT=  vector<vector<int>>; 

//generic template
template<typename T>
class generadora {
public:
    void construir_Json(const T& tipo){
        cout<<"guardar un vector de tipo no definido"<<endl;
    }
};

template<>
class generadora<vecDT>{
public:
    void construir_Json(const vecDT& vec){
        cout<<"\"vec_doubles\":";
        if constexpr(is_same_v<typename vecDT:: value_type,double>){
            cout<<"Es un double"<<endl;
        } else{
            cout<<"No es un double"<<endl;
        }

    }
};

template<>
class generadora<PalabrasDT>{
public:
    void construir_Json(const PalabrasDT& pal){
        cout<<"\"palabras\":";
        if constexpr(is_same_v<typename PalabrasDT:: value_type,string>){
            cout<<"Es un vector de string"<<endl;
        } else{
            cout<<"No es un vector de string"<<endl;
        }

    }
};


template<>
class generadora<listasDT>{
public:
    void construir_Json(const listasDT& li){
        cout<<"\"listas\":[\n"; //esto creo q va dsp cuadno creo el archivo...
        if constexpr(is_integral_v<typename listasDT::value_type::value_type>){
            cout<<"Es un vector de enteros"<<endl;
        } else{
            cout<<"No es un vector de enteros"<<endl;
        }

    }
};

