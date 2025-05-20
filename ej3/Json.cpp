#include <iostream>
#include <string>
#include <vector>
using namespace std;

//defino tipos de datos 
using vecDT= vector<double>;
using PalabrasDT= vector<string>;
using listasDT=  vector<vector<int>>; 

//hago una clase base para usar polimorfismo con la clase 2. Como en la clase 1, T varia , no puedo guardar sus objetos 
class GeneradoraBase
{
public:
    virtual void construir_Json(const string& etiqueta) const = 0;
    virtual ~GeneradoraBase()= default;
};

//CLASE 1
//generic template
template<typename T>
class generadora: public GeneradoraBase {
private: 
    T datos;

public:

    void agregar(const T& entradas){
        datos= entradas;
    }

    void construir_Json(const string& etiqueta)const override {
        if constexpr(is_same_v<T, vecDT>){
            cout<<"\""<<etiqueta<<"\" : [";
            for (size_t i=0; i< datos.size(); ++i){
                cout<<datos[i];
                if(i < datos.size() -1){
                    cout<< ",";
            }
        }
        }
        else if constexpr(is_same_v<T, PalabrasDT>){
        
            for (size_t i=0; i< datos.size(); ++i){
                cout<<"\""<<datos[i]<<"\"";
                if(i< datos.size()-1){
                    cout<< ", ";
            }
        }
        }
        else if constexpr(is_integral_v<T, listasDT>){
        
            for (size_t i=0; i< datos.size();++i){
                cout <<"          [";
                cout<< datos[i][0]<< "," <<datos[i][1];
                cout<< "]";
                if( i!= datos.size() -1) cout << ",";
                cout<<"\n";
            }
        } 
        else{
            cout<<"guardar un vector de tipo no definido"<<endl;
        }

    }
};

//CLASE 2
class creadoraJson {
public:
    void mostrarVec_double(const vecDT& vec){
        cout<<"\"vec_doubles\" : [";

        // for (size_t i=0; i< vec.size(); ++i){
        //     cout<<vec[i];
        //     if(i < vec.size() -1){
        //         cout<< ",";
        //     }
        // }
        cout<<"],\n";
        
    }
    void mostrar_pal(const PalabrasDT& pal){
        cout<<"  \"palabras\" : [";
  
        cout<< "],\n";
    }

    void mostrar_lista(const listasDT& li){
        cout<<"  \"listas\" : [\n";
        // for (size_t i=0; i< li.size();++i){
        //     cout <<"          [";
        //     cout<< li[i][0]<< "," <<li[i][1];
        //     cout<< "]";
        //     if( i!= li.size() -1) cout << ",";
        //     cout<<"\n";
        //     }
        cout<< "         ]\n";
        }

    void printJson(const vecDT& vector_double,const PalabrasDT& palabras,const listasDT& lista_int){
        cout<<"{ ";
        mostrarVec_double(vector_double);
        mostrar_pal(palabras);
        mostrar_lista(lista_int);
        cout<<"}\n";
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