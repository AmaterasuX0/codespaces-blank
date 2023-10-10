using namespace std;
#include <iostream>
#include <string>
#include<vector>
#include "software.h"
#include"juego.cpp"
#include"produccion.cpp"
#include"navegador.cpp"
#include"seguridad.cpp"
#include"ofimatica.cpp"
#include"social.cpp"
#pragma once
//////Se crea clase biblioteca, que mediante vectores almacena cada tipo de software.
class biblioteca{
     private:
        vector<juego>listaJuegos;
        vector<ofimatica>listaOfimatica;
        vector<produccion>listaProd;
        vector<navegador>listaNav;
        vector<social>listaSocial;
        vector<seguridad>listaSeg;
    public:
        biblioteca();
        vector<juego> getListaJuego(){return listaJuegos;};
        vector<ofimatica> getListaOfi(){return listaOfimatica;}
        vector<produccion> getListaProd(){return listaProd;}
        vector<navegador> getListaNav(){return listaNav;}
        vector<social> getListaSocial(){return listaSocial;}
        vector<seguridad>getListaSeg(){return listaSeg;}

        //Setters que establecen los vectores correspondientes
        void setListaJuego(vector<juego>);
        void setListaOfimatica(vector<ofimatica>);
        void setListaProd(vector<produccion>);
        void setListaNav(vector<navegador>);
        void setListaSocial(vector<social>);
        void setListaSeg(vector<seguridad>);

        //Funcion que crea y añade software a la biblioteca general.
        void addNewSoftware();

        //Funciones que añaden software a su respectiva lista dentro de la biblioteca.
        void addGame(juego);
        void addOfi(ofimatica);
        void addProd(produccion);
        void addNav(navegador);
        void addSocial(social);
        void addSeg(seguridad);

        //Funciones que muestran y permite "usar" software.
        void getSoftware();
        void deleteSoftware();
        void useSoftware(int,string);

   

};








