/*
    Proyecto: Juego de bus
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Controller.cpp
    Resumen: Implementación de la clase Controller, que maneja el view y el model.

    Descripción:
    Este proyecto pretende llevar a cabo la realización de un videojuego de ordenamiento lógico bidimensional bajo el modelo MVC. 
    El principal objetivo es lograr que cada peatón logre abordar un vehículo de su mismo color y así hasta despejar el paradero.

    
    Autor
  
    Estudiante: Javier Felipe Contreras Díaz
    Código: 202535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Junio 2026
*/



#include "Controller.h"
#include "Model.h"
#include "View.h"
#include <iostream>
#include "Tablero.h"
#include <thread>
#include <chrono>
#include <string>
#include <vector>

/**
*@brief Constructor de la clase Controller
*@param auxModel referencia al objeto model del main
*@param auxVista referencia al objeto vista del
**/
Controller::Controller(Model& auxModelo, View& auxVista): vista(auxVista), model(auxModelo){
  int nivel = -1;
}




bool Controller::iniciarJuego(int contador){

  if (contador == 0){
    vista.mostrarHistoria();
  }
  std::vector<std::string> menu = {
  "1. Estación de arte",
  "2. Casino",
  "3. Unidad médica"};
  //Muestra un titulo de menú.
  if(!(nivelesRealizados.empty())){
    for (int i = 0; i < nivelesRealizados.size(); i++){
      menu[nivelesRealizados[i]-1] = "ZonaEvacuada";
    }
  }
  
  vista.mostrarMenu();  
  vista.mostrarBarraMapa();
  std::cout<<"                                                                                       Ingrese el número de estación que desea evacuar"<<std::endl;
  std::cout<<"                                                                                      ▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌"<<std::endl;
  for (int i = 0; i < menu.size(); i++){
    std::cout<<"                                                                                                      "<<menu[i]<<std::endl;  
  }
  std::cout<<"                                                                                                      0. Huir al centro galáctico"<<std::endl; 
  std::cout<<"                                                                                      ▐▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌"<<std::endl;

  vista.mostrarBarraMapa();
  std::cout<<"                                                                                                ";
    
  //elegir el nivel 
  while(!(std::cin>>nivel) || nivel < 0 || nivel >3 ){
    
    vista.mostrarMenu();  
    vista.mostrarBarraMapa();
    std::cout<<"                                                                                       Ingrese el número de estación que desea evacuar"<<std::endl;
    std::cout<<"                                                                                      ▐▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▌"<<std::endl;
    for (int i = 0; i < menu.size(); i++){
      std::cout<<"                                                                                                      "<<menu[i]<<std::endl;  
    }
    std::cout<<"                                                                                                      0. Huir al centro galáctico"<<std::endl; 
    std::cout<<"                                                                                      ▐▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▌"<<std::endl;

    vista.mostrarBarraMapa();
    std::cout<<"                                                                                                ";

    std::cin.clear();
    std::cin.ignore();
  }//end while elegir nivel

  
  nivelesRealizados.push_back(nivel);
  if(nivel == 0){
    return false;
  }

  //cargar el archivo según el nivel
  model.cargarTxt(nivel);
  model.cargarVehiculosEnTablero();
  model.cargarPasajerosEnTablero();

  //mostrar mapa
  vista.mostrarNivel(nivel);
  vista.mostrarBarraMapa();
  vista.mostrarZonaPasajeros(model.getTablero());
  vista.mostrarZonaAbordaje(model.getTablero());
  vista.mostrarZonaCoches(model.getTablero());
  vista.mostrarBarraMapa();
  return true;
}
          

void Controller::mostrarMapa(){
  //mostrar mapa
  vista.mostrarNivel(nivel);
  vista.mostrarBarraMapa();
  vista.mostrarZonaPasajeros(model.getTablero());
  vista.mostrarZonaAbordaje(model.getTablero());
  vista.mostrarZonaCoches(model.getTablero());
  vista.mostrarBarraMapa();  
}

//pide coordenadas, las verifica, pide dirección y sea una entrada válida. Verifica la colisión del vehículo, de no haber entra en un bucle que mientras mover vehículo sea true verifica sus coordenadas más actuales y se mueve.
//también, en caso de que el vehículo esté en los bordes, resta uno al tamaño, así elimina la dirección del último borde y ya.
bool Controller::movimientosVehiculos(){
    //Verifica que la posición seleccionada corresponda a un vehículo en el tablero, sino entra en bucle hasta que el usuario ingrese unas coordenadas válidas.
   auto[posX, posY] = model.verificarPosicionVehiculo();
   if(posX == 0 && posY == 0){
    return false;
   }
   Vehiculo* carro = model.getTablero().getZonaCoches()[posX][posY];    
   int tam = carro->getTamano();
   //Verifica que la dirección ingresada sea válida y convierte el input int (1,2,3,4) en una dirección tipo char ('^','v','<','>')
   char dir = model.verificarInputDireccion();

   //verifica colisión antes de seguir con el movimiento.
   if (!(model.getTablero().verificarColision(posX, posY))){
    while(model.moverVehiculo(posX,posY,tam,dir)){
      posX = carro->getPosX();
      posY = carro->getPosY();
      //antes de seguir, vemos si el vehículo está en un borde, de ser así se le reduce el tamaño para que el próximo while tam elimine su propia posicion en el tablero de punteros        
      if (carro->getPosX() == 0 ||carro->getPosY() == 0 || carro->getPosX()== model.getTablero().getFilas()-1 ||carro->getPosY()== model.getTablero().getColumnas()-1){
        tam -= 1;
      }
          //mostrar mapa
          vista.mostrarNivel(nivel);
          vista.mostrarBarraMapa();
          vista.mostrarZonaPasajeros(model.getTablero());
          vista.mostrarZonaAbordaje(model.getTablero());
          vista.mostrarZonaCoches(model.getTablero());
          vista.mostrarBarraMapa();
          std::this_thread::sleep_for(std::chrono::milliseconds(300));    
    }
    //mostrar mapa
    vista.mostrarNivel(nivel);
    vista.mostrarBarraMapa();
    vista.mostrarZonaPasajeros(model.getTablero());
    vista.mostrarZonaAbordaje(model.getTablero());
    vista.mostrarZonaCoches(model.getTablero()); 
    vista.mostrarBarraMapa();
   }
   return true;
}


//Genera un for de 0 a 3, ya que es el numero de zonas de recogida que hay. 4 zonas donde se aparcan los coches para recoger peatones.
void Controller::pushPasajerosBus(){

  //verifica que el primero peatón en la fila de pasajeros, pueda ingresar a un vehículo de los 4 que hay en la zona de recogida de su mismo color y que tenga espacio dentro de el, sino es así rompe el ciclo.
  while(model.verificarPushPasajeros()){
    model.pushPasajerosBus();
    //mostrar mapa
    vista.mostrarNivel(nivel);
    vista.mostrarBarraMapa();
    vista.mostrarZonaPasajeros(model.getTablero());
    vista.mostrarZonaAbordaje(model.getTablero());
    vista.mostrarZonaCoches(model.getTablero());
    vista.mostrarBarraMapa();
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
  }
}

//se supone que debe verificar si los buses están llenos o no en los 4 puestos donde se recogen pasajeros, y si están llenos los manda a "Zona victoria" donde irán los buses llenos.
void Controller::verificarZonaRecogida(){
  model.verificarZonaRecogida();
  //mostrar mapa
  vista.mostrarNivel(nivel);
  vista.mostrarBarraMapa();
  vista.mostrarZonaPasajeros(model.getTablero());
  vista.mostrarZonaAbordaje(model.getTablero());
  vista.mostrarZonaCoches(model.getTablero());
  vista.mostrarBarraMapa();
}


//Verifica si hay 4 coches llenos en la zona de recogida, de ser así, la próxima vez que se envíe un vehículo a esa zona, perderá el juego.
bool Controller::verificarDerrota(){
 if (model.getVerificarDerrota()){
  vista.pantallaDerrota();
  return model.getVerificarDerrota();
 }
 return model.getVerificarDerrota();
}

bool Controller::verificarVictoria(){
  std::vector<Pasajero*> filaPasajeros = model.getTablero().getFilaPasajeros();
  if (filaPasajeros.size() == 0){
    //mostrar mapa
    vista.mostrarNivel(nivel);
    vista.mostrarBarraMapa();
    vista.mostrarZonaPasajeros(model.getTablero());
    vista.mostrarZonaAbordaje(model.getTablero());
    vista.mostrarZonaCoches(model.getTablero());
    vista.mostrarBarraMapa();
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    vista.pantallaVictoria();
    return true;
  }
  else {
    return false;
  }
}

