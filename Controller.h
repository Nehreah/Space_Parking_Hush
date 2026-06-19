/*
    Clase: Controller
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Controller.h
    Resumen: Implementación de la clase Controller, que maneja el view y el model.

    Descripción:
        Este proyecto pretende llevar a cabo la realización de un videojuego de ordenamiento lógico bidimensional bajo el modelo MVC. 
        El principal objetivo es lograr que cada peatón logre abordar un vehículo de su mismo color y así hasta despejar el paradero.

    Información CRC:
    
    Clase: Controller

    Responsabilidades:
        - Flujo principal del juego controlando model y view.
        - Captura y válida las entradas del usuario.

   Colaboradores:

    Model: Interactúa con model para ordenar la carga de archivos de texto, 
          solicitar la actualización de coordenadas de los vehículos y consultar el estado lógico del juego.

    View: Actualiza la interfaz gráfica en la consola tras cada movimiento o cambio de turno.

    Tablero: Accede a su referencia (a través del Model) para evaluar de forma directa las condiciones del escenario.

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.


    Autores:
    Estudiante: Javier Felipe Contreras Díaz
    Código: 202535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Junio 2026
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <vector>
#include "Model.h"
#include "View.h"


class Controller{

private:

int nivel;
View& vista;
Model& model;


public:

Controller(Model& auxModelo, View& auxVista);
bool iniciarJuego(int contador);
bool movimientosVehiculos();
void mostrarMapa();
void pushPasajerosBus();
void verificarZonaRecogida();
bool verificarDerrota();
bool verificarVictoria();
};

#endif
