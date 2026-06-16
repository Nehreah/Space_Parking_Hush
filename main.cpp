/*
    Proyecto: Juego de bus
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Main.cpp
    Resumen: Implementación del main, que maneja el flujo del programa a través del controller.

    Descripción:
    Este proyecto pretende llevar a cabo la realización de un videojuego de ordenamiento lógico bidimensional bajo el modelo MVC. 
    El principal objetivo es lograr que cada peatón logre abordar un vehículo de su mismo color y así hasta despejar el paradero.
    
    Autores:

    Estudiante: Javier Felipe Contreras Díaz
    Código: 202535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Junio 2026
*/
#include "Controller.h"
#include "Model.h"
#include "View.h"
#include "ViewConsola.h"
#include <iostream>


int main() {
//se crean 2 objetos de vista, uno para tener un View de consola y otro (aun no implementado) tendrá una vista con SFML
  ViewConsola vistaConsola;
  //Este vistaConsola2, se usará en un futuro ViewSFML y se llamará vistaSFML
  ViewConsola vistaConsola2;
  //un puntero que inicia nulo y a posteriori apuntará a la vistaConsola o vistaSFML según elija el usuario.
  View* vista = nullptr;
  //Se crea el modelo.
  Model modelo;

  //Se realiza un while para elegir el tipo de vista.
  int opcion;
  system("clear");
  std::cout<<"Elija el modo de vista que desea para el juego: \n1. Consola \n2. Vista gráfica(aun no está lista) \n0. Para cerrar el programa"<<std::endl;
   while(!(std::cin>>opcion) || opcion > 2 || opcion <0 ){
    std::cout<<"Por favor ingrese una opción válida: "<<std::endl;
    std::cin.clear();
    std::cin.ignore();
   }
   // un if y 2 else if según la opción elegida.
  if (opcion == 0 ){
    std::cout<<"El programa ha finalizado con éxito"<<std::endl;
    return 0;
  }
  else if (opcion == 1){
    vista = &vistaConsola;
  }
  else if (opcion == 2){
  vista = &vistaConsola2;
  }
  //Ahora controller se instancia con el modelo y el puntero al tipo de vista elegido.
  Controller control(modelo, *vista);
 
 //hacemos un while que mientras iniciar juego elija un nivel real, el juego iniciará, al elegir 0 se cierra el loop y el juego. Aquí ocurre la selección de niveles y el juego.
    while(control.iniciarJuego()){
    //Permite 30 movimientoa, estoy pensando en reducirlo y si se acaban los movimientos, entonces game over. Aquí ocurre el juego.
      for(int i =0; i = 30; i++){
  //Es un bucle, mientras sea true todo seguirá, pero si es false (esto ocurre si selecciona coordenadas 0,0) retorna a este menú de selección y hace un break del for, volviendo al while
        if(!(control.movimientosVehiculos())){
          break;
        }
        //luego de mover el vehículo, se envían los peatones a los buses
        control.pushPasajerosBus();
        //luego se verifica la zona de recogida y si hay autos llenos, se envían a la zona de victoria.
        control.verificarZonaRecogida();
        if(control.verificarDerrota()){
          return 0;
        }
        //se verifica la victoria, sí se ha ganado, al igual que antes, se genera un break del nivel en el for y se regresa al while: el selector de niveles
        else if(control.verificarVictoria()){
          break;
        }
      }
    }

  return 0;
}

