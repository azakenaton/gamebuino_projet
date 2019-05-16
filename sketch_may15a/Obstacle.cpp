#include "Obstacle.h"
#include <Gamebuino-Meta.h>

Obstacle::Obstacle(){
  x = 0;
  y = 0;
  taille = 2;
}

Obstacle::Obstacle(int positionX, int positionY){
  x = positionX;
  y = positionY;
  taille = 2;
}

bool Obstacle::colision(int px, int py, int ptaille){
  int col = gb.collide.rectRect(px,py,ptaille,ptaille,x,y,taille,taille);
  return col;
}

void Obstacle::avX(){
  x += vObs;
}

void Obstacle::avY(){
  y += vObs;
}

int Obstacle::getposX(){
  return x;
}

int Obstacle::getposY(){
  return y;
}

void Obstacle::setposX(int posX){
  x = posX;
}

void Obstacle::setposY(int posY){
  y = posY;
}

int Obstacle::getTaille(){
  return taille;
}

