/*
    Clase: Vehiculo
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Vehiculo.h
    Resumen: Implementación de la clase Vehículo que interactuará con el tablero y los pasajeros.
    
    Descripción:
        Este proyecto pretende llevar a cabo la realización de un videojuego de ordenamiento lógico bidimensional bajo el modelo MVC. 
        El principal objetivo es lograr que cada peatón logre abordar un vehículo de su mismo color y así hasta despejar el paradero.

    Información CRC:
    
    Clase: Vehiculo

    Responsabilidades:
        -Creación de objeto que interactuará con tablero y pasajeros, tendrá color, tipo y dirección.
        -Almacenar y encapsular de forma privada el vector de punteros (sillas) donde abordan con éxito los peatones.
        -Mantener actualizadas sus coordenadas bidimensionales de origen dentro del mapa de juego.

   Colaboradores:

      -Pasajero: Vehículo es un vector de punteros de pasajeros.

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.


    Autores:

    Estudiante: Javier Felipe Contreras Díaz
    Código: 202535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Junio 2026
*/

#ifndef VEHICULO_H
#define VEHICULO_H
#include "Vehiculo.h"
#include "Pasajero.h"
#include <vector>

class Vehiculo {

private:

char tipo;
char color;
char orientacion;
int tamano;
int posX;
int posY;
std::vector<Pasajero*> sillas;

public:

//CONSTRUCTOR
Vehiculo(char auxTipo,char auxColor,char auxOrientacion, int auxTamano, int auxPosX, int auxPosY);

char getColor();
char getTipo();
int getTamano();
char getOrientacion();
int getPosX();
int getPosY();
int getSizeSillas();
void setPos(int x,int y);
void pushPasajerosBus(Pasajero* peaton);

};

#endif
