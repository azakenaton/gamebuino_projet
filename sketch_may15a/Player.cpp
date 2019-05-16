#include "Player.h"
#include <Gamebuino-Meta.h>

Player::Player(){
  x = 0;
  y = 0;
  taille = 4;
}

Player::Player(int posX, int posY){
  x = posX;
  y = posY;
  taille = 4;
}

void Player::moove_player(){
  
  if(gb.buttons.repeat(BUTTON_UP,1)){
    if (y > 0){
      y -= player_vit;
    }
   }
   if(gb.buttons.repeat(BUTTON_DOWN,1)){
    if (y < gb.display.height()-4){
      y += player_vit;
    }
   }
   if(gb.buttons.repeat(BUTTON_LEFT,1)){
     if (x > 0){
      x -= player_vit;
    }
   }
   if(gb.buttons.repeat(BUTTON_RIGHT,1)){
     if (x < gb.display.width()-4){
      x += player_vit;
    }
   }
   gb.display.setColor(WHITE);
   gb.display.fillRect(x, y, 4, 4);
}

int Player::getposX(){
  return x;
}
int Player::getposY(){
  return y;
}
int Player::getTaille(){
  return taille;
}

