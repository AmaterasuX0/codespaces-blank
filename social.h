using namespace std;
#include"software.h"
#include <iostream>
#include <string>
#pragma once
class social:public software{
    private:
        int cantUser;
    public:
        social(string,string,int,int);
        int getCantUser(){return cantUser;};
        void usar(){cout<<"Se usó: "<<getNombre()<<endl;};
        void toString(){cout<<"Nombre: "<<getNombre()<<"|Developer: "<<getDeveloper()<<"|Edad: "<<getMinEdad()<<"|Precio: "<<getPrecio()<<endl;}
};