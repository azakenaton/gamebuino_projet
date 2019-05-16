#include <Gamebuino-Meta.h>

// Items
const int nbrItems = 6;
int itemGaucheX[nbrItems] = {};
int itemGaucheY[nbrItems] = {};

int itemHautX[nbrItems] = {};
int itemHautY[nbrItems] = {};

const int itemLargeur = 2;
const int itemHauteur = 2;

void setup() {
   gb.begin();
   for (int i = 0; i < nbrItems; i += 1) {
    itemGaucheX[i] = random(-40, 0);
    itemGaucheY[i] = random(0, gb.display.height()); 

    itemHautX[i] = random(0, gb.display.width());  
    itemHautY[i] = random(-40, 0); // Au dessus de l'écran
    
  }
}

void loop() {
  while (!gb.update());
  gb.display.clear();
  for (int i = 0; i < nbrItems; i += 1) {     
    itemGaucheX[i] += 1;
    itemHautY[i] += 1;


  if (itemGaucheX[i]>= gb.display.width()){
    itemGaucheX[i] = random(-40, 0);
    itemGaucheY[i] = random (0, gb.display.height());
  }

   if (itemHautY[i] >= gb.display.height()){
    itemHautX[i] =  random(0, gb.display.width());
    itemHautY[i] = random(-40, 0); // Au dessus de l'écran
  }
  
  for (int j = 0; j < nbrItems; j += 1) {
    gb.display.fillRect(itemGaucheX[j], itemGaucheY[j], itemLargeur, itemHauteur);
    gb.display.fillRect(itemHautX[j], itemHautY[j], itemLargeur, itemHauteur);
  }    
  }
}
