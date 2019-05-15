#include <Gamebuino-Meta.h>

// Items
const int nbrItems = 7;
int itemGaucheX[nbrItems] = {};
int itemGaucheY[nbrItems] = {};

int itemDroiteX[nbrItems] = {};
int itemDroiteY[nbrItems] = {};

const int itemLargeur = 2;
const int itemHauteur = 2;

void setup() {
   gb.begin();
   for (int i = 0; i < nbrItems; i += 1) {
    itemGaucheX[i] = random(-40, 0);
    itemGaucheY[i] = random(0, gb.display.height());  // Au dessus de l'écran

    itemDroiteX[i] = random( gb.display.width(),gb.display.width()+40);
    itemDroiteY[i] = random(0, gb.display.height());
    
  }
}

void loop() {
  while (!gb.update());
  gb.display.clear();
  for (int i = 0; i < nbrItems; i += 1) {     
    itemGaucheX[i] += 1;
    itemDroiteX[i] -= 1;


  if (itemGaucheX[i]>= gb.display.width()){
    itemGaucheX[i] = random(-40, 0);
    itemGaucheY[i] = random (0, gb.display.height());
  }

   if (itemDroiteX[i] <= 0){
    itemDroiteX[i] =  random( gb.display.width(),gb.display.width()+40);
    itemDroiteY[i] = random (0, gb.display.height());
  }
  
  for (int j = 0; j < nbrItems; j += 1) {
    gb.display.fillRect(itemGaucheX[j], itemGaucheY[j], itemLargeur, itemHauteur);
    gb.display.fillRect(itemDroiteX[j], itemDroiteY[j], itemLargeur, itemHauteur);
  }    
  }
}
