#include <Gamebuino-Meta.h>

int posX = 1;
int speedX = 1;

void setup() {
  gb.begin();
}


void loop() {
  while(!gb.update());
  gb.display.clear();

  if(posX == gb.display.width()-4){
    speedX = -1;
  }
  if(posX == 0){
    speedX = 1;
  }

  posX = posX + speedX;
  
  gb.display.setColor(BROWN);
  gb.display.fillRect(posX, 32, 4, 4);
  
}
