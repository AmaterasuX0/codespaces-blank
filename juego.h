using namespace std;
#include"software.h"
#include <iostream>
#include <string>
#pragma once
////Se crea la clase juego,derivada de Software
class juego:public software{
    private:
        string genero;
    public:
        juego(string,string,int,int,string);
        juego();
        string getGenero(){return genero;};
        void toString(){cout<<"Nombre:"<<getNombre()<<"|Developer:"<<getDeveloper()<<"|Edad;"<<getMinEdad()<<"|Precio:"<<getPrecio()<<"|Genero"<<getGenero()<<endl;}
        //funcion que imprime jugando mas el nombre del juego
        void jugar(){cout<<"Jugando "<<getNombre()<<endl;};
};