using namespace std;
#include"software.h"
#include <iostream>
#include <string>
#pragma once
class seguridad:public software{
    private:
        string tipo;
    public:
        seguridad(string,string,int,int,string);
        string getTipo(){return tipo;};
        void usar(string typeuser){
             if(typeuser!="admin"){
                cout<<"Acceso restringido.\nNo tienes permisos de administrador"<<endl;
            }
            else if(typeuser=="admin"){
                cout<<"Usando "<<getNombre()<<endl;
            }
        }
        void toString(){cout<<"Nombre: "<<getNombre()<<"|Developer: "<<getDeveloper()<<"|Edad: "<<getMinEdad()<<"|Precio: "<<getPrecio()<<"|Tipo de seguridad: "<<getTipo()<<endl;}
};