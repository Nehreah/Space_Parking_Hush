/*
    Proyecto: Juego de bus
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Model.cpp
    Resumen: Implementación de la clase Model encargada de la carga de archivos y objetos y el manejo del tablero.

    Descripción:
    Este proyecto pretende llevar a cabo la realización de un videojuego de ordenamiento lógico bidimensional bajo el modelo MVC. 
    El principal objetivo es lograr que cada peatón logre abordar un vehículo de su mismo color y así hasta despejar el paradero.

    
    Autores:

    Estudiante: Javier Felipe Contreras Díaz
    Código: 202535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Junio 2026
*/

#include "Vehiculo.h"
#include "Pasajero.h"
#include "Tablero.h"
#include "Model.h"
#include <iostream>

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

Model::Model(){
}

//Carga el archivo, pide el número de nivel porque ese será el nombre del txt que cargará
void Model::cargarTxt(int nivel){
//Limpia los vectores, porque se iniciaron vacíos y así se evita la basura.
  vehiculos.clear();
  pasajeros.clear();
  
  //Nombre del archivo, + el int nivel, para cargar el archivo según el número del nivel
  std::string archivo = "nivel";
  archivo += std::to_string(nivel);
  archivo += ".txt";
  //Carga el archivo en una variable llamada mapa.
  std::ifstream mapa(archivo);
  //Crea un string auxLine donde se cargarán las líneas de mapa
  std::string auxLine;
  
  //While, mientras se cargue una línea completa del mapa (el nivel cargado) y se agrega esa línea al recién creado auxLine
  while(std::getline(mapa, auxLine)){
    char color;
    char tipo;
    char orientacion;
    int tamano;
    int posX;
    int posY;
    int filas;
    int columnas;
    std::string temp;
    //el string auxLine, se convierte en un stringstream llqmqeo linea para manejarlo mejor.
    std::stringstream linea(auxLine);
    //se reaaliza una revisión de caracter por caracter en linea, y sea agrega a la variable temporal temp. Luego se convierte temp en el tipo de cada parametro solicita y se asigna a su variable respectiva.
    std::getline(linea,temp,',');
    //asigna el tipo del objeto que se encuentra en temp.
    tipo = temp[0];
    //si el tipo recién asignado corresponde a 'D' de dimensiones, crea un objeto Tablero con las dimensiones de filas y columnas y se lo asigna a su parametro privado "tablero"
    if (tipo == 'D'){
      std::getline(linea,temp,',');
      filas = std::stoi(temp);
      std::getline(linea,temp,',');
      columnas = std::stoi(temp);
      Tablero auxTab(filas,columnas);
      tablero = auxTab;
    }
    
    //si el tipo es 'P' Pasajero, crea un objeto pasajero y lo agrega al vector de pasajeros privado.
    else if (tipo == 'P'){
      std::getline(linea,temp,',');
      color = temp[0];
      Pasajero pasajero(color);
      pasajeros.push_back(pasajero);
    }
    
    //si el tipo es 'V' Vehiculo, crea un objeto de tipo Vehículo y lo envía al vector provado de vehílos
    else if (tipo== 'V'){ 
      std::getline(linea,temp,',');
      color = temp[0];
      std::getline(linea,temp,',');
      orientacion =temp[0];
      std::getline(linea,temp,',');
      tamano=std::stoi(temp); 
      std::getline(linea,temp,',');
      posX=std::stoi(temp);
      std::getline(linea,temp,',');
      posY = std::stoi(temp);
      Vehiculo vehiculo(tipo,color,orientacion,tamano,posX,posY);
      vehiculos.push_back(vehiculo);
    }
  }
  mapa.close();
}

//Carga los vehículos de los vectores privados, y los envía como referencias al tablero, con setZonaCoches y allí los recibe como punteros para manejarlos mejor.
void Model::cargarVehiculosEnTablero(){
  for (auto& v: vehiculos){
    tablero.setZonaCoches(&v);
  }
}

//Carga los Pasajeros de los vectores privados, y los envía como referencias al tablero, con pushFilaPasajeros y allí los recibe como punteros para manejarlos mejor.
void Model::cargarPasajerosEnTablero(){
  for (auto& p: pasajeros){
    tablero.pushFilaPasajeros(&p);
  }
}

//Verifica si hay colisión para saber si se puede mover o no
bool Model::verificarColision(int posX, int posY){
  bool colision = tablero.verificarColision(posX, posY);
  return colision;
}



//Verifica si los valores ingresados en la dirección, corresponden a parámetros válidos, sino solicita nuevamente que se ingresen datos.
char Model::verificarInputDireccion(){
    std::string dir;
    std::cout<<"¿Ingrese el número de la dirección en la que se desea mover: "<<std::endl;  
    //mientras dir que es la dirección sea falso, y además dir no sea 1, 2, 3 o 4, se hace un while
    while(!(std::cin>>dir) || !(dir == "1" || dir == "2" || dir == "3" || dir == "4")){
      std::cout<<"¿Ingrese el número de la dirección en la que se desea mover: "<<std::endl;
     std::cout<<std::endl;
     std::cin.clear();
     std::cin.ignore();
      
      }
      //convierte dir en un char llamado direccion
      char direccion;
      direccion = dir[0];
      switch(direccion){
        case '1': {
          dir = "^";
        }
        break;
        case '2': {
          dir = "v";
        }
        break;
        case '3': {
          dir = "<";
        }
        break;
        case '4': {
          dir = ">";
        }
        break;
      }
      //al finalizar dirección cambia de ser un char numerico a un char de direccion <,^,>,v
      direccion = dir[0];
      return direccion;
}


//Verifica si la dirección ingresada corresponde con la dirección en la que se puede mover el coche.
bool Model::verificarDireccion(char direccion,  int posX, int posY){
  bool direccionCorrecta = tablero.verificarDireccion(direccion, posX, posY);
  return direccionCorrecta;
}



//verifica si la posición ingresada del vehículo corresponde a una posición real en el tablero, sino, pide que se ingresen datos nuevamente.
std::tuple<int,int> Model::verificarPosicionVehiculo(){
  int posX;
  int posY;
  std::cout<<"Ingrese las coordenadas (0,0) y regresará al menú de elección de nivel"<<std::endl;
  std::cout<<"Qué nave desea mover, ingrese el número de filas [↓↑] de enter e ingrese el número de columnas [←→] y de enter."<<std::endl;
  std::cin>>posX>>posY;
  int filas = tablero.getColumnas();
  int columnas = tablero.getFilas();  

  while (posX > filas || posY > columnas || posX < 0 || posY < 0 ){
    std::cout<<"Error. Posición por fuera del mapa, elija una posición válida"<<std::endl;
    std::cout<<"Qué nave desea mover, ingrese las filas [↓↑] de enter e ingrese las columnas [←→] y de enter"<<std::endl;
    std::cin>>posX>>posY;
  }
    if (posX == 0 && posY == 0){
      return {posX, posY};
  }

  //le resta uno a cada pos, ya que c++ lee desde 0.
  posX-=1;
  posY-=1;
  Vehiculo* carro = tablero.getZonaCoches()[posX][posY];
  //Mientras el puntero vehículo sea falso hace un bucle para pedir la posición nuevamente y restarle uno a cada uno nuevamente.
    while( !(carro) ){
      std::cout<<"Error. No hay vehículos en la dirección dada, elija una posición válida"<<std::endl;
      std::cout<<"Qué nave desea mover, ingrese las filas [↓↑] de enter e ingrese las columnas [←→] y de enter"<<std::endl;
      std::cin>>posX>>posY;
      posX-=1;
      posY-=1;
      carro = tablero.getZonaCoches()[posX][posY];
    }
    posX = carro->getPosX();
    posY = carro->getPosY();
  return {posX, posY};
}


//toma una posición y dirección de controller y verifica que la dirección del vehículo y la dirección ingresa tengan el mismo valor. luego llama a la zona de recogida, y si mover vehículo es true, devuelve true y mueve el vehículo. 
bool Model::moverVehiculo(int posX, int posY, int tam,char direccion){
        if(tablero.verificarDireccion(direccion, posX, posY)){
          //Ya que sabemos que la dirección es correcta, invocamos la zona de recogida 
          std::vector<Vehiculo*>& zonaRecogida = tablero.getZonaRecogida();
          //mientras se pueda mover y se mueva el vehículo hará     
          if(tablero.moverVehiculo(posX,posY,tam)){
            return true;
          }
        }
  return false;
}

//Envía los pasajeros de la fila a los buses corespondientes a su color si el bus todavía tiene cupo.
void Model::pushPasajerosBus(){
    
    for (int i = 0; i < 4; i++){
      //llamo una referencia de zona de recogida
      std::vector<Vehiculo*>& zonaRecogida =  tablero.getZonaRecogida();
      //Busco el vehículo que está en la zona de recogida
      Vehiculo* carro = zonaRecogida[i];
      //unicamente si hay un carro en esa zona de recogida, se ejecuta el código:
      if(carro){
            char colorCarro = carro->getColor();
            std::vector<Pasajero*>& filaPasajeros = tablero.getFilaPasajeros();
            Pasajero* peaton = filaPasajeros[0];
            int capacidad = carro->getTamano()*2;
            int estCap = carro->getSizeSillas();
          if(peaton){
            char colorPeaton = peaton->getColor(); 
            if((estCap < capacidad) && (colorCarro == colorPeaton) ){
                tablero.pushPasajerosBus(peaton, i);
                estCap = carro->getSizeSillas();
            }
          }
        }
    }
}


//Verifica si los buses de la zona de recogida están llenos, en caso de que sí, debería enviarlos a la zona de victoria donde están los buses llenos.
void Model::verificarZonaRecogida(){
 tablero.verificarZonaRecogida();
}

bool Model::verificarPushPasajeros(){
 return tablero.verificarPushPasajeros();
}

//Verifica si hay más de 4 vehículos en la zona de recogida, y si sí y se envía otro bus a dicha zona, se pierde.
bool Model::getVerificarDerrota(){
  return tablero.getVerificarDerrota();
}

//devuelve una referencia del tablero.
Tablero& Model::getTablero(){
  return tablero;
}

