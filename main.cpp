#include <iostream>
#include <stdlib.h>
#include <vector>
#include <list>
#include"biblioteca.cpp"
#include"user.cpp"
using namespace std;

///Funcion login, ingresa como parametro un vector de usuarios y retorna el indice del usuario dentro de la lista de usuarios, si no encuentra al usuario retorna -1.
int login(vector<user>listaUsuarios){
    int log=-30;
    cout<<"Nombre de usuario:"<<endl;
    string username;getline(cin,username);
    int cont=0;
    cout<<"Contraseña"<<endl;
    string pass;getline(cin,pass);
    for(int i=0;i<listaUsuarios.size();i++){
        if(listaUsuarios[i].getName()!=username){
            cont++;}
        if(cont==listaUsuarios.size()){
            cout<<"Usuario no encontrado"<<endl;
            log=-1;
            break;}

        else if(username==listaUsuarios[i].getName()&&pass==listaUsuarios[i].getPass()){
            cout<<"Ingreso correcto";
            log=i;
        }
    }
    return log;

    
}

////funcion que despliega el menu.
void menu(biblioteca bgeneral,vector<user>lu){
    int entrada=login(lu);
    if(entrada==-1){cout<<"ADIOS"<<endl;}
    else{
    user u=lu[entrada];
    cout<<"------------MENU---------------"<<endl;
    while(entrada!=-1){
        cout<<"1)Ver Software\n2)Usar Software\n3)Agregar Programa a mi Biblioteca\n4)Agregar Programa a Biblioteca General\n5)Eliminar programa\n6)Ver mi Software\n7)Cerrar Sesion"<<endl;
        int opt;cin>>opt;
        cin.ignore();
        switch(opt){
            //se muestran todos los software segun el tipo.
            case 1:
                bgeneral.getSoftware();
                break;
            //usuario escoge una aplicacion para "ejecutarla".
            case 2: 
                bgeneral.useSoftware(u.getEdad(),u.gettypeUser());
                break;
            //se pregunta tipo de software a añadir, se muestran todas las opciones de la biblioteca general y el usuario escoge cual añadir a su biblioteca.
            case 3:{ 
                cout<<"Elegir tipo de software:\nA)Juego\nB)Ofimatica\nC)Produccion\nD)Navegadores\nE)Social\nF)Seguridad";
                char opt2;cin>>opt2;opt2=toupper(opt2);
                if(opt2=='A'){
                    for(int i=0;i<bgeneral.getListaJuego().size();i++){
                        cout<<bgeneral.getListaJuego()[i].getNombre()<<endl;}
                         cin.ignore();
                         string game;
                         getline(cin,game);
                         for(int j=0;j<bgeneral.getListaJuego().size();j++){
                             if(game==bgeneral.getListaJuego()[j].getNombre()){
                                cout<<"se ha añadido: "<<bgeneral.getListaJuego()[j].getNombre()<<" a tu biblioteca"<<endl;
                                    u.addGame(bgeneral.getListaJuego()[j]);
                                  }
                 }
                }
                if(opt2=='B'){
                    for(int i=0;i<bgeneral.getListaOfi().size();i++){
                        cout<<bgeneral.getListaOfi()[i].getNombre()<<endl;
                    }
                    cin.ignore();
                    string ofiname;
                    getline(cin,ofiname);
                    for(int j=0;j<bgeneral.getListaOfi().size();j++){
                        if(ofiname==bgeneral.getListaOfi()[j].getNombre()){
                            cout<<"Se ha añadido: "<<bgeneral.getListaOfi()[j].getNombre()<<" a tu biblioteca"<<endl;
                            u.addOfi(bgeneral.getListaOfi()[j]);
                        }
                    }
                }
                if(opt2=='C'){
                    for(int i=0;i<bgeneral.getListaProd().size();i++){
                        cout<<bgeneral.getListaProd()[i].getNombre()<<endl;
                    }
                    cin.ignore();
                    string prodname;
                    getline(cin,prodname);
                    for(int j=0;j<bgeneral.getListaProd().size();j++){
                        if(prodname==bgeneral.getListaProd()[j].getNombre()&&u.getEdad()>18){
                            cout<<"Se ha añadido "<<bgeneral.getListaProd()[j].getNombre()<<" a tu biblioteca"<<endl;
                            u.addProd(bgeneral.getListaProd()[j]);
                        }
                        else if(u.getEdad()<18){
                            cout<<"No puedes agregarlo a tu biblioteca. Solo para mayores de 18 años"<<endl;
                            break;
                        }
                    }
                }
                if(opt2=='D'){
                    for(int i=0;i<bgeneral.getListaNav().size();i++){
                        cout<<bgeneral.getListaNav()[i].getNombre();
                    }
                    cin.ignore();
                    string navname;
                    getline(cin,navname);
                    for(int j=0;j<bgeneral.getListaNav().size();j++){
                        if(navname==bgeneral.getListaNav()[j].getNombre()){
                            cout<<"Se ha añadido "<<bgeneral.getListaNav()[j].getNombre()<<" a tu biblioteca"<<endl;
                            u.addNav(bgeneral.getListaNav()[j]);
                        }
                    }
                }
                if(opt2=='E'){
                    for(int i=0;i<bgeneral.getListaSocial().size();i++){
                        cout<<bgeneral.getListaSocial()[i].getNombre()<<endl;
                    }
                    cin.ignore();
                    string socialname;
                    getline(cin,socialname);
                    for(int j=0;j<bgeneral.getListaSocial().size();j++){
                        if(socialname==bgeneral.getListaSocial()[j].getNombre()){
                            cout<<"Se ha añadido "<<bgeneral.getListaSocial()[j].getNombre()<<" a tu biblioteca"<<endl;
                            u.addSocial(bgeneral.getListaSocial()[j]);
                        }
                    }
                }
                if(opt2=='F'){
                    for(int i=0;i<bgeneral.getListaSeg().size();i++){
                        cout<<bgeneral.getListaSeg()[i].getNombre()<<endl;;
                    }
                    cin.ignore();
                    string segname;
                    getline(cin,segname);
                    for(int j=0;j<bgeneral.getListaSeg().size();j++){
                        if(segname==bgeneral.getListaSeg()[j].getNombre()&&u.gettypeUser()=="admin"){
                            cout<<"Se ha añadido "<<bgeneral.getListaSeg()[j].getNombre()<<" a tu biblioteca"<<endl;
                        }
                        else if(u.gettypeUser()=="normal"){
                            cout<<"No puedes agregarlo a tu biblioteca. Unico para administrador"<<endl;
                            break;
                        }
                    }
                }
            
                 break;
            }
            case 4:
            //se añade nuevo software
             bgeneral.addNewSoftware();
                break;
            case 6:
            //se muestran los software por tipo del usuario.
                u.getMySoftware();
                break;
            case 5:
                cout<<"Nada por acá......"<<endl;
                break;
            case 7:
            //cierre de sesion y cambio de usuario, de no encontrar el usuario el programa termina.
                cout<<"Saliendo...."<<endl;
                entrada=login(lu);
                if(entrada==-1){break;}
                else{
                u=lu[entrada];
                break;}
            default: //en caso de escoger un indice de menu no disponible.
                cout<<"Opcion no valida. Intentar denuevo"<<endl;
                break;
        }
    }



    }
}
////////////////////////////////////////////////////////////////////////////

int main(){
    //Se crean 20 juegos
    juego j1=juego("League of Legends","Riot Games",13,0,"MOBA");
    juego j11=juego("DOTA 2","Valve Corporation",13,0,"MOBA");
    juego j2=juego("GTA V","Rockstar Games",18,28000,"Open World");
    juego j5=juego("GTA San Andreas","Rockstar Games",18,10000,"Open World");
    juego j3=juego("Minecraft","Mojang Studios",10,20000,"Survival");
    juego j4=juego("God of War","Santa Monica Studio",18,35000,"Accion");
    juego j9=juego("Marvel's Spiderman","Insomniac Games",13,42.000,"Accion");
    juego j6=juego("The Witcher 3: Wild Hunt","CD Projekt",18,16300,"Rol de Accion");
    juego j7=juego("The Elder Scrolls V:Skyrim","Bethesda",18,26990,"Rol de Accion");
    juego j8=juego("FIFA 24","EA Sports",8,55990,"Deportes");
    juego j10=juego("NBA 2K24","2K Games",8,48990,"Deportes");
    juego j12=juego("World of Warcraft","Blizzard Entertainment",13,10000,"MMO");
    juego j13=juego("Lost Ark","Tripod Studio",18,0,"MMO");
    juego j14=juego("Call of Duty:Black Ops 2","Treyarch",18,32900,"FPS");
    juego j15=juego("Counter Strike","Valve Corporation",18,4400,"FPS");
    juego j16=juego("The Talos Principle","Croteam",13,15500,"PUZZLE");
    juego j17=juego("Portal 2","Valve Corporation",10,5750,"PUZZLE");
    juego j18=juego("Rust","Facepunch Studios",18,17900,"Survival");
    juego j19=juego("Sims 4","Maxis",8,0,"Simulacion");
    juego j20=juego("Football Manager 2023","British developer Sports Interactive",8,39000,"Simulacion");
   
    //Se crean 5 software de ofimatica
    ofimatica o1=ofimatica("Power Point","Microsoft",0,139990);
    ofimatica o2=ofimatica("Google Drive","Google",0,7990);
    ofimatica o3=ofimatica("Outlook","Microsoft",0,0);
    ofimatica o4=ofimatica("Microsoft Word","Microsoft",0,139990);
    ofimatica o5=ofimatica("Microsoft Excel","Microsoft",0,139990);
    //Se crean 4 software de produccion
    produccion p1=produccion("Youtube","Google",18,0,"Video");
    produccion p2=produccion("Spotify","Martin Lorentzon",18,0,"Musica");
    produccion p3=produccion("Twitch","Justin Kan",18,0,"Streaming");
    produccion p4=produccion("Instagram","Kevin Systorm",18,0,"Fotos");
    //Se crean Navegadores
    navegador n1=navegador("Google Chrome","Google",0,0);
    navegador n2=navegador("Mozilla Firefox","Mozilla",0,0);
    //Se crean Software de seguridad
    seguridad s1=seguridad("Kapersky","Eugene Kapersky",0,0,"Troyano");
    seguridad s2=seguridad("Avast","Pavel Daubis",0,0,"Spyware");
    seguridad s3=seguridad("AVG","AVG Technologies",0,0,"Botnet");
    seguridad s4=seguridad("Avira","Tjark Auerbach",0,0,"rootkit");
    seguridad s5=seguridad("Microsoft Security Essentials","Microsoft",0,0,"gusano");
    seguridad s6=seguridad("McAfee","John McAfee",0,0,"Ransomware");
    //Se crean software sociales
    social ss1=social("Facebook","Mark Zuckerberg",13,0);
    social ss2=social("Twitter","Jack Dorsey",13,0);
    //Se crea lista de cada software y se rellena con los software creados
    vector<juego>listaJuegos;
    listaJuegos.push_back(j1);
    listaJuegos.push_back(j2);
    listaJuegos.push_back(j3);
    listaJuegos.push_back(j4);
    listaJuegos.push_back(j5);
    listaJuegos.push_back(j6);
    listaJuegos.push_back(j7);
    listaJuegos.push_back(j8);
    listaJuegos.push_back(j9);
    listaJuegos.push_back(j10);
    listaJuegos.push_back(j11);
    listaJuegos.push_back(j12);
    listaJuegos.push_back(j13);
    listaJuegos.push_back(j14);
    listaJuegos.push_back(j15);
    listaJuegos.push_back(j16);
    listaJuegos.push_back(j17);
    listaJuegos.push_back(j18);
    listaJuegos.push_back(j19);
    listaJuegos.push_back(j20);
    vector<navegador>listaNavegador;
    listaNavegador.push_back(n1);
    listaNavegador.push_back(n2);
    vector<seguridad>listaSeguridad;
    listaSeguridad.push_back(s1);
    listaSeguridad.push_back(s2);
    listaSeguridad.push_back(s3);
    listaSeguridad.push_back(s4);
    listaSeguridad.push_back(s5);
    listaSeguridad.push_back(s6);
    vector<social>listaSocial;
    listaSocial.push_back(ss1);
    listaSocial.push_back(ss2);
    vector<ofimatica>listaOfimatica;
    listaOfimatica.push_back(o1);
    listaOfimatica.push_back(o2);
    listaOfimatica.push_back(o3);
    listaOfimatica.push_back(o4);
    listaOfimatica.push_back(o5);
    vector<produccion>listaProduccion;
    listaProduccion.push_back(p1);
    listaProduccion.push_back(p2);
    listaProduccion.push_back(p3);
    listaProduccion.push_back(p4);
    //se crean usuarios y se completan con software
    user u1=user("Jorge Diaz","123jd123",18,"georgeday@hotmail.com","admin");
    u1.addGame(j1);
    u1.addNav(n1);
    user u2=user("Juan Jeus","jj-0.",22,"yonyisusgmail.com","normal");
    u2.addProd(p2);
    u2.addSocial(ss1);
    u2.addGame(j2);
    user u3=user("Patricia Perez","PPpp.23",23,"paty23@hotmail.com","normal");
    u3.addGame(j20);
    u3.addGame(j17);
    user u4=user("andresito","123456789",18,"aghost@hotmail.com","normal");
    u4.addProd(p4);
    user u5=user("pepe grillo","del1al9",18,"ppgriyo1@gmail.com","normal");
    u5.addGame(j15);
    u5.addGame(j13);
    user u6=user("undertaker","deadman",18,"umdertarkerwwe@hotmail.com","normal");
    u6.addSocial(ss2);
    user u7=user("darth vader","padme<3",42,"lordsith@gmail.com","normal");
    u7.addOfi(o3);
    user u8=user("anakin skywalker","masternot",22,"a&p4e@hotmail.com","normal");
    u8.addGame(j7);
    u8.addGame(j3);
    user u9=user("Itachi Uchiha","amaterasu",21,"itachianbu@gail.com","normal");
    u9.addOfi(o1);
    user u10=user("Pablo Diaz","ContraseñaSegura.0",33,"pablouu1@gmail.com","normal");
    u10.addSocial(ss1);
    user u11=user("Alexis Sanchez","atomhumber",16,"as9@hotmail.com","normal");
    u11.addGame(j9);
    user u12=user("Mati Fernandez","14delosblancos",18,"georgeday@hotmail.com","normal");
    u12.addProd(p3);
    user u13=user("Chupete Suazo","venidodelplanetagol",14,"chupetesuazo@hotmail.com","normal");
    u13.addGame(j11);
    user u14=user("Lionel Messi","liomesi10",17,"soymesi@gmail.com","normal");
    u14.addOfi(o2);
    user u15=user("Cristiano Ronaldo","elbicho",13,"cr7rm@hotmail.com","normal");
    u15.addProd(p1);
    vector<user>listaUser;
    listaUser.push_back(u1);
    listaUser.push_back(u2);
    listaUser.push_back(u3);
    listaUser.push_back(u4);
    listaUser.push_back(u5);
    listaUser.push_back(u6);
    listaUser.push_back(u7);
    listaUser.push_back(u8);
    listaUser.push_back(u9);
    listaUser.push_back(u10);
    listaUser.push_back(u11);
    listaUser.push_back(u12);
    listaUser.push_back(u13);
    listaUser.push_back(u14);
    listaUser.push_back(u15);
    //Se crea la biblioteca general, formada por la base de datos creada anteriormente, se asocian las listas de software creadas anteriormente a las que contiene la biblioteca.
    biblioteca b=biblioteca();
    b.setListaJuego(listaJuegos);
    b.setListaNav(listaNavegador);
    b.setListaOfimatica(listaOfimatica);
    b.setListaProd(listaProduccion);
    b.setListaSocial(listaSocial);
    b.setListaSeg(listaSeguridad);
    menu(b,listaUser);
}
    




