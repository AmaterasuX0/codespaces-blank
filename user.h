using namespace std;
#include <iostream>
#include <string>
#include"biblioteca.h"
#pragma once

class user{
 private:
        string username;
        string pass;
        int edad;
        string email;
        string typeuser;
        biblioteca b;
        
    public:
        user(string,string,int,string,string);
        string getName(){return username;};
        string getPass(){return pass;};
        int getEdad(){return edad;};
        string getEmail(){return email;};
        string gettypeUser(){return typeuser;};
        //funcion que retorna la biblioteca personal
        biblioteca getLibrary(){return b;};
        //funcion que imprime el software de la biblioteca personal
        void getMySoftware();
        //funciones que añaden software respectivo a la biblioteca.
        void addGame(juego);
        void addOfi(ofimatica);
        void addProd(produccion);
        void addNav(navegador);
        void addSeg(seguridad);
        void addSocial(social);
        //funcion que imprime los datos del usuario
        void toString();        
};