#include <iostream>
#include <string>
#include <vector>
using namespace std;

//defino tipos de datos 
using vecDT= vector<double>;
using PalabrasDT= vector<string>;
using listasDT=  vector<vector<int>>; 

//CLASE 1
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
        if constexpr(is_integral_v<typename listasDT::value_type::value_type>){
            cout<<"Es un vector de enteros"<<endl;
        } else{
            cout<<"No es un vector de enteros"<<endl;
        }

    }
};

//CLASE 2
class creadoraJson{
public:
    void mostrarVec_double(const vecDT& vec){
        cout<<"\"vec_doubles\": [";
        for (size_t i=0; i< vec.size(); ++i){
            cout<<vec[i];
            if(i < vec.size() -1){
                cout<< ",";
            }
        }
        cout<<"],\n";
        
    }
    void mostrar_pal(const PalabrasDT& pal){
        cout<<"\"palabras\": [";
        for (size_t i=0; i< pal.size(); ++i){
            cout<<"\""<<pal[i]<<"\"";
            if(i< pal.size()-1){
                cout<< ", ";
            }
        }
        cout<< "],\n";
    }

    void mostrar_lista(const listasDT& li){
        cout<<"\"listas\": [\n";
        for (size_t i=0; i< li.size();++i){
            cout <<"[";
            cout<< li[i][0]<< "," <<li[i][1];
            cout<< "]";
            if( i!= li.size() -1) cout << ",";
            cout<<"\n";
            }
        cout<< "]\n";
        }

    void printJson(const vecDT& vector_double,const PalabrasDT& palabras,const listasDT& lista_int){
        cout<<"{ ";
        mostrarVec_double(vector_double);
        mostrar_pal(palabras);
        mostrar_lista(lista_int);
        cout<<"}";
    }
};


int main(){
    creadoraJson print;
    //defino vec
    vecDT vect_double{1.3,2.1,3.2};
    PalabrasDT pal{"Hola","Mundo"};
    listasDT enteros;
    enteros={
        {1,2},
        {3,4}
    };
    
    print.printJson(vect_double, pal,enteros);
}