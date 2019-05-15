#include <Gamebuino-Meta.h>

int posX;
int posY;
int speedX = 1;

void setup() {
  gb.begin();
  posX = (gb.display.width()/2)-2;
  posY = (gb.display.height()/2)-2;
}


void loop() {
  while(!gb.update());
  gb.display.clear();

  if(gb.buttons.repeat(BUTTON_UP,1)){
    posY -= 1;
  }
  if(gb.buttons.repeat(BUTTON_DOWN,1)){
    posY += 1;
  }
  if(gb.buttons.repeat(BUTTON_LEFT,1)){
    posX -= 1;
  }
  if(gb.buttons.repeat(BUTTON_RIGHT,1)){
    posX += 1;
  }

  
  gb.display.setColor(WHITE);
  gb.display.fillRect(posX, posY, 4, 4);
  
}
