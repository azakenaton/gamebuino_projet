#include <Gamebuino-Meta.h>

const int nbrItems = 7;
int posX;
int posY;
double vit = 2;
Player *p;
int al;//= rand() % 100; entre 0 et 70 = 1 / entre 70 et 90 = 2 / entre 90 et 99 = 3
Obstacle *obsTabG[nbrItems];
Obstacle *obsTabH[nbrItems];
vObs = 1;//vitesse obstacle

class Player 
{
  private:
  
  int x;
  int y;
  int taille;

  public:

  Player::Player()
  {
    this.x = (gb.display.width()/2)-2;
    this.y = (gb.display.height()/2)-2;
    this.taille = 4;
    this.setColor(WHITE);
    gb.display.fillRect(x, y, taille, taille);
  }

  void moove_player(){
  
    if(gb.buttons.repeat(BUTTON_UP,1)){
      if (this.y > 0){
        this.y -= vit;
      }
     }
     if(gb.buttons.repeat(BUTTON_DOWN,1)){
      if (this.y < gb.display.height()-4){
        this.y += vit;
      }
     }
     if(gb.buttons.repeat(BUTTON_LEFT,1)){
       if (this.x > 0){
        this.x -= vit;
      }
     }
     if(gb.buttons.repeat(BUTTON_RIGHT,1)){
       if (this.x < gb.display.width()-4){
        this.x += vit;
      }
     }

     gb.display.fillRect(this.x, this.y, taille, taille);
  }
  
};

class Obstacle
{
  private:
  int x;
  int y;
  int type;

  Obstacle::Obstacle(int positionX, int positionY, int typeObs)
  {
    this.x = positionX;
    this.y = positionY;
    this.type = typeObs;
  }

  void avX(){
    this.x += vObs;
  }

  void avY(){
    this.y += vObs;
  }

  void reX(){
    this.x -= vObs;
  }

  void reY(){
    this.y -= vObs;
  }

};

int get_type(){
  al = rand() % 100;
  if(0 <= al <=69){
    al = 1;
  }else if(70 <= al <= 89){
    al = 2;
  }else{
    al = 3;
  }
}

Obstacle creation_obstacle(){
  for(int i = 0; i< nbrItems; i += 1) {
    int typeObs;
    typeObs = get_type();
    obsTabG[i] = new Obstacle(random( gb.display.width(),gb.display.width()+40),random(0, gb.display.height()),typeObs);
    typeObs = get_type();
    obsTabH[i] = new Obstacle(random(-40, 0),random(0, gb.display.height()),typeObs);
  }
}

Obstacle creation_obstacle(){
  for(int i = 0; i< nbrItems; i += 1) {
    int typeObs;
    typeObs = get_type();
    obsTabG[i] = new Obstacle(random( gb.display.width(),gb.display.width()+40),random(0, gb.display.height()),typeObs);
    typeObs = get_type();
    obsTabH[i] = new Obstacle(random(-40, 0),random(0, gb.display.height()),typeObs);
  }
}

Obstacle creationGauche(){
  int typeObs;
  typeObs = get_type();
  obsTabG[nbrItems] = new Obstacle(random( gb.display.width(),gb.display.width()+40),random(0, gb.display.height()),typeObs);
}

Obstacle creationHaut(){
  int typeObs;
  typeObs = get_type();
  obsTabH[nbrItems] = new Obstacle(random(-40, 0),random(0, gb.display.height()),typeObs);
}

void setup() {
  gb.begin();
  p = new Player;
  creation_obstacle(); 
}

void loop() {
  while(!gb.update());
  gb.display.clear();

  p->moove_player();

  for (int i = 0; i < nbrItems; i += 1) {     
    obsTabG[i]->avX();
    obsTabH[i]->reX();
  }
}
