using namespace std;
#include"software.h"
#include <iostream>
#include <string>
#pragma once
class navegador:public software{
    private:
        string historial[10];
    public:
        navegador(string,string,int,int);
        string getHistorial(){return "ARREGLAR";};
        void addPagina(string);
        void clearHistorial();
        void usar(){
            cout<<"Navegando en "<<getNombre()<<endl;
           
        }
        void toString(){cout<<"Nombre: "<<getNombre()<<"|Developer: "<<getDeveloper()<<"|Edad: "<<getMinEdad()<<"|Precio: "<<getPrecio()<<endl;}
};