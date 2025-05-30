#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

//CLASE 1
template<typename T> 
class generadora {
private: 
    vector<T> vect_tipo; //vector que se va llenando 
public:

    void agregar(const T& dato){
        vect_tipo.push_back(dato);
    }


    string construir_Json() const { //funcion que convierte vec a str
       ostringstream pasaje;

        if constexpr(is_same_v<T, double>){
            pasaje <<"[";
            for (size_t i=0; i< vect_tipo.size(); ++i){
                pasaje <<vect_tipo[i];
                if( i < vect_tipo.size() -1) pasaje<<", ";
            }
            pasaje <<"]"; 
        }
        else if constexpr(is_same_v<T, string>){
            pasaje<<"[";
            for (size_t i=0; i< vect_tipo.size(); ++i){
                pasaje<<"\""<<vect_tipo[i]<<"\"";
                if(i< vect_tipo.size()-1) pasaje<< ",";  
            } 
            pasaje<<"]";
        }

        else if constexpr(is_same_v<T, vector<int>>){
            pasaje<<"[\n";
            for (size_t i=0; i< vect_tipo.size();++i){
                pasaje <<"           [";
                for (size_t j=0; j< vect_tipo[i].size();++j){
                    pasaje<< vect_tipo[i][j];
                    if( j < vect_tipo.size() -1) pasaje << ",";
                }
                pasaje<<"]";
                if( i < vect_tipo.size() -1) pasaje << ",";
                pasaje<<"\n";
            }

            pasaje<< "           ]\n";
        }

        return pasaje.str();
    } 
};

//CLASE 2
class creadoraJson { 
private:
    vector<string> etiquetas;
    vector<string> contenidos;
public:
    template <typename T>
    void unir(const string& etiqueta, const generadora<T>& elem){ //segundo argumento es objeto de la clase 1, se pasa en el main para unir etiqueta con vector
        etiquetas.push_back(etiqueta);
        contenidos.push_back(elem.construir_Json());

    }

    void printJson()const {
        cout<<"{";
        for(size_t i=0; i< etiquetas.size(); ++i){
            cout<<" ";
            cout<< "  \""<<etiquetas[i]<<"\":"<< contenidos[i]; 
            if(i < etiquetas.size()-1) cout<< ",";
            cout<<"\n";
        }
       
        cout<<"}\n";
    }

};

int main(){
    
    //vector de doubles
    generadora <double> vectorD;
    vectorD.agregar({1.3});
    vectorD.agregar({2.1});
    vectorD.agregar({3.2});
    //vector de str
    generadora <string> vectorS;
    vectorS.agregar({"Hola"});
    vectorS.agregar({"Mundo"});
    //lista de vector de ints
    generadora <vector<int>> vectorL;
    vectorL.agregar({1,2});
    vectorL.agregar({3,4});

    //creo json
    creadoraJson crear;
    crear.unir("vec_doubles",vectorD);
    crear.unir("palabras",vectorS);
    crear.unir("listas",vectorL);

    crear.printJson();

    return 0;
}