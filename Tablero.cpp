/*
    Proyecto: Juego de bus
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle
    Archivo: Tablero.cpp
    Resumen: Implementación de la clase Tablero encargada del mapa e interactúa con los objetos que se mueven en el.

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
#include "Pasajero.h"
#include "Tablero.h"
#include <vector>
#include <iostream>


Tablero::Tablero(){
}
Tablero::Tablero(int auxFilas, int auxColumnas):filas(auxFilas),columnas(auxColumnas){
  zonaCoches = std::vector<std::vector<Vehiculo*>>(filas, std::vector<Vehiculo*>(columnas, nullptr));
  zonaRecogida = std::vector<Vehiculo*>(4, nullptr);
  verificarDerrota = false;
}


/*p
 < = Horizontal ya que se mueve a la izquierda, carga el vehículo hacia la derecha para que no estorbe en el for del método moverse.
 > = Horizontal ya que se mueve a la derecha, carga el vehículo hacia la izquierda para que no estorbe en el for del método moverse.
 ^ = Vertical ya que se mueve a la arriba, carga el vehículo hacia la abajo para que no estorbe en el for del método moverse.
 v = Vertical ya que se mueve a la abajo, carga el vehículo hacia la arriba para que no estorbe en el for del método moverse.
*/


//Envía los cada puntero de vehículo a una posición de la matriz de Vehículos* llamada zonaCoches.
void Tablero::setZonaCoches(Vehiculo* auxVehiculo){
  int posX = auxVehiculo->getPosX();
  int posY = auxVehiculo->getPosY();
  int tamano = auxVehiculo->getTamano();
  char orientacion = auxVehiculo->getOrientacion();
  
  if (orientacion == '<'){
    for (int i = 0; i<tamano; i++){
      zonaCoches[posX][posY+i] = auxVehiculo;
    }
  }
  else if(orientacion == '>'){
   for (int i = 0; i<tamano; i++){
      zonaCoches[posX][posY-i] = auxVehiculo;
    }
  }
  else if(orientacion == '^'){
   for (int i = 0; i<tamano; i++){
     zonaCoches[posX+i][posY] = auxVehiculo;
   }
  }
  else if(orientacion =='v'){
   for (int i = 0; i<tamano; i++){
     zonaCoches[posX-i][posY] = auxVehiculo;
   }
  } 
}

//Envía punteros de pasajeros al vector interno de Pasajeros*
void Tablero::pushFilaPasajeros(Pasajero* auxPasajero){
  filaPasajeros.push_back(auxPasajero);
}



 
/*
< = Horizontal verificar espacio libre hacia la izquierda
> = Horizontal verificar espacio libre hacia la derecha
^ = Vertical verificar espacio libre hacia arriba
v = vertical verificar espacio libre hacia abajo
*/
 
 //Verfiica si un vehículo colisionaría o no con otro en caso de moverse.
bool Tablero::verificarColision(int posX,int posY){
 Vehiculo* auxVehiculo = zonaCoches[posX][posY];
 if (auxVehiculo == nullptr) {
  return false;
 }
 char orientacion = auxVehiculo->getOrientacion();
 bool colision = false;
 if (orientacion == '<'){
  for (int i = 1;posY-i >=0; i++){
    if (zonaCoches[posX][posY-i] == nullptr){
      colision = false;
    }
    else {
        return true;
    }
  }
 }
 else if(orientacion == '>'){
  for (int i = 1; posY+i <columnas; i++){ 
    if (zonaCoches[posX][posY+i] == nullptr){
      colision = false;
    }
    else {
        return true;
    }
  }
 }
  else if(orientacion == '^'){
    for (int i = 1; posX-i >= 0; i++){
      if (zonaCoches[posX-i][posY] == nullptr){
        colision = false;
      }
      else {
        return true;
      }
    }
  }
  else if(orientacion == 'v'){
    for (int i = 1; posX+i<filas; i++){
      if (zonaCoches[posX+i][posY] == nullptr){
        colision = false;
      }
      else {
        return true;
      }
    }
  }
 return colision;
}



bool Tablero::verificarDireccion(char direccion, int posX, int posY){
  Vehiculo* auxVehiculo = zonaCoches[posX][posY];
  if (auxVehiculo->getOrientacion() == direccion){ 
    return true;
  }
  return false;
}


 /*
 < = Horizontal se mueve hacia la izquierda
 > = Horizontal se mueve hacia la derecha
 ^ = Vertical se mueve hacia arriba
 v = vertical se mueve hacia abajo
 */

bool Tablero::getVerificarDerrota(){
  return verificarDerrota;
}

//mueve el vehículo en una dirección, en el controller está en ciclo de movimiento hasta el final del tablero (sus orillas) ahí  lo envía a zona de recogida
bool Tablero::moverVehiculo(int posX, int posY, int tam){
  Vehiculo* auxVehiculo = zonaCoches[posX][posY];
  char orientacion = auxVehiculo->getOrientacion();
  int tamano = auxVehiculo->getTamano()-1;
  int x = auxVehiculo->getPosX();
  int y = auxVehiculo->getPosY();

  if (!(x==0 || y == 0 ||x==filas-1 || y==columnas-1 )){
    if (orientacion == '<'){
          zonaCoches[x][y+tamano] = nullptr;
          zonaCoches[x][y-1] = auxVehiculo;
          auxVehiculo->setPos(x,y-1);
          return true;
    }
    else if(orientacion == '>'){
          zonaCoches[x][y-tamano] = nullptr;
          zonaCoches[x][y+1] = auxVehiculo;
          auxVehiculo->setPos(x,y+1);
          return true;
    }
    else if(orientacion == '^'){
        zonaCoches[x+tamano][y] = nullptr;
        zonaCoches[x-1][y] = auxVehiculo;
        auxVehiculo->setPos(x-1,y);
        return true;
    }
    else if(orientacion == 'v'){
        zonaCoches[x-tamano][y] = nullptr;
        zonaCoches[x+1][y] = auxVehiculo;
        auxVehiculo->setPos(x+1,y);
        return true;
    }
  }
  //Acá se elimina un puntero en el tablero x=tamaño posiciones en el tablero, cuando está en el borde, controller le resta 1 a tam y acá se elimina en su propia posición en el tablero
  else if ((x==0 || y == 0 ||x==filas-1 || y==columnas-1) && tam >= 0){
      if(orientacion == '^'){
        zonaCoches[x+tam][y]= nullptr;
      }
      else if(orientacion == 'v'){
        zonaCoches[x-tam][y] = nullptr;
      }
      else if(orientacion == '>'){
        zonaCoches[x][y-tam] = nullptr;
      }
      else if(orientacion == '<'){
        zonaCoches[x][y+tam] = nullptr;
      }
      if (tam == 0){
        if(zonaRecogida[0] == nullptr && zonaRecogida[1] == nullptr && zonaRecogida[2] == nullptr && zonaRecogida[3] == nullptr){
          zonaRecogida.clear();
        }
        //si los 4 punteros son reales, no agrega nada
      if(zonaRecogida[0] && zonaRecogida[1] && zonaRecogida[2] && zonaRecogida[3] ){
         verificarDerrota = true;
         return false;  
       }
        for (int i = 0 ; i < 4; i++){
         if (!(zonaRecogida[i])){
          zonaRecogida[i] = auxVehiculo;
          int newPosY = zonaRecogida.size()-1;
          auxVehiculo->setPos(0,newPosY);
          //Como ya se encontró un puntero vacío, y se ubicó al auxVehiculo, entonces se retorna false para que en el controller deje de moverse. 
          return false;
         }
        }
      }
      return true;
  }
  return false;
}


//Acá se envía cada pasajero al bus correspondiente a su color (la lógica de los colores está en el model)
void Tablero::pushPasajerosBus(Pasajero* peaton, int i){
 Vehiculo* coche = zonaRecogida[i];
 coche->pushPasajerosBus(peaton);
 filaPasajeros.erase(filaPasajeros.begin()); 
}


//Acá es donde todo falla. intenté varias cosas, pero no logro hacer que si un bus está lleno, se vaya a la zona de victoria. Creo que no puedo lograr conseguir el tamaño del vector, con size() me falla :(
void Tablero::verificarZonaRecogida(){
  std::cout<<"Tamaño del vector: "<< std::endl;
 for (int i = 0; i < 4;i++){
  if (zonaRecogida[i]){
    std::cout<<"dentro del if i:"<<i<<". "<<zonaRecogida[i]->getTipo()<<zonaRecogida[i]->getTamano()<<zonaRecogida[i]->getTamano()*2<<"   "<<zonaRecogida[i]->getSizeSillas()<<std::endl;
    if (zonaRecogida[i]->getTamano()*2 == zonaRecogida[i]->getSizeSillas()){
      zonaVictoria.push_back(zonaRecogida[i]);
      zonaRecogida[i] = nullptr;
    }
  }
 }
}

//ACá debería irse a la zona de victoria los que están llenos en zona recogida.
void Tablero::pushZonaVictoria(Vehiculo* carro){
 zonaVictoria.push_back(carro); 
}
    

  

std::vector<Pasajero*>& Tablero::getFilaPasajeros(){
  return filaPasajeros;
}

std::vector<Vehiculo*>& Tablero::getZonaRecogida(){
  return zonaRecogida;
}

std::vector<std::vector<Vehiculo*>>& Tablero::getZonaCoches(){
  return zonaCoches;
}

std::vector<Vehiculo*>& Tablero::getZonaVictoria(){
  return zonaVictoria;
}


int Tablero::getFilas(){
  return filas;
}

int Tablero::getColumnas(){
  return columnas;
}





bool Tablero::verificarPushPasajeros(){
  char color0;
  char color1;
  char color2;
  char color3;
  char colorPeaton = filaPasajeros[0]->getColor();
  
  if (zonaRecogida[0]){
    color0 = zonaRecogida[0]->getColor();
  }
  if (zonaRecogida[1]){
    color1 = zonaRecogida[1]->getColor();
  }
  if (zonaRecogida[2]){
    color2 = zonaRecogida[2]->getColor();
  }
  if (zonaRecogida[3]){
    color3 = zonaRecogida[3]->getColor();
  }
  
  if((colorPeaton == color0 && zonaRecogida[0]->getSizeSillas() != zonaRecogida[0]->getTamano()*2 ) ||(colorPeaton == color1 && zonaRecogida[1]->getSizeSillas() != zonaRecogida[1]->getTamano()*2) ||(colorPeaton == color2 && zonaRecogida[2]->getSizeSillas() != zonaRecogida[2]->getTamano()*2) || (colorPeaton == color3 && zonaRecogida[3]->getSizeSillas()!= zonaRecogida[3]->getTamano()*2)){
    return true;
  }
  else {
    return false;
  }
}
