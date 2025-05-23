#include <iostream>
#include <string>
#include <vector>
#include <memory>
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
template<typename T> //deberia tener un vector aca que le meta los tipos T , y en l¿clase dos hago agregacion de los vectores 
class generadora: public GeneradoraBase {
private: 
    T datos;

public:

    void agregar(const T& entradas){
        datos= entradas;
    }

    void construir_Json(const string& etiqueta)const override {
        if constexpr(is_same_v<T, vecDT>){
            cout<<" \""<<etiqueta<<"\" : [";
            for (size_t i=0; i< datos.size(); i++){
                cout<<datos[i];
                if( i!= datos.size() -1) {cout << ", ";}
                else{cout<<"],\n";
                }

        
            //";
        }
        }
        else if constexpr(is_same_v<T, PalabrasDT>){
            cout<<"  \""<<etiqueta<<"\" : [";
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
            
            cout<<"  \""<<etiqueta<<"\" :[\n";
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
class creadoraJson { //se pasa como atributo private la clase 1 y ahi se llama y se concatena con la etiqueta correspondiente 
private:
    vector<pair< string, shared_ptr<GeneradoraBase>>> vect;
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


int main(){
    creadoraJson creador; //deberia poner un obj de la clase 1 y llamar a agregar y vopy agregando con 1.3 otro 2.1 , 3.2
    
    creador.agregar_vect("vec_doubles", vecDT{1.3, 2.1, 3.2});
    creador.agregar_vect("palabras", PalabrasDT{"Hola", "Mundo"});
    creador.agregar_vect("listas", listasDT{{1,2},{3,4}});

    creador.printJson();
}

/* tmbien meto print en clase 1 , bhice uan especie de polimorfismo esta bien ? porque sino no podia tomar herencia de la clase 1 porque es unaa calse template  */

