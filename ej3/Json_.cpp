#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

//defino tipos de datos 
// using vecDT= vector<double>;
using paso_aString= vector<string>;
// using listasDT=  vector<vector<int>>;

//CLASE 1
//generic template
template<typename T> //deberia tener un vector aca que le meta los tipos T , y en l¿clase dos hago agregacion de los vectores 
class generadora {
private: 
    vector<T> vect_tipo; //vector que se va llenando 
public:

    void agregar(const T& dato){
        vect_tipo.push_back(dato);
    }

    void construir_Json(const string& etiqueta)const {
        if constexpr(is_same_v<T, vecDT>){
            /*cout<<" \""<<etiqueta<<"\*/" :  [";
            for (size_t i=0; i< vect_tipo.size(); i++){
                cout<<vect_tipo[i];
                if( i!= vect_tipo.size() -1) {cout << ", ";}
                else{cout<<"],\n";
                }

            //";
        }
        }
        else if constexpr(is_same_v<T, PalabrasDT>){
            /*cout<<"  \""<<etiqueta<<"\*/ " : [";
            for (size_t i=0; i< datos.size(); ++i){
                cout<<"\""<<datos[i]<<"\"";
                if(i< datos.size()-1){
                    cout<< ",";
                }else{
                    cout<<"],\n";
                } 
        }
        }
        else if constexpr(is_same_v<T, listasDT>){
            
            /*cout<<"  \""<<etiqueta<<"\*/" :[\n";
            for (size_t i=0; i< datos.size();++i){
                cout <<"          [";
                cout<< datos[i][0]<< "," <<datos[i][1];
                cout<< "]";
                if( i!= datos.size() -1) cout << ",";
                cout<<"\n";
            }
            cout<< "         ]\n";
        } 
        else{
            cout<<"guardar un vector de tipo no definido"<<endl;
        }

    }
};

//CLASE 2
template<typename T>
class creadoraJson { //se pasa como atributo private la clase 1 y ahi se llama y se concatena con la etiqueta correspondiente 
private:

    generadora crear;

public:
    template<typename T>
    void agregar_vect(const string& etiqueta,const T& datos){
        auto gen= make_shared<generadora<T>>(); //me creo obj de clase gen
        gen->agregar(datos);
        vect.push_back({etiqueta, gen}); 
    } //NO VA VA EN CLASE 1 

    void printJson(){
        cout<<"{";
        for(size_t i=0; i< vect.size(); ++i){
            vect[i].second->construir_Json(vect[i].first); //dereferencio para entrar al derivado de la base
        }
        cout<<"}\n";
    }

};
