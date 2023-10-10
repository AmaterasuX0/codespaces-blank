using namespace std;
#include"software.h"
#include <iostream>
#include <string>
#pragma once
////Se crea clase produccion, derivada de software.
class produccion:public software{
    private:
        string solucion;
    public:
        produccion(string,string,int,int,string);
        string getSolucion(){return solucion;};
        void producir(int edad){ 
            if (edad<18){
                cout<<"Acceso restringido. Aplicacion solo para mayores de edad."<<endl;
        }
        else{
            cout<<"Se accedió a: "<<getNombre()<<endl;
        }
        }
        void toString(){cout<<"Nombre: "<<getNombre()<<"|Developer: "<<getDeveloper()<<"|Edad: "<<getMinEdad()<<"|Precio: "<<getPrecio()<<"|Solucion: "<<getSolucion()<<endl;}
};