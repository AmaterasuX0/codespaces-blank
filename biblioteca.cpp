#include"biblioteca.h"
biblioteca::biblioteca(){
    listaJuegos=vector<juego>();
    listaOfimatica=vector<ofimatica>();
    listaProd=vector<produccion>();
    listaNav=vector<navegador>();
    listaSocial=vector<social>();
    listaSeg=vector<seguridad>();
}
////////////////////// Se imprimen los nombres de los distintos software que maneja el usuario o bien todos los disponibles, distribuidos en sus respectivas listas.
void biblioteca::getSoftware(){
    cout<<"Elegir tipo de software:\nA)Juego\nB)Ofimatica\nC)Produccion\nD)Navegadores\nE)Social\nF)Seguridad";
    char opt;cin>>opt;opt=toupper(opt);
    if(opt=='A'){
        for(int i=0;i<listaJuegos.size();i++){
        cout<<listaJuegos[i].getNombre()<<endl;
    }
    }
    if(opt=='B'){
        for(int i=0;i<listaOfimatica.size();i++){
            cout<<listaOfimatica[i].getNombre()<<endl;
    }
    }
    if(opt=='C'){
        for(int i=0;i<listaProd.size();i++){
        cout<<listaProd[i].getNombre()<<endl;
    }
    }
    if(opt=='D'){
        for(int i=0;i<listaNav.size();i++){
        cout<<listaNav[i].getNombre()<<endl;
    }
    }
    if(opt=='E'){
        for(int i=0;i<listaSocial.size();i++){
        cout<<listaSocial[i].getNombre()<<endl;
    }
    }

}

/////////Funcion que añade software nuevo a la biblioteca.
void biblioteca::addNewSoftware(){ ///añade software a la biblioteca general
 cout<<"Elegir tipo de software:\nA)Juego\nB)Ofimatica\nC)Produccion\nD)Navegadores\nE)Social";
    char opt;cin>>opt;opt=toupper(opt);
    if(opt=='A'){
        string nombre;
        cout<<"Nombre del juego:"<<endl;
        cin.ignore();
        getline(cin,nombre);
        cout<<"Nombre del desarrollador:"<<endl;
        cin.ignore();
        string developer;getline(cin,developer);
        cout<<"Edad minima:"<<endl;
        int edad;cin>>edad;
        cout<<"Precio del producto:"<<endl;
        int precio;cin>>precio;
        cout<<"Genero del Juego"<<endl;
        cin.ignore();
        string genero;getline(cin,genero);
        juego j=juego(nombre,developer,edad,precio,genero);
        listaJuegos.push_back(j);
    }
    if(opt=='B'){
        cout<<"Nombre del programa"<<endl;
        string nombre;
        cin.ignore();
        getline(cin,nombre);
        cout<<"Nombre del desarrollador:"<<endl;
        cin.ignore();
        string developer;
        getline(cin,developer);
        cout<<"Edad minima;"<<endl;
        int edad;cin>>edad;
        cout<<"Precio del producto"<<endl;
        int precio;cin>>precio;
        ofimatica o=ofimatica(nombre,developer,edad,precio);
        listaOfimatica.push_back(o);
    }
    if(opt=='C'){
        cout<<"Nombre del programa"<<endl;
        cin.ignore();
        string nombre;
        getline(cin,nombre);
        cout<<"Nombre del desarrollador"<<endl;
        cin.ignore();
        string developer;
        getline(cin,developer);
        cout<<"Edad minima automatica es 18"<<endl;
        cout<<"Precio del producto"<<endl;
        int precio;cin>>precio;
        cout<<"Tipo:"<<endl;
        cin.ignore();
        string tipo;
        getline(cin,tipo);
        produccion p=produccion(nombre,developer,18,precio,tipo);
        listaProd.push_back(p);
    }
    if(opt=='D'){
        cout<<"Nombre del programa"<<endl;
        cin.ignore();
        string nombre;
        getline(cin,nombre);
        cout<<"Nombre del desarrollador"<<endl;
        cin.ignore();
        string developer;
        getline(cin,developer);
        cout<<"Edad minima"<<endl;
        int edad;cin>>edad;
        cout<<"Precio"<<endl;
        int precio;cin>>precio;
        navegador n=navegador(nombre,developer,edad,precio);
        listaNav.push_back(n);
    }
    if(opt=='E'){
        cout<<"Nombre del programa"<<endl;
        cin.ignore();
        string nombre;
        getline(cin,nombre);
        cout<<"Nombre del desarrollador"<<endl;
        string developer;
        getline(cin,nombre);
        cout<<"Edad minima"<<endl;
        int edad;cin>>edad;
        cout<<"Precio"<<endl;
        int precio;cin>>precio;
        social s=social(nombre,developer,edad,precio);
        listaSocial.push_back(s);

    }

}
//borra software 
void biblioteca::deleteSoftware(){
    cout<<"Elegir tipo de software:\nA)Juego\nB)Ofimatica\nC)Produccion\nD)Navegadores\nE)Social";
    char opt;cin>>opt;opt=toupper(opt);
    if(opt=='A'){
        cout<<"Nombre del juego"<<endl;
        cin.ignore();
        string name;getline(cin,name);
        for(int i=0;i<listaJuegos.size();i++){
            if(name==listaJuegos[i].getNombre()){
                listaJuegos.erase(listaJuegos.begin()+i);
                cout<<"Se ha eliminado con exito";
            }
        }
    }
    if(opt=='B'){
        cout<<"Nombre del programa";
        cin.ignore();
        string name;getline(cin,name);
        for(int i=0;i<listaOfimatica.size();i++){
            listaOfimatica.erase(listaOfimatica.begin()+i);

        }
    }
    if(opt=='C'){}
    if(opt=='D'){}
    if(opt=='E'){}
    if(opt=='F'){}
    
}
//funcion que "utiliza" software de la biblioteca general
void biblioteca::useSoftware(int edad,string usertype){
    cout<<"Elegir tipo de software:\nA)Juego\nB)Ofimatica\nC)Produccion\nD)Navegadores\nE)Social\nF)Seguridad";
    char opt;cin>>opt;opt=toupper(opt);
    if(opt=='A'){
        for(int i=0;i<listaJuegos.size();i++){
        cout<<listaJuegos[i].getNombre()<<endl;}
        cin.ignore();
        string game;
        getline(cin,game);
            for(int j=0;j<listaJuegos.size();j++){
                if(game==listaJuegos[j].getNombre()){
                    listaJuegos[j].jugar();
                }
            }
    
    }
    if(opt=='B'){
        for(int i=0;i<listaOfimatica.size();i++){
            cout<<listaOfimatica[i].getNombre()<<endl;}
            cin.ignore();
            string ofi;
            getline(cin,ofi);
            for(int j=0;j<listaOfimatica.size();j++){
                if(ofi==listaOfimatica[j].getNombre()){
                    listaOfimatica[j].usar();
                    break;}
            }
    }
    
    if(opt=='C'){
        for(int i=0;i<listaProd.size();i++){
        cout<<listaProd[i].getNombre()<<endl;}
        cin.ignore();
        string prod;
        getline(cin,prod);
        for(int j=0;j<listaProd.size();j++){
            if(prod==listaProd[j].getNombre()){
                listaProd[j].producir(edad);
                break;
            }
        }
    }
    if(opt=='D'){
        for(int i=0;i<listaNav.size();i++){
        cout<<listaNav[i].getNombre()<<endl;}
        cin.ignore();
        string nav;
        getline(cin,nav);
        for(int j=0;j<listaNav.size();j++){
            if(nav==listaNav[j].getNombre()){
                listaNav[j].usar();
            }
        }
    }
    if(opt=='E'){
        for(int i=0;i<listaSocial.size();i++){
        cout<<listaSocial[i].getNombre()<<endl;}
        cin.ignore();
        string social;
        getline(cin,social);
        for(int j=0;j<listaSocial.size();j++){
            if(social==listaSocial[j].getNombre()){
                listaSocial[j].usar();
            }
        }
    }
    if(opt=='F'){
        for(int i=0;i<listaSeg.size();i++){
            cout<<listaSeg[i].getNombre();
        }
        cin.ignore();
        string seg;
        getline(cin,seg);
        for(int j=0;j<listaSeg.size();j++){
            if(seg==listaSeg[j].getNombre()){
                listaSeg[j].usar(usertype);
            }
        }
    }
}
//funciones que sirven para ingresar software a la biblioteca del usuario
void biblioteca::addGame(juego j){
    listaJuegos.push_back(j);
}
void biblioteca::addOfi(ofimatica o){
    listaOfimatica.push_back(o);
} 
void biblioteca::addProd(produccion p){
    listaProd.push_back(p);
}
void biblioteca::addNav(navegador n){
    listaNav.push_back(n);
}
void biblioteca::addSeg(seguridad s){
    listaSeg.push_back(s);
}
void biblioteca::addSocial(social s){
    listaSocial.push_back(s);
}



void biblioteca::setListaJuego(vector<juego>lj){
    listaJuegos=lj;
}
void biblioteca::setListaNav(vector<navegador>ln){
    listaNav=ln;
}
void biblioteca::setListaOfimatica(vector<ofimatica>lo){
    listaOfimatica=lo;
}
void biblioteca::setListaProd(vector<produccion>lp){
    listaProd=lp;
}
void biblioteca::setListaSeg(vector<seguridad>ls){
    listaSeg=ls;
}
void biblioteca::setListaSocial(vector<social>lss){
    listaSocial=lss;
}