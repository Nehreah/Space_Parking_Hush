/*
    Proyecto: Juego de bus
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Pasajero.cpp
    Resumen: Implementación de la clase pasajero, un objeto que interactúa con el tablero y los vehículos.

    Descripción:
    Este proyecto pretende llevar a cabo la realización de un videojuego de ordenamiento lógico bidimensional bajo el modelo MVC. 
    El principal objetivo es lograr que cada peatón logre abordar un vehículo de su mismo color y así hasta despejar el paradero.

    
    Autores:

    Estudiante: Javier Felipe Contreras Díaz
    Código: 202535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Junio 2026
*/
#include "Pasajero.h"


Pasajero::Pasajero(char auxColor): color(auxColor){
}

char Pasajero::getColor(){
  return color;
}
