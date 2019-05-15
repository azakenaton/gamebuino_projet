#include <Gamebuino-Meta.h>

int posX;
int posY;
double vit = 2;
Player *p;

class Player 
{
  private:
  
  int x;
  int y;

  public:

  Player::Player()
  {
    x = (gb.display.width()/2)-2;
    y = (gb.display.height()/2)-2;
    this.setColor(WHITE);
    gb.display.fillRect(x, y, 4, 4);
  }
  
};

void setup() {
  gb.begin();
  p = new Player; 
}

void moove_player(){
  
  if(gb.buttons.repeat(BUTTON_UP,1)){
    if (posY > 0){
      posY -= vit;
    }
   }
   if(gb.buttons.repeat(BUTTON_DOWN,1)){
    if (posY < gb.display.height()-4){
      posY += vit;
    }
   }
   if(gb.buttons.repeat(BUTTON_LEFT,1)){
     if (posX > 0){
      posX -= vit;
    }
   }
   if(gb.buttons.repeat(BUTTON_RIGHT,1)){
     if (posX < gb.display.width()-4){
      posX += vit;
    }
   }

   gb.display.setColor(WHITE);
   gb.display.fillRect(posX, posY, 4, 4);
}

void loop() {
  while(!gb.update());
  gb.display.clear();

  moove();
  
}
