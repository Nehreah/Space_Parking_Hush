/*
    Clase: Tablero
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Tablero.h
    Resumen: Implementación de la clase Tablero encargada del mapa e interactúa con los objetos que se mueven en el.
    
    Descripción:
        Este proyecto pretende llevar a cabo la realización de un videojuego de ordenamiento lógico bidimensional bajo el modelo MVC. 
        El principal objetivo es lograr que cada peatón logre abordar un vehículo de su mismo color y así hasta despejar el paradero.

    Información CRC:
    
    Clase: Tablero

    Responsabilidades:
        -Gestionar espacialidad del escenario mediante una matriz bidimensional de punteros (zonaCoches).
        -Administrar y controla de manerala fila de peatones en espera (filaPasajeros), el muelle de embarque 
          (zonaRecogida) y el depósito de evacuación exitosa (zonaVictoria).
        -Validar la lógica de los movimientos, y se asegura de no bloquear o desbordar ningún límite del mapa.

   Colaboradores:

      -Vehiculo: Organiza punteros de esta clase dentro de la matriz zonaCoches y los vectores de zonaRecogida y zonaVictoria.
      -Pasajero: Administra punteros de esta entidad antes de ir a los vehículos.

    Este es un proyecto del curso FPOO de la Universidad del Valle, 
    desarrollado con fines académicos. Puede ser utilizado con fines 
    académicos dando los créditos de la autoría.


    Autores:
    Estudiante: Javier Felipe Contreras Díaz
    Código: 202535936
    Email: contreras.javier@correounivalle.edu.co
		
    Fecha: Junio 2026
*/
#ifndef TABLERO_H 
#define TABLERO_H 

#include "Vehiculo.h"
#include "Pasajero.h"
#include <vector>

class Tablero{

private:

int filas;
int columnas;
std::vector<std::vector<Vehiculo*>> zonaCoches; 
std::vector<Pasajero*> filaPasajeros;
std::vector<Vehiculo*> zonaRecogida;
std::vector<Vehiculo*> zonaVictoria;
bool verificarDerrota;

public:

Tablero();
Tablero(int auxFilas, int auxColumnas);
void setZonaCoches(Vehiculo* auxVehiculo);
void pushFilaPasajeros(Pasajero*);
bool verificarColision(int posX,int posY);
bool verificarDireccion(char direccion, int posX, int posY);
bool getVerificarDerrota();
bool moverVehiculo(int posX, int posY, int tam);
void pushPasajerosBus(Pasajero* peaton, int i);
void verificarZonaRecogida();
void pushZonaVictoria(Vehiculo* carro);

std::vector<Pasajero*>& getFilaPasajeros();
std::vector<Vehiculo*>& getZonaRecogida();
std::vector<std::vector<Vehiculo*>>& getZonaCoches();
std::vector<Vehiculo*>& getZonaVictoria();
int getFilas();
int getColumnas();
bool verificarPushPasajeros();

};

#endif
