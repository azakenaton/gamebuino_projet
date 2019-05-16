#include <Gamebuino-Meta.h>
#include "Player.h"
#include "Obstacle.h"

//Initialisation
const int nbrItems = 5;
Player *p;
int posX;
int posY;
double vit = 2;
Obstacle *obsTabG[nbrItems];
Obstacle *obsTabH[nbrItems];
bool col;
bool fini = false;

//Methodes
int get_type(){
  int al;
  al = rand() % 100;
  if(0 <= al <=69){
    al = 1;
  }else if(70 <= al <= 89){
    al = 2;
  }else{
    al = 3;
  }
  return al;
}

void creation_obstacleG(){
  for (int i = 0; i < nbrItems; i += 1) {
    obsTabG[i] = new Obstacle(random(-40, 0),random(0, gb.display.height()));
  }
}

void creation_obstacleH(){
  for (int i = 0; i < nbrItems; i += 1) {
    obsTabH[i] = new Obstacle(random(0, gb.display.width()),random(-40, 0));
  }
}

bool checkColision(){
  col = false;
  for (int i = 0; i < nbrItems; i += 1) {
    col = obsTabH[i]->colision(p->getposX(),p->getposY(),p->getTaille());
    if(col == false){
      col = obsTabG[i]->colision(p->getposX(),p->getposY(),p->getTaille());
    }else{
      return col;
    }
    if(col == true){
      return col;
    }
  }
  return col;
}

void theEnd(){
  gb.display.clear();
  fini = true;
  gb.display.print("The end");
}

void setup() {
  gb.begin();
  p = new Player((gb.display.width()/2)-2,(gb.display.height()/2)-2); 
  creation_obstacleG();
  creation_obstacleH();
}


void loop() {
  while(!gb.update());
  gb.display.clear();
  if(fini == false){
    for (int i = 0; i < nbrItems; i += 1) {
    int itemGaucheX = obsTabG[i]->getposX();
    int itemHautY = obsTabH[i]->getposY();
    obsTabG[i]->avX();
    obsTabH[i]->avY();
    
    if(itemGaucheX >= gb.display.width()){
      obsTabG[i]->setposX(random(-40, 0));
      obsTabG[i]->setposY(random (0, gb.display.height()));
    }

    if(itemHautY >= gb.display.height()){
      obsTabH[i]->setposX(random(0, gb.display.width()));
      obsTabH[i]->setposY(random(-40, 0));
    }
  }

  for (int j = 0; j < nbrItems; j += 1) {
    gb.display.setColor(RED);
    gb.display.fillRect(obsTabG[j]->getposX(), obsTabG[j]->getposY(), obsTabG[j]->getTaille(), obsTabG[j]->getTaille());
    gb.display.fillRect(obsTabH[j]->getposX(), obsTabH[j]->getposY(), obsTabH[j]->getTaille(), obsTabH[j]->getTaille());
  }

  p->moove_player();

  if(checkColision() == true){
    theEnd();
  }
  }else{
    theEnd();
  }
}
