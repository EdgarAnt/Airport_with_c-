#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std;

class Nodo{
public:
string nombre;
string viaje;
string maletas;
string fecha;
int numero;
string id;

Nodo *next;
};


void gotoxy(int x,int y){
      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      COORD dwPos;
      dwPos.X = x;
      dwPos.Y= y;
      SetConsoleCursorPosition(hcon,dwPos);
}

bool validar(char numero[]);
void gotoxy(int,int);
bool colaVacia(Nodo *);
void asientos(Nodo *&);
void tabla(Nodo *&);
void pasajero(int rangoTotal, int ban);
void servicio(int);
void arribo();
void funcionDesencolar(int numNodos);
void eliminar(Nodo *&,Nodo *&,int);
void avion();
void avion2();
void uber();
void mostrarUber2();
void push(Nodo *&,Nodo *&,int,string);
void mostrar(Nodo *&);
void desencolarT(int numNodos);

bool colaVacia(Nodo *adelante){
    return (adelante == NULL)? true : false;
};

void eliminar(Nodo *&adelante,Nodo *&fin,int numero_){
numero_ = adelante->numero;
Nodo *aux = adelante;
    if(adelante = fin){
    adelante = NULL;
    fin = NULL;}
    else{
    adelante = adelante->next;}
    delete aux;
};

int CuentaNodosG;

void push(Nodo *&adelante,Nodo *&fin,int numero_,string id_,string nombre_,string viaje_,string fecha_,string maletas_){
Nodo *nuevo_nodo = new Nodo();
nuevo_nodo->numero = numero_;
nuevo_nodo->id = id_;
nuevo_nodo->nombre = nombre_;
nuevo_nodo->viaje = viaje_;
nuevo_nodo->fecha = fecha_;
nuevo_nodo->maletas = maletas_;
nuevo_nodo->next = NULL;
    if(colaVacia(adelante)){
    adelante = nuevo_nodo;}
    else{
    fin->next = nuevo_nodo;}
    fin = nuevo_nodo;
};



void mostrar(Nodo *&adelante){
Nodo *temp = adelante;
    if(temp!=NULL){
    gotoxy(10,5);
      cout<<"  TICKETS"<<endl;
    while(temp!=NULL){
      cout<<"\t"<<temp->numero<<".- "<<"Nombre: "<<temp->nombre<<"  |Maletas: "<<temp->maletas<<" | ";
      temp = temp->next;}
    int band=0;
    servicio(band);
    }
};

void tabla(Nodo *&adelante){
Nodo *temp = adelante;
    if(temp!=NULL){
    gotoxy(10,5);
      cout<<"  Clientes"<<endl;
      cout<<"\t ----------------------------------------"<<endl;
    while(temp!=NULL){
      cout<<"\t-Cliente #|"<<temp->numero<<"|"<<endl;
      cout<<"\t-Nombre: "<<temp->nombre<<endl;
      cout<<"\t-Id: "<<temp->id<<endl;
      cout<<"\t-Viaje: "<<temp->viaje<<endl;
      cout<<"\t-Fecha de vuelo: "<<temp->fecha<<endl;
      cout<<endl<<"\t ----------------------------------------"<<endl;
    temp = temp->next;}
    }
};

void asientos(Nodo *&adelante){
Nodo *temp = adelante;
    if(temp!=NULL){
    gotoxy(10,5);
    cout<<"  Asientos"<<endl;
    cout<<"\t ----------------------------------------"<<endl;
    while(temp!=NULL){
    cout<<"\t |"<<temp->nombre<<"|";
    temp = temp->next;}
    }
};


void avion(){
int i=0, rango=63;
    for(int j=0;j<1;j++){
    for(i=0;i<rango;i++){
    Sleep(100);
    cout<<endl<<endl<<endl<<endl;
gotoxy(i,10); cout<<"              .------,"<<endl;
gotoxy(i,11); cout<<"              =\      \\"<<endl;
gotoxy(i,12); cout<<" .---.         =\      \\"<<endl;
gotoxy(i,13); cout<<" | M~ \\         =\      \\"<<endl;
gotoxy(i,14); cout<<" |     `----------'------'----------,"<<endl;
gotoxy(i,15); cout<<".'     LI.-.LI LI LI LI LI LI LI.-.LI`-."<<endl;
gotoxy(i,16); cout<<"  \\ _/.____|_|______.------,______|_|_____)"<<endl;
gotoxy(i,17); cout<<"                 /      /"<<endl;
gotoxy(i,18); cout<<"               =/      /"<<endl;
gotoxy(i,19); cout<<"              =/      /"<<endl;
gotoxy(i,20); cout<<"             =/      /"<<endl;
gotoxy(i,21); cout<<"             .------,"<<endl;
    }
    }
};


void pasajero(int rangoTotal, int ban, int j){
    gotoxy(rangoTotal,9);cout<<"  "<<j;
    gotoxy(rangoTotal,10);cout<<"  o";
    gotoxy(rangoTotal,11);cout<< " /|\\";
    if(ban==0){
    gotoxy(rangoTotal,12);cout<< " / ";
    ban=1;}
    else{
    gotoxy(rangoTotal,12);cout<< "   \\";
    ban=0;};
};

void funcionDesencolar(int numNodos, int cuentaNodos){
    system("cls");
    int ban=0;
    int auxa = cuentaNodos;
      cout<<"  BIENVENIDOS"<<endl;
    int band=1;
    servicio(band);
    avion2();
    int rangoTotal = 100-(numNodos*10);
    for(int j=1; j<=numNodos;j++){
    pasajero(rangoTotal, ban, auxa);
    auxa -= 1;
    rangoTotal +=10;};
    Sleep(1250);
    system("cls");
};

void servicio(int band){
int i=0, rango=100;
    if(band==0){
    for(i=0;i<rango;i++){
    gotoxy(64,10); cout<<"    o";
    gotoxy(64,11); cout<<"   /|\\";
    }
    gotoxy(64,12); cout<<"|=======|";
    gotoxy(64,13); cout<<"|GOOD   |";
    gotoxy(64,13); cout<<"| TRAVEL|";

    }
//    else if(band==1){
//    for(i=0;i<rango;i++){
//    gotoxy(64,10); cout<<"    o";
//    gotoxy(64,11); cout<<"   /|\\";
//    }
//    gotoxy(64,12); cout<<"|=========|";
//    gotoxy(64,13); cout<<"|RECEPCION|";
//    }
    else if(band==2){
    for(i=0;i<rango;i++){
    gotoxy(64,10); cout<<"    o";
    gotoxy(64,11); cout<<"   /|\\";
    }
    gotoxy(64,12); cout<<"|=======|";
    gotoxy(64,13); cout<<"|Welcome|";
    }
};


void desencolarT(int numNodos, int CuentaNodos){
int ban=0, auxa = CuentaNodos;
    system("cls");
      cout<<"  Llegada UBER"<<endl;
    mostrarUber2();
    int rangoTotal = 100-(numNodos*10);
    for(int j=1;j<=numNodos;j++){
    pasajero(rangoTotal, ban, auxa);
    auxa -= 1;
    rangoTotal +=10;}
    Sleep(1250);
    system("cls");
};

void avion2(){
      cout<<"              .------,"<<endl;
cout<<"              =\      \\"<<endl;
cout<<" .---.         =\      \\"<<endl;
cout<<" | M~ \\         =\      \\"<<endl;
cout<<" |     `----------'------'----------,"<<endl;
cout<<".'     LI.-.LI LI LI LI LI LI LI.-.LI`-."<<endl;
cout<<"  \\ _/.____|_|______.------,______|_|_____)"<<endl;
cout<<"                 /      /"<<endl;
cout<<"               =/      /"<<endl;
cout<<"              =/      /"<<endl;
cout<<"             =/      /"<<endl;
cout<<"             /_____,'"<<endl;
};

void uber(){
int i=0, rango=80;
    system("cls");
    for(int j=0;j<1;j++){
    for(i=0;i<rango;i++){
    Sleep(100);
            gotoxy(i,7); cout<<"-----------------------------------------"<<endl;
            gotoxy(i,8); cout<<"             GRACIAS POR MIRAR           "<<endl;
            gotoxy(i,9); cout<<"-----------------------------------------"<<endl;
            gotoxy(i,16); cout<<"         -            __                "<<endl;
            gotoxy(i,17); cout<<"        --          ~( @\\   \\           "<<endl;
            gotoxy(i,18); cout<<"       ---   _________]_[__/_>_______  "<<endl;
            gotoxy(i,19); cout<<"  |UBER|----/  ____ \ \<>     |  ____  \\ "<<endl;
            gotoxy(i,20); cout<<"           =\_/ __ \\_\\_______|_/ __ \\__D"<<endl;
            gotoxy(i,21); cout<<"       ________(__)_____________(__)____"<<endl;
    }
  }
}


void arribo(){
Nodo *frente = NULL;
int ban=0, ban2=2, rango=55;
int auxa=1, i=0, j=0;
int rangoTotal=90-(CuentaNodosG*10);
    system("cls");
      cout<<"  BAJADA DEL AVION"<<endl;
    servicio(ban2);
    mostrar(frente);
    for(j=1;j<=CuentaNodosG;j++){
    for(i=0;i<rango;i++){
    gotoxy(i,9);cout<<"  "<<j;
    gotoxy(i,10);cout<<"  o";
    gotoxy(i,11);cout<< " /|\\";
    if(ban==0){
    gotoxy(i,12);cout<< " / ";
    ban=1;}
    else{
    gotoxy(i,12);cout<< "   \\";
    ban=0;}
    Sleep(25);}
    if(i>=34){
    rango=45;}
    else if(i>=45){
    rango=35;}
    }
};


void mostrarUber2(){
    Sleep(100);
            cout<<"         -            __                "<<endl;
            cout<<"        --          ~( @\   \           "<<endl;
            cout<<"       ---   _________]_[__/_>________  "<<endl;
            cout<<"  |UBER|----/  ____ \ <>     |  ____  \ "<<endl;
            cout<<"           =\_/ __ \_\_______|_/ __ \__D"<<endl;
            cout<<"       ________(__)_____________(__)____"<<endl;
};



int main(){
Nodo *adelante = NULL;
Nodo *fin = NULL;
int ban=0,i=0,rango=55,insertar, cuentaNodos=0;
string id, nombre, viaje, fecha, maletas;

    do{
    cuentaNodos++;
    CuentaNodosG=cuentaNodos;
    system("cls");
      cout<<"  --------------Registro del CLiente-----------------------------"<<endl<<endl;
      cout<<"  Id del cliente: # "<<cuentaNodos<<": "<<endl<<" -> ";
       cin>>id;
      cout<<"  Nombre del cliente: # "<<cuentaNodos<<": "<<endl<<" -> ";
       cin>>nombre;
      cout<<"  viaje del cliente: # "<<cuentaNodos<<": "<<endl<<" -> ";
       cin>>viaje;
      cout<<"  fecha de viaje del cliente: # "<<cuentaNodos<<": "<<endl<<" -> ";
       cin>>fecha;
      cout<<"  Numero de maletas del cliente: # "<<cuentaNodos<<": "<<endl<<" -> ";
       cin>>maletas;
    push(adelante,fin,cuentaNodos,id,nombre,viaje,fecha,maletas);
    system("cls");
      cout<<endl<<"  Insertar otro cliente: "<<endl;
      cout<<"1) si"<<endl;
      cout<<"2) no"<<endl<<"->";
       cin>>insertar;
    }while(insertar!=2);
    system("cls");
    mostrar(adelante);
    for(int j=1;j<=cuentaNodos;j++){
    for(i=0;i<rango;i++){
    gotoxy(i,9);cout<<"  "<<j;
    gotoxy(i,10);cout<<"  o";
    gotoxy(i,11);cout<< " /|\\";
    if(ban==0){
    gotoxy(i,12);cout<< " / ";
    ban=1;}
    else{
    gotoxy(i,12);cout<< "   \\";
    ban=0;}
    Sleep(25);}

    if(i>=34){
    rango=45;}
    else if(i>=45){
    rango=35;}}




    for(int j = cuentaNodos; j > 0; j-- ){
    funcionDesencolar(j, cuentaNodos);
    Sleep(50);
    };
    for(int x=0;x<=cuentaNodos;x++){
    asientos(adelante);
    Sleep(1000);
    }
    for(int x=0;x<=cuentaNodos;x++){
    system("cls");
    tabla(adelante);
    Sleep(1000);
    }
    system("cls");
    avion();
    arribo();
    for(int j=cuentaNodos;j>0;j--){
    desencolarT(j,cuentaNodos);
    Sleep(50);
    }
    system("cls");
    uber();
    Sleep(1000);
    i = 70;
    system("pause>>cls");
return 0;}
