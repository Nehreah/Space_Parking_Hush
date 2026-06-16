/*
    Clase: Pasajero
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Pasajero.h
    Resumen: Implementación de la clase pasajero, un objeto que interactúa con el tablero y los vehículos.
    
    Descripción:
        Este proyecto pretende llevar a cabo la realización de un videojuego de ordenamiento lógico bidimensional bajo el modelo MVC. 
        El principal objetivo es lograr que cada peatón logre abordar un vehículo de su mismo color y así hasta despejar el paradero.

    Información CRC:
    
    Clase: Pasajero

    Responsabilidades:
        -Crear la clase pasajero que interactuará con le tablero y los vehículos
        -Brindar información de su atributo color 


    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.


    Autores:
    Estudiante: Javier Felipe Contreras Díaz
    Código: 202535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Junio 2026
*/
#ifndef PASAJERO_H
#define PASAJERO_H




class Pasajero{

private:

char color;

public:
Pasajero(char auxColor);
char getColor();

};

#endif
