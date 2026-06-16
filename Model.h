/*
    Clase: Model
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Model.h
    Resumen: Implementación de la clase Model encargada de la carga de archivos y objetos y el manejo del tablero.
    
    Descripción:
        Este proyecto pretende llevar a cabo la realización de un videojuego de ordenamiento lógico bidimensional bajo el modelo MVC. 
        El principal objetivo es lograr que cada peatón logre abordar un vehículo de su mismo color y así hasta despejar el paradero.

    Información CRC:
    
    Clase: Model

    Responsabilidades:
        -Actuar como la clase central y persistente de la información del juego, conteniendo los objetos reales Vehículo y Pasajero.
        -Gestionar lectura de los archivos planos (nivel1.txt, etc.) para instanciación dinámica.
        -Construye y procesar la lógica interna del juego de colisiones, abordaje y etc.

   Colaboradores:

      -Tablero: El modelo delega la responsabilidad de almacenar el tablero espacial 
                y gestionar la distribución física de sus objetos vehículo y pasajero.
      -Vehiculo: Contiene los objetos principales de vehículo
      -Pasajero: Contiene los objetos principales de pasajero

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.


    Autores:
    Estudiante: Javier Felipe Contreras Díaz
    Código: 202535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Junio 2026
*/
#ifndef MODEL_H
#define MODEL_H

#include "Vehiculo.h"
#include "Pasajero.h"
#include "Tablero.h"


#include <vector>
#include <string>

class Model{

private:
std::vector<Vehiculo> vehiculos;
std::vector<Pasajero> pasajeros;
Tablero tablero;


public:
Model();
void cargarTxt(int nivel);
void cargarVehiculosEnTablero();
void cargarPasajerosEnTablero();

bool verificarColision(int posX, int posY);
bool verificarDireccion(char direccion, int posX, int posY);
char verificarInputDireccion();
std::tuple<int,int> verificarPosicionVehiculo();
void verificarZonaRecogida();

bool moverVehiculo(int posX, int posY, int tam,char direccion);
void pushPasajerosBus();

bool verificarPushPasajeros();
bool getVerificarDerrota();
Tablero& getTablero();
};

#endif
