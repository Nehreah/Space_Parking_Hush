/*
    Clase: View
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: View.h
    Resumen: Implementación de la clase abstracta View encargada de ser la clase padre, qué con ayuda de herencia y polimorfismo da impresión de datos en pantalla ya sea en consola o sfml.
    
    Descripción:
        Este proyecto pretende llevar a cabo la realización de un videojuego de ordenamiento lógico bidimensional bajo el modelo MVC. 
        El principal objetivo es lograr que cada peatón logre abordar un vehículo de su mismo color y así hasta despejar el paradero.

    Información CRC:
    
    Clase: View

    Responsabilidades:
        -Encargarse de la interfaz de usuario en modo texto, transformando 
          las matrices numéricas y punteros del sistema en información en pantalla.
        -Mostrar en la consola los menús interactivos, las pantallas de selección 
          de nivel y los títulos decorativos del juego.

   Colaboradores:

      Tablero: Recibe una referencia del tablero como parámetro en su método mostrarMapa
              (Tablero& paradero) para poder leer la matriz de datos e imprimir en pantalla.

      Vehiculo: Accede a los Getters de los vehículos para imprimirlos en la interfaz de usuario.

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.


    Autores:

    Estudiante: Javier Felipe Contreras Díaz
    Código: 202535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Junio 2026
*/
#ifndef VIEW_H
#define VIEW_H

#include "Tablero.h"

class View{


public:

View(){};

virtual void mostrarMenu() = 0;
virtual void mostrarNivel(int nivel) = 0;
virtual void mostrarBarraMapa() = 0;
virtual void mostrarZonaPasajeros(Tablero& datosMapa) = 0;
virtual void mostrarZonaAbordaje(Tablero& datosMapa) = 0;
virtual void mostrarZonaCoches(Tablero& datosMapa) = 0;
virtual void mostrarHistoria() = 0;
virtual void pantallaDerrota() = 0;
virtual void pantallaVictoria() = 0;

virtual ~View(){};

};

#endif
