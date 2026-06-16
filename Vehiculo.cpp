/*
    Proyecto: Juego de bus
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Vehiculo.cpp
    Resumen: Implementación de la clase Vehículo que interactuará con el tablero y los pasajeros.

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
#include <vector>
#include <string>


Vehiculo::Vehiculo(char auxTipo,
        char auxColor,
        char auxOrientacion,  
        int auxTamano, 
        int auxPosX, 
        int auxPosY): 
        tipo(auxTipo), 
        color(auxColor),
        orientacion(auxOrientacion),
        tamano(auxTamano),
        posX(auxPosX),
        posY(auxPosY) {
        sillas.clear();
}

char Vehiculo::getColor(){
  return color;
}

char Vehiculo::getTipo(){
  return tipo;
}

int Vehiculo::getTamano(){
  return tamano;
}

char Vehiculo::getOrientacion(){
  return orientacion;
}

int Vehiculo::getPosX(){
  return posX;
}

int Vehiculo::getPosY(){
  return posY;
}

int Vehiculo::getSizeSillas(){
  return sillas.size();
}

void Vehiculo::setPos(int x,int y){
  posX = x;
  posY = y;
}

void Vehiculo::pushPasajerosBus(Pasajero* peaton){
  sillas.push_back(peaton);
}
