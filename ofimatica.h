using namespace std;
#include"software.cpp"
#include <iostream>
#include <string>
#pragma once
class ofimatica:public software{
    private:
        int cant;//Numero de archivos
    public:
        ofimatica(string,string,int,int);
        int getCant(){
            return cant;
        };
        void usar(){
            cout<<"Se creó un archivo"<<endl;
        };
        void toString(){cout<<"Nombre: "<<getNombre()<<"|Developer: "<<getDeveloper()<<"|Edad: "<<getMinEdad()<<"|Precio: "<<getPrecio()<<endl;}
};