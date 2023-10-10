#include"user.h"
user::user(string nombreuser,string passuser,int edaduser,string emailuser,string typeuserx){
    username=nombreuser;
    pass=passuser;
    edad=edaduser;
    email=emailuser;
    typeuser=typeuserx;
}
//Funcion que muestra el software del usuario, enlazando con la funcion de biblioteca que muestra software.
void user::getMySoftware(){
    b.getSoftware();
}
//Funcion que entrega el email
//Funciones que añaden software a la biblioteca del usuario.
void user::addGame(juego j){
    b.addGame(j);
}
void user::addOfi(ofimatica o){
    b.addOfi(o);
}
void user::addProd(produccion p){
    b.addProd(p);
}
void user::addNav(navegador n){
    b.addNav(n);
}
void user::addSocial(social s){
    b.addSocial(s);
}
//funcion que imprime los datos del usuario
void user::toString(){
    cout<<"Nombre: "<<getName()<<"|Contraseña: "<<getPass()<<"|Edad: "<<getEdad()<<"|Email: "<<getEmail()<<"|Tipo de Usuario: "<<gettypeUser()<<endl;
}