using namespace std;
#include <string>
#include <vector>
#pragma once
//se crea la clase padre, Software
class software{
    private:
        string nombre;
        string developer;
        int edad;
        int precio;
    public:
        software(string,string,int,int);
        string getNombre(){return nombre;};
        string getDeveloper(){return developer;};
        int getMinEdad(){return edad;};
        int getPrecio(){return precio;};
        void toString();
};